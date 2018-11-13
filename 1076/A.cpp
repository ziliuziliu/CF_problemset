#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 200050
using namespace std;
char s[maxn];
int n,pos=-1;
int main()
{
	scanf("%d",&n);
	scanf("%s",s);
	for (int i=0;i<n-1;i++)
	{
		if (s[i]>s[i+1])
		{pos=i;break;}
	}
	if (pos==-1) pos=n-1;
	for (int i=0;i<n;i++) if (i!=pos) printf("%c",s[i]);
	return 0;
}
//find the first one of i which s[i]>s[i+1]
//or i=m-1,assuring the smaller length
