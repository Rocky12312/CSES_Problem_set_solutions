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

ll custom_pow(ll a,ll b){
	ll res = 1;
	while(b>0){
		if(b&1){
			res = ((res%Mod)*(a%Mod))%Mod;
		}
		a = ((a%Mod)*(a%Mod))%Mod;
		b = b>>1;
	}
	return res;
}

void solve(int n,string s){
	if(n<s.length()){
		cout<<0<<endl;
		return;
	}
	int rem_pos = n-s.length();
	ll op = custom_pow(26,rem_pos);
	op = op;
	op = ((op)*(rem_pos+1))%Mod;
	op = op;
	cout<<op<<endl;
	return;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin>>n;
  string s;
  cin>>s;
  solve(n,s);
  return 0;
}
