#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 105
#define inf 2000000000
using namespace std;
int q,n,k,a[maxn];
void work()
{
	int mn=inf,mx=0;
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		mn=min(mn,a[i]);mx=max(mx,a[i]);
	}
	if (mn+k>=mx-k) printf("%d\n",mn+k);
	else printf("-1\n");
}
int main()
{
	scanf("%d",&q);
	for (int i=1;i<=q;i++) work();
	return 0;
}
//[mx-k.mn+k]
