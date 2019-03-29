#include <iostream>
using namespace std;
#define MAXSIZE 10
class queue
{
	public:
		queue();
		bool IsFull();//���� 
		bool IsEmpty();//�п� 
		bool Enterqueue(int);//���� 
		bool Deletequeue(int&d);//���� 
		int QueueLength();//��ȡ���г��� 
		void ClearQueue();//��ն���
		void display();
	private:
	    int size[MAXSIZE];//Ԫ������
		int front;//��ͷ
		int rear;//��β 
		
};
queue::queue()
{
	this->front=0;
	this->rear=0;
}

bool queue::IsFull()
{
	if((this->rear+1)%MAXSIZE==this->front)
	return true;
	else
	return false;
}

bool queue::IsEmpty()
{
	if(this->front==this->rear)
	return true;
	else
	return false;
}

void queue::ClearQueue()
{
	this->front=0;
	this->rear=0;	
}

bool queue::Enterqueue(int d)
{
	if(this->IsFull() )
	return false;
	this->size[this->rear]=d;
	this->rear=(this->rear+1)%MAXSIZE;
	return true;
}

bool queue::Deletequeue(int &d)
{
	if(this->IsEmpty())
	return false;
	d=this->size[this->front];
	this->front=(this->front+1)%MAXSIZE;
	return true;
}


int queue::QueueLength()
{
	return 0;
}

void queue::display()
{
	int i=0;
	int len=0;
	if(this->rear>this->front)
		len=this->rear-this->front;
		else
		len=MAXSIZE-this->front+this->rear;
	for(;i<len;i++)
		cout<<size[i]<<endl;
}

int main()
{
	queue q;
	q.Enterqueue(2);
	q.Enterqueue(3);
	q.Enterqueue(4);
	q.display();
	int value=0;
	q.Deletequeue(value);
	cout<<"delete "<<value<<endl;
	q.display();
	
	
	
}




















