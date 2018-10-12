#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define maxv 1050
#define maxe 2000050
#define inf 1000000007
using namespace std;
int n,mp[15][15],g[maxv],nume=1,cnt=0,id[15][15][3];
int dx[]={0,-2,-1,1,2,2,1,-1,-2},dy[]={0,-1,-2,-2,-1,1,2,2,1};
struct edge
{
	int v,nxt,f;
}e[maxe];
struct pnt
{
	int d1,d2;
	pnt (int d1,int d2):d1(d1),d2(d2) {}
	pnt () {}
	friend pnt operator + (const pnt &x,const pnt &y)
	{
		return pnt(x.d1+y.d1,x.d2+y.d2);
	}
}dis[maxv],f[maxv][3][3],dp[maxv][3];
queue <int> q;
bool vis[maxv];
bool check(int x,int y) {return ((1<=x)&(x<=n)&(1<=y)&(y<=n));}
bool cmp(int u,int v,int f)
{
	if (dis[u].d1+1<dis[v].d1) return true;
	if (dis[u].d1+1==dis[v].d1 && dis[u].d2+f<dis[v].d2) return true;
	return false;
}
bool cmp2(pnt x,pnt y)
{
	if (x.d1<y.d1) return true;
	if (x.d1==y.d1 && x.d2<y.d2) return true;
	return false;
}
void update(int x,int y,int f) {dis[y].d1=dis[x].d1+1;dis[y].d2=dis[x].d2+f;}
void addedge(int u,int v,int f) {e[++nume].v=v;e[nume].nxt=g[u];e[nume].f=f;g[u]=nume;}
void build()
{
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			for (int k=0;k<=2;k++)
				id[i][j][k]=++cnt;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
		{
			for (int k=0;k<=2;k++)
			{
				addedge(id[i][j][k],id[i][j][(k+1)%3],1);
				addedge(id[i][j][k],id[i][j][(k+2)%3],1);
			}
			for (int k=1;k<=8;k++)
			{
				int px=i+dx[k],py=j+dy[k];
				if (check(px,py)) addedge(id[i][j][0],id[px][py][0],0);
			}
			int px=i-1,py=j-1;
			while (check(px,py)) {addedge(id[i][j][1],id[px][py][1],0);px--;py--;}
			px=i+1;py=j+1;
			while (check(px,py)) {addedge(id[i][j][1],id[px][py][1],0);px++;py++;}
			px=i-1;py=j+1;
			while (check(px,py)) {addedge(id[i][j][1],id[px][py][1],0);px--;py++;}
			px=i+1;py=j-1;
			while (check(px,py)) {addedge(id[i][j][1],id[px][py][1],0);px++;py--;}
			for (int k=1;k<=n;k++)
				if (k!=i) addedge(id[i][j][2],id[k][j][2],0);
			for (int k=1;k<=n;k++)
				if (k!=j) addedge(id[i][j][2],id[i][k][2],0);
		}
}
void spfa(int i,int k,int x,int y)
{
	for (int i=1;i<=cnt;i++) {vis[i]=false;dis[i].d1=dis[i].d2=inf;}
	q.push(id[x][y][k]);dis[id[x][y][k]].d1=dis[id[x][y][k]].d2=0;vis[id[x][y][k]]=true;
	while (!q.empty())
	{
		int x=q.front();q.pop();
		for (int i=g[x];i;i=e[i].nxt)
		{
			int v=e[i].v;
			if (cmp(x,v,e[i].f))
			{
				update(x,v,e[i].f);
				if (!vis[v]) {vis[v]=true;q.push(v);}
			}
		}
		vis[x]=false;
	}
	for (int a=1;a<=n;a++)
		for (int b=1;b<=n;b++)
		{
			if (mp[a][b]==i+1)
			{
				for (int c=0;c<=2;c++)
					f[i][k][c]=dis[id[a][b][c]];
				break;
			}
		}
}	
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			scanf("%d",&mp[i][j]);
	build();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
		{
			if (mp[i][j]==n*n) continue;
			for (int k=0;k<=2;k++) spfa(mp[i][j],k,i,j);
		}
	for (int i=0;i<=2;i++) dp[1][i].d1=dp[1][i].d2=0;
	for (int i=2;i<=n*n;i++)
		for (int j=0;j<=2;j++)
			dp[i][j].d1=dp[i][j].d2=inf;
	for (int i=2;i<=n*n;i++)
		for (int j=0;j<=2;j++)
			for (int k=0;k<=2;k++)
			{
				if (cmp2(dp[i-1][j]+f[i-1][j][k],dp[i][k]))
					dp[i][k]=dp[i-1][j]+f[i-1][j][k];
			}
	pnt ans;ans.d1=ans.d2=inf;
	for (int i=0;i<=2;i++)
		if (cmp2(dp[n*n][i],ans)) ans=dp[n*n][i];
	printf("%d %d\n",ans.d1,ans.d2);
	return 0;
}
//by using spfa,pre_set f[i][0-2][0-2](from i to i+1,from which kind to which kind,how many moves)
//get dp[i][0-2],which means go to point i with status 0-2 in minimum move
//they share the same update strategy
