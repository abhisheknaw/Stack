#include <bits/stdc++.h>
using namespace std;
int min_ele=-1;
stack<int>s;
void push(int x)
{
	if(s.empty())
	{
		s.push(x);
		min_ele=x;
	}
	else
	{
		if(x >= min_ele)
		{
			s.push(x);
		}
		else if(x < min_ele)
		{
			s.push(2*x-min_ele);
			min_ele=x;
		}
	}
}
void pop()
{
	if(s.empty())
	{
		return;
	}
	else
	{
		if(s.top() >= min_ele)
		{
			s.pop();
		}
		else if(s.top() < min_ele)
		{
			min_ele=2*min_ele-s.top();
			s.pop();
		}
	} 
}
int top()
{
	if(s.empty())
	{
		return -1;
	}
	else
	{
		if(s.top()>=min_ele)
		{
			return s.top();
		}
		else if(s.top()<min_ele)
		{
			return min_ele;
		}
	}
	return 0;
}
int mint()
{
	if(s.size()==0)
	{
		return -1;
	}
	return min_ele;
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
	int x;
	cin>>x;
	for(int i=0;i<x;i++)
	{
		int a;
		cin>>a;
		push(a);
	}
	/*pop();
	pop();*/
	cout<<top();
	cout<<mint();
	return 0;
}	