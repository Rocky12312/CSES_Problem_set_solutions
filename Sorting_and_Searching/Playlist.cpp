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
    unordered_map<ll,ll> um;
    ll res = 0;
    ll i=0;
    ll j=0;
    while(j<n){
        if(um.find(arr[j])!=um.end()){
            um.erase(arr[i]);
            i++;
        }else{
            um[arr[j]]++;
            res = max(res,j-i+1); 
            j++;
        }
    }
    cout<<res<<endl;
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