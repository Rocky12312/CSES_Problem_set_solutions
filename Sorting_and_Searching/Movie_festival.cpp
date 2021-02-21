#include<iostream>
#include<algorithm>
#include<vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define Mod 1000000007
#define not_taken -9999999
using namespace std;

struct movies{
    int a;
    int b;
};

bool comp(movies m1,movies m2){
    return m1.b<m2.b;
}

void solve(int n,movies arr[]){
    if(n == 0){
        cout<<0<<endl;
        return;
    }
    int movies_can_watch = 1;
    sort(arr,arr+n,comp);
    movies temp = arr[0];
    int i = 1;
    while(i<n){
        if(arr[i].a>=temp.b){
            movies_can_watch++;
            temp = arr[i];
            i++;
        }else{
            i++;
        }
    }
    cout<<movies_can_watch<<endl;
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    movies arr[n];
    movies temp;
    for(int i=0;i<n;i++){
        cin>>temp.a;
        cin>>temp.b;
        arr[i] = temp;
    }
    solve(n,arr);
    return 0;
}