// Subsequence.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"stdio.h"
#include"string.h"
#include"iostream"
#include"fstream"
#include"stdlib.h"
#include"list"
using namespace std;
list<int> temp1,temp2;
list<int>::iterator it1,it2;

void pushList(list<int> temp,int &MAX,int len,char a[100])
{
		for(int j=0;j<len;j++)
		{
			temp1.push_back(a[j]-'0');
			if(MAX<(a[j]-'0'))
				MAX=a[j]-'0';
		}
}
int _tmain(int argc, _TCHAR* argv[])
{
	FILE *fp= fopen("data.txt","r+");
	char a[100],b[100];
	int MAX;
	if(fp==NULL)
		exit(0);
	int i,j,len1,len2;
	for(i=0;i<3;i++)
	{
		MAX=INT_MIN;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		temp1.clear();
		temp2.clear();
		fscanf(fp,"%s",a);
		fscanf(fp,"%s",b);
		len1=strlen(a);
		len2=strlen(b);
		if(len2>len1)
		{
			pushList(temp1,MAX,len2,b);
			pushList(temp2,MAX,len1,a);
		}
		else{
			pushList(temp1,MAX,len1,a);
			pushList(temp2,MAX,len2,b);
		}
		printf("第%d组最大值为：%d\n",i+1,MAX);
		it2=temp2.begin();
		it1=temp1.begin();
		int flag=0;
		for(;it2!=temp2.end();it2++)
			for(;it1!=temp1.end();it1++)
				if(*it2==*it1)
				{
					flag++;
					break;
				}
		if(flag==len2)
			printf("一个序列是另一个序列的子序列\n");
		else
			printf("不存在子序列\n");
		cout<<endl;
	
	}
	fclose(fp);
	system("pause");
	return 0;
}

