#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 500050
typedef long long ll;
using namespace std;
ll n,a[maxn],ans=0;
int main()
{
	scanf("%I64d",&n);
	for (int i=1;i<=n;i++) scanf("%I64d",&a[i]);
	sort(a+1,a+n+1);
	for (int i=1;i<=n/2;i++)
		ans+=(a[i]+a[n+1-i])*(a[i]+a[n+1-i]);
	printf("%I64d\n",ans);
	return 0;
}
//the answer is easy to guess:make each two in a group
