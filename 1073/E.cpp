#include<iostream>
#include<cstdio>
#include<cstring>
#define mod 998244353
typedef long long ll;
using namespace std;
ll l,r,k,sum[20][1050][2],cnt[20][1050][2],tab[20];
int count(int x)
{
	int ret=0;
	while (x) 
	{
		if (x&1) ret++;
		x>>=1;
	}
	return ret;
}
void get_table()
{
	tab[0]=1;for (int i=1;i<=18;i++) tab[i]=tab[i-1]*10;
	cnt[0][0][0]=1;
	for (int k=0;k<10;k++)
	{
		cnt[1][1<<k][0]=1;if (k) cnt[1][1<<k][1]=1;
		sum[1][1<<k][0]=k;if (k) sum[1][1<<k][1]=k;
	}
	for (int i=1;i<=18;i++)
		for (int j=1;j<1024;j++)
		{
			for (int k=0;k<10;k++)
			{
				cnt[i+1][j|(1<<k)][0]+=cnt[i][j][0];cnt[i+1][j|(1<<k)][0]%=mod;
				if (k) {cnt[i+1][j|(1<<k)][1]+=cnt[i][j][0];cnt[i+1][j|(1<<k)][1]%=mod;}
				sum[i+1][j|(1<<k)][0]+=sum[i][j][0];sum[i+1][j|(1<<k)][1]%=mod;
				sum[i+1][j|(1<<k)][0]+=k*(tab[i]%mod)%mod*cnt[i][j][0]%mod;sum[i+1][j|(1<<k)][1]%=mod;
				if (k)
				{
					sum[i+1][j|(1<<k)][1]+=sum[i][j][0];sum[i+1][j|(1<<k)][0]%=mod;
					sum[i+1][j|(1<<k)][1]+=k*(tab[i]%mod)%mod*cnt[i][j][0]%mod;sum[i+1][j|(1<<k)][0]%=mod;
				}
			}
		}
}
ll work(ll x)
{
	ll xx=1,bit=0,ans=0;
	while (x>=xx) {xx*=10;bit++;}
	xx/=10;bit--;
	for (int i=1;i<=bit;i++)
		for (int j=0;j<1024;j++)
			if (count(j)<=k) ans=(ans+sum[i][j][1])%mod;
	ll flag1=0,flag2=0;
	for (int i=bit;i>=0;i--)
	{
		int up=(x/tab[i])%10;
		for (int j=(i==bit)?1:0;j<up;j++)
			for (int kk=0;kk<1024;kk++)
			{
				if (count(flag1|(1<<j)|kk)<=k) 
				{
					ans+=sum[i][kk][0];ans%=mod;
					ans+=(flag2+j*(tab[i]%mod)%mod)%mod*cnt[i][kk][0]%mod;ans%=mod;
				}
			}
		flag1|=(1<<up);flag2+=up*(tab[i]%mod)%mod;flag2%=mod;
	}
	if (count(flag1)<=k) ans=(ans+x)%mod;
	return ans%mod;
}
int main()
{
	scanf("%I64d%I64d%I64d",&l,&r,&k);
	get_table();
	printf("%I64d\n",(work(r)-work(l-1)+mod)%mod);
	return 0;
}
//f**king digit dp
