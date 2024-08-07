#include<bits/stdc++.h>
using namespace std; 
#define             ll  long long
//#define             int long long
//#define             db  double 
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
#define           TASK  "H8DART"

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

//const db PI = acos(-1);
const ll inf = 1e13;
const int N = 105 ,M=1e4+5, base=331;
bool mtt = 0;
int test = 1 ;  

//------Starting-------
int n,m=0;
struct bg
{
    int ke;
    ll w;
};
vector <bg> g[N];
//vector <int> M,G;

void doc()
{
    cin>>n;
    int u,v;
    ll w1,w2;
    char type;
    while (cin>>u>>v>>w1>>w2>>type)
    {
        if (type=='M')  v=v+n;
        else u=u+n;
        g[u].pb({v,w1});
        g[v].pb({u,w2});
        //if (type==)
    }
}

namespace sub1
{
    ll f[N];
    int dd[N];
    struct cmp
    {
        bool operator()(bg a,bg b)
        {
            return a.w>b.w;
        }
    };
    void dij(int u)
    {
        memset(f,0x3f,sizeof f);
        memset(dd,0,sizeof dd);
        f[u]=0;
        priority_queue <bg,vector<bg>,cmp> h;
        h.push({u,f[u]});
        while (!h.empty())
        {
            int u=h.top().ke;
            h.pop();
            if (dd[u])  continue;
            dd[u]=1;
            for (bg r:g[u])
            {
                int v=r.ke;
                ll w=r.w;
                if (f[v]>f[u]+w and dd[v]==0)
                {
                    minimize(f[v],f[u]+w);
                    h.push({v,f[v]});
                }
            }
        }
    }
    void xuly()
    {
        ll res=inf;
        dij(n);
        minimize(res,min(f[1],f[n+1]));
        dij(2*n);
        minimize(res,min(f[1],f[n+1]));
        cout<<res;
    }
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
    //xuly();
    FOR(i,1,test)
    {
        doc();
        sub1::xuly();
    }

}
