#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#define maxn 200050
#define inf 2000000050
using namespace std;
int n,sumx[maxn],sumy[maxn],dx=0,dy=0,x,y,ans=-1,l;
char s[maxn];
bool check2(int x,int l)
{
	if (x&1) return false;
	x>>=1;
	if (0<=x && x<=l) return true;
	else return false;
}
bool check(int xx)
{
	for (int i=xx;i<=n;i++)
	{
		dx=sumx[i]-sumx[i-xx];dy=sumy[i]-sumy[i-xx];
		dx=sumx[n]-dx;dy=sumy[n]-dy;
		dx=x-dx;dy=y-dy;
		if (((abs(dx)+abs(dy))&1)^(xx&1)) continue;
		if ((abs(dx)+abs(dy))>xx) continue;
		return true;
	}
	return false;
}
void binary_search()
{
	int l=0,r=n,mid;
	while (l<=r)
	{
		mid=(l+r)>>1;
		if (check(mid)) {ans=mid;r=mid-1;}
		else l=mid+1;
	}
}
int main()
{
	scanf("%d",&n);
	scanf("%s",s);l=strlen(s);
	scanf("%d%d",&x,&y);
	for (int i=0;i<l;i++)
	{
		sumx[i+1]=sumx[i];sumy[i+1]=sumy[i];
		if (s[i]=='U') sumy[i+1]++;
		else if (s[i]=='D') sumy[i+1]--;
		else if (s[i]=='L') sumx[i+1]--;
		else sumx[i+1]++;
	}
	binary_search();
	printf("%d\n",ans);
	return 0;
}
//obviously we use binary_search,but how to check?
//first we look at the parity,we notice that each move change the parity of |x|+|y| once
//then we check whether n move is enough,by check whether n>=|x|+|y|
//enough.But I don't know why
