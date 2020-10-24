#include <bits/stdc++.h>
using namespace std;
void stock(int arr[],int n,vector<int>&v)
{
	int i;
	stack<pair<int,int>>s;
	for(i=0;i<n;i++)
	{
		if(s.empty())
		{
			v.push_back(-1);
		}
		else if(s.top().first>arr[i])
		{
			v.push_back(s.top().second);
		}
		else if(s.top().first<=arr[i])
		{
			while(s.top().first<=arr[i] && !s.empty())
			{
				s.pop();
			}
			if(s.top().first>arr[i])
			{
				v.push_back(s.top().second);
			}
			else
			{
				v.push_back(-1);
			}
		}
		s.push({arr[i],i});
	}
	for(i=0;i<n;i++)
	{
		v[i]=i-v[i];
	}
}

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
	int arr[n];
	vector<int>v;
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	stock(arr,n,v);
	
	for(int i=0;i<n;i++)
	{
		cout<<v[i];
		cout<<" ";
	}
	return 0;
}