#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
ll q,n,a,b;
int main()
{
	scanf("%I64d",&q);
	for (ll i=1;i<=q;i++)
	{
		scanf("%I64d%I64d%I64d",&n,&a,&b);
		if (a*2<=b) printf("%I64d\n",n*a);
		else printf("%I64d\n",(n/2)*b+(n&1)*a);
	}
	return 0;
}
//nothing to say.
