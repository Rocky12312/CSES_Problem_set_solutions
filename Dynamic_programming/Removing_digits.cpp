#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define Mod 1000000007
#define not_taken -99999999
using namespace std;
 
void solve(int n){
	int nx[n+1];
	for(int i=0;i<n+1;i++){
		nx[i] = 99999999;
	}
	nx[0] = 0;
	for(int i=0;i<n+1;i++){
		for(char c:to_string(i)){
			nx[i] = min(nx[i],1+nx[i-(c-'0')]);
		}
	}
	cout<<nx[n]<<endl;
	return;
}
 
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    solve(n);
    return 0;
}