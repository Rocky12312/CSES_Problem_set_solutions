#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define Mod 1000000007
#define INT_MAX +2147483647
#define INT_MIN -2147483648
#define ulmax 4294967295
#define llmin -9223372036854775808
#define llmax 9223372036854775807
#define ullmax 18446744073709551615 
using namespace std;

void solve_helper(int idx,int n,int m,vector<vector<int>>& v,vector<bool>& visited){
	visited[idx] = 1;
	for(int j=0;j<v[idx].size();j++){
		if(visited[v[idx][j]]==0){
			solve_helper(v[idx][j],n,m,v,visited);
		}
	}
}

void solve(int n,int m,vector<vector<int>>& v,vector<bool>& visited){
	vector<int> res;
	for(int i=1;i<=n;i++){
		if(visited[i]==0){
			res.push_back(i);
			solve_helper(i,n,m,v,visited);
		}
	}
	cout<<res.size()-1<<endl;
	for(int i=1;i<res.size();i++){
		cout<<res[i-1]<<" "<<res[i]<<endl;
	}
	return;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,m;
  cin>>n>>m;
  vector<vector<int>> v(n+1);
  vector<bool> visited(n+1,0);
  int to;
  int from;
  for(int i=0;i<m;i++){
  	cin>>to>>from;
  	v[to].push_back(from);
  	v[from].push_back(to);
  }
  solve(n,m,v,visited);
  return 0;
}
