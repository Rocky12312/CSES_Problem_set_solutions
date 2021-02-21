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

void solve(int n,ll arr[]){
	int nx[n];
	for(int i=0;i<n;i++){
		nx[i] = arr[i];
	}
	nx[0] = arr[0];
	nx[1] = max(arr[0],arr[1]);
	for(int i=2;i<n;i++){
		nx[i] = max(nx[i]+nx[i-2],nx[i-1]);
	}
	int max_val_stolen = INT_MIN;
	for(int i=0;i<n;i++){
		max_val_stolen = max(max_val_stolen,nx[i]);
	}
	cout<<max_val_stolen<<endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;cin>>n;
  ll arr[n];
  for(int i=0;i<n;i++){
  	cin>>arr[i];
  }
  solve(n,arr);
  return 0;
}

