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
const int N=3e5+5;
int n,q;
vector <int> g[N];
//void add(int &x,const int &y){x+=y;if(x>=sm)x-=sm;}
//void sub(int &x,const int &y){x-=y;if(x<0)x+=sm;}
/*END*/
int root;
void doc()
{
	cin>>n>>q;
	fr(i,1,n)
	{
		int x;
		cin>>x;
		if(x==0) 
		{
			root=i;
		}
		else 
		{
			g[i].pb(x);
			g[x].pb(i);
		}
	}
}
namespace sub1
{
	int pa[N];
	int f[N];
	void dfs(int x,int p)
	{
		f[x]=1;
		for(auto v:g[x])
		{
			if(v==p) continue;
			pa[v]=x;
			
			dfs(v,x);
			f[x]+=f[v];
		}
	}
	int find(int x,int p,int n)
	{
		for(auto v:g[x]){
			if(v==p) continue;
			if(2*f[v]>=n)
			{
				return find(v,x,n);
			}
		}
		return x;
	}
	void xuly()
	{
		dfs(root,0);
		while(q--)
		{
			int x;
			cin>>x;
			cout<<find(x,pa[x],f[x])<<" ";
		}
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























