#pragma once
#ifndef _HUFF_H_
#define _HUFF_H_

typedef struct ht_Node
{
char symbol;//�ַ�
struct ht_Node *ltree, *rtree;
}htNode;

typedef struct ht_Tree
{
htNode *root;//���ڵ�
}htTree;

typedef struct hl_Node
{
char symbol;//�ַ�
char *code;//����
struct hl_Node *next;//
}hlNode;

typedef struct hl_table
{
	hlNode *first;
	hlNode *last;
}hlTable;

htTree *buildTree(char *tstring);
hlTable *buildTable(htTree *huffmanTree);
void encode(hlTable *table,char *stringToEncode);
void decode(htTree *tree,char *stringToDecode);

#endif