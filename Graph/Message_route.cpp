#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
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

void solve(int n,int m,vector<vector<int>>& v,vector<int>& parent){
	int src = 1;
	int des = n;
	queue<int> q;
	q.push(src);
	parent[src] = -1;
	while(q.empty()==false){
		int t = q.front();
		q.pop();
		if(t==des){
			vector<int> vs;
			while(parent[t]!=-1){
				vs.push_back(t);
				t = parent[t];
			}
			vs.push_back(src);
			reverse(vs.begin(),vs.end());
			cout<<vs.size()<<endl;
			for(int idx=0;idx<vs.size();idx++){
				cout<<vs[idx]<<" ";
			}cout<<endl;
			exit(0);
		}
		for(auto& i:v[t]){
			if(parent[i]==0){
				q.push(i);
				parent[i] = t;
			}
		}
	}
	return;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,m;
  cin>>n>>m;
  vector<vector<int>> v(n+1);
  vector<int> parent(n+1,0);
  int to;
  int from;
  for(int i=0;i<m;i++){
  	cin>>to;
  	cin>>from;
  	v[to].push_back(from);
  	v[from].push_back(to);
  }
  solve(n,m,v,parent);
  cout<<"IMPOSSIBLE"<<endl;
  return 0;
}

