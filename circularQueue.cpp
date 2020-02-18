// circularQueue.cpp : 定义控制台应用程序的入口点。
//循环队列---有两个下标的数组

#include "stdafx.h"
#include"iostream"
using namespace std;
#define MAXSIZE 100//***********我们认为有99个数据时队列已满~！！！！！！*****************
typedef struct{
	int *base;
	int front;
	int rear;
}sqQueue;
 void init(sqQueue &q)
 {
	 q.base=new int[MAXSIZE];
	 q.front=q.rear=0;
 }
 void push(sqQueue &q,int e)
 {
	 if((q.rear+1)%MAXSIZE==q.front)
		 exit(0);
	 q.base[q.rear]=e;
	 q.rear=(q.rear+1)%MAXSIZE;
 }
 bool empty(sqQueue q)
 {
	 return q.front==q.rear?true:false;
 }
 int front(sqQueue q)
 {
	 if(q.front!=q.rear)
		return q.base[q.front];
 }
 int back(sqQueue q)
 {
	 if(q.front!=q.rear)
		return q.base[q.rear-1];
 }
 void pop(sqQueue &q)
 {
	  if(q.front!=q.rear)
		  q.front=(q.front+1)%MAXSIZE;
 }
 int getLength(sqQueue q)
 {
	 return (q.rear-q.front+MAXSIZE)%MAXSIZE;
 }
 void show(sqQueue q)
 {
	 for(int i=q.front;i!=q.rear;i=(i+1)%MAXSIZE)
		 cout<<q.base[i]<<" ";
	 cout<<endl;
 }
int _tmain(int argc, _TCHAR* argv[])
{
	sqQueue q;
	init(q);
	push(q,1);
	push(q,4);
	push(q,9);
	push(q,7);
	push(q,8);
	show(q);
	cout<<getLength(q)<<endl;
	pop(q);
	pop(q);
	show(q);
	cout<<getLength(q)<<endl;
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

