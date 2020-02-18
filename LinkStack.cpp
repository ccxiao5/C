// LinkStack.cpp : 定义控制台应用程序的入口点。
//链栈

#include "stdafx.h"
#include"iostream"
using namespace std;
typedef struct stackNode{
	int e;
	stackNode *next;
}stackNode,*LinkStack;

void init(LinkStack &LS)
{
	LS=NULL;
}
void push(LinkStack &LS,int e)
{
	stackNode *t;
	t=new stackNode;
	t->e=e;
	t->next=LS;
	LS=t;
}
void pop(LinkStack &LS)
{
	if(LS==NULL)
		exit(0);
	LinkStack p=LS;
	LS=LS->next;
	delete p;
}

int  top(LinkStack LS)
{
	if(LS)
		return LS->e;
	else
		exit(0);
}
void show(LinkStack LS)
{
	LinkStack p=LS;
	while(p)
		{ 
			cout<<p->e<<" ";
			p=p->next;	
		}
	cout<<endl;
}
int _tmain(int argc, _TCHAR* argv[])
{
	stackNode *s;
	init(s);
	push(s,3);
	push(s,7);
	push(s,9);
	push(s,4);
	push(s,1);
	show(s);
	
	pop(s);
	pop(s);
	show(s);

	cout<<top(s)<<"\n";
	system("pause");
	return 0;
}

