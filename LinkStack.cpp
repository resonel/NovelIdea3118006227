#include <iostream>
#include<cstdlib>
using namespace std;
struct QNode
{
	QNode *next;
	double data;
};

struct LinkQueue
{
	QNode *front;
	QNode *rear;
	
};

void InitQueue(LinkQueue &Q)
{
	QNode *q;
	q=new QNode;
	q->next=NULL;
	Q.front=q;
	Q.rear=q;
}

bool IsEmpty(LinkQueue &Q)
{
	if(Q.rear==Q.front)
	return true;
	else return false;
}

void EnQueue (LinkQueue &Q,double e)
{
	QNode *p;
	p=new QNode;
	p->next=NULL;
	p->data=e;
	Q.rear->next=p;
	Q.rear=p; 
}

void DeQueue(LinkQueue &Q,double &e)
{
	QNode *p;
	p=Q.front->next;
	e=p->data;
	Q.front->next=p->next;
	if(Q.rear==p)
	Q.rear=Q.front;delete p;
}

void display(LinkQueue &Q)
{
    QNode *p;
    p=Q.front->next;
    while(p!=NULL)
	{
		cout<<p->data<<" ";
	p=p->next;
	}
}


int main()
{
	LinkQueue *Q;
	Q=new LinkQueue;
	InitQueue(*Q);
	double a,b;
	cout<<"please input a number:" <<endl;
	cin>>a;
	while (a!=-1)//当输入-1时停止输入
	{
		EnQueue(*Q,a);
		cout<<"please input a number:"<<endl;
		cin>>a;
	}
	QNode *p;
	p=Q->front->next;
	if(IsEmpty(*Q))
	cout<<"emety!"<<endl;
	display(*Q);
	DeQueue(*Q,b);
	cout<<"delete "<<b<<endl;
    display(*Q);
	
}































