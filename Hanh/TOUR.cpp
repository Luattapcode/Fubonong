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
const int N=1000+5;
struct bg{
	int x;
	int y;
};
vector <bg> g[N];
vector <bg> g1[N];
vector <bg> G1[N];
vector <bg> G2[N];
int n,S,T;
//void add(int &x,const int &y){x+=y;if(x>=sm)x-=sm;}
//void sub(int &x,const int &y){x-=y;if(x<0)x+=sm;}
/*END*/
void doc()
{
	cin>>n>>S>>T;
	int x,y;
	cin>>x;
	fr(i,1,x)
	{
		int u,v,z;
		cin>>u>>v>>z;
		g[u].pb({v,z});
		g[v].pb({u,z});
	}
	cin>>y;
	fr(i,1,y)
	{
		int u,v,z;
		cin>>u>>v>>z;
		g1[u].pb({v,z});
		g1[v].pb({u,z});
	}
}
namespace sub1
{
	int f[N];
	int ans[2*N][N];
	int check[N];
	struct cmp{
		bool operator()(bg u,bg v)
		{
			return u.y>v.y;
		}
	};
	void dij(int x,vector <bg> g [])
	{
		priority_queue<bg,vector <bg>,cmp> h;
		memset(f,0x3f,sizeof(f));
		memset(check,0,sizeof(check));
		f[x]=0;
		h.push({x,0});
		while(!h.empty())
		{
			int u=h.top().x;
			h.pop();
			if(check[u]) continue;
			check[u]=1;
			for(auto v:g[u])
			{
				int ke=v.x;
				int ts=v.y;
				if(minimize(f[ke],f[u]+ts))
				{
					h.push({ke,f[ke]});
				}
			}
		}
	}
	void bfs(int x)
	{
		memset(f,0,sizeof(f));
		memset(check,0,sizeof(check));
		queue <bg> q;
		q.push({x,1});
		q.push({x,0});
		f[x]=0;
		while(!q.empty())
		{
			int u=q.front().x;
			int l=q.front().y;
			q.pop();
			if(l%2==1)
			{
				for(auto v:G1[u])
				{
					int ke=v.x;
					int ts=v.y;
					if(check[ke]) continue;
					check[ke]=1;
					if(maximize(f[ke],f[u]+ts))
					{
						q.push({ke,l+1});
					}
				}
			}
			else 
			{
				for(auto v:G2[u])
				{
					int ke=v.x;
					int ts=v.y;
					if(maximize(f[ke],f[u]+ts))
					{
						q.push({ke,l+1});
					}
				}
			}
		}
	}
	void xuly()
	{
		dij(T,g);
		fr(i,1,n)
		{
			for(auto v:g[i])
			{
				int ke=v.x;
				int ts=v.y;
				if(f[i]>f[ke])
				{
					G1[i].pb({ke,ts});
				}
			}
		}
		dij(T,g1);
		fr(i,1,n)
		{
			for(auto v:g1[i])
			{
				int ke=v.x;
				int ts=v.y;
				if(f[i]>f[ke])
				{
					G2[i].pb({ke,ts});
				}
			}
		}
		fr(i,0,2*n)
		{
			fr(j,1,n)
			{
				ans[i][j]=-1;
			}
		}
			ans[0][S]=0;
		fr(k,0,2*n-1)
		{
			if(k%2==0)
			{
			fr(u,1,n)
			{
				if(ans[k][u]!=-1)
				{
					for(auto v:G1[u])
					{
						int ke=v.x;
						int ts=v.y;
						maximize(ans[k+1][ke],ans[k][u]+ts);
					}
				}
			}
			}
			else 
			{
				fr(u,1,n)
			{
				if(ans[k][u]!=-1)
				{
					for(auto v:G2[u])
					{
						int ke=v.x;
						int ts=v.y;
						maximize(ans[k+1][ke],ans[k][u]+ts);
					}
				}
			}
			}
		}
		int res=0;
		fr(i,1,n)
		{
			if(ans[2*n][i]!=-1) 
			{
				cout<<-1;
				return;
			}
		}
		fr(i,0,2*n)
		{
			maximize(res,ans[i][T]);
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
























