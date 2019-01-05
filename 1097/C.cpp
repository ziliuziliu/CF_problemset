#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 500050
using namespace std;
int n,cnt1[maxn],cnt2[maxn],cnt3=0,sum[maxn],ans=0;
char s[maxn];
void check1()
{
	int l=strlen(s);sum[0]=0;
	for (int i=0;i<l;i++)
	{
		if (s[i]=='(') sum[i+1]=sum[i]+1;
		else sum[i+1]=sum[i]-1;
		if (sum[i+1]<0) return;
	}
	if (!sum[l]) cnt3++;
	else cnt1[sum[l]]++;
}
void check2()
{
	int l=strlen(s);sum[l+1]=0;
	for (int i=l-1;i>=0;i--)
	{
		if (s[i]=='(') sum[i+1]=sum[i+2]+1;
		else sum[i+1]=sum[i+2]-1;
		if (sum[i+1]>0) return;
	}
	if (sum[1]<0) cnt2[-sum[1]]++;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%s",s);
		check1();check2();
	}
	for (int i=1;i<=maxn-50;i++) ans+=min(cnt1[i],cnt2[i]);
	ans+=cnt3/2;
	printf("%d\n",ans);
	return 0;
}
//first we calculate which can be a prefix,and which can be a suffix,and which is correct already
//then match them!
