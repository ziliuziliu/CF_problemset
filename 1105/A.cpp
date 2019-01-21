#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1050
#define inf 2000000000
using namespace std;
int n,a[maxn],tot=inf,ans=-1;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int t=1;t<=100;t++)
	{
		int ret=0;
		for (int i=1;i<=n;i++)
		{
			if (a[i]>=t+1) ret+=a[i]-t-1;
			else if (a[i]<=t-1) ret+=t-1-a[i];
		}
		if (ret<tot) {tot=ret;ans=t;}
	}
	printf("%d %d\n",ans,tot);
	return 0;
}
//nothing to say..
