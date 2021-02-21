#include<iostream>
#include<algorithm>
#include<vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define Mod 1000000007
#define not_taken 9999999
#define INT_MAX +2147483647
#define INT_MIN -2147483648
#define lmax 9223372036854775
using namespace std;
const int p = 5005;

ll nx[p][p];

ll solve(ll start,ll end,ll arr[]){
  if(start>end){
    return lmax;
  }
  if(nx[start][end]!=-1){
    return nx[start][end];
  }
  if(start==end){
    return arr[start];
  }
  if(end-start==1){
    return max(arr[start],arr[end]);
  }
  ll f1_play = arr[start]+min(solve(start+2,end,arr),solve(start+1,end-1,arr));
  ll f2_play = arr[end]+min(solve(start+1,end-1,arr),solve(start,end-2,arr));
  return nx[start][end] = max(f1_play,f2_play);
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
  for(ll i=0;i<5005;i++){
    for(ll j=0;j<5005;j++){
      nx[i][j] = -1;
    }
  }
  ll res = solve(0,n-1,arr);
  cout<<res<<endl;
  return 0;
}