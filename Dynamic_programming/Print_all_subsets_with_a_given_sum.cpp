//Question link -- https://www.geeksforgeeks.org/perfect-sum-problem-print-subsets-given-sum/
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

void solve(int idx,int n,ll k,ll arr[],vector<int>& temp){
	if(idx>n || k<0){
		return;
	}
	if(k==0){
		for(int i=0;i<temp.size();i++){
			cout<<temp[i]<<" ";
		}
		cout<<endl;
		return;
	}
	temp.push_back(arr[idx]);
	solve(idx+1,n,k-arr[idx],arr,temp);
	temp.pop_back();
	solve(idx+1,n,k,arr,temp);
	return;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;cin>>n;
  ll k;cin>>k;
  ll arr[n];
  for(int i=0;i<n;i++){
  	cin>>arr[i];
  }
  vector<int> temp;
  solve(0,n,k,arr,temp);
  return 0;
}
