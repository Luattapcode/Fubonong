// Program link: 
// Program name: v 
#define TASK  "color"
// sol: 
 
 
 
#include <bits/stdc++.h>
#define             pl  pair<ll,ll>  
#define             pb  push_back  
#define             ll  long long
#define             db  double
#define            nnc  signed main()
#define             se  second 
#define             fi  first
#define             el  "\n"
#define         all(a)  a.begin(),a.end()
#define      alla(a,n)  a+1,a+n+1
#define     FOR(i,a,b)  for(ll i=a;i<=b;i++)
#define    FORD(i,a,b)  for(ll i=a;i>=b;i--)
#define    FORN(i,a,b)  for(ll i=a;i<b;i++)
#define   FORDN(i,a,b)  for(ll i=a;i>b;i--)
#define     print(a,n)  for(ll i=1;i<=n;i++) cout<<a[i]<<" ";cout<<el;
#define      printv(v)  for(auto it:v) cout<<it<<" ";cout<<el;
#define     printvp(v)  for(auto it:v) cout<<it.fi<<" "<<it.se<<el;
#define       ieozzool  cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
using namespace std;
 
 
ll mlt=0;
ll test=1;
 
ll dx[]={1,-1,0,0};
ll dy[]={0,0,1,-1};
char hh[]={'D','U','R','L'};
 
const long long inf = 1e18;
const ll N = 3e5 + 5 , N1 = 1e3 + 5 , MOD = 1e9 +7, sminf = 1e9;
const db PI = asin(1) * 2;
 
ll gcd(ll a,ll b){return __gcd(a,b);}
ll bp(ll a){return a*a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}
 
string a,b;
map<string,ll> mp;
string s[N];
 
 
void befout()
{
    mp["Red"]=1;
    mp["Orange"]=2;
    mp["Yellow"]=3;
    mp["Green"]=4;
    mp["Blue"]=5;
    mp["Purple"]=6;
    s[1]="Red";
    s[2]="Orange";
    s[3]="Yellow";
    s[4]="Green";
    s[5]="Blue";
    s[6]="Purple";
    cin>>a>>b;
}
    
void befin()
{
    
}
 
namespace mnp
{
    void xuli(string a,string b)
    {
        if(a==b)
        {
            cout<<"Same";return;
        }
        else if(abs(mp[a]-mp[b])==1 || abs(mp[a]-mp[b])==5)
        {
            cout<<"Adjacent";return;
        } 
        else if(abs(mp[a]-mp[b])==3)
        {
            cout<<"Complementary";return;
        }
        else
        {
            ll x=mp[a],y=mp[b];
            if(x>y) swap(x,y);
            if(y-x==2)
            {
                cout<<s[y-1];return;
            }
            if(x==1 && y==5)
            {
                cout<<s[6];return;
            }
            if(x==2 && y==6)
            {
                cout<<s[1];return;
            }
        }
        cout<<"None";
    }
    
    
    void sol()
    {
        xuli(a,b);
    }
}
 
    
 
// "..."
 
nnc
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP" ,"r",stdin) ;
        freopen(TASK".OUT" ,"w",stdout);
    }
    if(mlt) cin>>test;
    befout();
    FOR(i,1,test)
    {
        befin();
        mnp::sol();
    }
    ieozzool;
}
/*
                  ¦¦¦¦¦¦¦¦¦¦¦¦                                            
                ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦                                          
              ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦                                        
            ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦                                        
            ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦  ¦¦¦¦¦¦                                      
        ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦                                      
  ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦                                      
                    ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦                                      
                        ¦¦¦¦¦¦¦¦¦¦¦¦                                      
                        ¦¦¦¦¦¦¦¦¦¦                                        
                      ¦¦¦¦¦¦  ¦¦¦¦                                        
                  ¦¦¦¦¦¦¦¦¦¦¦¦¦¦                                          
              ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦                                            
            ¦¦¦¦  ¦¦¦¦¦¦¦¦¦¦                                              
          ¦¦¦¦¦¦¦¦        ¦¦¦¦¦¦¦¦¦¦                                      
        ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦                                
      ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦                            
      ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦  ¦¦¦¦                        
    ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦  ¦¦¦¦                    
    ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦  ¦¦¦¦                
    ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦    ¦¦              
    ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦  ¦¦¦¦          
    ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦        
    ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦  ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦    ¦¦    
    ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦    ¦¦¦¦¦¦¦¦¦¦¦¦¦¦    ¦¦  
      ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦  ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦    
      ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦            ¦¦  ¦¦¦¦¦¦
          ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦  
            ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦          
              ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦                  
                  ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦                              
                            ¦¦¦¦¦¦¦¦¦¦                                    
                            ¦¦¦¦¦¦¦¦¦¦                                    
                              ¦¦  ¦¦                                      
                              ¦¦  ¦¦                                      
                              ¦¦  ¦¦                                      
                              ¦¦  ¦¦                                      
                    ¦¦¦¦¦¦¦¦  ¦¦  ¦¦                                      
                ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦   
*/
