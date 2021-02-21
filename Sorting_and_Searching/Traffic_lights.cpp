#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define Mod 1000000007
#define not_taken -9999999
using namespace std;

void solve(ll x,ll n,ll arr[]){
	multiset<ll> ms;
	ms.insert(1);
	ms.insert(x);
	ll s_range_val = 1;
	ll e_range_val = x;
	ll prev_max_second = 0;
	for(ll i=0;i<n;i++){
		ll ele = arr[i];
		auto l=ms.lower_bound(ele);
		auto r=ms.upper_bound(ele);
		ll max_passage_val = 0;
		ll lval=0;
		ll rval=0;
		if(l!=ms.end()){
			lval = *l;
		}
		if(r!=ms.end()){
			rval = *r;
		}
		if(lval==a && rval==b){
			max_passage_val = max(prev_max_second,max(ele-lval,rval-ele));
			if(prev_max_second > max(ele-lval,rval-ele)){
				max_passage_val = prev_max_second;
			}
			if(abs(ele-lval) > abs(rval-ele)){
				a = lval;
				b = ele;
			}else{
				a = ele;
				b = rval;
			}
		}else{
			max_passage_val = b-a;
		}
		ms.insert(arr[i]);
		cout<<max_passage_val<<endl;
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll x,n;
    cin>>x>>n;
    ll arr[n];
    for(ll i=0;i<n;i++){
    	cin>>arr[i];
    }
    solve(x,n,arr);
    return 0;
}