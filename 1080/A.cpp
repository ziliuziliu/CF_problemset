#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
typedef long long ll;
using namespace std;
ll n,k;
int main()
{
	scanf("%I64d%I64d",&n,&k);
	ll ans=0;
	ans+=n*2/k;if ((n*2)%k) ans++;
	ans+=n*5/k;if ((n*5)%k) ans++;
	ans+=n*8/k;if ((n*8)%k) ans++;
	printf("%I64d\n",ans);
	return 0;
}
//using ceil function
