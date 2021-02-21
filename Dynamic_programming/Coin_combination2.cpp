#include<iostream>
#include<algorithm>
#include<vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define Mod 1000000007
#define not_taken -9999999
using namespace std;

void solve(int n,int x,int arr[]){
	int nx[n+1][x+1];
	for(int i=0;i<n+1;i++){
		for(int j=0;j<x+1;j++){
			if(i==0){
				nx[i][j] = 0;
			}else if(j==0){
				nx[i][j] = 1;
			}
		}
	}
	for(int i=1;i<n+1;i++){
		for(int j=1;j<x+1;j++){
			if(arr[i-1]<=j){
				nx[i][j] = (nx[i][j-arr[i-1]]+nx[i-1][j]);
				nx[i][j] = nx[i][j]%Mod;
			}else{
				nx[i][j] = nx[i-1][j];
				nx[i][j] = nx[i][j]%Mod;
			}
		}
	}
	cout<<nx[n][x]<<endl;
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x;
    cin>>n>>x;
    int arr[n];
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    }
    solve(n,x,arr);
    return 0;
}