#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
typedef long long ll;
using namespace std;
ll n,r=1;
ll get_ans(ll x)
{
	ll ret=0;
	while (x) {ret+=x%10;x/=10;}
	return ret;
}
int main()
{
	scanf("%I64d",&n);
	if (n<=9) printf("%I64d\n",n);
	else
	{
		ll ret=n;
		while (ret) {ret/=10;r*=10;}
		r/=10;r--;
		printf("%I64d\n",get_ans(r)+get_ans(n-r));
	}
	return 0;
}
//the best answer:find the closet number that consists of 999...
