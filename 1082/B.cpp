#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100050
using namespace std;
int n,cnt[maxn],ret=0,ans=0;
bool mp[maxn];
char s[maxn];
int main()
{
	scanf("%d",&n);
	scanf("%s",s);
	for (int i=1;i<=n;i++) if (s[i-1]=='G') mp[i]=1;
	for (int i=1;i<=n;i++) 
	{
		if (mp[i]) cnt[i]=cnt[i-1]+1;
		else cnt[i]=0;
	}
	for (int i=n-1;i>=1;i--) if (mp[i] && mp[i+1]) cnt[i]=cnt[i+1];
	for (int i=1;i<=n;i++) if (!mp[i-1] && mp[i]) ret++;
	for (int i=1;i<=n;i++)
	{
		if (!mp[i] && mp[i-1] && mp[i+1])
		{
			if (ret>=3) ans=max(ans,cnt[i-1]+cnt[i+1]+1);
			else ans=max(ans,cnt[i-1]+cnt[i+1]);
		}
		ans=max(ans,cnt[i]);
		if (ret>=2) ans=max(ans,cnt[i]+1);
	}
	printf("%d\n",ans);
	return 0;
}
//check carefully,pay attention to segment=2 situation
