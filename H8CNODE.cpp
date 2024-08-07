#include<bits/stdc++.h>
using namespace std; 
#define             ll  long long
//#define             int long long
#define             db  double 
#define             fi  first
#define             se  second
#define     FOR(i,a,b)  for(int i=(int)(a);i<=(int)(b);i++)
#define    FORD(i,a,b)  for(int i=(int)(a);i>=(int)(b);i--)
#define        MASK(i)   (1ll<<(i))
#define       c_bit(i)  __builtin_popcountll(i)  //d?m s? bit dang b?t
#define       BIT(x,i)  ((x) & MASK(i))  //TR?NG THÁI C?A BIT TH? I TRONG X
#define    set_on(x,i)  ((x) | MASK(i)) // b?t bit th? i trong x
#define   set_off(x,i)  ((x) & ~MASK(i)) //t?t bit th? i trong x
#define             pb  push_back
#define           TASK  "VTRAVEL"

template <class X, class Y>
    bool minimize (X &x, const Y &y)
    {
        if (x>y)
        {
            x=y;
            return 1;
        }
        else return 0;
    }
template <class X, class Y>
    bool maximize(X &x, const Y &y)
    {
        if (x<y)
        {
            x=y;
            return 1;
        }
        else return 0;
    }
template <class T>
    T Abs(const T &x)
    {
        return (x<0 ? -x : x);
    }

const int sm =1e9+7,sm2=1e9+7; 

int gcd(int a,int b){return __gcd(a,b);} 
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
void add (ll &x, const ll &y) {x+=y; if (x>=sm) x-=sm;}
void sub (ll &x, const ll &y) {x-=y; if (x<0) x+=sm;}

int xx[]={0,-1,-1,0,1,1,1,0,-1};
int yx[]={0,0,1,1,1,0,-1,-1,-1};

const db PI = acos(-1);
const ll inf = 1e18;
const int N = 1e5+5 ,base=331;
bool mtt = 0 ;
int test = 1 ;  

//------Starting-------
int n,m;
vector <int> g[N];

void doc()
{
    cin>>n>>m;
    FOR(i,1,m)  
    {
        int x,y;
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }
}

int num[N],low[N],stt=0,K[N],sk=0,nc[N];


void dfs(int u,int parent)
{
    num[u]=low[u]=++stt;
    nc[u]=0;
    for (int v:g[u])
    {
        if (v==parent)  continue;
        //if (tp[c]!=0) continue;
        if (num[v]!=0)   low[u]=min(low[u],num[v]);
        else
        {
            //cha[v]=u;
            nc[u]++;
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if (low[v]>=num[u])
            {
                K[u]=1;
                sk++;
            }
        }
    }

}

void sub1()
{
    FOR(i,1,n)  
    {
        if (!num[i])  
        {
            dfs(i,-1);
            if (K[i] and nc[i]<2)   K[i]=0,sk--;
        }
    }
    //cout<<sk<<"\n";
    sk=0;
    FOR(i,1,n)  if (K[i])   sk++;
    cout<<sk<<"\n";
    FOR(i,1,n)  if (K[i])   cout<<i<<" ";
}



signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin);
        freopen(TASK".OUT","w",stdout);
    }
    else if (fopen("INP.INP","r"))
    {
        freopen("INP.INP","r",stdin);
        freopen("INP.OUT","w",stdout);
    }
    if(mtt) cin>>test;
    while (test--)
    {
        doc();
        sub1();
    }

}
