#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
typedef long long ll;
using namespace std;
ll t,s,a,b,c;
int main()
{
	scanf("%I64d",&t);
	for (int i=1;i<=t;i++)
	{
		scanf("%I64d%I64d%I64d%I64d",&s,&a,&b,&c);
		printf("%I64d\n",s/(a*c)*(a+b)+(s%(a*c))/c);
	}
	return 0;
}
//nothing to explain
