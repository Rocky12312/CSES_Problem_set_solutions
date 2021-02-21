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
#define llmin -9223372036854775806
#define llmax 9223372036854775807
#define ullmax 18446744073709551615 
using namespace std;
const int sz = 3e2;

void solve(int n,int m,ll arr[][sz],bool vertices_present[]){
	ll arr_temp[sz][sz];
	for(int i=0;i<sz;i++){
		for(int j=0;j<sz;j++){
			arr_temp[i][j] = arr[i][j];
		}
	}
	for(int k=0;k<sz;k++){
		if(vertices_present[k]==true){
			for(int i=0;i<sz;i++){
				for(int j=0;j<sz;j++){
					if(vertices_present[i] && vertices_present[j]){
						if(arr[i][k]==llmin || arr[k][j]==llmin){
							continue;
						}else if(arr[i][k]+arr[k][j]>arr[i][j]){
							arr[i][j] = arr[i][k]+arr[k][j];
						}
					}
				}
			}
		}
	}
	cout<<arr[1][n]<<endl;
	return;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,m;
  cin>>n>>m;
  ll arr[sz][sz];
  for(int i=0;i<sz;i++){
  	for(int j=0;j<sz;j++){
  		arr[i][j] = llmin;
  	}
  }
  bool vertices_present[sz];
  int start,end;
  ll val_inc;
  for(int i=0;i<m;i++){
  	cin>>start>>end>>val_inc;
  	arr[start][end] = val_inc;
  	vertices_present[start] = true;
  	vertices_present[end] = true;
  }
  solve(n,m,arr,vertices_present);
  return 0;
}