#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1050
using namespace std;
int n,tx,ty;
struct pnt 
{
	int x,y;
	pnt (int x,int y):x(x),y(y) {}
	pnt () {}
}a[maxn],b[maxn];
bool cmp1(const pnt &x,const pnt &y)
{
	if (x.x==y.x) return x.y<y.y;
	return x.x<y.x;
}
bool cmp2(const pnt &x,const pnt &y)
{
	if (x.x==y.x) return x.y>y.y;
	return x.x>y.x;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d%d",&a[i].x,&a[i].y);
	for (int i=1;i<=n;i++) scanf("%d%d",&b[i].x,&b[i].y);
	sort(a+1,a+n+1,cmp1);sort(b+1,b+n+1,cmp2);
	printf("%d %d\n",a[1].x+b[1].x,a[1].y+b[1].y);
	return 0;
}
//sort a and b
