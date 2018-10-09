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

void floyd_warshall(vector<vector<int> >&a,int n)
{
	int i,j,k;
	FOR(k,1,n)
	{
		FOR(i,1,n)
		{
			FOR(j,1,n)
			{
				a[j][j]=0;
				if(a[i][j]>a[i][k]+a[k][j])
				{
					a[i][j]=a[i][k]+a[k][j];
				}
			}
		}
	}
}


int main() {
	// your code goes here
	int t=0;
	int n,q,i,j,k,x,y,z;
	int v1,c1,v2,c2;
	
	scanf("%d",&t);
	while(t--)
	{
		cin>>n>>q;
		vector<vector<vector<int> > > mat;
		//vector<vector<int> >va(n+1,0);
		FOR(i,0,n-1)
		{
			cin>>x;
			//va[i+1]=x;
			vector<vector<int> > a(x+1,vector<int>(x+1,N));
			FOR(j,1,x-1)
			{
				cin>>a[j][j+1];
				a[j+1][j]=a[j][j+1];
			}
			cin>>a[x][1];
			a[1][x]=a[x][1];
			floyd_warshall(a,x);
			mat.push_back(a);
		}
		vector<int>weight(n+1,0),node(n+1,0);
		FOR(i,1,n-1)
		{
			cin>>node[i]>>node[i+1]>>weight[i];
		}
		cin>>node[n]>>node[1]>>weight[n];
		FOR(i,0,q-1)
		{
			cin>>v1>>c1>>v2>>c2;
			if(c1>c2)
			{
				c1^=c2;
				c2^=c1;
				c1^=c2;
				v1^=v2;
				v2^=v1;
				v1^=v2;
			}
			x=mat[c1][v1][node[c1]];
			//FOR(i,c1,c2-1)
			for(i=c1;i<=c2-1;)
			{
				x+=weight[c1];
				i=(i+1)%n;
				if(i==0)
					i=1;
			}
			y=0;
			for(i=c2;i<c1;)
			{
				y=0;
				i=(i+1)%n;
				if(i==0)
					i=1;
			}
			//cout<<(mat[c1]+mat[c2])<<endl;
		}



	}
	
	return 0;
}