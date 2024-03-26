#include<stdio.h>
#include"LinkQueue.h"
extern int sum=0;
//#include<stdlib.h>
void CreatBiTree(BiTree &T)
{
	char key;
	scanf_s("%c", &key);
	if (key == '#') T = NULL;
	else 
	{
		{
			T = (BiNode*)malloc(sizeof(BiNode));
			T->data = key;
			CreatBiTree(T->left);
			CreatBiTree(T->right);
		}
	}
}
//DLR
void PreOrder(BiTree &T)
{
	if (T)
	{
		printf("%c", T->data);
		PreOrder(T->left);		
		PreOrder(T->right);
	}
}

//LDR
void InOrder(BiTree &T)
{
	if (T)
	{
		InOrder(T->left);
		printf("%c", T->data);
		InOrder(T->right);
	}
}

//层次遍历
void LevelOrder(BiNode T)
{
	char string[100];
	int i = 0;
	BiNode* tempNodePtr = (BiNode*)malloc(sizeof(BiNode));
	LinkQueue* L = (LinkQueue*)malloc(sizeof(LinkQueue));
	InitLinkQueue(L);
	EnterLinkQueue(L, T);
	while (!IsEmptyQueue(L))
	{
		DeleteLinkQueue(L,tempNodePtr);
		string[i] = tempNodePtr->data;
		i++;
		if (tempNodePtr->left != NULL)
		{
			EnterLinkQueue(L, *tempNodePtr->left);
		}
		if (tempNodePtr->right != NULL)
		{
			EnterLinkQueue(L, *tempNodePtr->right);
		}
		
	}
	string[i] = '\0';
	printf("层次遍历：%s\n", string);
	
}
void Yezi(BiTree T)
{
	if (T)
	{
		if (!T->left && !T->right) {
			sum++;printf("%c", T->data);
		}
		Yezi(T->left);
		Yezi(T->right);
	}
}
//ABC##DE#G##F###
int main()
{
	BiTree T;
	printf("请按先序输入二叉树，#表述无孩子：\n") ;
	CreatBiTree(T);
	printf("中序遍历：");
	InOrder(T);
	printf("\n");
	printf("叶子节点：");
	Yezi(T);
	printf("\n");
	printf("叶子节点个数：%d\n",sum);
	LevelOrder(*T);
}


