#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 5050
using namespace std;
int n,nume;
bool vis[maxn];
int main()
{
	scanf("%d",&n);
	for (int i=2;i<=maxn;i++)
	{
		if (vis[i]) continue;
		for (int j=2;i*j<=maxn;j++)
			vis[i*j]=true;
	}
	nume=n;
	while (vis[nume]) nume++;
	printf("%d\n",nume);
	for (int i=1;i<=n-1;i++) printf("%d %d\n",i,i+1);
	printf("%d 1\n",n);
	for (int i=1;i<=nume-n;i++) printf("%d %d\n",i,i+n/2);
	return 0;
}
