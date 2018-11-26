#include<iostream>
#include<cstdio>
#include<cstring>
typedef long long ll;
using namespace std;
ll t,n,k,ans=0,ret=0;
ll pow(ll a,ll b)
{
	ll ans=1,base=a;
	while (b)
	{
		if (b&1) ans*=base;
		base*=base;
		b>>=1;
	}
	return ans;
}
ll find(ll x)
{
	for (ll nn=1;nn<=n;nn++)
	{	
		if (pow(2,nn+1)-nn-2>k)
		{
			ret=k-pow((ll)2,nn)+nn+1;
			return nn-1;
		}
	}
	ret=k-pow((ll)2,n+1)+n+2;
	return n;
}
void work()
{
	ans=0;ret=0;bool flag=false;
	scanf("%I64d%I64d",&n,&k);
	ans=find(k);
	if (n>=32) {printf("YES %I64d\n",n-ans);return;}
	for (int i=1;i<=ans;i++)
	{
		if ((pow((ll)2,2*n-2*i)-1)/3*(pow((ll)2,i+1)-3)<0) {printf("YES %I64d\n",n-ans);return;}
		ret-=(pow((ll)2,2*n-2*i)-1)/3*(pow((ll)2,i+1)-3);
		if (ret<=0) flag=true;
	}
	if (!flag) printf("NO\n");
	else printf("YES %I64d\n",n-ans);
}
int main()
{
	scanf("%I64d",&t);
	for (int i=1;i<=t;i++) work();
	return 0;
}
//do it greedily:first divide the lower right part,say we need x moves now
//then check whether k-x moves are possible,using some math formula
