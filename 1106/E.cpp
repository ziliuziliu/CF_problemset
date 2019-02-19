#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#define maxn 100005
#define maxm 205
#define inf 0x7f7f7f7f7f7f7f7f
using namespace std;
typedef long long ll;
int n,m,k,a,b,c,d,now=0;
struct envelope
{
	int s,t,d,w;
	bool operator < (const envelope &x) const
	{
		if (w!=x.w) return w<x.w;
		return d<x.d;
	}
	envelope (int s,int t,int d,int w):s(s),t(t),d(d),w(w) {}
	envelope () {}
}e[maxn];
ll dp[maxn][maxm],ans=inf;
priority_queue <envelope> q;
bool cmp(const envelope &x,const envelope &y)
{
	return x.s<y.s;
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=k;i++)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		e[i]=envelope(a,b,c,d);
	}
	for (register int i=1;i<=n+1;i++)
		for (register int j=0;j<=m+1;j++)
			dp[i][j]=inf;
	dp[1][0]=0;
	sort(e+1,e+k+1,cmp);
	for (int i=1;i<=n;i++)
	{
		while (!q.empty() && q.top().t<i) q.pop();
		while (now<k && e[now+1].s<=i) {now++;q.push(e[now]);}
		if (q.empty())
		{
			for (int j=0;j<=m;j++)
				dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
		}
		else
		{
			envelope nowe=q.top();
			for (int j=0;j<=m;j++)
			{
				dp[nowe.d+1][j]=min(dp[nowe.d+1][j],dp[i][j]+(ll)nowe.w);
				dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]);
			}
		}
	}
	for (int i=0;i<=m;i++) ans=min(ans,dp[n+1][i]);
	printf("%I64d\n",ans);
	return 0;
}
//dp+priority_queue
//it's strange,neither queue itself nor dp[i][j] always contain the right answer
//but since the writher of the problem only care about the final result,the answer is correct
//weird.
