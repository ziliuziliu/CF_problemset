#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define maxv 100050
#define maxe 200050
using namespace std;
int n,m,nume=1,x,y,p[maxv];
bool vis[maxv];
vector <int> v[maxv];
priority_queue <int,vector<int>,greater<int> > q;
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (int i=1;i<=n;i++) sort(v[i].begin(),v[i].end());
	q.push(1);vis[1]=true;
	while (!q.empty())
	{
		int x=q.top();q.pop();
		printf("%d ",x);
		for (int i=0;i<v[x].size();i++)
		{
			if (!vis[v[x][i]])
			{
				vis[v[x][i]]=true;
				q.push(v[x][i]);
			}
		}
	}
	return 0;
}
//!it's not solved in a greedy solution.
//by using a priority queue,each time we add one point to the visited set
//then add the point adjacent to the point we mentioned earlier into the priority queue
