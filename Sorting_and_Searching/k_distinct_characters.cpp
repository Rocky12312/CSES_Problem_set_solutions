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
 
void solve(int n,int k,ll arr[]){
	if(k==1){
		cout<<n<<endl;
		return;
	}
	unordered_map<ll,ll> um;
	int i=0,j=0;
	ll sbarrs = 0;
	while(j<n){
		um[arr[j]]++;
		if(um.size()<=k){
			sbarrs += j-i+1;
			j++;
		}else{
			while(um.size()>k){
				um[arr[i]]--;
				if(um[arr[i]]==0){
					um.erase(arr[i]);
				}
				i++;
			}
			if(um.size()==k){
				sbarrs += j-i+1;
			}
			j++;
		}
		if(j==n && um.size()<=k){
			break;
		}
	}
	cout<<sbarrs<<endl;
	return;
}
 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,k;
  cin>>n>>k;
  ll arr[n];
  for(int i=0;i<n;i++){
  	cin>>arr[i];
  }
  solve(n,k,arr);
  return 0;
}
