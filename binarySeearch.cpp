// binarySeearch.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"iostream"
using namespace std;
//二分查找的数组必须排好序
/*
bool binarySearch(int a[],int t,int low,int high)//递归
{
	int mid=(low+high)/2;
	if(low<=high)
	{
		if(a[mid]==t)
			return true;
		else if(t<a[mid])
		{
			high=mid-1;
			binarySearch(a,t,low,high);
		}
		else if(t>a[mid])
		{
			low=mid+1;
			binarySearch(a,t,low,high);
		}
	}
	else
		return false;
}
*/
bool binarySearch(int a[],int t,int low,int high)
{
	int i=low,j=high,mid=(i+j)/2;
	while(i<=j)
	{
		mid=(i+j)/2;
		if(a[mid]==t)
			return true;
		else if(t>a[mid])
			i=mid+1;
		else
			j=mid-1;
	}
	return false;
}
int _tmain(int argc, _TCHAR* argv[])
{
	int a[10]={1,7,9,10,12,18,90,100,101,210};
	int t;
	while(scanf("%d",&t)!=EOF)
	{
		if(binarySearch(a,t,0,9))
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	system("pause");
	return 0;
}

