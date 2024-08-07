/*The best way to get something done is to begin*/
#include <bits/stdc++.h>
#define ll long long
#define openfile if(fopen("Data.inp","r")) {freopen("Data.inp", "r", stdin); freopen("Data.out", "w", stdout);}
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define frd(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define TASK "camera"
using namespace std;
/*Khai Bao*/
const long long inf=1e18;
const int LO=17;
const int CH=27;
ll n,k,r,ti;
const int N=3e5+5;
ll a[N];
ll f[N];
ll t[4*N];
ll dp[N];
/*END*/
void update(ll k,ll l,ll r,ll v,ll val)
{
		if(v>r or v<l) return;
		if(l==r)
		{
			t[k]+=val;
			return;
		}
		ll mid=(l+r)/2;
		update(2*k,l,mid,v,val);
		update(2*k+1,mid+1,r,v,val);
		t[k]=t[2*k]+t[2*k+1];
}
	ll get(ll k,ll l,ll r,ll u,ll v)
{
	if(v<l or u>r) return 0;
	if(u<=l and v>=r) return t[k];
	ll mid=(l+r)/2;
	ll m1=get(2*k,l,mid,u,v);
	ll m2=get(2*k+1,mid+1,r,u,v);
	return m1+m2;
}
void doc()
{
	cin>>n>>k>>r>>ti;
	fr(i,1,k)
	{
		
		ll x;
		cin>>x;
		a[x]=1;
		update(1,1,n,x,1);
	}
}
namespace sub1
{	
	void xuly()
	{
		vector <int> v;
		ll cnt=0;
		fr(i,r,n)
		{
			ll dem=ti-get(1,1,n,i-r+1,i);
			if(dem<=0) continue;
			frd(j,i,1)
			{
				if(a[j]==0)
				{
					update(1,1,n,j,1);
					dem--;
					a[j]=1;
					v.pb(j);
				}
				if(dem==0) break;
			}
		}
		cout<<v.size()<<'\n';
		for(auto l:v) cout<<l<<" ";
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
	freopen(TASK".INP", "r", stdin);
	freopen(TASK".OUT", "w", stdout);
	doc();
	sub1::xuly();
	time();
}
/*
	Name of problem:
	Copyright: Luattapcode
	Author: Huynh Quoc Luat
*/















