#include<iostream>
#include<cstdio>
#include<cstring>
typedef long long ll;
using namespace std;
ll n,pos=-1;
int main()
{
	scanf("%I64d",&n);
	for (int i=2;i<=100000;i++)
	{
		if (!(n%i)) 
		{
			pos=i;
			break;
		}
	}
	if (pos==-1) pos=n;
	if (n&1) printf("%I64d\n",((n-pos)>>1)+1);
	else printf("%I64d\n",n>>1);
	return 0;
}
//if n is even,print n/2 since the minimum divisor is 2
//if n is odd,find the maximum divisor pos,then n-pos is even
