#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 200050
using namespace std;
int n,a[maxn],sum1[maxn],sum2[maxn],ans=0;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sum1[1]=a[1];
	for (int i=2;i<=n;i++) sum1[i]=sum1[i-2]+a[i];
	for (int i=n;i>=1;i--) sum2[i]=sum2[i+2]+a[i];
	for (int i=1;i<=n;i++)
	{
		int s1=0,s2=0;
		if (i==1) {s1=sum2[3];s2=sum2[2];}
		else if (i&1) {s1=sum1[i-2]+sum2[i+1];s2=sum1[i-1]+sum2[i+2];}
		else {s1=sum1[i-1]+sum2[i+2];s2=sum1[i-2]+sum2[i+1];}
		if (s1==s2) ans++;
	}
	printf("%d\n",ans);
	return 0;
}
//nothing to say.
