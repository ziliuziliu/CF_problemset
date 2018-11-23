#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define maxv 300050
#define maxe 600050
typedef long long ll;
using namespace std;
int n,xx,yy,m,v,d,x,g[maxv],nume=1,qg[maxv],numq=0,dis[maxv];
int root=1,ls[maxv<<2],rs[maxv<<2],tot=0;
ll sum[maxv<<2],ans[maxv],lazy[maxv<<2];
struct edge
{
	int v,nxt;
}e[maxe];
struct query
{
	int d,nxt,x;
}q[maxv];
void addedge(int u,int v) {e[++nume].v=v;e[nume].nxt=g[u];g[u]=nume;}
void addquery(int v,int d,int x)
{
	q[++numq].d=d;q[numq].x=x;
	q[numq].nxt=qg[v];qg[v]=numq;
}
void build(int &now,int left,int right)
{
	now=++tot;sum[now]=lazy[now]=0;
	if (left==right) return;
	int mid=(left+right)>>1;
	build(ls[now],left,mid);
	build(rs[now],mid+1,right);
}
void pushdown(int now,int left,int right)
{
	int mid=(left+right)>>1;
	lazy[ls[now]]+=lazy[now];lazy[rs[now]]+=lazy[now];
	sum[ls[now]]+=lazy[now]*(mid-left+1);
	sum[rs[now]]+=lazy[now]*(right-mid);
	lazy[now]=0;
}
void modify(int now,int left,int right,int l,int r,int x)
{
	pushdown(now,left,right);
	if (left==l && right==r)
	{
		lazy[now]+=(ll)x;sum[now]+=(ll)(r-l+1)*(ll)x;
		return;
	}
	int mid=(left+right)>>1;
	if (r<=mid) modify(ls[now],left,mid,l,r,x);
	else if (l>=mid+1) modify(rs[now],mid+1,right,l,r,x);
	else {modify(ls[now],left,mid,l,mid,x);modify(rs[now],mid+1,right,mid+1,r,x);}
	sum[now]=sum[ls[now]]+sum[rs[now]];
}
ll ask(int now,int left,int right,int x)
{
	pushdown(now,left,right);
	if (left==right) return sum[now];
	int mid=(left+right)>>1;
	if (x<=mid) return ask(ls[now],left,mid,x);
	else return ask(rs[now],mid+1,right,x);
}
void dfs1(int x,int fath)
{
	for (int i=g[x];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if (v==fath) continue;
		dis[v]=dis[x]+1;dfs1(v,x);
	}
}
void dfs2(int x,int fath)
{
	for (int i=qg[x];i;i=q[i].nxt)
		modify(root,1,n,dis[x],min(dis[x]+q[i].d,n),q[i].x);
	ans[x]=ask(root,1,n,dis[x]);
	for (int i=g[x];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if (v==fath) continue;
		dfs2(v,x);
	}
	for (int i=qg[x];i;i=q[i].nxt) modify(root,1,n,dis[x],min(dis[x]+q[i].d,n),-q[i].x);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n-1;i++) {scanf("%d%d",&xx,&yy);addedge(xx,yy);addedge(yy,xx);}
	scanf("%d",&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&v,&d,&x);
		addquery(v,d,x);
	}
	build(root,1,n);
	dis[1]=1;dfs1(1,0);dfs2(1,0);
	for (int i=1;i<=n;i++) printf("%I64d ",ans[i]);	
	return 0;
}
//locate the query on every point
//do dfs,when get to point x,[dis[x],dis[x]+q[i].d]+val,using a segment tree
//when finish dfs of this subtree,cancel the modification
