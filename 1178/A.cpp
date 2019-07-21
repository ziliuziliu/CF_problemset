#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 105
using namespace std;
int n,a[maxn],cnt=0,id[maxn],sum=0,csum=0;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	cnt=1;id[1]=1;csum=a[1];
	for (int i=2;i<=n;i++)
	{
		if (a[1]>=2*a[i]) 
		{
			csum+=a[i];
			id[++cnt]=i;
		}
	}
	if (csum<=sum/2) printf("0\n");
	else
	{
		printf("%d\n",cnt);
		for (int i=1;i<=cnt;i++) printf("%d ",id[i]);
	}
	return 0;
}
