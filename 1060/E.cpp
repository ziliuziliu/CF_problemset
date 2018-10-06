#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxv 200050
#define maxe 400050
typedef long long ll;
using namespace std;
int n,x,y,g[maxv],nume=1,dis[maxv],size[maxv],fath[maxv],f[maxv][2];
ll ans=0,dp[maxv],ret=0;
struct edge
{
	int v,nxt;
}e[maxe];
void addedge(int u,int v) {e[++nume].v=v;e[nume].nxt=g[u];g[u]=nume;}
void dfs1(int x)
{
	size[x]=1;f[x][0]=1;
	for (int i=g[x];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if (v==fath[x]) continue;
		fath[v]=x;dis[v]=dis[x]+1;
		dfs1(v);
		size[x]+=size[v];
		f[x][0]+=f[v][1];f[x][1]+=f[v][0];
		dp[1]+=(ll)dis[v];
	}
}
void dfs2(int x)
{
	ans+=dp[x];ret+=(ll)f[x][1];
	for (int i=g[x];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if (v==fath[x]) continue;
		f[v][0]=f[x][1];f[v][1]=f[x][0];
		dp[v]=dp[x]+n-2*size[v];
		dfs2(v);
	}
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n-1;i++) {scanf("%d%d",&x,&y);addedge(x,y);addedge(y,x);}
	dfs1(1);dfs2(1);
	printf("%I64d\n",(ans+ret)>>2);
	return 0;
}
//the answer is sigma(ceil(length_of_path/2))
//thus we have to count the number of path,which length is an odd number
