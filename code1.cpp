#include <iostream>
#include <vector>
using namespace std;
#define ll long long

ll int oldMaxSum(vector<ll int> arr, int n)
{
	ll int ans = arr[0], sum = 0;
	for(int i = 0;i < n;i++)
	{
		sum += arr[i];
		if(ans < sum)
		{
			ans = sum;
		}
		if(sum<0)
		{
			sum = 0;
		}
	}
	// cout<<"oldMaxSum "<<ans<<endl;
	return(ans);
}


ll int wholeSum(vector<ll int> arr, int n)
{
	ll int ans = 0;
	for(int i = 0;i < n;i++)
	{
		ans += arr[i];
	}
	// cout<<"wholeSum "<<ans<<endl;
	return(ans);
}

ll int maxFromFront(vector<ll int> arr, int n)
{
	ll int ans = arr[0], sum = 0;
	for(int i = 0;i < n;i++)
	{
		sum += arr[i];
		if(sum>ans)
		{
			ans = sum;
		}
	}
	// cout<<"maxFromFront "<<ans<<endl;
	return(ans);
}

ll int maxFromLast(vector<ll int> arr, int n)
{
	ll int ans = arr[n-1], sum = 0;
	for(int i = n-1;i >= 0;i--)
	{
		sum += arr[i];
		if(sum>ans)
		{
			ans = sum;
		}
	}
	// cout<<"maxFromLast "<<ans<<endl;
	return(ans);
}

ll int maxSum(vector<ll int> arr, int n, int k)
{
	ll int ans = 0;
	if(k>1)
	{
		ll int x = wholeSum(arr, n);
		ll int y = maxFromFront(arr, n);
		ll int z = maxFromLast(arr, n);

		if(x<=0 && y<=0 && z<=0)
		{
			ans = oldMaxSum(arr,n);
		}
		else
		{
			if(x>0)
			{
				ans += ((k-2)*x);
			}
			if(y>0)
			{
				ans += y;
			}
			if(z>0)
			{
				ans += z;
			}
		}
	}
	else
	{
		ans = oldMaxSum(arr, n);
	}
	return(ans);
}


int main() {
	// your code goes here
	int t,n,k;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		vector<ll int> arr(k*n, 0);
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
			// cout<<arr[i]<<"--";
		}
		int j = n;
		int i=0;
		while(j<n*k)
		{
			i%=n;
			arr[j++] = arr[i++];
			// cout<<arr[j-1]<<"--";
		}
		cout<<oldMaxSum(arr, n*k)<<endl;
	}
	return 0;
}