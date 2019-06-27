#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a;
bool check(int x)
{
	int sum=0;
	while (x) {sum+=x%10;x/=10;}
	return (sum%4==0);
}
int main()
{
	scanf("%d",&a);
	for (;;a++)
	{
		if (check(a))
		{
			printf("%d\n",a);
			return 0;
		}
	}
}
//brute force
