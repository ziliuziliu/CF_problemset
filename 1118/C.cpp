#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1050
using namespace std;
int n,a,cnt[maxn],cnt_mod[5],mp[25][25],now=0;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
		{
			scanf("%d",&a);
			cnt[a]++;
		}
	for (int i=1;i<=1000;i++) cnt_mod[cnt[i]%4]++;
	if (n&1)
	{
		int tr=0;
		for (int i=1;i<=1000;i++) tr+=cnt[i]/4;
		if (tr<((n-1)*(n-1)/4)) {printf("NO\n");return 0;}
		for (int i=1;i<=(n-1)/2;i++)
			for (int j=1;j<=(n-1)/2;j++)
			{
				while (cnt[now]<4 && now<1000) now++;
				cnt[now]-=4;mp[i][j]=mp[n+1-i][j]=mp[i][n+1-j]=mp[n+1-i][n+1-j]=now;
			}
		now=0;tr=0;
		for (int i=1;i<=1000;i++) tr+=cnt[i]/2;
		if (tr<n-1) {printf("NO\n");return 0;}
		for (int i=1;i<=(n-1)/2;i++)
		{
			while (cnt[now]<2 && now<1000) now++;
			cnt[now]-=2;mp[(n-1)/2+1][i]=mp[(n-1)/2+1][n+1-i]=now;
			while (cnt[now]<2 && now<1000) now++;
			cnt[now]-=2;mp[i][(n-1)/2+1]=mp[n+1-i][(n-1)/2+1]=now;
		}
		now=0;tr=0;
		for (int i=1;i<=1000;i++)
		{
			if (cnt[i])
			{
				now=i;
				tr+=cnt[i];
			}
		}
		if (tr!=1) {printf("NO\n");return 0;}
		mp[(n-1)/2+1][(n-1)/2+1]=now;
		printf("YES\n");
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
				printf("%d ",mp[i][j]);
			printf("\n");
		}
	}
	else if ((!(n&1)) && cnt_mod[1]==0 && cnt_mod[2]==0 && cnt_mod[3]==0)
	{
		for (int i=1;i<=n/2;i++)
			for (int j=1;j<=n/2;j++)
			{
				while (!cnt[now]) now++;
				cnt[now]-=4;mp[i][j]=mp[n+1-i][j]=mp[i][n+1-j]=mp[n+1-i][n+1-j]=now;
			}
		printf("YES\n");
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++) printf("%d ",mp[i][j]);
			printf("\n");
		}
	}
	else printf("NO\n");
}
//when n is odd,things get a little bit tricky.
