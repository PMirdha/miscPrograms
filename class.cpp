#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;
#define FOR(x,a,b) for(x=a;x<=b;x++)
#define MALLOC(a,dt,n) a=(dt*)malloc(sizeof(dt)*n)
#define MEMSET(a,dt,n) memset(a,0,sizeof(dt)*n)
#define ABS(x) ((x)<0?(-1*(x)):(x))
#define MAX(x,y) x>y?x:y
#define MIN(x,y) x<y?x:y
#define ll long long
#define N 1000000007


int main() {
	// your code goes here
	int t=0;
	int n,i,j,x,y,z;
	int sum;
	
	scanf("%d",&t);
	while(t--)
	{
		cin>>n;
		vector<int> a(n);
		FOR(i,0,n-1)
		{
			cin>>a[i];
		}
		sum=0;
		FOR(i,0,n-2)
		{
			x=a[i];
			if(x!=0)
			{
				FOR(j,i+1,n-1)
				{
					if(a[j]!=0 && a[i]*a[j]<0)
					{
						y=ABS(a[i]+a[j]);
						if(a[i]<0)
						{
							a[i]+=y;
							a[j]-=y;
						}
						else
						{
							a[i]-=y;
							a[j]+=y;
						}
						sum+=((j-i)*y);
					}
					if(a[i]==0)
					{
						break;
					}
				}
			}
		}
		cout<<sum<<endl;



	}
	
	return 0;
}