#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define Mod 1000000007
#define not_taken -9999999
using namespace std;

struct node{
	ll a;
	ll b;
};

void solve(ll n,node arr[]){
	
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    node arr[n];
    node temp;
    for(int i=0;i<n;i++){
    	cin>>temp.a;
    	cin>>temp.b;
    	arr[i] = temp;
    }
    solve(n,arr);
    return 0;
}