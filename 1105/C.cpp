#include<iostream>
#include<cstdio>
#include<cstring>
#define mod 1000000007
#define maxn 200050
typedef long long ll;
using namespace std;
ll n,l,r,ans=0,cnt[5],dp[maxn][3][3];
ll pow(ll a,ll b)
{
	ll base=a,ans=1;
	while (b)
	{
		if (b&1) ans=(ans*base)%mod;
		base=(base*base)%mod;
		b>>=1;
	}
	return ans;
}
void calc1()
{
	cnt[0]=r/3-(l-1)/3;
	cnt[1]=(r-1)/3-(l-2)/3;if (l==1) cnt[1]++;
	cnt[2]=(r-l+1)-cnt[0]-cnt[1];
}
void calc2()
{
	dp[0][0][0]=1;
	for (int i=0;i<=n-1;i++)
		for (int j=0;j<=2;j++)
			for (int k=0;k<=2;k++)
			{
				dp[i+1][j][k]+=dp[i][j][k]*cnt[0]%mod;dp[i+1][j][k]%=mod;
				dp[i+1][(j+1)%3][k]+=dp[i][j][k]*cnt[1]%mod;dp[i+1][(j+1)%3][k]%=mod;
				dp[i+1][j][(k+1)%3]+=dp[i][j][k]*cnt[2]%mod;dp[i+1][j][(k+1)%3]%=mod;
			}
	ans=(dp[n][0][0]+dp[n][1][1]+dp[n][2][2])%mod;
}
int main()
{
	scanf("%I64d%I64d%I64d",&n,&l,&r);
	calc1();
	calc2();
	printf("%I64d\n",ans);
	return 0;
}
//a simple dp problem:we notice that the total num of %3==1 and %3==2 must be the same
