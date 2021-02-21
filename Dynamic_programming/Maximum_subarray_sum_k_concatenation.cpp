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

void solve(int n,int k,ll arr[]){
	ll max_ending_here = arr[0];
	ll max_so_far = arr[0];
	for(int i=1;i<n*k;i++){
		if(max_ending_here+arr[i%k]>max_ending_here){
			max_ending_here = max_ending_here+arr[i%k];
		}else{
			max_ending_here = arr[i%k];
		}
		if(max_so_far<max_ending_here){
			max_so_far = max_ending_here;
		}
	}
	cout<<max_so_far<<endl;
	return;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;cin>>n;
  int k;cin>>k;
  ll arr[n];
  for(int i=0;i<n;i++){
  	cin>>arr[i];
  }
  solve(n,k,arr);
  return 0;
}
