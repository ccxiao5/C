// binaryConversion.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"iostream"
using namespace std;
#define MAXSIZE 100
typedef struct sqStack
{
	int *base;
	int *top;
	int stacksize;
};//顺序栈

void init(sqStack &S)
{
	S.base=new int[MAXSIZE];
	S.top=S.base;
	S.stacksize=MAXSIZE;
}
void push(sqStack &S,int e)
{
	if(S.top-S.base==S.stacksize)
		exit(0);
	*S.top++=e;
}
bool empty(sqStack S)
{
	if(S.top==S.base)
		return true;
	else
		return false;
}
void pop(sqStack &S)
{
	if(S.top<=S.base)
		exit(0);
	S.top--;
}
int top(sqStack S)
{
	if(S.top<=S.base)
		exit(0);
	return *(S.top-1);
}
void show(sqStack S)
{
	int *p=S.top-1;
	while(p>=S.base)
		cout<<*p--;
	cout<<endl;
}
void binaryConversion(sqStack q,int num,int dec)
{
	int divNum,modNum;
	divNum=num;
	do
	{	
		modNum=divNum%dec;
		divNum/=dec;
		push(q,modNum);
	}while(divNum);
	show(q);
}
int _tmain(int argc, _TCHAR* argv[])
{
	int num,dec;//num表示10进制数,dec要转换成的进制
	sqStack q;
	init(q);	
	cin>>num>>dec;
	binaryConversion(q,num,dec);
	system("pause");
	return 0;
}

