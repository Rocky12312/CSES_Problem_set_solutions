#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cmath>
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
	ll nx[n];
	for(int i=0;i<n;i++){
		nx[i] = arr[i];
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<=sqrt(i+1);j++){
			if((i+1)%j==0 && nx[j-1]+arr[i]>nx[i]){
				nx[i] = nx[j-1]+arr[i];
			}
		}
	}
	for(int i=0;i<n;i++){
		cout<<nx[i]<<endl;
	}
	return;
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
