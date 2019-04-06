#include<iostream>
#include<stdlib.h> 
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10 
using namespace std;
 
typedef  struct BiTNode
{
	char  data;
	struct BiTNode *lchild , *rchild;  //左右孩子指针 
} BiTNode , *BiTree;
 
bool  CreateBiTree(BiTree &T)
{
	//按先序序列输入二叉树中的节点值,空格代表空字符 
	char ch; 
	cout<<"先序输入字符"<<endl; 
	cin>>ch;
	if(ch == '0')  T = NULL;
	else
	{
		if(! (T = (BiTNode*) malloc (sizeof(BiTNode))))	  return false;
		T->data = ch;
		CreateBiTree(T->lchild) ; //构造左子树
		CreateBiTree(T->rchild) ;//构造右子树 
	}
	return true;
}
 
 
//构建栈 
typedef  struct 
{
	BiTree *base;
	BiTree *top;  //指向二叉树节点指针的指针
	int stacksize; //当前以分配的存储空间 , 以元素为单位 
}SqStack;
 
bool InitStack(SqStack s)
{
	s.base =  (BiTree *)  malloc( STACK_INIT_SIZE * sizeof(BiTree));
	if(!s.base) return false; //存储分配失败
	s.top = s.base;
	s.stacksize = STACK_INIT_SIZE;
	return true; 
}
 
bool  Push(SqStack &s , BiTree e)
{
	//插入指向二叉树节点的指针为栈顶元素
	if(s.top - s.base >= s.stacksize) {  //栈满,追加存储空间 
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
	if(s.top == s.base )  return false;  //栈空
	e = * --s.top;
//	cout<<"以退栈"<<e->data<<endl;
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
 
 
 
bool visit(BiTree e)  //将二叉树的节点显示到控制台上 
{
	//if(e)  return false;
	cout<<e->data;
	return true;
}
 
 
SqStack s;  //定义栈头结点 
  
 
 
//中序遍历 
bool InOrderTraverse(BiTree T , bool  (*visit)(BiTree e)) //后一个参数为接收visit函数指针 
{
	cout<<"中序遍历结果如下:"<<endl; 
	InitStack(s); 
	BiTree p ; p=T;
	while(p || !StackEmpty(s))
	{
		if(p)
		{
			Push(s , p) ; p = p->lchild;  //根指针进栈 , 遍历左子树 
		}
		else
		{
			//根指针退栈, 访问根节点 ,遍历右子树
			Pop(s , p); 
			cout<<p->data;
			p = p->rchild;
		}
	}
	return true;
}
 
//非递归前序遍历 
bool PreOrderTracerse(BiTree T , bool (*visit)(BiTree e))
{
cout <<"前序遍历如下:"<<endl;
InitStack(s); 
	BiTree p ; p=T;
	while(p|| !StackEmpty(s))
	{
		while(p)
		{
			cout<<p->data;//将访问结果输出后压入栈中 
			Push(s,p);p=p->lchild;
		}
		if(!StackEmpty(s))
		{
			Pop(s,p);//出栈后访问右孩子后再次遍历左孩子 
			p=p->rchild;
			
		}
	}
}

//非递归后序遍历 
bool PosOrderTracerse(BiTree T , bool (*visit)(BiTree e))
{
	cout <<"后序遍历如下:"<<endl;
InitStack(s); 
	BiTree p ; p=T;
	BiTree recent=NULL;//保存最近的节点
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
			if(p->rchild&&p->rchild!=recent)//若右子树等于附近访问节点，说明节点右子树遍历完成，应该弹出节点 
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
	//定义一个visit函数指针
	bool (*visit_point) (BiTree e);
	visit_point = visit;
	BiTree T;
	CreateBiTree(T) ;
	cout<<"二叉树构造完成!"<<endl<<endl<<endl; 
	InOrderTraverse(T , visit_point); 
	cout<<endl;
	PreOrderTracerse(T , visit_point) ;
	cout<<endl;
	PosOrderTracerse(T , visit_point);
	return true;
}
