#include<bits/stdc++.h>
using namespace std;

void fillleft(vector<int>&hist, vector<int>&left) {
  stack<int>st;
  int extreme = -1;

  for (int i = 0; i < hist.size(); i++) {
    if (st.empty()) {
      left.push_back(extreme);
    }
    else if (hist[st.top()] < hist[i]) {
      left.push_back(st.top());
    }
    else {
      while (!st.empty() && hist[st.top()] >= hist[i]) {
        st.pop();
      }

      if (st.empty()) {
        left.push_back(extreme);
      }
      else {
        left.push_back(st.top());
      }
    }
    st.push(i);
  }

}

void fillright(vector<int>&hist, vector<int>&right) {
  stack<int>st;
  int extreme = hist.size();

  for (int i = hist.size() - 1; i >= 0; i--) {
    if (st.empty()) {
      right.push_back(extreme);
    }
    else if (hist[st.top()] < hist[i]) {
      right.push_back(st.top());
    }
    else {
      while (!st.empty() && hist[st.top()] >= hist[i]) {
        st.pop();
      }

      if (st.empty()) {
        right.push_back(extreme);
      }
      else {
        right.push_back(st.top());
      }
    }
    st.push(i);
  }
  reverse(right.begin(), right.end());

}
int MAH(vector<int>&hist)
{
  vector<int>left;
  vector<int>right;
  vector<int>area;
  fillleft(hist, left);
  fillright(hist, right);

  for (int i = 0; i < hist.size(); i++) {

    int width = right[i] - left[i] - 1;
    int answer = hist[i] * width;

    area.push_back(answer);
  }

  return *max_element(area.begin(), area.end());

}
int MARBM(vector<vector<int>>&v, int n ,int m)
{
  vector<int>vec;
  vector<int>hist(m);
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(v[i][j]==0){
        hist[i]=0;
      }
      else{
        hist[i]=hist[i]+v[i][j];
      }
    }
    vec.push_back(MAH(hist));
  }
  return *max_element(vec.begin(),vec.end());

}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

#ifndef ONLINE_JUDGE
  // for getting input from input.txt
  freopen("input.txt", "r", stdin);
  // for writing output to output.txt
  freopen("output.txt", "w", stdout);
#endif
 

  int n,m;
  cin >> n;
  cin >> m;

  vector<vector<int>> v(n,vector<int>(m));


  for (int i=0 ;i<n ;i++){
    for(int j=0 ;j<m ;j++){
      cin>>v[i][j];
      cout<<endl;
    }
  }
  int max = MARBM(v , n , m);
  cout << max;

  return 0;
}