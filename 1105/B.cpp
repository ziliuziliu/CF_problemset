#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 200050
using namespace std;
char s[maxn];
int n,k,cnt[30],ans=0;
int main()
{
	scanf("%d%d",&n,&k);
	scanf("%s",s);
	int l=0,r=0;
	for (l=0;l<n;l=r+1)
	{
		r=l;while (r<n-1 && s[r+1]==s[l]) r++;
		cnt[s[l]-'a'+1]+=(r-l+1)/k;
	}
	for (int i=1;i<=26;i++) ans=max(ans,cnt[i]);
	printf("%d\n",ans);
	return 0;
}
//constructive problem
