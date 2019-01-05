#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char s[4];
bool vis[1050];
int flag=0;
int main()
{
	scanf("%s",s);vis[s[0]]=vis[s[1]]=true;
	for (int i=1;i<=5;i++)
	{
		scanf("%s",s);
		flag|=(vis[s[0]])||(vis[s[1]]);
	}
	if (flag) printf("YES\n");
	else printf("NO\n");
	return 0;
}
//nothing to say
