#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 20
#define maxs 10050
using namespace std;
int n,a[maxn];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=0;i<(1<<n);i++)
	{
		int sum=0;
		for (int j=0;j<n;j++) 
		{
			if (i&(1<<j)) sum+=a[j+1];
			else sum-=a[j+1];
		}
		if (sum%360==0) {printf("YES\n");return 0;}
	}
	printf("NO\n");
	return 0;
}
//check every possible situation
