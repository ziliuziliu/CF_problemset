#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define inf 1e15 
#define maxv 600050
#define maxe 1200050
typedef long long ll;
using namespace std;
int n,m,k,x,y,w,g[maxv],nume=1,ans=0;
ll dis[maxv];
struct edge
{
	int v,id,nxt;
	ll w;
}e[maxe];
bool vis[maxv],flag[maxv];
queue <int> q;
void addedge(int u,int v,ll w,int id)
{
	e[++nume].v=v;e[nume].w=w;e[nume].id=id;
	e[nume].nxt=g[u];g[u]=nume;
}
void spfa()
{
	for (int i=1;i<=n;i++) {vis[i]=false;dis[i]=inf;}
	dis[1]=0;vis[1]=true;q.push(1);
	while (!q.empty())
	{
		int x=q.front();q.pop();
		for (int i=g[x];i;i=e[i].nxt)
		{
			int v=e[i].v;
			if (dis[v]>dis[x]+e[i].w)
			{
				dis[v]=dis[x]+e[i].w;
				if (!vis[v]) {vis[v]=true;q.push(v);}
			}
		}
		vis[x]=false;
	}
	return;
}
void bfs()
{
	memset(vis,false,sizeof(vis));
	while (!q.empty()) q.pop();
	q.push(1);vis[1]=true;
	while (!q.empty())
	{
		int x=q.front();q.pop();
		for (int i=g[x];i;i=e[i].nxt)
		{
			int v=e[i].v;
			if (dis[v]!=dis[x]+e[i].w || vis[v]) continue;
			if (ans==k) break;
			vis[v]=true;ans++;flag[e[i].id]=true;q.push(v);
		}
	}
	return;
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%I64d",&x,&y,&w);
		addedge(x,y,w,i);addedge(y,x,w,i);
	}
	spfa();
	bfs();
	printf("%d\n",ans);
	for (int i=1;i<=m;i++) if (flag[i]) printf("%d ",i);
	printf("\n");
	return 0;
}
//something's wrong,it works well on my PC,but prints 0 in cf...I don't know why
//perhaps a mixed int and longlong?
//solution is simple,do spfa and find a tree of nodes with k+1 verticles
