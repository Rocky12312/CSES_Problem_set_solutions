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

ll solve(ll a,ll b,ll c){
	ll res_l1 = 1;
	while(c > 0){
		if(c&1){
			res_l1 = (res_l1*b)%llmax;
		}
		b = (b*b)%llmax;
		c = c>>1;
	}
  ll res_l2 = 1;
  while(res_l1 > 0){
    if(res_l1&1){
      res_l2 = (res_l2*a)%Mod;
    }
    a = (a*a)%Mod;
    res_l1 = res_l1>>1;
  }
  return res_l2;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n;
  cin>>n;
  ll a,b,c;
  while(n--){
  	cin>>a>>b>>c;
  	ll res = solve(a,b,c);
  	cout<<res<<endl;
  }
  return 0;
}
