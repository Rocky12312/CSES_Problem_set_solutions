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
#define llmin -9223372036854775806
#define llmax 9223372036854775807
#define ullmax 18446744073709551615 
using namespace std;

void generate_sgtree(ll start,ll end,ll n,ll idx,ll arr[],ll sg_tree[]){
	if(start>end){
		return;
	}
	if(start==end){
		sg_tree[idx] = arr[start];
		return;
	}
	ll mid = (start+end)/2;
	generate_sgtree(start,mid,n,2*idx,arr,sg_tree);
	generate_sgtree(mid+1,end,n,2*idx+1,arr,sg_tree);
	sg_tree[idx] = max(sg_tree[2*idx],sg_tree[2*idx+1]);
	return;
}

ll query_tree(ll s_que,ll e_que,ll start,ll end,ll idx,ll sg_tree[]){
	if(s_que>end || e_que<start){
		return llmin;
	}
	if(s_que<=start && e_que>=end){
		return sg_tree[idx];
	}
	ll mid = (start+end)/2;
	ll left = query_tree(s_que,e_que,start,mid,2*idx,sg_tree);
	ll right = query_tree(s_que,e_que,mid+1,end,2*idx+1,sg_tree);
	return max(left,right);
}

void solve(ll n,ll q,ll arr[],ll q_arr[]){
	ll sg_tree[4*n+1];
	generate_sgtree(0,n-1,n,1,arr,sg_tree);
	for(ll i=0;i<q;i++){
		ll res = query_tree(q_arr[i]-1,n-1,0,n-1,1,sg_tree);
		cout<<res<<endl;
	}
	return;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin>>t;
  while(t--){
  	ll n;
  	cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++){
    	cin>>arr[i];
    }
    ll q;
    cin>>q;
    ll q_arr[q];
    for(int i=0;i<q;i++){
  	  cin>>q_arr[i];
    }
    solve(n,q,arr,q_arr);
   }
  return 0;
}
