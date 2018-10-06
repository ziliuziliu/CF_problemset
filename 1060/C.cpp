#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 2050
#define inf 1000000007
typedef long long ll;
using namespace std;
int n,m,a[maxn],b[maxn],x,sa[maxn],sb[maxn],mn[maxn],ans=0;
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) {scanf("%d",&a[i]);sa[i]=sa[i-1]+a[i];}
	for (int i=1;i<=m;i++) {scanf("%d",&b[i]);sb[i]=sb[i-1]+b[i];}
	for (int i=1;i<=m;i++) mn[i]=inf;
	for (int i=1;i<=m;i++)
		for (int j=i;j<=m;j++)
			mn[j-i+1]=min(mn[j-i+1],sb[j]-sb[i-1]);
	scanf("%d",&x);
	for (int i=1;i<=n;i++)
	{
		int p=m;
		for (int j=i;j<=n;j++)
		{
			while (p>=1 && (ll)(sa[j]-sa[i-1])*mn[p]>(ll)x) p--;
			if (!p) break;
			ans=max(ans,(j-i+1)*p);
		}
	}
	printf("%d\n",ans);
	return 0;
}
//firstly,answer can be shown as product of two interval sum
//for every interval of array a,find the maximum interval sum of array b
//get array mn in advance,where mn[x] shows the maximum interval sum,the length of it is x
//it's monotonic while we enumerate
