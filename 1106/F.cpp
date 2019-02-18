#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<cmath>
#include<algorithm>
#define mod 998244353
typedef long long ll;
using namespace std;
ll k,b[105],n,m;
vector <int> v;
struct matrix
{
	ll a[105][105];
	friend matrix operator *(matrix a,matrix b)
	{
		matrix c;
		for (int i=1;i<=k;i++)
			for (int j=1;j<=k;j++)
				c.a[i][j]=0;
		for (int i=1;i<=k;i++)
			for (int j=1;j<=k;j++)
				for (int r=1;r<=k;r++)
				{
					c.a[i][j]+=a.a[i][r]*b.a[r][j]%(mod-1);
					c.a[i][j]%=(mod-1);
				}
		return c;
	}
}ans,base;
void reset()
{
	for (ll i=1;i<=k;i++) base.a[i][1]=b[i];
	for (ll i=1;i<=k-1;i++) base.a[i][i+1]=1;
	ans.a[1][1]=1;
}
void matrix_pow(ll x)
{
	while (x)
	{
		if (x&1) ans=ans*base;
		base=base*base;
		x>>=1;
	}
}
ll pow_mod(ll a,ll i, ll n)
{
	ll ans=1,base=a;
	while (i)
	{
		if (i&1) ans=(ans*base)%n;
		base=(base*base)%n;
		i>>=1;
	}
	return ans;
}
ll extend_gcd(ll a,ll b,ll &x,ll &y)
{
	if (b==0) 
	{
		x=1;y=0;
		return a;
	}
	else
	{
		ll r=extend_gcd(b,a%b,y,x);
		y-=x*(a/b);
		return r;
	}
}
ll discrete_log(int x,int n,int m)
{
	map <int,int> rec;
	int s=(int)sqrt((double)m);
	for (;(ll)s*s<=m;) s++;
	ll cur=1;
	for (int i=0;i<s;i++)
	{
		rec[(int)cur]=i;
		cur=cur*x%m;
	}
	ll mul=cur;
	cur=1;
	for (int i=0;i<s;i++)
	{
		ll more=(ll)n*pow_mod(cur,m-2,m)%m;
		if (rec.count((int)more))
			return i*s+rec[(int)more];
		cur=cur*mul%m;
	}
	return -1;
}
int residue(int p,int N,int a)
{
	int g=3;
	ll m=discrete_log(g,a,p);
	if (a==0) return 0;
	if (m==-1) return -1;
	ll A=N,B=p-1,C=m,x,y;
	ll d=extend_gcd(A,B,x,y);
	if (C%d!=0) return -1;
	x=x*(C/d)%B;
	ll delta=B/d;
	for (int i=0;i<d;i++)
	{
		x=((x+delta)%B+B)%B;
		return pow_mod(g,x,p);
	}
	return -1;
}
int main()
{
	scanf("%I64d",&k);
	for (ll i=1;i<=k;i++) scanf("%I64d",&b[i]);
	scanf("%I64d%I64d",&n,&m);
	reset();
	matrix_pow(n-k);
	printf("%d\n",residue(mod,ans.a[1][1],m));
	return 0;
}
//a simple residue problem
