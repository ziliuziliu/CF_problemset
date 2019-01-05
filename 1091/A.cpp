#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int r,b,y;
int main()
{
	scanf("%d%d%d",&y,&b,&r);
	printf("%d\n",min(r-2,min(b-1,y))*3+3);
	return 0;
}
//nothing to say...
