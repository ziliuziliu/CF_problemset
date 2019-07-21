#include<iostream>
#include<cstdio>
#include<cstring>
#define mod 998244353
typedef long long ll;
ll w,h;
ll pow(ll a,ll b)
{
	ll ans=1,base=a;
	while (b)
	{
		if (b&1) ans=(ans*base)%mod;
		base=(base*base)%mod;
		b>>=1;
	}
	return ans;
}
int main()
{
	scanf("%I64d%I64d",&w,&h);
	printf("%I64d\n",pow(2,w+h));
	return 0;
}
