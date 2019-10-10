#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool wildcardMatching(char pat[],char inp[]){

	ll m=strlen(pat);
	ll n=strlen(inp);

	bool dp[m+1][n+1];

	memset(dp,false,sizeof(dp));
	dp[0][0]=true;

	for(int i=1;i<=m;i++){
		if(pat[i-1]=='*'){
			dp[i][0]=dp[i-1][0];
		}
	}

	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){

			if(pat[i-1]=='*'){
				dp[i][j]=dp[i-1][j] || dp[i][j-1];
			}

			else if(pat[i-1]==inp[j-1] || pat[i-1]=='?')
			{
				dp[i][j]=dp[i-1][j-1];
			}

			else
				dp[i][j]=false;
		}
	}
	return dp[m][n];
}
int main(){

	char inp[100000];
	char par[100000];

	cin>>inp;
	cin>>par;

	cout<<wildcardMatching(par,inp)<<endl;
	return 0;
}
