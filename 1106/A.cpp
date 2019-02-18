#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 505
using namespace std;
char s[maxn];
bool mp[maxn][maxn];
int ans=0,n;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%s",s);
		for (int j=0;j<n;j++)
			if (s[j]=='X') mp[i][j+1]=1;
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			ans+=(mp[i][j] && mp[i-1][j-1] && mp[i-1][j+1] && mp[i+1][j-1] && mp[i+1][j+1]);
	printf("%d\n",ans);
	return 0;
}
//nothing to say.
