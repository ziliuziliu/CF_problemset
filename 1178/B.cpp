#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
typedef long long ll;
#define maxn 1000050
using namespace std;
char s[maxn];
ll cnt1[maxn],cnt2[maxn],ans=0,l;
int main()
{
	scanf("%s",s);l=strlen(s);
	cnt1[0]=cnt2[l-1]=0;
	for (int i=1;i<l;i++) 
	{
		if (s[i]=='v' && s[i]==s[i-1])
			cnt1[i]=cnt1[i-1]+1;
		else cnt1[i]=cnt1[i-1];
	}
	for (int i=l-2;i>=0;i--) 
	{
		if (s[i]=='v' && s[i]==s[i+1])
			cnt2[i]=cnt2[i+1]+1;
		else cnt2[i]=cnt2[i+1];
	}
	for (int i=0;i<l;i++)
	{
		if (s[i]=='o') 
			ans+=cnt1[i]*cnt2[i];
	}
	printf("%I64d\n",ans);
	return 0;
}
