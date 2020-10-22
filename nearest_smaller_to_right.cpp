#include <bits/stdc++.h>
using namespace std;
void solve(int arr[],vector<int>&v,int n)
{
	stack<int>s;
	for(int i=n-1;i>=0;i--)
	{
		if(s.size()==0)
		{
			v.push_back(-1);
		}
		else if(s.top()<=arr[i])
		{
			v.push_back(s.top());
		}
		else if(s.top()>arr[i])
		{
			while(s.size()!=0 && s.top()>arr[i])
			{
				s.pop();
			}
			if(s.size()==0)
			{
				v.push_back(-1);
			}
			else
			{
				v.push_back(s.top());
			}
		}
		s.push(arr[i]);
	}
	reverse(v.begin(),v.end());
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
	vector<int>v(n);
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	solve(arr,v,n);
	
	for(int i=0;i<n;i++)
	{
		cout<<v[i];
		cout<< " ";
	}
	return 0;
}	