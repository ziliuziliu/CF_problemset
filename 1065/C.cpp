#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 200500
typedef long long ll;
using namespace std;
ll n,k,h[maxn],ans=0;
ll get_ans(ll x,ll p)
{
	h[x]-=p;
	if (x<=1) return 0;
	if (h[x]-h[x-1]==0) return get_ans(x-1,0);
	ll r1=(h[x]-h[x-1])/(k/(n-x+1)),r2=(h[x]-h[x-1])%(k/(n-x+1));
	if (!r2) return r1+get_ans(x-1,0);
	ll pos=x-1,ret=r2*(n-x+1);
	while (pos>=1 && ret+(h[pos]-h[pos-1])*(n-pos+1)<=k) 
	{
		ret+=(h[pos]-h[pos-1])*(n-pos+1);
		pos--;
	}
	p=(k-ret)/(n-pos+1);return r1+1+get_ans(pos,p);
}
int main()
{
	scanf("%I64d%I64d",&n,&k);
	for (ll i=1;i<=n;i++) scanf("%I64d",&h[i]);
	sort(h+1,h+n+1);
	printf("%I64d\n",get_ans(n,0));
	return 0;
}
//do it gredily!be careful with the details
