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

struct query_node{
	int a;
	int b;
};

void solve(ll n,ll q,ll arr[],query_node q_arr[]){
	ll psum[n];
	psum[0] = arr[0];
	for(ll i=1;i<n;i++){
		psum[i] = psum[i-1]+arr[i];
	}
	for(int i=0;i<q;i++){
		ll res = psum[q_arr[i].b-1]-psum[q_arr[i].a-1]+arr[q_arr[i].a-1];
		cout<<res<<endl;
	}
	return;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n,q;
  cin>>n>>q;
  ll arr[n];
  for(ll i=0;i<n;i++){
  	cin>>arr[i];
  }
  query_node q_arr[q];
  query_node temp;
  for(int i=0;i<q;i++){
  	cin>>temp.a>>temp.b;
  	q_arr[i] = temp;
  }
  solve(n,q,arr,q_arr);
  return 0;
}
