#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
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
const int sz =1e3;

ll solve(int count,int i,int j,ll arr[],ll nx[][sz]){
	if(nx[i][j]!=-1){
		return nx[i][j];
	}
	if(i>j){
		return 0;
	}
	if(i==j){
		return nx[i][j] = arr[i]*count;
	}
	ll left = solve(count+1,i+1,j,arr,nx)+arr[i]*count;
	ll right = solve(count+1,i,j-1,arr,nx)+arr[j]*count;
	return nx[i][j] = max(left,right);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;cin>>n;
  ll arr[n];
  for(int i=0;i<n;i++){
  	cin>>arr[i];
  }
  ll nx[sz][sz];
  memset(nx,-1,sizeof(nx));
  ll res = solve(1,0,n-1,arr,nx);
  cout<<res<<endl;
  return 0;
}

