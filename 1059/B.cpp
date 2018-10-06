#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1050
using namespace std;
char s[maxn];
int n,m;
bool mp1[maxn][maxn],mp2[maxn][maxn];
bool check(int x,int y)
{
	for (int i=x;i<=x+2;i++)
		for (int j=y;j<=y+2;j++)
		{
			if (i==x+1 && j==y+1) continue;
			if (!mp1[i][j]) return false;
		}
	return true;
}
void paint(int x,int y)
{
	for (int i=x;i<=x+2;i++)
		for (int j=y;j<=y+2;j++)
		{
			if (i==x+1 && j==y+1) continue;
			mp2[i][j]=1;
		}
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%s",s);
		for (int j=0;j<m;j++)
		{
			if (s[j]=='#') mp1[i][j+1]=1;
			else mp1[i][j+1]=0;
		}
	}
	for (int i=1;i<=n-2;i++)
		for (int j=1;j<=m-2;j++)
			if (check(i,j)) paint(i,j);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			if (mp1[i][j]!=mp2[i][j])
			{
				printf("NO\n");
				return 0;
			}
		}
	printf("YES\n");
	return 0;
}
//paint the map greedily
//find every inked place and paint it if 8 blocks are painted in the original map
//compare the new map with the old one
