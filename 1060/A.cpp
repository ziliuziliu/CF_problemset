#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 105
using namespace std;
int n,cnt[10],sum=0;
char s[maxn];
int main()
{
	scanf("%d",&n);
	scanf("%s",s);
	for (int i=0;i<n;i++) cnt[s[i]-'0']++;
	printf("%d\n",min(n/11,cnt[8]));
	return 0;
}
//two condition:total amount of phone number and how many 8's
