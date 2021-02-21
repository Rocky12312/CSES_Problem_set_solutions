#include<iostream>
#include<algorithm>
#include<vector>
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
	int pre_nx[n];
	memset(pre_nx,0,sizeof(pre_nx));
	pre_nx[0] = 1;
	for(int i=1;i<n;i++){
		pre_nx[i] = 1;
		for(int j=0;j<i;j++){
			if(abs(arr[i]-arr[j])<=1 && pre_nx[j]+1>pre_nx[i]){
				pre_nx[i] = pre_nx[j]+1;
			}
		}
	}
	int max_len = INT_MIN;
	for(int i=0;i<n;i++){
		max_len = max(max_len,pre_nx[i]);
	}
	cout<<max_len<<endl;
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
