#pragma once
#ifndef _QUEUE_H
#define _QUEUE_H

#include "huff.h"
#define TYPE htNode*

#define MAX_SZ 256//ASALL

typedef struct p_QueueNode 
{
TYPE val;
unsigned int  priority;//��¼���ֵĴ�����Ȩ�أ�
struct p_QueueNode *next;//ָ����һ���ڵ�
}pQueueNode;

typedef struct p_Queue
{
unsigned int size;//����Ԫ�ظ���
pQueueNode *first;//ָ��ͷ���
}pQueue;

void initPQueue(pQueue **queue);//�������У����ڵ�ָ���ָ�봫��
void addPQueue(pQueue **queue,TYPE val,unsigned int priority);//����Ȩ�ز������
TYPE getPQueue(pQueue **queue);

#endif
