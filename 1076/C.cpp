#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int t,d;
double a;
int main()
{
	scanf("%d",&t);
	for (int i=1;i<=t;i++)
	{
		scanf("%d",&d);
		if (d==0) printf("Y 0.000000000 0.000000000\n");
		else if (d<4) printf("N\n");
		else
		{
			a=((double)d+sqrt(d*d-4*d))/2;
			printf("Y %.9f %.9f\n",a,d-a);
		}
	}
	return 0;
}
//solve (d-a)=d/a,using delta to check
