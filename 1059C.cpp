#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1000050
using namespace std;
int n,ret=1;
void work(int n)
{
	if (n==1) {printf("%d ",ret);return;}
	if (n==2) {printf("%d %d ",ret,ret*2);return;}
	if (n==3) {printf("%d %d %d ",ret,ret,ret*3);return;}
	if (n&1)
	{
		for (int i=1;i<=n;i+=2) printf("%d ",ret);
		ret<<=1;work((n-1)>>1);
	}
	else
	{
		for (int i=2;i<=n;i+=2) printf("%d ",ret);
		ret<<=1;work(n>>1);
	}
}
int main()
{
	scanf("%d",&n);
	work(n);
	return 0;
}
//if n<=3 print the result as given example
//otherwise,notice that the best way is delete each odd number(delete minimum amount of number)
//transfer the problem to a similar one
