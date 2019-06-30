#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxb 70
#define maxn 100050
typedef long long ll;
using namespace std;
ll n,q,u,bit[maxb],top=0,pnt,l;
char s[maxn];
void get_bit(ll u)
{
	top=0;pnt=-1;
	while (u)
	{
		bit[top]=u&1;
		if (bit[top] && pnt==-1) pnt=top;
		top++;u>>=1;
	}
	bit[top]=0;
}
void work()
{
	scanf("%I64d",&u);
	scanf("%s",s);l=strlen(s);
	for (ll i=0;i<l;i++)
	{
		get_bit(u);
		if ((u&1) && ((s[i]=='L') || (s[i]=='R'))) continue;
		if (s[i]=='L') u-=(1LL<<(pnt-1));
		else if (s[i]=='R') u+=(1LL<<(pnt-1));
		else
		{
			if ((bit[pnt]) && (bit[pnt+1])) u-=(1LL<<pnt);
			else
			{
				if (u+(1LL<<pnt)>n) continue;
				u+=(1LL<<pnt);
			}
		}
	}
	printf("%I64d\n",u);
}
int main()
{
	scanf("%I64d",&n);scanf("%I64d",&q);
	for (ll i=1;i<=q;i++) work();
	return 0;
}
