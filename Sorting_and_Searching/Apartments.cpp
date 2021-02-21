#include<iostream>
#include<algorithm>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define Mod 1000000007
#define not_taken -9999999
using namespace std;

void solve(int n,int m,int k,int peoples_arr[],int apartment_arr[]){
    int count = 0;
    sort(apartment_arr,apartment_arr+m);
    sort(peoples_arr,peoples_arr+n);
    int i = 0;
    int j = 0;
    while(i<n && j<m){
        if(peoples_arr[i]+k<apartment_arr[j]){
            i++;
        }else if(peoples_arr[i]-k>apartment_arr[j]){
            j++;
        }else{
            i++;
            j++;
            count++;
        }
    }
    cout<<count<<endl;
    return;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,k;
    cin>>n>>m>>k;
    int peoples_arr[n];
    int apartment_arr[m];
    for(int i=0;i<n;i++){
        cin>>peoples_arr[i];
    }
    for(int i=0;i<m;i++){
        cin>>apartment_arr[i];
    }
    solve(n,m,k,peoples_arr,apartment_arr);
    return 0;
}