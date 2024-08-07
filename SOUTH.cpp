/*The best way to get something done is to begin*/
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define frd(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define fi first
#define se second
#define el '\n'
#define dembit1(x) __builtin_popcount(x)
#define TASK "data"
#define prev luatnek
#define openfile if(fopen(TASK".inp","r")) {freopen(TASK".inp", "r", stdin); freopen(TASK".out", "w", stdout);}
using namespace std;
template <class X, class Y>
	bool minimize(X &x, const Y &y) {
		if (x > y) {
			x = y;
			return true;
		} else return false;
	}
template <class X, class Y>
	bool maximize(X &x, const Y &y) {
		if (x < y) {
			x = y;
			return true;
		} else return false;
	}
template<class T>
    T Abs(const T &x) {
        return (x < 0 ? -x : x);
    }
/* Author: Huynh Quoc Luat */
/*Khai Bao*/
const long long inf=1e18;
const int LO=17;
const int CH=27;
const int N=1e6+5;
vector <int> g[N];
int n;
int a[N];
int f[N][3][3];
//void add(int &x,const int &y){x+=y;if(x>=sm)x-=sm;}
//void sub(int &x,const int &y){x-=y;if(x<0)x+=sm;}
/*END*/
void doc()
{
	cin>>n;
	fr(i,1,n) cin>>a[i];
	fr(i,1,n-1)
	{
		int x,y;
		cin>>x>>y;
		g[x].pb(y);
		g[y].pb(x);
	}
}
namespace sub1//truong hop la doan thang
{
	void xuly()
	{
		memset(f,-0x3f,sizeof f);
		f[0][0][0]=0;
		fr(i,0,n-1)
		{
			fr(add,0,1)
			{
				fr(sub,0,1)
				{
					if(f[i][add][sub]>-inf)
					{
						maximize(f[i+1][add][sub],f[i][add][sub]);//hong dat dau o i+1
						if(!add)//dat dau + o i+1
						{
							maximize(f[i+1][1][sub],f[i][add][sub]+a[i+1]);
						}
						if(!sub)//dat dau - o i+1
						{
							maximize(f[i+1][add][1],f[i][add][sub]-a[i+1]);	
						}
						// ngat doan tai i va bat dau o i+1
						if(add && sub)
						{
							maximize(f[i+1][0][0],f[i][add][sub]);
							maximize(f[i+1][1][0],f[i][add][sub]+a[i+1]);
							maximize(f[i+1][0][1],f[i][add][sub]-a[i+1]);	
						}
					}
				}
			}
		}
		cout<<f[n][1][1];
	}
}
namespace sub2
{
	int prev[3][3];
	void dfs(int u,int p)
	{
		for(auto v:g[u])
		{
		if(v==p) continue;
		dfs(v,u);
	}
		f[u][0][0]=0;
		f[u][1][0]=a[u];
		f[u][0][1]=-a[u];
		f[u][1][1]=-inf;
		for(auto v:g[u])
		{
			if(v==p) continue;
			fr(add,0,1)
			{
				fr(sub,0,1)
				{
					prev[add][sub]=f[u][add][sub];
					f[u][add][sub]=-inf;
				}
			}
		//giu lai canh u v
		fr(ua,0,1)
		{
			fr(us,0,1)
			{
				fr(va,0,1)
				{
					fr(vs,0,1)
					{
						if(ua && va) continue;
						if(us && vs) continue;
						maximize(f[u][ua || va][us || vs],prev[ua][us]+f[v][va][vs]);
					}
				}
			}
		}
		// ngat canh uv
		fr(ua,0,1)
		{
			fr(us,0,1)
			{
				maximize(f[u][ua][us],f[v][1][1]+prev[ua][us]);
			}
		}
	}
	}
	void xuly()
	{
		dfs(1,0);
		cout<<max((ll)0,f[1][1][1]);
	}
}
void time()
{
	cerr<< endl<<"Luattapcode: "<<clock()<<"ms"<<endl;
}
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	openfile
	//freopen(TASK".INP", "r", stdin);
	//freopen(TASK".OUT", "w", stdout);
	doc();
	sub2 ::xuly();
	time();
}
























