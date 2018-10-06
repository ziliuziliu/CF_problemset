#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#define maxn 100050
typedef long double ld;
using namespace std;
int n,flag=0;
struct pnt
{
	ld x,y;
}p[maxn];
ld mn,mx;
bool check(ld r)
{
	mn=1e18;mx=-1e18;
	for (int i=1;i<=n;i++)
	{
		if (p[i].y>2*r) return false;
		ld ret=sqrt(r*r-(p[i].y-r)*(p[i].y-r));
		mx=max(mx,p[i].x-ret);mn=min(mn,p[i].x+ret);
	}
	return mx<=mn;
}
ld binary_search()
{
	ld ans,l=0,r=1e16,mid,cnt=0;
	while (cnt<=200)
	{
		cnt++;mid=(l+r)/2;
		if (check(mid)) ans=r=mid;
		else l=mid;
	}
	return ans;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%Lf%Lf",&p[i].x,&p[i].y);
		if (p[i].y<0) {flag++;p[i].y=-p[i].y;}
	}
	if (flag && flag!=n) {printf("-1\n");return 0;}
	printf("%.7Lf\n",binary_search());
	return 0;
}
//for each point,draw a circle with radius r
//if we could find a point lies in every circle,this radius r is legal
//we find out that the center of the circle is in line y=r
//in other words,draw a circle for each point,and we have n segments on the line y=r
//if all n segments are intersected,the r is legal
//do binary search,be careful with accuracy problems
