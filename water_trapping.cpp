#include <bits/stdc++.h>
using namespace std;

int main() 
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin>>n;
	vector<int>ht(n);
	for(int i=0;i<n;i++)
	{
		cin>>ht[i];
	}	
	vector<int>maxl(n);
	vector<int>maxr(n);
	for(int i=0;i<n;i++)
	{
		if(i==0)
		{
			maxl[0]=ht[0];
		}
		else{
			maxl[i]=max(ht[i],maxl[i-1]);
		}
		
	}
	for(int i=n-1;i>=0;i--)
	{
		if(i==n-1)
		{
			maxr[i]=ht[i];
		}
		else{
			maxr[i]=max(ht[i],maxr[i+1]);
		}
		
	}
	vector<int>water(n);
	for(int i=0;i<n;i++)
	{
		water[i]=min(maxl[i],maxr[i])-ht[i];
	}
	int ans=0;
	for(int i=0;i<n;i++)
	{
		ans=ans+water[i];
	}
	cout<<ans;
	return 0;
}	
		