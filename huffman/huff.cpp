#include <iostream>
#include <string>
#include<cstring>
#include <stdlib.h>
#include "huff.h"
#include "queue.h"
using namespace std;
void traverseTree(htNode *treeNode,hlTable **table,int k,char code[256])
{
	if(treeNode->ltree==NULL&&treeNode->rtree==NULL)
	{
		code[k]='\0';
		hlNode *aux=(hlNode *)malloc(sizeof(hlNode));
		aux->code=(char*)malloc(sizeof(char)*(strlen(code)+1));
		strcpy(aux->code,code);
		aux->symbol=treeNode->symbol;
		aux->next=NULL;
		
		if((*table)->first==NULL)
		{
			(*table)->first=aux;
			(*table)->last=aux;
		}
		else
		{
			(*table)->last->next=aux;
			(*table)->last=aux;
		}
	}
	
	
	if(treeNode->ltree!=NULL)
	{
		code[k]='0';
		traverseTree(treeNode->ltree,table,k+1,code);
	}
	
	if(treeNode->rtree!=NULL)
	{
		code[k]='1';
		traverseTree(treeNode->rtree,table,k+1,code);
	}
}



hlTable *buildTable(htTree *huffmanTree)
{
	hlTable *table =(hlTable *)malloc(sizeof(hlTable));
	table->first=NULL;
	table->last=NULL;
	char code[256];
	int k=0;
	traverseTree(huffmanTree->root,&table,k,code);
	return table;
}





htTree *buildTree(char *tstring)
{
	int *probability=(int *)malloc(sizeof(int)*256);
	//初始化
	for(int i=0;i<256;i++)
	{
		probability[i]=0;
	}
    //统计出现次数
	for(int j=0;tstring[j]!='\0';j++)
	{
		probability[(unsigned char)tstring[j]]++;
	}
	cout<<"统计完成"<<endl;
	
	
	//生成队列并填充
	pQueue *huffmanQueue ;
	initPQueue(&huffmanQueue);
	cout<<"已建立队列"<<endl;	
	int y=0;
	for (int k=0; k<256 ;k++)
	{
		if(probability[k]!=0)
		{
			htNode *aux = (htNode *)malloc(sizeof(htNode));
			aux->ltree=NULL;
			aux->rtree=NULL;
			aux->symbol=(char) k;
			addPQueue(&huffmanQueue,aux,probability[k]);
		}
	}
	free(probability);
	cout<<"已排列并加权"<<endl;
	while(huffmanQueue->size!=1)
	{
		int priority=huffmanQueue->first->priority;
		priority+=huffmanQueue->first->next->priority;
		htNode *left=getPQueue(&huffmanQueue);
		htNode *right=getPQueue(&huffmanQueue);
		
		htNode *sumNode=(htNode *)malloc(sizeof(htNode));
		sumNode->ltree=left;
		sumNode->rtree=right;
		
		addPQueue(&huffmanQueue,sumNode,priority);
	}
	htTree *tree=(htTree *)malloc(sizeof(htTree));
	tree->root=getPQueue(&huffmanQueue);
	cout<<"已建立哈夫曼树"<<endl;
	return tree;
	
}

void encode (hlTable *table ,char *stringToEncode)
{
	hlNode *traversal;
	cout<<"编码中......"<<endl;
	for(int i=0;stringToEncode[i]!='\0';i++)
	{
		traversal=table->first;
		while(traversal->symbol!=stringToEncode[i])
			
			traversal=traversal->next;
		cout<<traversal->code;
	}
	cout<<endl;
}

void decode (htTree *tree,char *stringToDecode)
{
	htNode *traversal=tree->root;
	cout<<"解码中"<<endl;
	for(int i=0 ;stringToDecode [i]!='\0';i++)
	{
		if(traversal->ltree==NULL && traversal->rtree==NULL)
		{
			cout<<traversal->symbol;
			traversal=tree->root;
		}
		if (stringToDecode[i]=='0')
			traversal=traversal->ltree;
		if(stringToDecode[i]=='1')
			traversal=traversal->rtree;
		if(stringToDecode[i]!='0'&&stringToDecode[i]!='1')
		{
			cout<<"解码错误！"<<endl;
			return;
		}

	}
	if (traversal->ltree==NULL&& traversal->rtree==NULL)
	{
	cout<<traversal->symbol;
	}
	

}



