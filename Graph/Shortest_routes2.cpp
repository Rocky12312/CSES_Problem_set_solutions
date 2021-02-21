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
const int sz = 5e2+5;
using namespace std;

struct queries_node{
	int a;
	int b;
};

void solve(int n,int q,ll arr[][sz],bool vertex_present[],queries_node q_arr[]){
	ll dummy_arr[sz][sz];
	for(int i=0;i<sz;i++){
		for(int j=0;j<sz;j++){
			dummy_arr[i][j] = arr[i][j];
		}
	}
	for(int k=0;k<sz;k++){
		if(vertex_present[k]==true){
			for(int i=0;i<sz;i++){
				for(int j=0;j<sz;j++){
					if(dummy_arr[i][k]==llmax || dummy_arr[k][j]==llmax){
						continue;
					}else if(dummy_arr[i][k]+dummy_arr[k][j]<dummy_arr[i][j]){
						dummy_arr[i][j] = dummy_arr[i][k]+dummy_arr[k][j];
					}
				}
			}
		}
	}
	queries_node temp_q;
	for(int i=0;i<q;i++){
		temp_q = q_arr[i];
		if(dummy_arr[temp_q.a][temp_q.b]!=llmax){
			cout<<dummy_arr[temp_q.a][temp_q.b]<<endl;
		}else{
			cout<<-1<<endl;
		}
	}
	return;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,m,q;
  cin>>n>>m>>q;
  ll arr[sz][sz];
  bool vertex_present[sz];
  for(int i=0;i<sz;i++){
  	for(int j=0;j<sz;j++){
  		arr[i][j] = llmax;
  	}
  }
  int to,from,dis;
  for(int i=0;i<m;i++){
  	cin>>to>>from>>dis;
  	if(arr[to][from]==llmax){
  		arr[to][from] = dis;
  	}
  	if(arr[from][to]==llmax){
  		arr[from][to] = dis;
  	}
  	vertex_present[to] = true;
  	vertex_present[from] = true;
  }
  queries_node q_arr[q];
  queries_node temp;
  for(int i=0;i<q;i++){
  	cin>>temp.a>>temp.b;
  	q_arr[i] = temp;
  }
  solve(n,q,arr,vertex_present,q_arr);
  return 0;
}