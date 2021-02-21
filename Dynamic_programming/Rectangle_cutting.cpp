#include<iostream>
#include<algorithm>
#include<vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define Mod 1000000007
#define not_taken 9999999
using namespace std;

int solve(int a,int b,int nx[][505]){
    if(nx[a][b]!=-1){
        return nx[a][b];
    }
    if(a<=0 || b<=0){
        return not_taken;
    }
    int min_val = 99999999;
    for(int i=1;i<a;i++){
        int left = solve(i,b,nx);
        int right = solve(a-i,b,nx);
        min_val = min(min_val,(1+left+right));
    }
    for(int i=1;i<b;i++){
        int left = solve(a,i,nx);
        int right = solve(a,b-i,nx);
        min_val = min(min_val,(1+left+right));
    }
    return nx[a][b] = min_val;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b;
    cin>>a>>b;
    int nx[505][505];
    for(int i=0;i<505;i++){
        for(int j=0;j<505;j++){
            if(i==j){
                nx[i][j] = 0;
            }else{
                nx[i][j] = -1;
            }
        }
    }
    int res = solve(a,b,nx);
    cout<<res<<endl;
    return 0;
}