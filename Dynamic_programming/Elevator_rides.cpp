#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define Mod 1000000007
#define not_taken 9999999
using namespace std;

void solve(ll n,ll x,ll arr[]){
	sort(arr,arr+n);
	ll sum = 0;
	for(ll i=0;i<n;i++){
		sum = sum+arr[i];
	}
	ll rides=(sum/x)+((sum%x)!=0);
	cout<<rides<<endl;
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,x;
    cin>>n>>x;
    ll arr[n];
    for(ll i=0;i<n;i++){
    	cin>>arr[i];
    }
    solve(n,x,arr);
    return 0;
}