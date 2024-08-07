/*The best way to get something done is to begin*/
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define frd(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define fi first
#define se second
#define dembit1(x) __builtin_popcount(x)
#define TASK "H2SHORTCUT"
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
int n;
int m,t;
int c[N];
struct bg{
	int x;
	int y;
};
vector <bg> g[N];
struct cmp{
	bool operator()(bg u,bg v)
	{
		return u.y>v.y;
	}
};
//void add(int &x,const int &y){x+=y;if(x>=sm)x-=sm;}
//void sub(int &x,const int &y){x-=y;if(x<0)x+=sm;}
/*END*/
void doc()
{
	cin>>n>>m>>t;
	fr(i,1,n) cin>>c[i];
	fr(i,1,m)
	{
		int x,y,z;
		cin>>x>>y>>z;
		g[x].pb({y,z});
		g[y].pb({x,z});
	}
}
namespace sub1
{
	bool check[N];
	int ri[N];
	vector <int> G[N];
	vector <int> ve;
	int f[N];//goi f[x] la duong di ngan nhat tu 1-x;
	int T[N];//goi t[v]=u :u la dinh lien truoc v trong ddnn,neu co nhieu dinh v thi chon v nho nhat
	int l[N];//goi l[i] la tong so luong nguoi thuoc nhanh con cua i
	void dij(int x)
	{
		fr(i,1,n) f[i]=inf,check[i]=0;
		priority_queue <bg,vector <bg>,cmp> h;
		f[x]=0;
		h.push({x,f[x]});
		while(!h.empty())
		{
			int k=h.top().x;
			h.pop();
			if(check[k]) continue;
			check[k]=1;
			ve.pb(k);
			for(auto v:g[k])
			{
				int id=v.x;
				int ts=v.y;
				if(f[id]>f[k]+ts)
				{
					f[id]=f[k]+ts;
					T[id]=k;
					h.push({id,f[id]});
				}
				else if(f[id]==f[k]+ts)
				{
					if(T[id]>k) T[id]=k;
				}
			}
		}
	}
	void dfs(int x,int p)
	{
		l[x]=c[x];
		for(auto v:G[x])
		{
			if(v==p) continue;
			dfs(v,x);
			l[x]+=l[v];
		}
	}
	void xuly()
	{
		dij(1);
		fr(i,1,n) l[i]=c[i];
		fr(i,2,n)
		{
			G[T[i]].pb(i);
			G[i].pb(T[i]);
		}
		dfs(1,0);
//		fr(i,1,n) ri[i]=f[i];
//		int res=0;
//		fr(i,2,n)
//		{
//			dij(i);
//			int ans=0;
//			fr(j,1,n)
//			{
//				if(f[j]+t<ri[j]) ans+=(ri[j]-f[j]-t)*c[j];
//			}
//			res=max(res,ans);
//		}
//		cout<<res;
int res=0;
		fr(i,2,n)
		{
			if(f[i]>t)
			{
				int cp=(l[i]*(f[i]-t));
				res=max(res,cp);
			}
		}
		cout<<res;
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






















