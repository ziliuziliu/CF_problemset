#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxn 200050
using namespace std;
int n,a[maxn],b,pre=0,pos[maxn];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {scanf("%d",&a[i]);pos[a[i]]=i;}
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&b);
		if (pos[b]<=pre) printf("0 ");
		else {printf("%d ",pos[b]-pre);pre=pos[b];}
	}
	return 0;
}
//since all numbers are distinct,we just have to simulate the move
