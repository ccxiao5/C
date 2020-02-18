// Tree.cpp : 定义控制台应用程序的入口点。
//
//-+a##*b##-c##d##/e##f##
//ABC##DE#GF##
#include "stdafx.h"
#include"iostream"
using namespace std;

typedef struct BiTNode{
	char data;
	BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

void creatTree(BiTree &T)
{
	char ch;
	cin>>ch;
	if(ch=='#')
		T=NULL;
	else
	{
		T=new BiTNode;
		T->data=ch;
		creatTree(T->lchild);
		creatTree(T->rchild);
	}
}
void preOrderTraversal(BiTree T)
{
	if(T)
	{
		cout<<T->data;
		preOrderTraversal(T->lchild);
		preOrderTraversal(T->rchild);
	}
}
void inOrderTraversal(BiTree T)
{
	if(T)
	{
		inOrderTraversal(T->lchild);
		cout<<T->data;
		inOrderTraversal(T->rchild);
	}
}
void postOrderTraversal(BiTree T)
{
	if(T)
	{
		postOrderTraversal(T->lchild);
		postOrderTraversal(T->rchild);
		cout<<T->data;
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	BiTNode *T;
	creatTree(T);
	preOrderTraversal(T);
	cout<<endl;
	inOrderTraversal(T);
	cout<<endl;
	postOrderTraversal(T);
	cout<<endl;
	system("pause");
	return 0;
}

