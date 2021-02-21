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

//O(n^2)
/*void solve(int n,ll arr[]){
	int lis[n];
	memset(lis,0,sizeof(lis));
	lis[0] = 1;
	for(int i=1;i<n;i++){
		lis[i] = 1;
		for(int j=0;j<i;j++){
			if(arr[j]<arr[i] && lis[j]+1>lis[i]){
				lis[i] = lis[j]+1;
			}
		}
	}
	int max_inc_subs_len = 0;
	for(int i=0;i<n;i++){
		max_inc_subs_len = max(max_inc_subs_len,lis[i]);
	}
	cout<<max_inc_subs_len<<endl;
	return;
}*/

//O(nlogn)
void solve(int n,ll arr[]){
	vector<int> v;
	for(int i=0;i<n;i++){
		auto itr = lower_bound(v.begin(),v.end(),arr[i]);
		if(itr==v.end()){
			v.push_back(arr[i]);
		}else{
			*itr = arr[i];
		}
	}
	cout<<v.size()<<endl;
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
