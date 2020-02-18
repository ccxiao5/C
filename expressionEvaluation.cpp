// expressionEvaluation.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"iostream"
#include"iomanip"
#include"string.h"
#include"math.h"
using namespace std;
#define MAXSIZE 100
struct sqStack
{
	double *base;
	double *top;
	int maxSize;
};

struct sqStackChar
{
	char *base;
	char *top;
	int maxSize;
};
void init(sqStack &S)
{
	S.base=new double[MAXSIZE];
	memset(S.base,0,sizeof(S.base));//初始化字符数组要不然会烫烫烫！！！
	S.top=S.base;
	S.maxSize=MAXSIZE;
}
void init(sqStackChar &S)
{
	S.base=new char[MAXSIZE];
	memset(S.base,0,sizeof(S.base));//初始化字符数组要不然会烫烫烫！！！
	S.top=S.base;
	S.maxSize=MAXSIZE;
}

void push(sqStack &S,double e)
{
	if(S.top-S.base==S.maxSize)
		exit(0);
	*S.top++=e;
}
void push(sqStackChar &S,char e)
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
void pop(sqStackChar &S)
{
	if(S.top==S.base)
		exit(0);
	S.top--;
}

double top(sqStack S)
{
	if(S.top==S.base)
		exit(0);
	return *(S.top-1);
}
char top(sqStackChar S)
{
	if(S.top==S.base)
		exit(0);
	return *(S.top-1);
}
bool empty(sqStack S)
{
	return S.base==S.top?true:false;
}
bool empty(sqStackChar S)
{
	return S.base==S.top?true:false;
}
char cmp(char a,char b)
{
	if(a=='('&&b==')')
		return '=';
	else if((a=='('&&b!=')')||b=='(')
		return '<';
	else if(a==')'||b==')')
		return '>';
	else if((a=='*'||a=='/'))
		return '>';
	else if((a=='+'||a=='-')&&(b=='*'||b=='/'))
		return '<';
	else if((a=='+'||a=='-')&&(b=='+'||b=='-'))
		return '>';
}

double operate(double a,char op,double b)
{
	if(op=='+')
		return a+b;
	else if(op=='-')
		return a-b;
	else if(op=='*')
		return a*b;
	else if(op=='/'&&b!=0)
		return a/b;
	else
		cout<<"式子无意义\n";
}

void evaluateExpression(char *c,sqStack num,sqStackChar opr)
{
	double total=0.0;
	int i,len=strlen(c)-1;
	int t,j,k;//记录小数点后数字个数
	int flag;//标记是否为小数
	double a,b;
	char op;
	for(i=0;i<len;i++)
	{
		if(c[i]<='9'&&c[i]>='0')
		{
			flag=0;
			total=total*10+(double)(c[i]-'0');
			for( k=i+1;(c[k]<='9'&&c[k]>='0')||c[k]=='.';k++)
			{
				if(c[k]<='9'&&c[k]>='0')
					total=total*10+(double)(c[k]-'0');
				else if(c[k]=='.')
				{
					flag=1;
					t=1;
					for( j=k+1;c[j]<='9'&&c[j]>='0';j++)
							{ 
								total+=(double)(c[j]-'0')*pow(10.0,-t);
								t++;
							}
					i=j-1;//让i回到最后一位数字
					break;
				}
			}
			if(!flag)//如果是整数
				i=k-1;//让i回到最后一位数字
			push(num,total);
			total=0.0;
		}
		else
		{
			if(empty(opr))
				push(opr,c[i]);
			else
				switch(cmp(top(opr),c[i]))
				{
					case '<':
						push(opr,c[i]);
						break;
					case '>':
						b=top(num);
						pop(num);
						a=top(num);
						pop(num);
						op=top(opr);
						pop(opr);
						push(num,operate(a,op,b));
						i--;
						break;
					case '=':
						pop(opr);
						break;
				}
		}
	}
	while(!empty(opr))
	{
		b=top(num);
		pop(num);
		a=top(num);
		pop(num);
		op=top(opr);
		pop(opr);
		push(num,operate(a,op,b));
	}
	cout<<fixed<<setprecision(2)<<top(num)<<endl;
}
int _tmain(int argc, _TCHAR* argv[])
{
	sqStack num;
	sqStackChar opr;
	init(num);
	init(opr);
	char c[100];
	while(cin>>c)
	{
		if(strcmp(c,"=")==0)
			break;
		evaluateExpression(c,num,opr);
	}
	system("pause");
	return 0;
}

//(1.5+3*2+(4-2)*2)/0.5
//(3+(1.5+0.5*3)/3*2)/5+4