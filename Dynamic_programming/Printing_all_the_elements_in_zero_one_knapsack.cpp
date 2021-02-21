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

void solve(int n,ll ks_cap,ll item_arr[],ll val_arr[]){
	ll nx[n+1][ks_cap+1];
	for(int i=0;i<n+1;i++){
		nx[i][0] = 0;
	}
	for(int i=0;i<ks_cap+1;i++){
		nx[0][i] = 0;
	}
	for(int i=1;i<n+1;i++){
		for(int j=1;j<ks_cap+1;j++){
			if(item_arr[i-1]<=j){
				nx[i][j] = max(val_arr[i-1]+nx[i-1][j-item_arr[i-1]],nx[i-1][j]);
			}else{
				nx[i][j] = nx[i-1][j];
			}
		}
	}
	cout<<nx[n][ks_cap]<<endl;
	//Printing the elements we have in knapsack when the value of knapsack items is maximum
	int ks_max_val = nx[n][ks_cap];
	int ks_mxallowable_wt = ks_cap;
	for(int i=n;i>0 && ks_max_val>0;i--){
		if(ks_max_val == nx[i-1][ks_mxallowable_wt]){
			continue;
		}else{
			cout<<item_arr[i-1]<<endl;
			ks_max_val = ks_max_val-val_arr[i-1];
			ks_mxallowable_wt = ks_mxallowable_wt-item_arr[i-1];
		}
	}
	return;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;cin>>n;
  ll ks_cap;cin>>ks_cap;
  ll item_arr[n];
  ll val_arr[n];
  for(int i=0;i<n;i++){
  	cin>>item_arr[i];
  }
  for(int i=0;i<n;i++){
  	cin>>val_arr[i];
  }
  solve(n,ks_cap,item_arr,val_arr);
  return 0;
}

