#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int t,a,cnt=0;
int main()
{
	scanf("%d",&t);
	for (int i=1;i<=t;i++)
	{
		scanf("%d",&a);cnt=0;
		while (a) {if (a&1) cnt++;a>>=1;}
		printf("%d\n",1<<cnt);
	}
	return 0;
}
//the answer is 2^cnt,cnt refers to the number of 1s in a in binary system.
