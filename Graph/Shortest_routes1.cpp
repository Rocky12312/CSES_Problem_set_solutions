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
const int sz = 100005;
using namespace std;

int find_min_vertex(int n,int s_distance[],bool vertex_chosen[],bool vertex_present[]){
	int min_vertex_idx = -1;
	int smallest_val = INT_MAX;
	for(int idx=1;idx<sz;idx++){
		if(vertex_present[idx]==true && s_distance[idx]<smallest_val && vertex_chosen[idx]==false){
			smallest_val = s_distance[idx];
			min_vertex_idx = idx;
		}
	}
	return min_vertex_idx;
}

void solve(int src,int n,int m,vector<vector<int>>& arr,bool vertex_present[]){
	int vertices_count = 0;
	for(int i=0;i<sz;i++){
		if(vertex_present[i]==true){
			vertices_count++;
		}
	}
	bool vertex_chosen[sz];
	int s_distance[sz];
	for(int i=0;i<sz;i++){
		if(vertex_present[i]==true){
			vertex_chosen[i] = false;
			s_distance[i] = INT_MAX;
		}
	}
	s_distance[src] = 0;
	for(int i=0;i<vertices_count-1;i++){
		int v_selected = find_min_vertex(n,s_distance,vertex_chosen,vertex_present);
		vertex_chosen[v_selected] = true;
		for(int j=0;j<sz;j++){
			if(arr[v_selected][j]!=-1 && vertex_present[j]==true && vertex_chosen[j]==false && s_distance[v_selected]!=INT_MAX && (s_distance[v_selected]+arr[v_selected][j]<s_distance[j])){
				s_distance[j] = s_distance[v_selected]+arr[v_selected][j];
			}
		}
	}
	for(int i=1;i<sz;i++){
		if(vertex_present[i]==true){
			cout<<s_distance[i]<<" ";
		}
	}
	cout<<endl;
	return;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,m;
  cin>>n>>m;
  //int arr[sz][sz];
  vector<vector<int>> arr(sz,vector<int>(sz,-1));
  bool vertex_present[sz];
  for(int i=0;i<sz;i++){
  	vertex_present[i] = false;
  }
  /*for(int i=0;i<sz;i++){
  	vertex_present[i] = false;
  	for(int j=0;j<sz;j++){
  		arr[i][j] = -1;
  	}
  }*/
  int to,from,dis;
  for(int i=0;i<m;i++){
  	cin>>to>>from>>dis;
  	if(arr[to][from]==-1){
  		arr[to][from] = dis;
  	    vertex_present[to] = true;
  	    vertex_present[from] = true;
  	}
  }
  int src = 1;
  solve(src,n,m,arr,vertex_present);
  return 0;
}
