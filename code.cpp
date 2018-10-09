#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;
#define ll long long

void solve(vector<int> a, int s1, int e1, vector<int> b, int s2, int e2, int k, int n0)
{
	// cout<<s1<<","<<e1<<"    "<<s2<<","<<e2<<" - "<<k<<endl;
	if(e1<s1)
	{
		cout<<b[s2+k-1]<<endl;
		return;
	}
	if(e2<s2)
	{
		cout<<a[s1+k-1]<<endl;
		return;
	}
	int m1 = (e1+s1)/2;
	int m2 = (e2+s2)/2;
	int n1 = m1-s1+1;
	int n2 = m2-s2+1;
	int n=0,x,y;

	if(k>=n1+n2)
	{
		// chote wala aur uska left ignore kerna
		if(a[m1]>b[m2])
		{
			s2=m2+1;
			n = n2;
		}
		else if(a[m1]<b[m2])
		{
			s1=m1+1;
			n = n1;
		}
		else
		{
			// cout<<"in equal k>=n1+n2"<<endl;
			x = a[m1];
			y = b[m2];
			if(m1-1>=0 && m1-1>=s1)
			{
				x = a[m1-1];
			}
			if(m2-1>=0 && m2-1>=s2)
			{
				y = b[m2-1];
			}
			if(x>y)
			{
				s2=m2+1;
				n = n2;
			}
			else
			{
				s1=m1+1;
				n = n1;
			}
		}
	}
	else if(k<n1+n2)
	{
		// Bade wala aur uska right ignore kerna
		if(a[m1]>b[m2])
		{
			e1 = m1-1;
		}
		else if(a[m1]<b[m2])
		{
			e2 = m2-1;
		}
		else
		{
			// cout<<"in equal k<n1+n2"<<endl;
			x = a[m1];
			y = b[m2];
			if(m1+1<n0 && m1+1<=e1)
			{
				x = a[m1+1];
			}
			if(m2+1<n0 && m2+1<=e2)
			{
				y = b[m2+1];
			}

			if(x>y)
			{
				e1 = m1-1;
			}
			else
			{
				e2 = m2-1;
			}

		}
	}
	solve(a,s1,e1,b,s2,e2,k-n,n0);
}

void get_input(vector<int> & arr1,vector<int> & arr2, int &n, int &k)
{
	int x;
	cout<<"Enter n = ";
	cin>>n;
	cout<<"Enter first array "<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		arr1.push_back(x);
	}
	cout<<"Enter second array "<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		arr2.push_back(x);
	}
	cout<<"Enter value of K(smallest element to find eg. 1,2,3......,n) =  "<<endl;
	cin>>k;

}

int main() {
	// your code goes here
	int n = 3, k = 1;
	// int arr1[] = {2,4,6,8,10,11};
	// int arr2[] = {1,3,5,7,9,12};
	// int arr1[] = {1,3,4};
	// int arr2[] = {1,3,6};
	vector<int> arr1;
	vector<int> arr2;
	get_input(arr1, arr2, n, k);

	solve(arr1,0,n-1,arr2,0,n-1,k,n);

	return 0;
}