#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
typedef long long ll;
using namespace std;
ll q,n,k,a,b;
void work()
{
	scanf("%I64d%I64d%I64d%I64d",&k,&n,&a,&b);
	if (k<=n*b) {printf("-1\n");return;}
	ll ans=(k-n*b)/(a-b);
	if (((k-n*b)%(a-b)==0) && (ans<=n)) ans--;
	ans=min(ans,n);
	printf("%d\n",ans);
}
int main()
{
	scanf("%I64d",&q);
	for (int i=1;i<=q;i++) work();
	return 0;
}
//(k-n*b)/(a-b)?n
