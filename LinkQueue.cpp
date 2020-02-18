// LinkQueue.cpp : 定义控制台应用程序的入口点。
//链队---链队和链表的区别就是有头尾指针来标记！！！！头结点是一个结构体。

#include "stdafx.h"
#include"iostream"
using namespace std;

typedef struct QNode
{
	int e;
	QNode *next;
}QNode,*QueuePtr;

typedef struct
{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

void init(LinkQueue &q)
{
	q.front=q.rear=new QNode;
	q.front->next=NULL;
}
void push(LinkQueue &q,int e)
{
	QNode *t=new QNode;
	t->e=e;
	t->next=NULL;
	q.rear->next=t;
	q.rear=t;
}
int front(LinkQueue q)
{
	if(q.front!=q.rear)
		return q.front->next->e;
}
int back(LinkQueue q)
{
	if(q.rear!=q.front)
		return q.rear->e;
}
void pop(LinkQueue &q)
{
	QueuePtr p=q.front->next;
	if(q.front!=q.rear)
		{ 
			q.front->next=p->next;
			if(q.rear==p)
				q.front=q.rear;
			delete p;	
		}
}
bool empty(LinkQueue q)
{
	return q.front==q.rear?true:false;
}
void show(LinkQueue q)
{
	QueuePtr p=q.front->next;
	while(p)
	{
		cout<<p->e<<" ";
		p=p->next;
	};
	cout<<endl;
}
int _tmain(int argc, _TCHAR* argv[])
{
	LinkQueue q;
	init(q);
	push(q,1);
	push(q,4);
	push(q,5);
	push(q,7);
	push(q,9);
	show(q);
	cout<<front(q)<<" "<<back(q)<<endl;

	pop(q);
	pop(q);
	show(q);
	cout<<front(q)<<" "<<back(q)<<endl;
	if(empty(q))
		cout<<"clear\n";
	else
		cout<<"not yet\n";
	pop(q);
	pop(q);
	pop(q);
	if(empty(q))
		cout<<"clear\n";
	else
		cout<<"not yet\n";
	system("pause");
	return 0;
}

