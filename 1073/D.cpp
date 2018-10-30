#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 200050
typedef long long ll;
using namespace std;
ll n,k=0,T,a[maxn],t[maxn],ans=0,ret=0;
ll read()
{
	char ch;ll data=0;
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') {data=data*10+ch-'0';ch=getchar();}
	return data;
}
inline int lowbit(int x) {return x&(-x);}
void add(int x,ll val)
{
	for (int i=x;i<=n;i+=lowbit(i))
		t[i]+=val;
}
ll ask(int x)
{
	ll ret=0;
	for (int i=x;i>=1;i-=lowbit(i)) ret+=t[i];
	return ret;
}
int find(int pos,ll val)
{
	int l=pos,r=n,mid,ans=l-1;
	ll base=ask(l-1);
	while (l<=r)
	{
		mid=(l+r)>>1;
		if (ask(mid)-base<=val) {ans=mid;l=mid+1;}
		else r=mid-1;
	}
	return ans;
}
int main()
{
	n=read();T=read();
	for (int i=1;i<=n;i++) {a[i]=read();add(i,a[i]);}
	while (1)
	{
		int now=1,pos;ret=0;
		for (;now<=n;)
		{
			pos=find(now,T-ret);
			ret+=ask(pos)-ask(now-1);
			if (pos==n) break;
			add(pos+1,-a[pos+1]);now=pos+2;k++;
		}
		if (ret<=0) break;
		ans+=(T/ret)*(n-k);T%=ret;
	}
	printf("%I64d\n",ans);
	return 0;
}
//find the boundary binarily,we have a method of nlogn^2 using BIT
//if can't reach one point,then it can't be reached forever
//so we need n times to find the boundary
