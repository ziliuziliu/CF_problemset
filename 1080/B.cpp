#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll q,l,r;
ll work(ll x)
{
	ll ans=x/2;
	if (x&1) ans-=x;
	return ans;
}
int main()
{
	scanf("%I64d",&q);
	for (int i=1;i<=q;i++)
	{
		scanf("%I64d%I64d",&l,&r);
		printf("%I64d\n",work(r)-work(l-1));
	}
	return 0;
}
//bond every two element
