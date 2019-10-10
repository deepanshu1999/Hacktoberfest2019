#include<bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;

const int N=2e5+1000;


ll p[N],n,tilll[N];

ll mann(string &s){

    string sss="&|";
    for(auto x:s) sss.pb(x),sss.pb('|');
    sss.pb('?');
    ll m=0,r=0,res=1;
    for(int i=2;i<sss.size()-2;i++){
        p[i]=(i<r)?min(r-i,p[m-(i-m)]):0;
        while(sss[i+p[i]+1]==sss[i-p[i]-1]) {
            p[i]++;
            if(p[i]%2 && p[i]!=n && sss[i]!='|') {
                tilll[i+p[i]-1]=max(tilll[i+p[i]-1],p[i]); 
                res=max(res,p[i]*tilll[i-p[i]]);
            }
        }
        if(i+p[i]>r) r=i+p[i],m=i;
        tilll[i]=max(tilll[i-1],tilll[i]);
        if(p[i]%2 && p[i]!=n)
            res=max(res,p[i]*tilll[i-p[i]]);
    }
    return res;

}


int main(){
    string s;
    n=s.size();
    cin>>s;
    cout<<mann(s);
    return 0;

}