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
int n,m;
bool ha[1000]={};
bool hb[1000]={};
pair<int,int> dsu[10000];
int size[10000];
	
int root(int a){
	while(dsu[a].ff!=a){
		a=dsu[a].ff;
	}
	return a;
}

void uni(int i,int j){
	int ra=root(i);
	int rb=root(j);
	dsu[ra].ff=rb;
	if(dsu[ra].ss || dsu[rb].ss){
		dsu[rb].ss=1;
	}

}

bool fin(int i,int j){
	int ra=root(i);
	int rb=root(j);
	if(ra!=rb){
		return true;
	}else{
		return false;
	}
}




int main(){
	fast;
//	#ifndef ONLINE_JUDGE
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
//	#endif
	
	cin>>n>>m;
	int b;
	int c;
	cin>>b;
	for(int i=0;i<b;i++){
		int x; cin>>x;
		ha[x]=1;
	}
	cin>>c;
	for(int i=0;i<c;i++){
		int x; cin>>x;
		hb[x]=1;
	}


	for(int i=0;i<n+m;i++){
		dsu[i].ff=i;
		if(i<n && ha[i]){
			dsu[i].ss=1;
		}
		if(i>=n && hb[i-n]){
			dsu[i].ss=1;
		}
		size[i]=1;
	}

	for(int i=0;i<n*m;i++){
		int x=i%n;
		int y=i%m;
		if(fin(x,n+y)){
			uni(x,n+y);
		}
	}

	int cnt=0;
	for(int i=0;i<n+m;i++){
		if(dsu[root(i)].ss){
			cnt++;
		}
	}

	if(cnt!=n+m){
		cout<<"NO"<<endl;
	}else{
		cout<<"YES"<<endl;
	}
	return 0;
}