#include "queue.h"
#include <iostream>
#include "huff.h"
#include <stdlib.h>

using namespace std;
void initPQueue(pQueue **queue)
{
	(*queue)=(pQueue *)malloc(sizeof(pQueue));
		(*queue)->first=NULL;
	(*queue)->size=0;//初始化队列
	return;
}
void addPQueue(pQueue **queue,TYPE val,unsigned int priority)
{
	if((*queue)->size==MAX_SZ)
	{
		cout <<endl;
		cout <<"队列已满"<<endl;
		return;
	}
	pQueueNode *aux=(pQueueNode *)malloc(sizeof(pQueueNode));
	aux->priority=priority;
	aux->val=val;
	if((*queue)->size==0||(*queue)->first==NULL)
	{
		aux->next=NULL;
		(*queue)->first=aux;
		(*queue)->size=1;
		return;
	}
	else
	{
		if(priority<=(*queue)->first->priority)
		{
			aux->next=(*queue)->first;
			(*queue)->first=aux;
			(*queue)->size++;
			return;
		}
		else
		{
			pQueueNode *T=(*queue)->first;
			while(T->next!=NULL)
			{
				if(priority<=T->next->priority)
				{
					aux->next=T->next;
					T->next=aux;
					(*queue)->size++;
					return;
				}
				T=T->next;
			}
			if (T->next==NULL)
			{
				aux->next=NULL;
				T->next=aux;
				(*queue)->size++;
				return;
			}
		}
	}
}

TYPE getPQueue(pQueue **queue)
{
	TYPE value;
	if((*queue)->size>0)
	{
		value=(*queue)->first->val;
		(*queue)->first=(*queue)->first->next;
		(*queue)->size--;
	}
	else
	{
		cout<<endl;
		cout<<"队列为空!"<<endl;
	}
	return value;
}

