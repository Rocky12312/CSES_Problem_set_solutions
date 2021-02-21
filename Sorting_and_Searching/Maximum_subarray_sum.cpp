#include<iostream>
#include<unordered_map>
#include<algorithm>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define Mod 1000000007
#define not_taken -9999999
using namespace std;

void solve(ll n,ll arr[]){
	ll max_ending_here = arr[0];
	ll max_so_far = arr[0];
	for(ll i=1;i<n;i++){
		max_ending_here = max(max_ending_here+arr[i],arr[i]);
		max_so_far = max(max_so_far,max_ending_here);
	}
	cout<<max_so_far<<endl;
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++){
    	cin>>arr[i];
    }
    solve(n,arr);
    return 0;
}