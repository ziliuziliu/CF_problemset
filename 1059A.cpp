#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100050
using namespace std;
int n,L,a,t[maxn],l[maxn],ans=0;
int main()
{
	scanf("%d%d%d",&n,&L,&a);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&t[i],&l[i]);
		ans+=(t[i]-t[i-1]-l[i-1])/a;
	}
	ans+=(L-t[n]-l[n])/a;
	printf("%d\n",ans);
	return 0;
}
