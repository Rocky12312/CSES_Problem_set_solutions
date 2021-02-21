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

void solve(ll n,ll arr[],ll k){
	bool nx[n+1][k+1];
	for(int i=0;i<n+1;i++){
		nx[i][0] = 1;
	}
	for(int i=0;i<k+1;i++){
		nx[0][i] = 0;
	}
	for(int i=1;i<n+1;i++){
		for(int j=1;j<k+1;j++){
			if(arr[i-1]<=j){
				nx[i][j] = nx[i-1][j-arr[i-1]] || nx[i-1][j];
			}else{
				nx[i][j] = nx[i-1][j];
			}
		}
	}
	if(nx[n][k]){
		cout<<"Subset exist"<<endl;
		return;
	}
	cout<<"No subset exist"<<endl;
	return;
}

/*void solve_recursive(ll idx,ll n,ll arr[],ll k){
	if(idx>n){
		return;
	}
	if(k==0){
		cout<<"Yes present"<<endl;
		exit(0);
	}

	if(arr[idx]>k){
		solve(idx+1,n,arr,k);
	}else{
		solve(idx+1,n,arr,k);
		solve(idx+1,n,arr,k-arr[idx]);
	}
	return;
}*/

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll n;cin>>n;
  ll k;cin>>k;
  ll arr[n];
  for(int i=0;i<n;i++){
  	cin>>arr[i];
  }
  //solve_recursive(0,n,arr,k);
  solve(n,arr,k);
  return 0;
}
