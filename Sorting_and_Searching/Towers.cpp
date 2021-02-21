#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define Mod 1000000007
#define not_taken -9999999
using namespace std;

void solve(ll n,ll arr[]){
	priority_queue<ll,vector<ll>,greater<ll>> pq;
	multiset<ll> s;
	pq.push(arr[0]);
	ll no_of_towers = 1;
	for(ll i=1;i<n;i++){
		if(pq.top()<=arr[i]){
			if(s.size() == 0){
				s.insert(arr[i]);
				no_of_towers++;
			}else{
				auto j = s.upper_bound(arr[i]);
				if(j!=s.end() && *j>arr[i]){
					s.erase(j);
					s.insert(arr[i]);
				}else if(j==s.end()){
					s.insert(arr[i]);
					no_of_towers++;
				}
			}
		}else{
			pq.push(arr[i]);
		}
	}
	cout<<no_of_towers<<endl;
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    ll arr[n];
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    }
    solve(n,arr);
    return 0;
}