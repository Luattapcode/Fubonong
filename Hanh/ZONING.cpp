/*The best way to get something done is to begin*/
#include <bits/stdc++.h>
#define ll long long
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define frd(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define fi first
#define se second
#define TASK "ZONING"
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
/*Author: Huynh Quoc Luat*/
/*Khai Bao*/
const long long inf=1e18;
const int LO=17;
const int CH=27;
const int N=1e5+5;
int f[N];
bool check[N];
int size[N];
vector <int> bac,dinh;
int n,m;
int deg[N];
vector <int> g[N];
multiset <pair<int,int>> mse;
/*END*/
void doc()
{
	cin>>n>>m;
	fr(i,1,m)
	{
		int x,y;
		cin>>x>>y;
		g[x].pb(y);
		g[y].pb(x);
		deg[x]++;
		deg[y]++;
	}
	fr(i,1,n)
	{
		mse.insert({deg[i],i});
	}
}
namespace sub1
{
	int goc(int x)
	{
		while(f[x]>0) x=f[x];
		return x;
	}
	void hn(int r1,int r2)
	{
		int t=f[r1]+f[r2];
		if(abs(f[r1])>abs(f[r2]))
		{
			f[r1]=t;
			f[r2]=r1;
		}
		else 
		{
			f[r1]=r2;
			f[r2]=t;
		}
	}
	void del()
	{
		pair <int,int> x=*mse.begin();
		bac.pb(x.fi);
		dinh.pb(x.se);
		mse.erase({deg[x.se],x.se});
		check[x.se]=1;
		for(auto v:g[x.se])
		{
			if(!check[v])
			{
				mse.erase({deg[v],v});
				deg[v]--;
				mse.insert({deg[v],v});
			}
		}
	}
	void xuly()
	{
		fr(i,1,n) del();
		reverse(bac.begin(),bac.end());
		reverse(dinh.begin(),dinh.end());
		fr(i,1,n) f[i]=-1;
		int res=0;
		fr(i,1,n) check[i]=0;
		fr(i,0,bac.size()-1)
		{
			int u=dinh[i];
			int y=bac[i];;
			check[u]=1;
			for(auto v:g[u])
			{
				if(!check[v]) continue;
				int r1=goc(u);
				int r2=goc(v);
				if(r1!=r2)
				{
					hn(r1,r2);
				}
			}
			res=max(res,y*abs(f[goc(u)]));
		}
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


















