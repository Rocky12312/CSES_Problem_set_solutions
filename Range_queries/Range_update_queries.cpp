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
	sg_tree[idx] = sg_tree[2*idx]+sg_tree[2*idx+1];
	return;
}

void query_tree_update(ll s_point,ll e_point,ll up_val,ll start,ll end,ll idx,ll sg_tree[]){
	if(e_point<start || s_point>end){
		return;
	}
	if(start==end){
		sg_tree[idx] = sg_tree[idx]+up_val;
		return;
	}
	ll mid = (start+end)/2;
	query_tree_update(s_point,e_point,up_val,start,mid,2*idx,sg_tree);
	query_tree_update(s_point,e_point,up_val,mid+1,end,2*idx+1,sg_tree);
	sg_tree[idx] = sg_tree[2*idx]+sg_tree[2*idx+1];
	return;
}

ll query_tree_sum(ll s_point,ll e_point,ll start,ll end,ll idx,ll sg_tree[]){
	if(s_point>end || e_point<start){
		return 0;
	}
	if(s_point<=start && e_point>=end){
		return sg_tree[idx];
	}
	ll mid = (start+end)/2;
	ll left = query_tree_sum(s_point,e_point,start,mid,2*idx,sg_tree);
	ll right = query_tree_sum(s_point,e_point,mid+1,end,2*idx+1,sg_tree);
	return left+right;
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
  ll sg_tree[4*n+1];
  generate_sgtree(0,n-1,n,1,arr,sg_tree);
  ll query_type = -1;
  for(ll i=0;i<q;i++){
  	cin>>query_type;
  	if(query_type == 1){
  		ll s_point,e_point,up_val;
  		cin>>s_point>>e_point>>up_val;
  		s_point = s_point-1;
  		e_point = e_point-1;
  		query_tree_update(s_point,e_point,up_val,0,n-1,1,sg_tree);
  	}else if(query_type == 2){
  		ll pos;
  		cin>>pos;
  		pos = pos-1;
  		ll p_sum_1e = query_tree_sum(pos-2,pos-1,0,n-1,1,sg_tree);
  		ll p_sum_1n = query_tree_sum(pos-2,pos,0,n-1,1,sg_tree);
  		ll res = p_sum_1n-p_sum_1e;
  		cout<<res<<endl;
  	}
  }
  return 0;
}
