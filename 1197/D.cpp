#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 300050
#define maxm 13
typedef long long ll;
using namespace std;
ll n,m,k,a[maxn],sum[maxn][maxm],q[maxm],ans=0,tag=0;
int main()
{
	memset(a,0,sizeof(a));
	scanf("%I64d%I64d%I64d",&n,&m,&k);
	for (int i=1;i<=n;i++)
	{
		scanf("%I64d",&a[i]);
		sum[i][1]=a[i];
	}
	for (int i=2;i<=m;i++)
		for (int j=1;j<=n;j++)
			sum[j][i]=sum[j][i-1]+a[j+i-1];
	for (int i=1;i<=m;i++)
		for (int j=1;j<=n;j++)
			sum[j][i]-=k;
	for (int i=n;i>=1;i--)
	{
		q[tag]=max(q[tag]+sum[i][m],sum[i][m]);
		for (int j=1;j<m;j++)
		{
			ans=max(ans,sum[i][j]);
			ans=max(ans,sum[i][j]+q[(tag-j+2*m)%m]);
		}
		ans=max(ans,q[tag]);
		tag=(tag+1)%m;
	}
	printf("%I64d\n",ans);
	return 0;
}
