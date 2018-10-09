#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxv 100050
#define maxe 200050
#define inf 1000000007
typedef long long ll;
int n,l,w[maxv],fath[maxv],g[maxv],nume=1,ans=0;
int dis[maxv],anc[maxv][20],pos[maxv],tab[20],posp[maxv];
ll sum[maxv][20],s;
struct edge
{
	int v,nxt;
}e[maxe];
void addedge(int u,int v) {e[++nume].v=v;e[nume].nxt=g[u];g[u]=nume;}
void dfs1(int x)
{
	for (int i=g[x];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if (v==fath[x]) continue;
		dis[v]=dis[x]+1;anc[v][0]=x;sum[v][0]=(ll)w[x];
		dfs1(v);
	}
}
void get_table()
{
	tab[0]=1;
	for (int e=1;e<=19;e++)
	{
		tab[e]=tab[e-1]<<1;
		for (int i=1;i<=n;i++)
		{
			anc[i][e]=anc[anc[i][e-1]][e-1];
			sum[i][e]=sum[i][e-1]+sum[anc[i][e-1]][e-1];
		}
	}
}
bool get_pos(int x)
{
	ll r1=w[x];int r2=1,ret=x;
	if (r1>s || r2>l) return false;
	for (int e=19;e>=0;e--)
	{
		if (!anc[ret][e]) continue;
		if (r1+sum[ret][e]<=s && r2+tab[e]<=l)
		{
			r1+=sum[ret][e];r2+=tab[e];
			ret=anc[ret][e];
		}
	}
	pos[x]=ret;return true;
}
void dfs2(int x)
{
	int p=0;
	for (int i=g[x];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if (v==fath[x]) continue;
		dfs2(v);if (posp[v]==v) continue;
		if (dis[posp[v]]<dis[p]) p=posp[v];
	}
	if (!p) {ans++;p=pos[x];}
	posp[x]=p;
}
int main()
{
	scanf("%d%d%I64d",&n,&l,&s);dis[0]=inf;
	for (int i=1;i<=n;i++) scanf("%d",&w[i]);
	for (int i=2;i<=n;i++) {scanf("%d",&fath[i]);addedge(i,fath[i]);addedge(fath[i],i);}
	dfs1(1);get_table();
	for (int i=1;i<=n;i++)
	{
		if (!get_pos(i))
		{
			printf("-1\n");
			return 0;
		}
	}
	dfs2(1);
	printf("%d\n",ans);
	return 0;
}
//update the answer greedily:for every point x,find how high the answer of the subtree can go
//if none of them can go higher than x,then ans++
