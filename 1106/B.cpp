

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100050
typedef long long ll;
using namespace std;
ll n,m,pr=1,ans=0,t,d,tab[maxn];
struct pnt
{
	ll a,c,id;
	pnt (ll a,ll c):a(a),c(c) {}
	pnt () {}
}p[maxn];
bool cmp(pnt x,pnt y)
{
	if (x.c!=y.c) return x.c<y.c;
	return x.id<y.id;
}
int main()
{
	scanf("%I64d%I64d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%I64d",&p[i].a);
	for (int i=1;i<=n;i++) scanf("%I64d",&p[i].c);
	for (int i=1;i<=n;i++) p[i].id=i;
	sort(p+1,p+n+1,cmp);
	for (int i=1;i<=n;i++) tab[p[i].id]=i;
	for (int i=1;i<=m;i++)
	{
		ans=0;
		scanf("%I64d%I64d",&t,&d);
		if (pr==n+1) {printf("0\n");continue;}
		ans+=min(p[tab[t]].a,d)*p[tab[t]].c;
		if (d<=p[tab[t]].a) {p[tab[t]].a-=d;printf("%I64d\n",ans);}
		else
		{
			d-=p[tab[t]].a;p[tab[t]].a=0;
			for (;;)
			{
				if (pr==n+1) break;
				ans+=min(p[pr].a,d)*p[pr].c;
				if (p[pr].a>=d) {p[pr].a-=d;break;}
				else
				{
					d-=p[pr].a;p[pr].a=0;
					pr++;
				}
			}
			if (pr==n+1) printf("0\n");
			else printf("%I64d\n",ans);
		}
	}
	return 0;
}
//do as writer says.
