#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define SIZE 200010
#define MOD 1000000007
#define BIG 998244353
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define mp make_pair
#define mii map<int,int>
#define set_bit __builtin_popcount
#define all(v) v.begin(),v.end()
#define PSET(x,y) fixed<<setprecision(y)<<x
#define pii pair<int,int>
#define vi vector<int>
#define vip vector<pair<int,int> >
#define MSET(table,i) memset(table, i, sizeof(table))
#define pi  3.1415926358
#define minimum(a,n) min_element(a,a+n)-a
#define maximum(a,n) max_element(a,a+n)-a
#define pqbig priority_queue<int>
#define pqsmall priority_queue<int,vector<int>,greater<int> >
#define all(v) v.begin(),v.end()
#define sitr set<int>:: iterator
#define mitr map<int,int>:: iterator
#define tc int tcs;cin>>tcs;while(tcs--)
int toint(const string &s) {stringstream ss; ss << s; int x; ss >> x; return x;}
string tostring ( int number ){stringstream ss; ss<< number; return ss.str();}

 
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl

int n; 
int mat[100][100]={};
bool valid(int i,int j){
	if(i>=n || i<0 || j>=n || j<0){
		return false;
	}else{
		return true;
	}
}
void solve(int i,int j,int mark){

	if(mat[i][j]!=0){
		return;
	}
	mat[i][j]=mark;


	if( valid(i+2,j+1) && mat[i+2][j+1]==0){
		//mat[i+2][j+1]=mark;
		solve(i+2,j+1,3-mark);
	}
	if( valid(i+2,j-1) && mat[i+2][j-1]==0){
		//mat[i+2][j-1]=mark;
		solve(i+2,j-1,3-mark);
	}
	if( valid(i+1,j+2) && mat[i+1][j+2]==0){
		//mat[i+1][j+2]=mark;
		solve(i+1,j+2,3-mark);
	}
	if( valid(i-1,j+2) && mat[i-1][j+2]==0){
		//mat[i-1][j+2]=mark;
		solve(i-1,j+2,3-mark);
	}
}

int main(){
	fast;
//	#ifndef ONLINE_JUDGE
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
//	#endif
	cin>>n;
	//mat[n/2][n/2]
	//solve(n/2,n/2,1);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(mat[i][j]==0){
				solve(i,j,1+(i+j)%2);
			}

			if(mat[i][j]==1){
				cout<<"W";
			}else{
				cout<<"B";
			}
		}
		cout<<endl;
	}


	return 0;
}