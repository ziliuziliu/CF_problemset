#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1050
using namespace std;
int n,m,t[maxn],l[maxn],r[maxn];
int a[maxn],b[maxn];
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) b[i]=-1;
	a[1]=n;
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&t[i],&l[i],&r[i]);
		if (t[i])
		{
			for (int j=l[i];j<r[i];j++)
				b[j]=0;
		}
	}
	for (int i=2;i<=n;i++) a[i]=a[i-1]+b[i-1];
	for (int i=1;i<=m;i++)
	{
		if (!t[i])
		{
			if (a[l[i]]==a[r[i]])
			{
				printf("NO\n");
				return 0;
			}
		}
	}
	printf("YES\n");
	for (int i=1;i<=n;i++) printf("%d ",a[i]);
	return 0;
}
