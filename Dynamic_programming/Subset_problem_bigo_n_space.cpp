//Duplicates allowed
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

void solve(ll n,ll k,ll arr[]){
	if(n==0){
		cout<<"Subset not found"<<endl;
	}
	bool nx[k+1];
	for(int i=0;i<k+1;i++){
		nx[i] = false;
	}
	nx[0] = true;
	for(int i=1;i<k+1;i++){
		for(int j=0;j<n;j++){
			if(i>=arr[j]){
				nx[i] = nx[i] || nx[i-arr[j]];
			}
		}
	}
	if(nx[k]){
		cout<<"Subset exist"<<endl;
		return;
	}
	cout<<"No subset exist"<<endl;
	return;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll n,k;
  cin>>n>>k;
  ll arr[n];
  for(int i=0;i<n;i++){
  	cin>>arr[i];
  }
  solve(n,k,arr);
  return 0;
}
