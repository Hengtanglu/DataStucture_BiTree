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
}LinkQueueNode;//���еĽ��ṹ

typedef struct
{
	LinkQueueNode* front;
	LinkQueueNode* rear;
}LinkQueue;//���е�����ṹ

//��ʼ������
void InitLinkQueue(LinkQueue* LQ)
{
	//����ͷ���
	LinkQueueNode* pHead = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
	if (pHead == NULL)
	{
		printf("InitLinkQueue fail:malloc error\n");
		return;
	}
	LQ->front = LQ->rear = pHead;//��ͷ�Ͷ�βָ��ͷ��� ps:��Ҫ������Ĳ������ǻ��ڴ�
	LQ->front->next = NULL;
}

//�ж϶����Ƿ�Ϊ��
int IsEmptyQueue(LinkQueue* LQ)
{
	if (LQ->front == LQ->rear)//��ͷָ�����βָ����ȣ�����Ϊ��
	{
		return 1;//����Ϊ��
	}
	return 0;
}

//��Ԫ�����
void EnterLinkQueue(LinkQueue *LQ, DataType data)
{
	LinkQueueNode* pNewNode = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
	if (pNewNode == NULL)
	{
		printf("EnterLinkQueue fail:malloc error\n");
		return;
	}
	//��ʽ���еĽ���Ƕ�̬���ٵģ�û���ж϶����Ƿ�Ϊ���Ĳ���
	//�������
	pNewNode->data = data;//������Ԫ�ظ�ֵ������������
	pNewNode->next = NULL;//������ָ�����ÿ�
	//ʵ�ֲ���
	LQ->rear->next = pNewNode;//�½��ӵ���һ�����β��
	LQ->rear = pNewNode;//��βָ������ָ�����ζ�β
}
//acde#bf######
//Ԫ�س���
void DeleteLinkQueue(LinkQueue *LQ,DataType *data)
{
	
	if (IsEmptyQueue(LQ))
	{
		printf("����Ϊ�գ�����ʧ��\n");
		return;
	}
	
	//pDelָ���ͷԪ�أ����ڶ�ͷָ��frontָ��ͷ��㣬����pDelָ��ͷ������һ�����
	LinkQueueNode* pDel = LQ->front->next;
	data->data =  ( & (pDel->data))->data;//��Ҫ���ӵ�Ԫ�ظ���data
	data->left = (&(pDel->data))->left;
	data->right = (&(pDel->data))->right;
	LQ->front->next = pDel->next;//ʹָ��ͷ����ָ��ָ��pDel����һ�����
	if (LQ->rear == pDel)//���������ֻ��һ��Ԫ��,����βָ��ָ��ͷ��㣬����Ϊ��
	{
		LQ->rear = LQ->front;
	}
	free(pDel);//�ͷ�pDelָ��Ŀռ�
}


//��ȡ��ͷԪ��
DataType GetHeadData(LinkQueue* LQ, DataType* data)
{
	if (IsEmptyQueue(LQ))
	{
		printf("����Ϊ��\n");
		return *data;
	}
	LinkQueueNode* pCur = LQ->front->next;//pCurָ����еĵ�һ��Ԫ�أ���ͷ������һ�����
	*data = pCur->data;
	return *data;
}

//��ȡ���г���
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

//��ӡ����Ԫ��
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

//��ն���
void ClearLinkQueue(LinkQueue* LQ)
{
	while (LQ->front != NULL)
	{
		LQ->rear = LQ->front->next;//��ɾ������ʱ����βָ���û�ô��ˣ��˴����ö�βָ���������ͷָ�����һ�����
		free(LQ->front);//ȫ���ͷţ�����ͷ���
		LQ->front = LQ->rear;
	}
}
