#pragma once
#include <stdio.h>
#include<string.h>
#include<malloc.h>

typedef struct Node {
	char data;
	struct Node* left;
	struct Node* right;
}BiNode, * BiTree;


typedef struct Node DataType;
typedef struct LinkQueueNode
{
	DataType data;
	struct LinkQueueNode* next;
}LinkQueueNode;//队列的结点结构

typedef struct
{
	LinkQueueNode* front;
	LinkQueueNode* rear;
}LinkQueue;//队列的链表结构

//初始化队列
void InitLinkQueue(LinkQueue* LQ)
{
	//创建头结点
	LinkQueueNode* pHead = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
	if (pHead == NULL)
	{
		printf("InitLinkQueue fail:malloc error\n");
		return;
	}
	LQ->front = LQ->rear = pHead;//队头和队尾指向头结点 ps:重要，后面的操作都是基于此
	LQ->front->next = NULL;
}

//判断队列是否为空
int IsEmptyQueue(LinkQueue* LQ)
{
	if (LQ->front == LQ->rear)//队头指针与队尾指针相等，队列为空
	{
		return 1;//队列为空
	}
	return 0;
}

//新元素入队
void EnterLinkQueue(LinkQueue *LQ, DataType data)
{
	LinkQueueNode* pNewNode = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
	if (pNewNode == NULL)
	{
		printf("EnterLinkQueue fail:malloc error\n");
		return;
	}
	//链式队列的结点是动态开辟的，没有判断队列是否为满的操作
	//建立结点
	pNewNode->data = data;//将数据元素赋值给结点的数据域
	pNewNode->next = NULL;//将结点的指针域置空
	//实现插入
	LQ->rear->next = pNewNode;//新结点接到上一个结点尾部
	LQ->rear = pNewNode;//队尾指针重新指向，新任队尾
}
//acde#bf######
//元素出队
void DeleteLinkQueue(LinkQueue *LQ,DataType *data)
{
	
	if (IsEmptyQueue(LQ))
	{
		printf("队列为空，出队失败\n");
		return;
	}
	
	//pDel指向队头元素，由于队头指针front指向头结点，所以pDel指向头结点的下一个结点
	LinkQueueNode* pDel = LQ->front->next;
	data->data =  ( & (pDel->data))->data;//将要出队的元素赋给data
	data->left = (&(pDel->data))->left;
	data->right = (&(pDel->data))->right;
	LQ->front->next = pDel->next;//使指向头结点的指针指向pDel的下一个结点
	if (LQ->rear == pDel)//如果队列中只有一个元素,将队尾指针指向头结点，队列为空
	{
		LQ->rear = LQ->front;
	}
	free(pDel);//释放pDel指向的空间
}


//获取队头元素
DataType GetHeadData(LinkQueue* LQ, DataType* data)
{
	if (IsEmptyQueue(LQ))
	{
		printf("队列为空\n");
		return *data;
	}
	LinkQueueNode* pCur = LQ->front->next;//pCur指向队列的第一个元素，即头结点的下一个结点
	*data = pCur->data;
	return *data;
}

//获取队列长度
int GetLinkQueueLength(LinkQueue* LQ)
{
	int length = 0;
	LinkQueueNode* pCur = LQ->front->next;
	while (pCur != NULL)
	{
		length++;
		pCur = pCur->next;
	}
	return length;
}

//打印队列元素
void PrintLinkQueue(LinkQueue* LQ)
{
	LinkQueueNode* pCur;
	pCur = LQ->front->next;
	while (pCur != NULL)
	{
		printf("%d ", pCur->data);
		pCur = pCur->next;
	}
	printf("\n");
}

//清空队列
void ClearLinkQueue(LinkQueue* LQ)
{
	while (LQ->front != NULL)
	{
		LQ->rear = LQ->front->next;//当删除队列时，队尾指针就没用处了，此处采用队尾指针来保存队头指针的下一个结点
		free(LQ->front);//全部释放，包括头结点
		LQ->front = LQ->rear;
	}
}
