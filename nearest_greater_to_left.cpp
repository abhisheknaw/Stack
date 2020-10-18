#include <bits/stdc++.h>
using namespace std;
void solve(int arr[],int n,vector<int>&a)
{
	stack<int>s;
	for(int i=0;i<n;i++)
	{
		if(s.size()==0)
		{
			a.push_back(-1);
		}
		else if(s.top()>arr[i])
		{
			a.push_back(s.top());
		}
		else if(s.top()<=arr[i])
		{
			while(s.size()!=0 && s.top()<=arr[i])
			{
				s.pop();
			}
			if(s.size()==0)
			{
				a.push_back(-1);
			}
			else if(s.top()>arr[i])
			{
				a.push_back(s.top());
			}

		}
		s.push(arr[i]);
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
	vector<int>a;
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	solve(arr,n,a);
	
	for(int i=0;i<n;i++)
	{
		cout<<a[i];
		cout<< " ";
	}
	return 0;
}	