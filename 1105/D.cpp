#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define maxn 1050
#define maxp 15
using namespace std;
int n,m,pl,s[maxp],mp[maxn][maxn],cnt[maxp];
char ch[maxn];
int dx[]={0,0,1,0,-1},dy[]={0,1,0,-1,0};
struct pnt
{
	int x,y,dis;
	pnt (int x,int y,int dis):x(x),y(y),dis(dis) {}
	pnt () {}
};
queue <pnt> q[maxp],q2;
bool check(int x,int y)
{
	return (x>=1 && x<=n && y>=1 && y<=m && mp[x][y]==0);
}
void bfs(int x)
{
	while (!q[x].empty())
	{
		pnt head=q[x].front();
		q[x].pop();
		head.dis=s[x];
		q2.push(head);
	}
	while (!q2.empty())
	{
		q[x].push(q2.front());
		q2.pop();
	}
	while (!q[x].empty() && q[x].front().dis!=0)
	{
		pnt head=q[x].front();
		q[x].pop();
		for (int i=1;i<=4;i++)
		{
			int tx=head.x+dx[i],ty=head.y+dy[i];
			if (check(tx,ty))
			{
				mp[tx][ty]=x;
				q[x].push(pnt(tx,ty,head.dis-1));
			}
		}
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&pl);
	for (int i=1;i<=pl;i++) scanf("%d",&s[i]);
	for (int i=1;i<=n;i++)
	{
		scanf("%s",ch);
		for (int j=0;j<m;j++)
		{
			if (ch[j]=='#') mp[i][j+1]=-1;
			else if (ch[j]=='.') mp[i][j+1]=0;
			else
			{
				mp[i][j+1]=ch[j]-'0';
				q[ch[j]-'0'].push(pnt(i,j+1,s[ch[j]-'0']));
			}
		}
	}
	while (1)
	{
		for (int i=1;i<=pl;i++) bfs(i);
		bool flag=true;
		for (int i=1;i<=pl;i++) flag&=(q[i].empty());
		if (flag) break;
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (mp[i][j]>=1) cnt[mp[i][j]]++;
	for (int i=1;i<=pl;i++) printf("%d ",cnt[i]);
	return 0;
}
//brute force:use 10 queues and it's done
