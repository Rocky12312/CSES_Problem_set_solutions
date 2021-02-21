#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_map>
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

void solve_helper(int idx,vector<vector<int>>& v,int parent[],int node_parent,bool visited[]){
	visited[idx] = true;
	parent[idx] = node_parent;
	for(auto j:v[idx]){
		if(visited[j]==false){
			solve_helper(j,v,parent,idx,visited);
		}else if(visited[j]==true && j!=node_parent){
			vector<int> round_path;
			int curr = idx;
			round_path.push_back(curr);
			while(parent[curr]!=j){
				curr = parent[curr];
				round_path.push_back(curr);
			}
			round_path.push_back(j);
			round_path.push_back(idx);
			cout<<round_path.size()<<endl;
			for(auto k:round_path){
				cout<<k<<" ";
			}
			cout<<endl;
			exit(0);
		}
	}
	return;
}

void solve(int n,vector<vector<int>>& v){
	int parent[n+1];
	bool visited[n+1];
	for(int i=0;i<n+1;i++){
		visited[i] = false;
		parent[i] = -1;
	}
	for(int i=1;i<n+1;i++){
		int node_parent = -1;
		if(visited[i]==false){
			solve_helper(i,v,parent,node_parent,visited);
		}
	}
	cout<<"IMPOSSIBLE"<<endl;
	return;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,m;
  cin>>n>>m;
  vector<vector<int>> v(n+1);
  int to;
  int from;
  for(int i=0;i<m;i++){
  	cin>>to>>from;
  	v[to].push_back(from);
  	v[from].push_back(to);
  }
  solve(n,v);
  return 0;
}
