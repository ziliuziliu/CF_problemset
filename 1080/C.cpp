#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
typedef long long ll;
using namespace std;
int t,n,m,x1,y1,x2,y2,x3,y3,x4,y4,xl,xr,yl,yr;
ll ans1=0,ans2=0,ret1=0,ret2=0;
void ask(int xl,int yl,int xr,int yr)
{
	ret1=0;ret2=0;
	ret1+=(ll)(xr-xl+1)*(yr-yl+1)/2;
	ret2+=(ll)(xr-xl+1)*(yr-yl+1)/2;
	if ((!((xr-xl+1)&1)) || (!((yr-yl+1)&1))) return;
	if ((xl+yl)&1) ret2++;else ret1++;
}
void modify()
{
	ll delta=0;
	xl=max(x1,x3);xr=min(x2,x4);
	yl=max(y1,y3);yr=min(y2,y4);
	if (xl<=xr && yl<=yr)
	{
		ask(xl,yl,xr,yr);
		ans1+=ret1;ans2+=ret2;
		delta=(ll)(xr-xl+1)*(yr-yl+1);
	}
	ans1+=(ll)(x2-x1+1)*(y2-y1+1)-delta;
}
void work()
{
	ans1=0;ans2=0;
	scanf("%d%d",&n,&m);
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	scanf("%d%d%d%d",&x3,&y3,&x4,&y4);
	ask(1,1,m,n);ans1+=ret1;ans2+=ret2;
	ask(x1,y1,x2,y2);ans1-=ret1;ans2-=ret2;
	modify();
	ask(x3,y3,x4,y4);ans1-=ret1;ans2-=ret2;
	ans2+=(ll)(x4-x3+1)*(y4-y3+1);
	printf("%I64d %I64d\n",ans1,ans2);
}
int main()
{
	scanf("%d",&t);
	for (int i=1;i<=t;i++) work();
	return 0;
}
//first calculate the whole part,then white,then combined part,then black
