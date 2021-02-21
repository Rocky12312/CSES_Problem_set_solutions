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
	sg_tree[idx] = min(sg_tree[2*idx],sg_tree[2*idx+1]);
	return;
}

ll query_tree(query_node temp,ll start,ll end,ll idx,ll sg_tree[]){
	if(temp.a>end || temp.b<start){
		return llmax;
	}
	if(temp.a<=start && temp.b>=end){
		return sg_tree[idx];
	}
	ll mid = (start+end)/2;
	ll left = query_tree(temp,start,mid,2*idx,sg_tree);
	ll right = query_tree(temp,mid+1,end,2*idx+1,sg_tree);
	return min(left,right);
}

void solve(ll n,ll q,ll arr[],query_node q_arr[]){
	ll sg_tree[4*n+1];
	generate_sgtree(0,n-1,n,1,arr,sg_tree);
	query_node temp;
	for(ll i=0;i<q;i++){
		temp = q_arr[i];
		temp.a = temp.a-1;
		temp.b = temp.b-1;
		ll res = query_tree(temp,0,n-1,1,sg_tree);
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
