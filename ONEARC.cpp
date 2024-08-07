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
#define free luatdepzai
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
int n,m;
vector <int> g[N];
int low[N],num[N],tplt[N],cnt=0;
int free[N];
int in[N],out[N];
//void add(int &x,const int &y){x+=y;if(x>=sm)x-=sm;}
//void sub(int &x,const int &y){x-=y;if(x<0)x+=sm;}
/*END*/
void doc()
{
	cin>>n>>m;
	fr(i,1,m)
	{
		int x,y;
		cin>>x>>y;
		g[x].pb(y);
	}
	fr(i,1,n) free[i]=1;
}
namespace sub1
{
	stack <int> st;
	int dem=0;
	int s,t;
	int l=0,l1=0;
	void dfs(int u)
	{
		low[u]=num[u]=++cnt;
		st.push(u);
		for(auto v:g[u])
		{
			if(free[v])
			{
				if(num[v]==0)
				{
					dfs(v);
					minimize(low[u],low[v]);
				}
				else minimize(low[u],num[v]);
			}
		}
		if(low[u]==num[u])
		{
			dem++;
			int k;
			do{
				k=st.top();
				st.pop();
				free [k]=0;
				tplt[k]=dem;
			}while(k!=u);
		}
	}
	void xuly()
	{
		fr(i,1,n)
		{
			if(!num[i]) dfs(i);
		}
		fr(i,1,n)
		{
			for(auto v:g[i])
			{
				if(tplt[i]!=tplt[v])
				{
					in[tplt[i]]++;
					out[tplt[v]]++;
				}
			}
		}
		fr(i,1,dem)
		{
			if(in[i]==0)
			{
				l++;
				s=i;
			}
			if(out[i]==0)
			{
				l1++;
				t=i;
			}
		}
		if(l!=1 or l1!=1 )
		{
			cout<<"NO";
			return;
		}
		fr(i,1,n)
		{
			if(tplt[i]==s)
			{
				s=i;
				break;
			}
		}
		fr(i,1,n)
		{
			if(tplt[i]==t)
			{
				t=i;
				break;
			}
		}
		cout<<"YES"<<'\n';
		cout<<s<<" "<<t;
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
























