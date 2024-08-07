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
const int N=2e5+5;
int n,m,k;
vector <int> g[N];
vector <int> G[N];
int id[N];
int S[N];
int f[N];//1-i;
int f1[N];//i-n;
int t[4*N];
//void add(int &x,const int &y){x+=y;if(x>=sm)x-=sm;}
//void sub(int &x,const int &y){x-=y;if(x<0)x+=sm;}
/*END*/
void doc()
{
	cin>>n>>m>>k;
	fr(i,1,m)
	{
		int x,y;
		cin>>x>>y;
		g[x].pb(y);
		G[y].pb(x);
	}
	fr(i,1,n)
	{
		cin>>S[i];
		id[S[i]]=i;
	}
}
namespace sub1
{
	int l[N];
	int check[N];
	void bfs1(int x)
	{
		fr(i,1,n) f[i]=inf;
		check[x]=1;
		queue <int> q;
		f[x]=0;
		q.push(x);
		while(!q.empty())
		{
			int k=q.front();
			q.pop();
			for(auto v:G[k])
			{
				if(check[v]==0)
				{
					check[v]=1;
					f[v]=f[k]+1;
					q.push(v);
				}
			}
		}
	}
	void up(int k,int l,int r,int v,int val)
	{
		if(v>r or v<l) return;
		if(l==r)
		{
			t[k]=val;
			return;
		}
		int mid=(l+r)/2;
		up(2*k,l,mid,v,val);
		up(2*k+1,mid+1,r,v,val);
		t[k]=min(t[2*k],t[2*k+1]);
	}
	int get(int k,int l,int r,int u,int v)
	{
		if(u>r or v<l) return inf;
		if(u<=l and v>=r) return t[k];
		int mid=(l+r)/2;
		int m1=get(2*k,l,mid,u,v);
		int m2=get(2*k+1,mid+1,r,u,v);
		return min(m1,m2);
	}
	void xuly()
	{
		fr(i,1,4*n) t[i]=inf;
		bfs1(n);
		fr(x,1,n)
		{
			l[S[x]]=id[S[x]]+f[S[x]]-1;
			up(1,1,n,S[x],l[S[x]]);
		}
		fr(i,1,k)
		{
			int x,y;
			cin>>x>>y;
			swap(S[x],S[y]);
			id[S[x]]=x;
			id[S[y]]=y;
			l[S[x]]=id[S[x]]+f[S[x]]-1;
			l[S[y]]=id[S[y]]+f[S[y]]-1;
			up(1,1,n,S[x],l[S[x]]);
			up(1,1,n,S[y],l[S[y]]);
			cout<<t[1]<<'\n';
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
























