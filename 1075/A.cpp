#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
typedef long long ll;
using namespace std;
ll n,x,y,mx,my;
int main()
{
	scanf("%I64d",&n);
	scanf("%I64d%I64d",&x,&y);
	mx=max(abs(x-1),abs(y-1));
	my=max(abs(x-n),abs(y-n));
	if (!my) printf("Black\n");
	else if (mx<=my) printf("White\n");
	else printf("Black\n");
	return 0;
}
//counting the Chebyshev distance
//be careful with details
