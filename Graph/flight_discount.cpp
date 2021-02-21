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
const int sz = 105;
using namespace std;

int find_min_vertex(int n,ll s_distance[],bool vertex_chosen[],bool vertex_present[]){
	int min_vertex_idx = -1;
	ll smallest_val = llmax;
	for(int idx=0;idx<sz;idx++){
		if(vertex_present[idx]==true && s_distance[idx]<smallest_val && vertex_chosen[idx]==false){
			smallest_val = s_distance[idx];
			min_vertex_idx = idx;
		}
	}
	return min_vertex_idx;
}

void solve(int src,int n,int m,vector<vector<pair<ll,ll>>>& v,bool vertex_present[]){
	int vertices_count = 0;
	for(int i=0;i<sz;i++){
		if(vertex_present[i]==true){
			vertices_count++;
		}
	}
	bool vertex_chosen[sz];
	ll s_distance[sz];
	for(int i=0;i<sz;i++){
		vertex_chosen[i] = false;
		s_distance[i] = llmax;
	}
	s_distance[src] = 0;
	for(int i=0;i<vertices_count-1;i++){
		int v_selected = find_min_vertex(n,s_distance,vertex_chosen,vertex_present);
		vertex_chosen[v_selected] = true;
		for(int j=0;j<v[v_selected].size();j++){
			int to = v[v_selected][j].first;
			ll price = v[v_selected][j].second;
			if(vertex_present[to]==true && vertex_chosen[to]==false && s_distance[v_selected]!=llmax && (s_distance[v_selected]+price<s_distance[j])){
				s_distance[j]=s_distance[v_selected]+price;
			}
		}
	}
	for(int i=0;i<sz;i++){
		cout<<s_distance[i]<<endl;
	}
	cout<<s_distance[n]<<endl;
	return;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,m;
  cin>>n>>m;
  vector<vector<pair<ll,ll>>> v(sz);
  bool vertex_present[sz];
  for(int i=0;i<sz;i++){
  	vertex_present[i] = false;
  }
  int from,to;
  ll price;
  for(int i=0;i<m;i++){
  	cin>>from>>to>>price;
  	v[from].push_back({to,price});
  	vertex_present[from] = true;
  	vertex_present[to] = true;
  }
  int src = 1;
  solve(src,n,m,v,vertex_present);
  return 0;
}
