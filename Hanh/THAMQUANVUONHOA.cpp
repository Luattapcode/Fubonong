#define TASK "INP"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"

bool mtt = 0 ;
int test = 1 ;  

#include<bits/stdc++.h>
using namespace std; 

#define             ll  long long
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
ll gcd(ll a,ll b){return __gcd(a,b);} 
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int xx[] = {0,-1,0,1} ; 
int yy[] = {0,-1,-1,-1} ;

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 ;
const int sm = 998244353,sm2=1e9+9; 
const int N = 2207+1 , C=3*1e6+1,oo = 2e9 , LO = 1e4+3 , CH = 26 ,base=337;

int m,n,k;
ll a[N][N];

void doc()
{
    cin>>m>>n>>k;
    FOR(i,1,m)  FOR(j,1,n)
    {
        cin>>a[i][j];
    }
}
void add(int &x,const int &y)
{
    x+=y;
    if (x>sm)   x-=sm;
}
void maximize(ll &x,const ll &y)
{
    if (x<y)    x=y;    
}


// namespace sub1
// {
//     ll f[N][N];

//     void xuly()
//     {
//         FOR(i,0,m+1)  FOR(j,0,n+1)  f[i][j]=-inf;
//         FOR(i,1,m)  f[i][1]=a[i][1];
//         FOR(j,2,n)  FOR(i,1,m)
//         {
//             FOR(t,1,3)
//             {
//                 int u=i+xx[t],v=j+yy[t];
//                 f[i][j]=max(f[i][j],f[u][v]+a[i][j]);
//             }
//         }
//         ll res=-inf;
//         FOR(i,1,m)
//         {
//             res=max(res,f[i][n]);
//         }
//         cout<<res;

//     }


// }
namespace sub2
{
    ll f[N][N][2];//g?i f[i][j][k] là cp l?n nh?t t?i ô (i,j) và dã s? d?ng k l?n d?ch chuy?n;
    ll maxc1[N],maxc2[N],maxh1[N],maxh2[N];
    void solve(ll &x,ll &y,ll val)
    {
        if (val>=x)  y=x,x=val;
        else maximize(y,val);
    }
    void xuly()
    {
        memset(f,-0x3f,sizeof f);
        FOR(i,1,m)  f[i][1][0]=a[i][1];
        FOR(t,0,k)
        {
            int u=t%2,v=(t+1)%2;
            FOR(j,1,n-1)  FOR(i,1,m)
            {
                if (i>1) maximize(f[i-1][j+1][u],f[i][j][u]+a[i-1][j+1]);
                if (i<m) maximize(f[i+1][j+1][u],f[i][j][u]+a[i+1][j+1]);
                maximize(f[i][j+1][u],f[i][j][u]+a[i][j+1]);
            }  
            FOR(i,1,m)  maxh1[i]=-inf,maxh2[i]=-inf;
            FOR(j,1,n)  maxc1[j]=-inf,maxc2[j]=-inf;
            FOR(i,1,m)  FOR(j,1,n)
            {
                solve(maxh1[i],maxh2[i],f[i][j][u]);
                solve(maxc1[j],maxc2[j],f[i][j][u]);
            }
            //if (t==k)   break;
            FOR(i,1,m)  FOR(j,1,n)
            {
                if (maxh1[i]==f[i][j][u])   maximize(f[i][j][v],maxh2[i]+a[i][j]);
                else maximize(f[i][j][v],maxh1[i]+a[i][j]);
                if (maxc1[j]==f[i][j][u])   maximize(f[i][j][v],maxc2[j]+a[i][j]);
                else maximize(f[i][j][v],maxc1[j]+a[i][j]);
            }

        }
        ll res=-inf;
        FOR(i,1,m) 
        {
            maximize(res,f[i][n][k%2]);
        }
        cout<<res;
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    freopen("garden.INP", "r", stdin);
	freopen("garden.OUT", "w", stdout);
    if(mtt) cin>>test;
    FOR(i,1,test)
    {
        doc();
        sub2::xuly();
    }
}
