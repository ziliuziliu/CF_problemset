#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxv 200050
#define maxe 400050
typedef long long ll;
using namespace std;
int n,x,y,g[maxv],dis[maxv],fath[maxv],size[maxv],nxt,nume=1;
ll sum=0,mx=0;
struct edge
{
	int v,nxt;
}e[maxe];
void addedge(int u,int v)
{
	e[++nume].v=v;e[nume].nxt=g[u];
	g[u]=nume;
}
void dfs1(int x)
{
	sum+=dis[x];size[x]=1;
	for (int i=g[x];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if (v==fath[x]) continue;
		dis[v]=dis[x]+1;fath[v]=x;
		dfs1(v);
		size[x]+=size[v];
	}
}
void dfs2(int x)
{
	mx=max(mx,sum);
	for (int i=g[x];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if (v==fath[x]) continue;
		sum+=n-2*size[v];
		dfs2(v);
		sum-=n-2*size[v];
	}
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		addedge(x,y);addedge(y,x);
	}
	dis[1]=1;dfs1(1);
	dfs2(1);
	printf("%I64d\n",mx);
	return 0;
}
