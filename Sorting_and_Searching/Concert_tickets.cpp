#include<iostream>
#include<algorithm>
#include<set>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define Mod 1000000007
#define not_taken -9999999
using namespace std;

void solve(int n,int m,int p_arr[],int t_arr[]){
    multiset<int,greater<int>> ms;
    for(int i=0;i<n;i++){
        ms.insert(p_arr[i]);
    }
    for(int i=0;i<m;i++){
        int ps = t_arr[i];
        auto j = ms.lower_bound(ps);
        if(j==ms.end()){
            cout<<-1<<endl;
        }else{
            cout<<*j<<endl;
            ms.erase(j);
        }
    }
    return;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    int p_arr[n];
    int t_arr[m];
    for(int i=0;i<n;i++){
        cin>>p_arr[i];
    }
    for(int i=0;i<m;i++){
        cin>>t_arr[i];
    }
    solve(n,m,p_arr,t_arr);
    return 0;
}