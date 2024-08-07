/*The best way to get something done is to begin*/
#include <bits/stdc++.h>
#define ll int
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define frd(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define fi first
#define se second
#define TASK "BDDN"
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
const int N=1e6+1;
string s;
int n,q;
int t[4*N];
int d[4*N];
int sum[N];
set <int> close_;
/*END*/
void doc()
{
	cin>>n>>q;
	cin>>s;
}
namespace sub1
{
	void build(int id,int l,int r)
	{
		if(l==r)
		{
			t[id]=sum[l];
		}
		else 
		{
		int mid=(l+r)/2;
		build(id<<1,l,mid);
		build(id<<1|1,mid+1,r);
		t[id]=min(t[id<<1],t[id<<1|1]);
	}
	}
	int query(int id,int l,int r,int pos)
	{
		if(t[id]>=2) return l;
		if(l>pos) return n+1;
		if(l==r) return n+1;
		int mid=(l+r)/2;
		d[id<<1]+=d[id];
		t[id<<1]+=d[id];
		d[id<<1|1]+=d[id];
		t[id<<1|1]+=d[id];
		d[id]=0;
		int res=n+1;
		if(mid>=pos)
		{
			res=query(id<<1,l,mid,pos);
		}
		else if(t[id<<1|1]>=2) res=min(mid+1,query(id<<1,l,mid,pos));
		else res=query(id<<1|1,mid+1,r,pos);
		return res;
	}	
	void updatelazy(ll id,ll l,ll r,ll u,ll v,ll x)
	{
		if(v<l or r<u) return;
		if(u<=l and r<=v) 
		{
			t[id]+=x;
			d[id]+=x;
			return;
		}
		ll mid=(l+r)/2;
			t[id<<1]+=d[id];
			t[id<<1|1]+=d[id];
			d[id<<1]+=d[id];
			d[id<<1|1]+=d[id];
			d[id]=0;
		updatelazy(id<<1,l,mid,u,v,x);
		updatelazy(id<<1|1,mid+1,r,u,v,x);
		t[id]=min(t[id<<1],t[id<<1|1]);
	}
	void up(int x)
	{
		if(s[x-1]=='(')
		{
			close_.insert(x);
			updatelazy(1,1,n,x,n,-2);
			s[x-1]=')';
		}
		else 
		{
			close_.erase(x);
			updatelazy(1,1,n,x,n,2);
			s[x-1]='(';
		}
	}
	void xuly()
	{
		fr(i,1,n)
		{
			sum[i]=sum[i-1]+(s[i-1]=='('?1:-1);
		}
		build(1,1,n);
		fr(i,1,n) if(s[i-1]==')') close_.insert(i);
		fr(i,1,q)
		{
			int x;
			cin>>x;
			char y=s[x-1];
			int res;
			up(x);
			if(y=='(')
			{
				res=*close_.begin();
			}
			else 
			{
				res=min(x,query(1,1,n,x));
			}
			cout<<res<<" ";
			up(res);
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



















