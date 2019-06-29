#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 200050
using namespace std;
int q,n,a[maxn],st[maxn],top=0,l=0,r=0,sum=0,pre=0;
void work()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	l=1;top=0;sum=0;pre=0;
	while (l<=n)
	{
		r=l;
		while (r<n && a[r+1]==a[l]) r++;
		st[++top]=r-l+1;pre=max(pre,r-l+1);
		l=r+1;
	}
	sort(st+1,st+top+1);sum+=pre;
	for (int i=top-1;i>=1;i--)
	{
		pre=min(pre-1,st[i]);
		if (pre<=0) break;
		sum+=pre;
	}
	printf("%d\n",sum);
}
int main()
{
	scanf("%d",&q);
	for (int i=1;i<=q;i++) work();
	return 0;
}
