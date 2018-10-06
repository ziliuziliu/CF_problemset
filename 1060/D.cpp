#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 200050
using namespace std;
typedef long long ll;
int n,l[maxn],r[maxn];
ll ans=0;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d%d",&l[i],&r[i]);
	sort(l+1,l+n+1);sort(r+1,r+n+1);
	for (int i=1;i<=n;i++) ans+=(ll)max(l[i],r[i]);
	ans+=(ll)n;
	printf("%I64d\n",ans);
	return 0;
}
//it doesn't occur a problem if we add every max(l[i],r[i])
//also there's no problem if we put l[] and r[] in arbitrary order
//to get the minimum answer,the best way is to sort l[] and r[]
