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

void solve(ll x){
	unordered_map<int,int> um;
	while(x%2==0){
		x = x/2;
		um[2]++;
	}
	for(ll i=3;i*i<=x;i=i+2){
		while(x%i==0){
			x = x/i;
			um[i]++;
		}
	}
	if(x>2){
		um[x]++;
	}
	ll num_of_divisors=1;
	for(auto i=um.begin();i!=um.end();i++){
		num_of_divisors = num_of_divisors*(i->second+1);
	}
	cout<<num_of_divisors<<endl;
	return;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n;
  cin>>n;
  ll x;
  while(n--){
  	cin>>x;
  	solve(x);
  }
  return 0;
}
