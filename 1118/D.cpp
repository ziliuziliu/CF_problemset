#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 200050
typedef long long ll;
using namespace std;
int n,m,a[maxn],ans=0;
bool cmp(const int &x,const int &y) {return x>y;}
bool check(int x)
{
	ll ret=0;
	for (int i=1;i<=n;i++) ret+=max(0LL,(ll)a[i]-(i-1)/x);
	return ret>=(ll)m;
}
int binary_search()
{
	int ans=-1,l=1,r=n;
	while (l<=r)
	{
		int mid=(l+r)>>1;
		if (check(mid)) {ans=mid;r=mid-1;}
		else l=mid+1;
	}
	return ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1,cmp);
	ans=binary_search();
	printf("%d\n",ans);
	return 0;
}
//check every possible answer
//why sort it and distribute each k coffee into k days?
//because the later a less valued coffee was drunk in a day,the cost is less,because of max(0,..)
