#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
typedef long long ll;
using namespace std;
ll n,m;
int main()
{
	scanf("%I64d%I64d",&n,&m);
	ll ret;
	if (n&1) ret=(n>>1)+1;else ret=n>>1;
	if (m<ret) printf("%I64d ",n-2*m);
	else printf("0 ");
	if (m==0) printf("%I64d\n",n);
	else printf("%I64d\n",n-(ll)ceil(((1.0+sqrt(8*m+1))/2)));
	return 0;
}
//min:each time connect two isolated point
//max:construct a complete graph,find the answer by solve a inequation
//special case:m=0
