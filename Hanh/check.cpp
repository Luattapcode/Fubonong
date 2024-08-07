
#define TASK "check"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"

bool mtt = 0 ;
int test = 1 ;  

#include<bits/stdc++.h>
using namespace std; 

#define             ll  long long 
#define             int long long
#define             db  double 
#define             fi  first
#define             se  second
#define     FOR(i,a,b)  for(int i=(int)(a);i<=(int)(b);i++)
#define    FORD(i,a,b)  for(int i=(int)(a);i>=(int)(b);i--)
#define     BIT(msk,i)  (msk>>(i)&1)
#define        Mask(i)  (1ll<<(i))
#define          SZ()  (int)(.size())
#define             pb  push_back
#define           btpc  __builtin_popcountll
ll gcd(ll a,ll b){return __gcd(a,b);} 
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int xx[] = {0,0,-1,1,0} ; 
int yy[] = {0,-1,0,0,1} ;

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 2*1e5+5 , C=1e3+5,oo = 2e9 , LO = 1e4+3 , CH = 26 ;

int n;
ll x[N],y[N];
char 
type[N];

void doc()
{
    cin>>x[0]>>y[0];
    FOR(i,1,n)
    {
        cin>>type[i]>>x[i]>>y[i];
    }

}



namespace sub1
{
    int a[N],b[N];
    vector <pair<int,int>> hang,cot,ctrai,cphai;
    bool solve(vector <pair<int,int>> v)
    {
        sort(v.begin(),v.end());
        int sz=v.size();
         if (sz==1)  return 0;
        FOR(i,1,sz) a[i]=v[i-1].fi,b[i]=v[i-1].se;
        b[sz+1]=0;
        int j=lower_bound(a+1,a+sz+1,0)-a;
        if (b[j-1]==1 or b[j+1]==1) return 1;
        return 0;

    }
    void xuly()
    {
        cot.clear();
        hang.clear();
        ctrai.clear();
        cphai.clear();
        cot.pb({0,0});
        hang.pb({0,0});
        ctrai.pb({0,0});
        cphai.pb({0,0});
        FOR(i,1,n)
        {
            x[i]-=x[0];y[i]-=y[0];
            if (type[i]=='R')
            {
                if (x[i]==0)    cot.pb({y[i],1});
                else if (y[i]==0)   hang.pb({x[i],1});
                else if (abs(x[i])==abs(y[i]) and x[i]*y[i]<0)   ctrai.pb({x[i],-1});
                else if (abs(y[i])==abs(x[i]) and x[i]*y[i]>0)  cphai.pb({x[i],-1});
            }
            if (type[i]=='B')
            {
                if (x[i]==0)    cot.pb({y[i],-1});
                else if (y[i]==0)   hang.pb({x[i],-1});
                else if (abs(x[i])==abs(y[i]) and x[i]*y[i]<0)   ctrai.pb({x[i],1});
                else if (abs(y[i])==abs(x[i]) and x[i]*y[i]>0)  cphai.pb({x[i],1});
            }
            if (type[i]=='Q')
            {
                if (x[i]==0)    cot.pb({y[i],1});
                else if (y[i]==0)   hang.pb({x[i],1});
                else if (abs(x[i])==abs(y[i]) and x[i]*y[i]<0)   ctrai.pb({x[i],1});
                else if (abs(y[i])==abs(x[i]) and x[i]*y[i]>0)  cphai.pb({x[i],1});
            }
        }
        if (solve(hang))    cout<<"YES\n";
        else if (solve(cot))    cout<<"YES\n";
        else if (solve(ctrai))  cout<<"YES\n";
        else if (solve(cphai))  cout<<"YES\n";
        else cout<<"NO\n";


        

    }



}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin) ;
        freopen(OUTPUT,"w",stdout);
    }
    if(mtt) cin>>test;
    FOR(i,1,test)
    {
        while (cin>>n)
        {
            if (n==-1)  return 0;
            doc() ; 
            sub1::xuly();
        }
    }
}
