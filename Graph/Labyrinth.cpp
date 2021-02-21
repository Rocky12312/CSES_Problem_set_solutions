//DFS approach
/*#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
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
const int sz = 1005;
using namespace std;

void solve_helper(int n,int m,int a_i,int a_j,char arr[][sz],int& min_length,string& temp,string& final){
	if(a_i<0 || a_i>=n || a_j<0 || a_j>=m || arr[a_i][a_j]=='#' || arr[a_i][a_j]=='@'){
		return;
	}
	if(arr[a_i][a_j]=='B'){
		if(temp.length()<min_length){
			min_length = temp.length();
			final = temp;
		}
		return;
	}
	char c = arr[a_i][a_j];
	arr[a_i][a_j] = '#';
	temp.push_back('U');
	solve_helper(n,m,a_i-1,a_j,arr,min_length,temp,final);
	temp.pop_back();
	temp.push_back('R');
	solve_helper(n,m,a_i,a_j+1,arr,min_length,temp,final);
	temp.pop_back();
	temp.push_back('D');
	solve_helper(n,m,a_i+1,a_j,arr,min_length,temp,final);
	temp.pop_back();
	temp.push_back('L');
	solve_helper(n,m,a_i,a_j-1,arr,min_length,temp,final);
	temp.pop_back();
	arr[a_i][a_j] = c; 
	return;
}

void solve(int n,int m,char arr[][sz],int a_i,int a_j){
	int min_length = INT_MAX;
	string temp = "";
	string final = "";
	solve_helper(n,m,a_i,a_j,arr,min_length,temp,final);
	if(final.length()==0){
		cout<<"NO"<<endl;
		return;
	}
	cout<<"YES"<<endl;
	cout<<min_length<<endl;
	cout<<final<<endl;
	return;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,m;
  cin>>n>>m;
  char arr[sz][sz];
  for(int i=0;i<sz;i++){
  	for(int j=0;j<sz;j++){
  		arr[i][j] = '@';
  	}
  }
  int a_i = -1;
  int a_j = -1;
  for(int i=0;i<n;i++){
  	string s;
  	cin>>s;
  	for(int j=0;j<m;j++){
  		arr[i][j] = s[j];
  		if(s[j]=='A'){
  			a_i = i;
  			a_j = j;
  		}
  	}
  }
  solve(n,m,arr,a_i,a_j);
  return 0;
}*/

//BFS Approach
#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pii pair<int,int>
const int nax = 1e3+10;
bool vis[nax][nax];
char last[nax][nax];
int sx , sy , ex, ey , n , m ;
 
bool valid( int x,int y ){
	if(x>=0 && y>=0 && x<n && y<m && !vis[x][y]){
		return 1;
	}
    return 0;
}
void solve(){
	vis[sx][sy] = 1;
    queue< pii > q;
    q.push({sx,sy});
    while(!q.empty()){
        pii p = q.front();
        q.pop();
        int x = p.ff;
        int y = p.ss;
        if(x==ex && y==ey){
        	string s;
            cout << "YES\n";
            while( x!=sx || y!=sy ){
            	s += last[x][y];
                if(last[x][y] == 'U'){
                	x++;
                }
                else if(last[x][y] == 'D'){
                	x--;
                }
                else if(last[x][y] == 'L'){
                	y++;
                }
                else{
                	y--;
                }
            }
            reverse(s.begin(),s.end());
            cout << s.size() << "\n" << s;
            exit(0);
        }
        if(valid(x-1,y)){
        	vis[x-1][y] = 1;
    	    last[x-1][y] = 'U';
    	    q.push({x-1,y});
    	}
        if(valid(x+1,y)){
        	vis[x+1][y] = 1;
    	    last[x+1][y] = 'D';
    	    q.push({x+1,y});
    	}if(valid( x,y-1)){
    		vis[x][y-1] = 1;
    	    last[x][y-1] = 'L';
    	    q.push({x,y-1});
    	}
        if(valid(x,y+1)){
        	vis[x][y+1] = 1;
    	    last[x][y+1] = 'R';
    	    q.push({x,y+1});
    	}
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 0 ; i < n  ; i++ ){
        string s;
        cin >> s;
        for(int j=0; j < m ; j++ ){
            if(s[j] == 'A'){
            	sx = i;
            	sy = j;
            }
            else if(s[j] == 'B'){
            	ex = i;
            	ey = j;
            }
            else if(s[j] == '#'){
            	vis[i][j] = 1;
            }
        }
    }
    solve();
    cout <<"NO"<<endl;
}

