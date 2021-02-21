#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int max_sum = n*1000;
  vector<int> x(n);
  for (int&v : x) cin >> v;
  vector<vector<bool>> dp(n+1,vector<bool>(max_sum+1,false));
  dp[0][0] = true;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= max_sum; j++) {
      dp[i][j] = dp[i-1][j];
      int left = j-x[i-1];
      if (left >= 0 && dp[i-1][left]) {
  dp[i][j] = true;
      }
    }
  }

  vector<int> possible;
  for (int j = 1; j <= max_sum; j++) {
    if (dp[n][j]) {
      possible.push_back(j);
    }
  }
  cout << possible.size() << endl;
  for (int v : possible) {
    cout << v << ' ';
  }
  cout << endl;
}
/*#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define Mod 1000000007
#define not_taken 9999999
using namespace std;
 
void solve(vector<int> v,int& count,int pos,int sum,set<int>& vsum){
  if(pos>v.size()){
    return;
  }
  if(pos == v.size()){
    if(vsum.find(sum)==vsum.end()){
      vsum.insert(sum);
      count++;
    }
    return;
  }
  sum = sum+v[pos];
  solve(v,count,pos+1,sum,vsum);
  sum = sum-v[pos];
  solve(v,count,pos+1,sum,vsum);
  return;
}
 
int main(){
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> v;
    int a;
    for(int i=0;i<n;i++){
      cin>>a;
      v.push_back(a);
    }
    sort(v.begin(),v.end());
    int pos = 0;
    int sum = 0;
    int count = 0;
    set<int> vsum;
    solve(v,count,pos,sum,vsum);
    vector<int> vsum_final;
    for(auto i=vsum.begin();i!=vsum.end();i++){
      vsum_final.push_back(*i);
    }
    cout<<count-1<<endl;
    for(int i=1;i<vsum_final.size();i++){
      cout<<vsum_final[i]<<" ";
    }cout<<endl;
    return 0;
}*/