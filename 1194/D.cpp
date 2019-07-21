#include<iostream>
#include<cstdio>
using namespace std;
int t,n,k;
int main()
{
    scanf("%d",&t);
    for (int i=1;i<=t;i++)
    {
    	scanf("%d%d",&n,&k);
    	if (k%3!=0)
    	{
    		if (n%3==0) printf("Bob\n");
    		else printf("Alice\n");
    	}
    	else
    	{
    		int flag=n%(k+1);
    		if (flag==k) printf("Alice\n");
    		else 
    		{
    			if (flag%3==0) printf("Bob\n");
    			else printf("Alice\n");
    		}
    	}
    }
    return 0;
}
