// BFS.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"stdio.h"
#include"queue"
#include"string.h"
using namespace std;
struct point{
	int x;
	int y;
	int step;
};
queue<point> q;
int _tmain(int argc, _TCHAR* argv[])
{
	int visited[25][25],map[25][25];
	int setoff[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
	int n,i,j;
	while(scanf("%d",&n)!=EOF){
		memset(visited,0,sizeof(visited));
		for(i = 0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%d",&map[i][j]);
		while(!q.empty())
		{
			q.pop();
		}
		point x;
		x.x=0;
		x.y=0;
		x.step=0;
		q.push(x);
		visited[x.x][x.y]=1;
		while(!q.empty())
		{
			point t=q.front();
			if(t.x==n-1&&t.y==n-1)
			{
				printf("%d\n",t.step+1);
				break;
			}
			else
			{
				for(i=0;i<4;i++)
					if(t.x+setoff[i][0]<n&&t.y+setoff[i][1]<n&&t.y+setoff[i][1]>=0&&t.x+setoff[i][0]>=0&&map[t.x+setoff[i][0]][t.y+setoff[i][1]]!=1)
					{
						point temp;
						temp.x=t.x+setoff[i][0];
						temp.y=t.y+setoff[i][1];
						temp.step=t.step+1;
						q.push(temp);
						visited[temp.x][temp.y]=1;
					}
			}
			q.pop();
		}
		if(q.empty())
			printf("NO\n");

	}
	return 0;
}

