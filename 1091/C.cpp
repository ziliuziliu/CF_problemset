#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define maxn 100050
typedef long long ll;
using namespace std;
ll n,tab[maxn],cnt=0;
int main()
{
	scanf("%I64d",&n);
	int top=(int)sqrt((double)n);
	for (int i=1;i<=sqrt(n);i++)
	{
		if (n%i) continue;
		tab[++cnt]=(n-i+2)*n/i/2;
		if (i==(n/i)) continue;
		tab[++cnt]=(n-n/i+2)*i/2;
	}
	sort(tab+1,tab+cnt+1);
	for (int i=1;i<=cnt;i++) printf("%I64d ",tab[i]);
	return 0;
}
//calc every divisor x,and we find that it's a sum of arithmetic progression
