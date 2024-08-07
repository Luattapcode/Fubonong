/*The best way to get something done is to begin*/
#include <bits/stdc++.h>
#define ll long long
#define openfile if(fopen("Data.inp","r")) {freopen("Data.inp", "r", stdin); freopen("Data.out", "w", stdout);}
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define frd(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define TASK "discounts"
using namespace std;
/*Khai Bao*/
const long long inf=1e18;
const int LO=17;
const int CH=27;
const int N=3e5+5;
ll X;
ll n,k;
ll p[N];
ll t[N];
struct bg{
	ll price;
	ll id;
	ll type;
};
vector <int> v[N];
bool cmp(bg u,bg v)
{
	if(u.type==v.type) return u.price>v.price;
	else return u.type<v.type;
}
bg a[N];
ll cnt=0;
/*END*/
void doc()
{
	cin>>X;
	cin>>n>>k;
	fr(i,1,n)
	{
		cin>>p[i]>>t[i];
	}
}
namespace sub1
{
	void xuly()
	{
		double res=0;
		fr(i,1,n)
		{
			a[i]={p[i],i,t[i]};
		}
		fr(i,1,n)
		{
			if(a[i].type==1) cnt++;
		}
		sort(a+1,a+n+1,cmp);
		if(cnt<k)
		{
			fr(i,1,cnt)
			{
				res+=a[i].price/2;
				v[i].pb(a[i].id);
			}
			fr(i,cnt+1,n)
			{
				res+=a[i].price;
			}
			fr(i,cnt+1,k-1)
			{
				v[i].pb(a[i].id);
			}
			fr(i,k,n)
			{
				v[k].pb(a[i].id);
			}
			cout<<setprecision(1)<<fixed<<(double)res;
			cout<<'\n';
			fr(i,1,k)
			{
				cout<<v[i].size()<<" ";
				for(auto luat:v[i]) cout<<luat<<" ";
				cout<<'\n';
			}
		}
		else 
		{
			fr(i,1,k-1)
			{
				res+=a[i].price;
				v[i].pb(a[i].id);
			}
			res+=min(a[cnt].price,a[n].price);
			res=res/2;
			fr(i,k,n)
			{
				res+=a[i].price;
				v[k].pb(a[i].id);
			}
			res-=min(a[cnt].price,a[n].price);
			cout<<setprecision(1)<<fixed<<(double) res<<'\n';
			fr(i,1,k)
			{
				cout<<v[i].size()<<" ";
				for(auto luat:v[i]) cout<<luat<<" ";
				cout<<'\n';
			}
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















