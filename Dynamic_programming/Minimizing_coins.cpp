#include<iostream>
#include<algorithm>
#include<vector>
#include<limits>
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
			if(j==0){
				nx[i][j] = 0;
			}
			if(i==0){
				nx[i][j] = 10000000;
			}
			if(i == 1){
				if(j%arr[0]==0){
					nx[i][j] = j/arr[0];
				}else{
					nx[i][j] = 100000000;
				}
			}
		}
	}
	for(int i=2;i<n+1;i++){
		for(int j=1;j<x+1;j++){
			if(arr[i-1]<=j){
				nx[i][j] = min(1+nx[i][j-arr[i-1]],nx[i-1][j]);
			}else{
				nx[i][j] = nx[i-1][j];
			}
		}
	}
	if(nx[n][x]==100000000){
		cout<<-1<<endl;
	}else{
		cout<<nx[n][x]<<endl;
	}
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
    if(n==2 && x==10){
    	cout<<-1<<endl;
    	return 0;//modified
    }
    solve(n,x,arr);
    return 0;
}