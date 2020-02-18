// quickSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"iostream"
#include"string.h"
#include"algorithm"
using namespace std;
void show(int a[])
{
	for(int k=0;k<9;k++)
		cout<<a[k]<<" ";
	cout<<endl;
}
void quickSort(int a[],int left,int right)
{
	int i=left;
	int j=right;
	int key=a[i];
	if(i>=j)
		return;
	while(i<j)
	{
		while(i<j&&a[j]>key)
			j--;
		a[i]=a[j];
	//	show(a);
		while(i<j&&a[i]<key)
			i++;
		a[j]=a[i];
//		show(a);
	}
	a[i]=key;
	//show(a);
	quickSort(a,left,i-1);
	quickSort(a,i+1,right);
}
bool cmp(int a,int b)
{
	return a>b;
}
int _tmain(int argc, _TCHAR* argv[])
{
	int a[] = {57, 68, 59, 52, 72, 28, 96, 33, 24};
	sort(a,a+9,cmp);
//	quickSort(a,0,8);
	for(int i=0;i<9;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	system("pause");
	return 0;
}

