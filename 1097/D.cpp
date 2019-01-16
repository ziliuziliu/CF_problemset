#include<iostream>
#include<cstdio>
#include<cstring>
#define mod 1000000007
#define maxn 105
typedef long long ll;
using namespace std;
ll n,k,tab1[maxn],tab2[maxn],cnt=0,dp[maxn],sum[maxn],inv[maxn],ans=1;
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
void get_table()
{
	for (int i=1;i<=100;i++) inv[i]=pow(i,mod-2);
	for (ll i=2;i*i<=n;i++)
	{
		if (n%i) continue;
		tab1[++cnt]=i;
		while (n%i==0) {tab2[cnt]++;n/=i;}
	}
	if (n!=1) {tab1[++cnt]=n;tab2[cnt]=1;}
}
void get_ans(int x)
{
	memset(dp,0,sizeof(dp));
	memset(sum,0,sizeof(sum));
	int top=tab2[x];
	for (int i=0;i<=top;i++) sum[i]=inv[top+1];dp[top]=1;
	for (int i=1;i<=k;i++)
	{
		for (int j=0;j<=top;j++) dp[j]=sum[j];
		for (int j=top;j>=0;j--) sum[j]=(sum[j+1]+dp[j]*inv[j+1]%mod)%mod;
	}
	ll ret1=0,ret2=1;
	for (int i=0;i<=top;i++)
	{
		ret1+=ret2*dp[i]%mod;ret1%=mod;
		ret2*=tab1[x];ret2%=mod;
	}
	ans=(ans*ret1)%mod;
}
int main()
{
	scanf("%I64d%I64d",&n,&k);
	get_table();
	for (int i=1;i<=cnt;i++) get_ans(i);
	printf("%I64d\n",ans);
	return 0;
}
//calculate the answer for every prime divisor
//dp[i][j] represents:after i moves,the probability of p^j
//then multiply the answer
