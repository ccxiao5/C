// mergeLinkList.cpp : 定义控制台应用程序的入口点。
// 有序链表合并

#include "stdafx.h"
#include"iostream"
using namespace std;

typedef struct LNode
{
	int num;
	LNode *next;
}LNode,*LinkList;

void init(LinkList &L)
{
	L=new LNode;
	L->next=NULL;
}
void push(LinkList &L,int e)
{
	LinkList p=L;
	while(p->next)
		p=p->next;
	LNode *t;
	t=new LNode;
	t->num=e;
	p->next=t;
	t->next=NULL;
}
void show(LinkList L)
{
	LinkList p=L->next;
	while(p)
	{
		cout<<p->num<<" ";
		p=p->next;
	}
	cout<<endl;
}

void mergeToNewLinkList(LinkList &A,LinkList &B)//将两条链表AB连接到新的链表C
{
	LNode *C,*pA=A->next,*pB=B->next;
	LinkList pC;
	init(C);
	pC=C;
	while(pA&&pB)
	{
		if(pA->num<pB->num)
		{
			pC->next=pA;
			pC=pA;
			pA=pA->next;
		}
		else
		{
			pC->next=pB;
			pC=pB;
			pB=pB->next;
		}
	}
	if(pA)
		pC->next=pA;
	else 
		pC->next=pB;
	show(C);
}
void mergeToTheFirstLinkList(LinkList &A,LinkList &B)//将B链表连接到A
{
	LinkList pA,pB;
	LinkList t=A;//标记新A链的位置
	pA=A->next;
	pB=B->next;
	while(pB&&pA)
	{
		if(pA->num>pB->num)
		{
			t->next=pB;
			t=pB;
			pB=pB->next;
		}
		else
		{
			t->next=pA;
			t=pA;
			pA=pA->next;
		}
	}
	if(pA)
		t->next=pA;
	else
		t->next=pB;
	show(A);

}
int _tmain(int argc, _TCHAR* argv[])
{
	LNode *t1,*t2;
	init(t1);
	init(t2);
	push(t1,3);
	push(t1,7);
	push(t1,10);
	push(t1,20);
	push(t1,30);
	push(t1,34);

	push(t2,1);
	push(t2,7);
	push(t2,9);
	push(t2,25);
	push(t2,29);
	//push(t2,37);

	//mergeToNewLinkList(t1,t2);
	mergeToTheFirstLinkList(t1,t2);

	system("pause");
	return 0;
}

