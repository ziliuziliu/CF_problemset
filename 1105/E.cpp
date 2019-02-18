#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxv 45
#define maxn 100050
typedef long long ll;
using namespace std;
int n,m,cnt=0,t,mp[maxv][maxv],top=0,dp[1<<21];
int trie[maxn][26],cnt_node=1,root=1,id[maxn];
ll q[maxn];
char s[maxv];
bool vis1[1<<21],vis2[maxv];
int search()
{
	int now=root,l=strlen(s);
	for (int i=0;i<l;i++)
	{
		if (!trie[now][s[i]-'a']) trie[now][s[i]-'a']=++cnt_node;
		now=trie[now][s[i]-'a'];
	}
	if (!id[now]) id[now]=++cnt;
	return id[now];
}
int dfs(ll bit)
{
	if (bit<(1LL<<20))
	{
		if (vis1[bit])
			return dp[bit];
	}
	if (!bit) return 0;
	int top=0;
	ll mask=0;
	for (int i=m;i>=1;i--)
	{
		if (bit&(1LL<<(i-1)))
		{
			top=i;
			break;
		}
	}
	for (int i=1;i<=m;i++)
		if (!mp[top][i]) mask|=(1LL<<(i-1));
	int ans=max(dfs(bit^(1LL<<(top-1))),dfs(bit&mask)+1);
	if (bit<(1LL<<20)) {dp[bit]=ans;vis1[bit]=true;}
	return ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	memset(mp,0,sizeof(mp));
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&t);
		if (t==1)
		{
			for (int j=1;j<=top;j++)
				for (int k=j+1;k<=top;k++)
						mp[q[j]][q[k]]=mp[q[k]][q[j]]=1;
			for (int j=1;j<=top;j++) vis2[q[j]]=false;
			top=0;
		}
		else
		{
			scanf("%s",s);
			int id1=search();
			if (!vis2[id1]) {vis2[id1]=true;q[++top]=id1;}
		}
	}
	for (int j=1;j<=top;j++)
		for (int k=j+1;k<=top;k++)
			mp[q[j]][q[k]]=mp[q[k]][q[j]]=1;
	memset(vis2,false,sizeof(vis2));
	for (int i=1;i<=m;i++) mp[i][i]=1;
	printf("%d\n",dfs((1LL<<m)-1LL));
	return 0;
}
//dfs one half,memory search the other half,makeing total complexity o(2^(m/2))
