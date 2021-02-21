#include<iostream>
#include<unordered_map>
#include<algorithm>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define Mod 1000000007
#define not_taken -9999999
using namespace std;

void solve(ll n,ll x,ll arr[]){
	ll temp_arr[n];
	for(ll i=0;i<n;i++){
		temp_arr[i] = arr[i];
	}
	sort(temp_arr,temp_arr+n);
	if(temp_arr[0]+temp_arr[1]>1000000000){
		cout<<"IMPOSSIBLE"<<endl;
		return;
	}
	unordered_map<ll,ll> um;
	for(int i=0;i<n;i++){
		ll val = x-arr[i];
		if(um.find(val)!=um.end()){
			cout<<i+1<<" "<<um[val]+1<<endl;
			return;
		}
		um[arr[i]] = i;
	}
	cout<<"IMPOSSIBLE"<<endl;
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