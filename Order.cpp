#include<iostream>
#include<stdlib.h> 
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10 
using namespace std;
 
typedef  struct BiTNode
{
	char  data;
	struct BiTNode *lchild , *rchild;  //���Һ���ָ�� 
} BiTNode , *BiTree;
 
bool  CreateBiTree(BiTree &T)
{
	//��������������������еĽڵ�ֵ,�ո������ַ� 
	char ch; 
	cout<<"���������ַ�"<<endl; 
	cin>>ch;
	if(ch == '0')  T = NULL;
	else
	{
		if(! (T = (BiTNode*) malloc (sizeof(BiTNode))))	  return false;
		T->data = ch;
		CreateBiTree(T->lchild) ; //����������
		CreateBiTree(T->rchild) ;//���������� 
	}
	return true;
}
 
 
//����ջ 
typedef  struct 
{
	BiTree *base;
	BiTree *top;  //ָ��������ڵ�ָ���ָ��
	int stacksize; //��ǰ�Է���Ĵ洢�ռ� , ��Ԫ��Ϊ��λ 
}SqStack;
 
bool InitStack(SqStack s)
{
	s.base =  (BiTree *)  malloc( STACK_INIT_SIZE * sizeof(BiTree));
	if(!s.base) return false; //�洢����ʧ��
	s.top = s.base;
	s.stacksize = STACK_INIT_SIZE;
	return true; 
}
 
bool  Push(SqStack &s , BiTree e)
{
	//����ָ��������ڵ��ָ��Ϊջ��Ԫ��
	if(s.top - s.base >= s.stacksize) {  //ջ��,׷�Ӵ洢�ռ� 
		s.base = (BiTree *) realloc(s.base , (s.stacksize +STACKINCREMENT) * sizeof(BiTree));
		if(!s.base)  return false;
		s.top = s.base + s.stacksize;
		s.stacksize += STACKINCREMENT;
	} 
	*s.top ++ = e;
	return true;
}
 
bool  Pop(SqStack &s , BiTree &e)
{
	if(s.top == s.base )  return false;  //ջ��
	e = * --s.top;
//	cout<<"����ջ"<<e->data<<endl;
	return true; 
}
 
 
bool StackEmpty(SqStack s)
{
	if(s.base == s.top) return true;
	else
	{
		return false;
	}
}
 
 
 
bool visit(BiTree e)  //���������Ľڵ���ʾ������̨�� 
{
	//if(e)  return false;
	cout<<e->data;
	return true;
}
 
 
SqStack s;  //����ջͷ��� 
  
 
 
//������� 
bool InOrderTraverse(BiTree T , bool  (*visit)(BiTree e)) //��һ������Ϊ����visit����ָ�� 
{
	cout<<"��������������:"<<endl; 
	InitStack(s); 
	BiTree p ; p=T;
	while(p || !StackEmpty(s))
	{
		if(p)
		{
			Push(s , p) ; p = p->lchild;  //��ָ���ջ , ���������� 
		}
		else
		{
			//��ָ����ջ, ���ʸ��ڵ� ,����������
			Pop(s , p); 
			cout<<p->data;
			p = p->rchild;
		}
	}
	return true;
}
 
//�ǵݹ�ǰ����� 
bool PreOrderTracerse(BiTree T , bool (*visit)(BiTree e))
{
cout <<"ǰ���������:"<<endl;
InitStack(s); 
	BiTree p ; p=T;
	while(p|| !StackEmpty(s))
	{
		while(p)
		{
			cout<<p->data;//�����ʽ�������ѹ��ջ�� 
			Push(s,p);p=p->lchild;
		}
		if(!StackEmpty(s))
		{
			Pop(s,p);//��ջ������Һ��Ӻ��ٴα������� 
			p=p->rchild;
			
		}
	}
}

//�ǵݹ������� 
bool PosOrderTracerse(BiTree T , bool (*visit)(BiTree e))
{
	cout <<"�����������:"<<endl;
InitStack(s); 
	BiTree p ; p=T;
	BiTree recent=NULL;//��������Ľڵ�
	while(p||!StackEmpty(s))
	{
		while(p)
		{
			Push(s,p);
			p=p->lchild;
		}
		if(!StackEmpty(s))
		{
			Pop(s,p);
			if(p->rchild&&p->rchild!=recent)//�����������ڸ������ʽڵ㣬˵���ڵ�������������ɣ�Ӧ�õ����ڵ� 
			{
				Push(s,p);
				p=p->rchild;
			}
			else
			{
				cout<<p->data;
				recent=p;
				p=NULL;
			}
		 } 
	 } 
 } 
 
 
 bool EnBitree(BiTree T , double e)
{
	BiTree q;
	q->data=e;
	BiTree p ; p=T;
	while(p)
	{
		if(e<p->data)
		p=p->lchild;
		else p=p->rchild; 
	}
	
}
 
 

 
 
int  main()
{
	//����һ��visit����ָ��
	bool (*visit_point) (BiTree e);
	visit_point = visit;
	BiTree T;
	CreateBiTree(T) ;
	cout<<"�������������!"<<endl<<endl<<endl; 
	InOrderTraverse(T , visit_point); 
	cout<<endl;
	PreOrderTracerse(T , visit_point) ;
	cout<<endl;
	PosOrderTracerse(T , visit_point);
	return true;
}
