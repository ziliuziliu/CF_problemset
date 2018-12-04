#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
using namespace std;
int t,n,x,y,d;
int main()
{
	scanf("%d",&t);
	for (int i=1;i<=t;i++)
	{
		scanf("%d%d%d%d",&n,&x,&y,&d);
		if (y%d==x%d) printf("%d\n",abs(x-y)/d);
		else
		{
			int r1=-1,r2=-1;
			if (y%d==1) r1=(int)ceil((double)(x-1)/d)+(y-1)/d;
			if (y%d==n%d) r2=(int)ceil((double)(n-x)/d)+(n-y)/d;
			if (y%d==n%d && y%d==1) printf("%d\n",min(r1,r2));
			else if (y%d==1) printf("%d\n",r1);
			else if (n%d==y%d) printf("%d\n",r2);
			else printf("-1\n");
		}
	}
	return 0;
}
//check both sides,find minimal answer
