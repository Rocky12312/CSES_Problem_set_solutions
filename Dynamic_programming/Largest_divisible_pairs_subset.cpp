//Question link -- https://www.geeksforgeeks.org/largest-divisible-pairs-subset/
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
	sort(arr,arr+n);
	ll nx[n];
	nx[n-1] = 1;
	for(int i=n-2;i>=0;i--){
		int mx = 0;
		for(int j=i+1;j<n;j++){
			if(arr[j]%arr[i]==0 || arr[i]%arr[j]==0){
				mx = max(mx,nx[j]);
			}
		}
		nx[i] = 1+mx;
	}
	int max_subset_len = 0;
	for(int i=0;i<n;i++){
		if(nx[i]>max_subset_len){
			max_subset_len = nx[i];
		}
	}
	cout<<max_subset_len<<endl;
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
