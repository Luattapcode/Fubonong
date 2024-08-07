/*The best way to get something done is to begin*/
#include <bits/stdc++.h>
#define ll long long
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define frd(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define fi first
#define se second
#define dembit1(x) __builtin_popcount(x)
#define TASK "data"
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
const int N=1e5+5;
int n,k;
vector<int> g[N];
int f[N];
int sz[N];
//void add(int &x,const int &y){x+=y;if(x>=sm)x-=sm;}
//void sub(int &x,const int &y){x-=y;if(x<0)x+=sm;}
/*END*/
void doc()
{
	cin>>n>>k;
	fr(i,1,n-1)
	{
		int x,y;
		cin>>x>>y;
		g[x].pb(y);
		g[y].pb(x);
	}
}
namespace sub1
{
	void dfs(int u,int p)
	{
		f[u]=1;
		for(auto v:g[u])
		{
			if(v==p) continue;
			dfs(v,u);
			f[u]+=f[v];
		}
	}
	int find(int u,int p)
	{
		for(auto v:g[u])
		{
			if(v==p) continue;
			if(f[v]>n/2) return find(v,u);
		}
		return u;
	}
	bool cmp(int u,int v)
	{
		return u>v;
	}
	void xuly()
	{
		dfs(1,0);
		int centroid=find(1,0);
		fr(i,1,n) f[i]=0;
		dfs(centroid,0);
		sort(f+1,f+n+1,cmp);
		int res=0;
		fr(i,k+2,n) res+=f[i];
		cout<<res;
	}
}
namespace sub2
{
	void xuly()
	{

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
	sub1::xuly();
	time();
}
/* May man chi den voi nhung nguoi co thuc luc */























