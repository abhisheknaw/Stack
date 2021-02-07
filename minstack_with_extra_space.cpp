#include <bits/stdc++.h>
using namespace std;
stack<int>s;
stack<int>ss;
void push(int a)
{
	s.push(a);
	if(ss.size()==0 || ss.top()>=a)
	{
		ss.push(a);
	}
	return;
}
void pop()
{
	if(s.empty())
	{
		return;
	}
	int a=s.top();
	s.pop();
	if(ss.top()==a)
	{
		ss.pop();
	}
}
int min()
{
	if(ss.size()==0)
	{
		return -1;
	}
	
	return ss.top();
	
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
	push(18);
	push(19);
	push(29);
	push(15);
	push(16);
	pop();
	pop();
	int a=min();
	cout<<a;
	return 0;
}	