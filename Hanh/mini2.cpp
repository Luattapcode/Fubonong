/*The best way to get something done is to begin*/
#include <bits/stdc++.h>
#define ll long long
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define frd(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define TASK "minimum"
#define fi first 
#define se second
#define openfile if(fopen(TASK".inp","r")) {freopen(TASK".inp", "r", stdin); freopen(TASK".out", "w", stdout);}
using namespace std;
/*Khai Bao*/
const long long inf=1e9;
const int LO=17;
const int CH=27;
const int N=5e6+5;
ll n,x,y;
ll a[N];
ll s[N];
stack <ll> st;
pair<int,int> t1[4*N];
pair<int,int> t2[4*N];
ll l[N];
ll r[N];
/*END*/
void doc()
{
	cin>>n>>x>>y;
	fr(i,1,n)
	{
		cin>>a[i];
	}
	fr(i,1,n) s[i]=s[i-1]+a[i];
}
namespace sub1
{
	void update1(ll k,ll l,ll r,ll v,ll val,ll i)
	{
		if(v<l or v>r) return;
		if(l==r)
		{
			t1[k].fi=val;
			t1[k].se=i;
			return;
		}
		ll mid=(l+r)/2;
		update1(2*k,l,mid,v,val,i);
		update1(2*k+1,mid+1,r,v,val,i);
		if(t1[2*k+1].fi>t1[2*k].fi) 
		{
			t1[k]=t1[2*k+1];
		}
		else 
		{
			t1[k]=t1[2*k];
		}
	}
	void update2(ll k,ll l,ll r,ll v,ll val,ll i)
	{
		if(v<l or v>r) return;
		if(l==r)
		{
			t2[k].fi=val;
			t2[k].se=i;
			return;
		}
		ll mid=(l+r)/2;
		update2(2*k,l,mid,v,val,i);
		update2(2*k+1,mid+1,r,v,val,i);
		if(t2[2*k+1].fi>t2[2*k].fi) 
		{
			t2[k]=t2[2*k];
		}
		else 
		{
			t2[k]=t2[2*k+1];
		}
	}
	pair <int,int> get2(ll k,ll l,ll r,ll u,ll v)
	{
	if(v<l or u>r) return {inf,inf};
	if(u<=l and v>=r) return t2[k];
	ll mid=(l+r)/2;
	pair<int,int> m1=get2(2*k,l,mid,u,v);
	pair<int,int> m2=get2(2*k+1,mid+1,r,u,v);
	if(m1.fi>m2.fi) return m2;
	else return m1;
	}
pair <int,int> get1(ll k,ll l,ll r,ll u,ll v)
	{
	if(v<l or u>r) return {-inf,-inf};
	if(u<=l and v>=r) return t1[k];
	ll mid=(l+r)/2;
	pair<int,int> m1=get1(2*k,l,mid,u,v);
	pair<int,int> m2=get1(2*k+1,mid+1,r,u,v);
	if(m1.fi>m2.fi) return m1;
	else return m2;
	}
	void xuly()
	{
		update1(1,0,n,0,0,0);
		update2(1,0,n,0,0,0);
		fr(i,1,n)
		{
			update1(1,0,n,i,s[i],i);
			update2(1,0,n,i,s[i],i);
		}
		st.push(1);
		l[1]=1;
		fr(i,2,n)
		{
			while(!st.empty() and a[st.top()]>=a[i]) st.pop();
			if(st.empty()) l[i]=1;
			else l[i]=st.top()+1;
			st.push(i);
		}
		while(!st.empty()) st.pop();
		r[n]=n;
		st.push(n);
		frd(i,n-1,1)
		{
			while(!st.empty() and a[st.top()]>=a[i]) st.pop();
			if(st.empty()) r[i]=n;
			else r[i]=st.top()-1;
			st.push(i);
		}
		int res=-1e9;
		int pos1,pos2;
		fr(i,1,n)
		{
			if(a[i]>=x and a[i]<=y) 
			{
				pair<int,int> left=get2(1,0,n,l[i]-1,i-1);
				pair<int,int> right=get1(1,0,n,i,r[i]);
//				cout<<left.fi<<" "<<right.fi<<'\n';
				if(right.fi-left.fi>res)
				{
					res=right.fi-left.fi;
					pos1=left.se+1;
					pos2=right.se;
				}
			}
		}
//		fr(i,1,n)
//		{
//			cout<<l[i]<<" "<<r[i]<<" ";
//		}
//		cout<<'\n';
		cout<<res<<'\n';
		cout<<pos1<<" "<<pos2;
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
/*
	Name of problem:
	Copyright: Luattapcode
	Author: Huynh Quoc Luat
*/

















