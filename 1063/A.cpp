#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100050
using namespace std;
int n,cnt[30],pos=1;
char s[maxn],ans[maxn];
int main()
{
	scanf("%d",&n);
	scanf("%s",s);
	for (int i=0;i<n;i++) cnt[s[i]-'a'+1]++;
	for (int i=0;i<n;i++) 
	{
		while (!cnt[pos]) pos++;
		ans[i]='a'+pos-1;cnt[pos]--;
	}
	printf("%s\n",ans);
	return 0;
}
//sort the string!
