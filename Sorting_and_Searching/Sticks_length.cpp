#include<iostream>
#include<algorithm>
#include<unordered_map>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define Mod 1000000007
#define not_taken -9999999
using namespace std;

void solve(ll n,ll arr[]){
	sort(arr,arr+n);
	ll mid = (0+n)/2;
	ll sum = 0;
	for(int i=0;i<n;i++){
		sum = sum+abs(arr[mid]-arr[i]);
	}
	cout<<sum<<endl;
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