#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxn 2050
#define inf 1000000007
using namespace std;
int n,m,r,c,X,Y,mp[maxn][maxn],dis[maxn][maxn],ans=0;
bool vis[maxn][maxn];
int dx[]={0,0,-1,0,1},dy[]={0,-1,0,1,0};
char s[maxn];
struct pnt
{
	int x,y;
	pnt (int x,int y):x(x),y(y) {}
	pnt () {}
};
queue <pnt> q;
bool check(int x,int y)
{
	if (y<=c) return ((dis[x][y]<=X) && (dis[x][y]-(c-y)<=Y));
	else return ((dis[x][y]<=X) && (dis[x][y]+(y-c)<=Y));
}
bool check2(int x,int y) {return ((x>=1) && (x<=n) && (y>=1) && (y<=m));}
void spfa()
{
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			dis[i][j]=inf,vis[i][j]=false;
	dis[r][c]=0;vis[r][c]=true;q.push(pnt(r,c));
	while (!q.empty())
	{
		pnt head=q.front();q.pop();
		int x=head.x,y=head.y;
		for (int i=1;i<=4;i++)
		{
			int tx=x+dx[i],ty=y+dy[i];
			if ((!mp[tx][ty]) && (dis[tx][ty]>dis[x][y]+(i==1)) && (check2(tx,ty)))
			{
				dis[tx][ty]=dis[x][y]+(i==1);
				if (check(tx,ty) && (!vis[tx][ty])) q.push(pnt(tx,ty));
			}
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	scanf("%d%d",&r,&c);
	scanf("%d%d",&X,&Y);
	for (int i=1;i<=n;i++)
	{
		scanf("%s",s);
		for (int j=1;j<=m;j++) mp[i][j]=(s[j-1]=='*');
	}
	spfa();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			ans+=check(i,j);
	printf("%d\n",ans);
	return 0;
}
//we find that for every point,if you know the left steps,you can calculate the right steps
//we just have to minimize the left steps
