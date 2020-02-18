// bracketMatching.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"iostream"
#include"string.h"
using namespace std;
#define MAXSIZE 100
typedef struct sqStack
{
	char *base;
	char *top;
	int maxSize;
};
void init(sqStack &S)
{
	S.base=new char[MAXSIZE];
	memset(S.base,0,sizeof(S.base));//初始化字符数组要不然会烫烫烫！！！
	S.top=S.base;
	S.maxSize=MAXSIZE;
}

void push(sqStack &S,char e)
{
	if(S.top-S.base==S.maxSize)
		exit(0);
	*S.top++=e;
}
void pop(sqStack &S)
{
	if(S.top==S.base)
		exit(0);
	S.top--;
}
char top(sqStack S)
{
	if(S.top==S.base)
		exit(0);
	return *(S.top-1);
}
bool empty(sqStack S)
{
	return S.base==S.top?true:false;
}
void show(sqStack S)
{
	char *p=S.base;
	while(p!=S.top)
		cout<<*p++;
	cout<<endl;
}
bool matching( char *c)
{
	sqStack q;
	init(q);
	int i;
	for(i=0;i<strlen(c);i++)
	{
		if(empty(q))
			push(q,c[i]);
		else
		{
			if(top(q)=='['&&c[i]==']')
				pop(q);
			else if(top(q)=='('&&c[i]==')')
				pop(q);
			else if(top(q)=='{'&&c[i]=='}')
				pop(q);
			else
				push(q,c[i]);
		}
//		cout<<c[i]<<"******\n";
	//	show(q);

	}
	return empty(q)?true:false;
}
int _tmain(int argc, _TCHAR* argv[])
{
	char c[100];//待检测的括号
	while(cin>>c)
	{
		if(matching(c))
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}

