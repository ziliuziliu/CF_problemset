#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[3];
int main()
{
	for (int i=1;i<=3;i++) scanf("%d",&a[i]);
	sort(a+1,a+4);
	printf("%d\n",max(0,a[3]-a[1]-a[2]+1));
	return 0;
}
//nothing to explain
