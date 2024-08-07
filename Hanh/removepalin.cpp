#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define             pb  push_back  
#define             ll  int
#define             el  "\n"
#define      alla(a,n)  a+1,a+n+1
#define         all(v)  v.begin(),v.end()
#define      fu(i,a,b)  for(ll i=a;i<=b;i++)
#define     fud(i,a,b)  for(ll i=a;i>=b;i--)

const int N=1e6+3;

string s;
ll f[N][5][5],value[N][5];


signed main(void)
{
    #define TASK  "removepalin"
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP" ,"r",stdin) ;
        freopen(TASK".OUT" ,"w",stdout);
    }
    fu(i,0,1e6) fu(j,0,4) fu(k,0,4) f[i][j][k]=2e9;
    // cout<<f[1][1][1]<<el;
    cin>>s;
    ll n=s.size();
    if(n<2)
    {
        cout<<0;

    }
    else
    {
        s=' '+s;
        fu(i,1,n) fu(j,-2,2)
        {
            value[i][j+2]=(s[i]-'a' +j +26) %26;
        }
        fu(j,0,4) fu(k,0,4) if(value[2][j]!=value[1][k]) f[2][j][k]=abs(j-2)+abs(k-2);
        fu(i,2,n-1) fu(j,0,4) fu(k,0,4) if(value[i][j]!=value[i-1][k])
        {
            fu(t,0,4) if(value[i+1][t]!=value[i][j] && value[i-1][k]!=value[i+1][t])
            {
                f[i+1][t][j]=min(f[i][j][k]+abs(t-2),f[i+1][t][j]);
            }
        }
        ll ans=1e9;
        fu(j,0,4) fu(k,0,4) if(value[n][j]!=value[n-1][k]) ans=min(ans,f[n][j][k]);
        cout<<ans;
    }
    
    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
}
