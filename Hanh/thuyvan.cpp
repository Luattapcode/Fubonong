/*The best way to get something done is to begin*/
#include <bits/stdc++.h>
#define ll long long
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define frd(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define TASK "thuyvan"
#define openfile if(fopen("TASK.inp","r")) {freopen("TASK.inp", "r", stdin); freopen("TASK.out", "w", stdout);}
using namespace std;
/*Khai Bao*/
const long long inf=1e18;
const int LO=17;
const int CH=27;
const int N=2e5+5;
const long long sm=1e9+7;
const long long sm1=1e9+9;
ll n,k;
string s[N];
ll h[N];
ll p[N];
/*END*/
void doc()
{
	cin>>n>>k;
	fr(i,1,n)
	{
		cin>>s[i];
	}
}
namespace sub1
{
	pair <int,int> gethash(ll id,ll l,ll r)
	{
	string x=s[id];
	pair <int,int> q;
	int m=x.size();
	x='('+x;
	h[0]=0;
	fr(i,1,m)
	{
		h[i]=(h[i-1]*256+x[i]-'A'+1)%sm;
	}
	p[0]=1;
	fr(i,1,m) p[i]=(p[i-1]*256)%sm;
	q.first=(h[r]-h[l-1]*p[r-l+1]+sm*sm)%sm;
	h[0]=0;
	fr(i,1,m)
	{
		h[i]=(h[i-1]*256+x[i]-'A'+1)%sm1;
	}
	p[0]=1;
	fr(i,1,m) p[i]=(p[i-1]*256)%sm1;
	q.second=(h[r]-h[l-1]*p[r-l+1]+sm1*sm1)%sm1;
	return q;
	}
	bool check(int l,bool trace)
	{
		map <pair<int,int>,ll> mp;
		fr(i,1,n)
		{
			fr(j,0,s[i].size()-l)
			{
				pair <int,int> tmp=gethash(i,j,j+l-1);
				ll &x=mp[tmp];
				x|=1ll << i;
				if(__builtin_popcount(x)>=k)
				{
					if(trace) cout<<s[i].substr(j,j+l-1);
					return 1;
				}
			}
		}
		return 0;
	}
	int solve(void)
	{
		int l=1;
		int r=1e6;
		while(true)
		{
			if(l==r) return r;
			if(r-l==1) return  check(r,false)?r:l  ;
			int mid=(l+r)/2;
			if(check(mid,false)) l=mid;else r=mid-1;
		}
	}
	void xuly()
	{
		int res=solve();
		check(res,true);
	}
}
namespace sub2
{
	
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
















