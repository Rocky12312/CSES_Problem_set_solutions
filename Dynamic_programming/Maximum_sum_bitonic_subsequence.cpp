#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
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
	ll inc_sum[n];
	ll dec_sum[n];
	for(int i=0;i<n;i++){
		inc_sum[i] = arr[i];
		dec_sum[i] = arr[i];
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(arr[j]<arr[i] && inc_sum[j]+arr[i]>inc_sum[i]){
				inc_sum[i] = inc_sum[j]+arr[i];
			}
		}
	}
	for(int i=n-2;i>=0;i--){
		for(int j=n-1;j>i;j--){
			if(arr[i]>arr[j] && dec_sum[j]+arr[i]>dec_sum[i]){
				dec_sum[i] = dec_sum[j]+arr[i];
			}
		}
	}
	int maximum_sum_bitonic_subsequence = INT_MIN;
	for(int i=0;i<n;i++){
		if(maximum_sum_bitonic_subsequence<inc_sum[i]+dec_sum[i]-arr[i]){
			maximum_sum_bitonic_subsequence = inc_sum[i]+dec_sum[i]-arr[i];
		}
	}
	cout<<maximum_sum_bitonic_subsequence<<endl;
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
