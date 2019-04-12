#pragma once
#ifndef _QUEUE_H
#define _QUEUE_H

#include "huff.h"
#define TYPE htNode*

#define MAX_SZ 256//ASALL

typedef struct p_QueueNode 
{
TYPE val;
unsigned int  priority;//记录出现的次数（权重）
struct p_QueueNode *next;//指向下一个节点
}pQueueNode;

typedef struct p_Queue
{
unsigned int size;//队列元素个数
pQueueNode *first;//指向头结点
}pQueue;

void initPQueue(pQueue **queue);//建立队列，将节点指针的指针传入
void addPQueue(pQueue **queue,TYPE val,unsigned int priority);//根据权重插入队列
TYPE getPQueue(pQueue **queue);

#endif
