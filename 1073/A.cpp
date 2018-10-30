#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1050
using namespace std;
int n;
char s[maxn];
int main()
{
	scanf("%d",&n);
	scanf("%s",s);
	for (int i=0;i<n-1;i++)
	{
		if (s[i]!=s[i+1])
		{
			printf("YES\n");
			printf("%c%c\n",s[i],s[i+1]);
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}
//to construct the answer,you just have to find two distinct continuous letters
