#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 200050
#define inf 1000000007
using namespace std;
int n,m,x[maxn],t[maxn],pos[maxn],cnt=0,ans[maxn],p=0;
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n+m;i++) scanf("%d",&x[i]);
	for (int i=1;i<=n+m;i++) {scanf("%d",&t[i]);if (t[i]) pos[++cnt]=i;}
	pos[m+1]=n+m+1;x[n+m+1]=inf;
	for (int i=1;i<=n+m;i++)
	{
		if (t[i]) continue;
		while (x[pos[p+1]]<=x[i]) p++;
		if (!p) ans[1]++;
		else if (p==m) ans[m]++;
		else if (x[i]-x[pos[p]]<=x[pos[p+1]]-x[i]) ans[p]++;
		else ans[p+1]++;
	}
	for (int i=1;i<=m;i++) printf("%d ",ans[i]);
	return 0;
}
//using a simple pointer
