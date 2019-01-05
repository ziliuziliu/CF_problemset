#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1000050
#define mod 998244353
typedef long long ll;
using namespace std;
ll n,a[maxn],tab[maxn];
int main()
{
	scanf("%I64d",&n);a[1]=1;tab[1]=1;
	for (int i=2;i<=n;i++) tab[i]=tab[i-1]*i%mod;
	for (int i=2;i<=n;i++) a[i]=((a[i-1]-1)*i%mod+tab[i])%mod;
	printf("%I64d\n",a[n]);
	return 0;
}
//f**king math formula
