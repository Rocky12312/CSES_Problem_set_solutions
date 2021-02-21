#include<iostream>
#include<algorithm>
#include<vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define Mod 1000000007
#define not_taken -9999999
using namespace std;

void solve(int n,int x,int price_arr[],int pages_arr[]){
	int nx[n+1][x+1];
	for(int i=0;i<n+1;i++){
		for(int j=0;j<x+1;j++){
			if(i==0 || j==0){
				nx[i][j] = 0;
			}
		}
	}
	for(int i=1;i<n+1;i++){
		for(int j=1;j<x+1;j++){
			if(price_arr[i-1]<=j){
				nx[i][j] = max(nx[i-1][j],pages_arr[i-1]+nx[i-1][j-price_arr[i-1]]);
			}else{
				nx[i][j] = nx[i-1][j];
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
    int price_arr[n];
    int pages_arr[n];
    for(int i=0;i<n;i++){
    	cin>>price_arr[i];
    }
    for(int i=0;i<n;i++){
    	cin>>pages_arr[i];
    }
    solve(n,x,price_arr,pages_arr);
    return 0;
}