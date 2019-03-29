#include <iostream>
#include<cstdlib>
using namespace std;
struct Node
{
	Node *next;
	double data;
}; 

struct LinkStack
{
	Node *front;
	Node *rear;
	
};

void InitStack(LinkStack &S)
{
	Node *p;
	p=new Node;
	p->next=NULL;
	S.front=p;
	S.rear=p;
}

void EnStack (LinkStack &S,double e)
{
	Node *p;
	p=new Node;
	p->next=NULL;
	p->data=e;
	S.rear->next=p;
	S.rear=p; 
}

void PushStack(LinkStack &S,double &e)
{
	Node *p;
	p=S.front->next;
	while(p->next->next)
	{
		p=p->next;
	}
	e=p->next->data;
	p->next=p->next->next;
	
}

void display(LinkStack &S)
{
	Node *p;
	p=S.front->next;
	while(p->next)
	{
		cout<<p->next->data<<endl;
		p=p->next;
	}
}

bool IsEmpty(LinkStack &S)
{
	if(S.rear==S.front)
	return true;
	else return false;
}

int main()
{
	LinkStack *S;
	S=new LinkStack;
	InitStack(*S);
	double a,b;
	cout<<"please input a number:" <<endl;
	cin>>a;
	while (a!=-1)//当输入-1时停止输入
	{
		EnStack(*S,a);
		cout<<"please input a number:"<<endl;
		cin>>a;
	}
	Node *p;
	p=S->front->next;
	if(IsEmpty(*S))
	cout<<"emety!"<<endl;
	display(*S);
	PushStack(*S,b);
	cout<<"delete "<<b<<endl;
    display(*S);
}























