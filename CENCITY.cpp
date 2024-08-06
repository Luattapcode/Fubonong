/*The best way to get something done is to begin*/
#include <bits/stdc++.h>
#define ll long long
#define openfile if(fopen("Data.inp","r")) {freopen("Data.inp", "r", stdin); freopen("Data.out", "w", stdout);}
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define frd(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define TASK data
using namespace std;
const int N=1e5+5;
ll m,n;
vector <ll> g[N];
bool check[N];
ll dd[N];
ll low[N];
stack <ll> st;
ll num[N];	
ll lt[N];
ll res=0;
ll cnt=0;
void doc()
{
	cin>>n>>m;
	fr(i,1,m)
	{
		ll u,v;
		cin>>u>>v;
		g[u].pb(v);	
	}
}
namespace sub1
{
	void dfs(ll x)
	{
		st.push(x);
		cnt++;
		low[x]=num[x]=cnt;
		for(auto v:g[x])
		{
			if(check[v]) continue;
			if(num[v]>0) low[x]=min(low[x],num[v]);
			else 
			{
				dfs(v);
				low[x]=min(low[x],low[v]);
			}
		}
		ll k;
		if(num[x]==low[x])
		{
			res++;
			do
			{
				k=st.top();
				st.pop();
				lt[k]=res;
				check[k]=1;
			}while(k!=x);
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
				if(lt[i]!=lt[v]) dd[lt[i]]=1;
			}
		}
		ll ans=0;
		ll pos=0;
		fr(i,1,res)
		{
			if(dd[i]==0)
			{
				ans++;
				pos=i;
			}
		}
		if(ans>1)
		{
			cout<<0;
			return;
		}
		else 
		{
			set <ll> s;
			fr(i,1,n) if(lt[i]==pos) s.insert(i);
			cout<<s.size()<<'\n';
			for(auto l:s) cout<<l<<" ";
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
	//freopen(TASK".INP", "r", stdin);
	//freopen(TASK".OUT", "w", stdout);
	doc();
	sub1::xuly();
	time();
}
/*
	Name of problem:
	Copyright: Luattapcode
	Author: Huynh Quoc Luat
*/












