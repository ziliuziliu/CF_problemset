#include<iostream>
#include<cstdio>
#include<cstring>
typedef long long ll;
int n,k;
int main()
{
	scanf("%d%d",&n,&k);
	if ((ll)k*k-(ll)k<n) {printf("NO\n");return 0;}
	printf("YES\n");
	for (int i=1;i<=k;i++)
		for (int j=i+1;j<=k;j++)
		{
			printf("%d %d\n",i,j);n--;
			if (!n) return 0;
			printf("%d %d\n",j,i);n--;
			if (!n) return 0;
		}
}
//using constrctive algorithm
//simply we find that arrange every possible answer in a particular order will do
