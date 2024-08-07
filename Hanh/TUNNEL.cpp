/*The best way to get something done is to begin*/
#include <bits/stdc++.h>
#define ll long long
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define frd(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define fi first
#define se second
#define TASK "TUNNEL"
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
const int N=1e5+5;
struct bg{
	int x;
	int y;
	int z;
};
int f[N];
int n;
struct bg1{
	int x;
	int y;
};
bool cmp1(bg1 u,bg1 v)
{
	return u.y<v.y;
}
vector <bg1> x,y,z;
vector <bg> v;
bool cmp(bg u,bg v)
{
	return u.z<v.z;
}
bg a[N];
/*END*/
void doc()
{
	cin>>n;
	fr(i,1,n)
	{
		cin>>a[i].x>>a[i].y>>a[i].z;
		x.pb({i,a[i].x});
		y.pb({i,a[i].y});
		z.pb({i,a[i].z});
	}
	sort(x.begin(),x.end(),cmp1);
	sort(y.begin(),y.end(),cmp1);
	sort(z.begin(),z.end(),cmp1);
	fr(i,1,x.size()-1)
	{
		v.pb({x[i].x,x[i-1].x,abs(x[i].y-x[i-1].y)});
	}
	fr(i,1,y.size()-1)
	{
		v.pb({y[i].x,y[i-1].x,abs(y[i].y-y[i-1].y)});
	}
	fr(i,1,z.size()-1)
	{
		v.pb({z[i].x,z[i-1].x,abs(z[i].y-z[i-1].y)});
	}
}
namespace sub1
{
	int goc(int x)
	{
		while(f[x]>0) x=f[x];
		return x;
	}
	void hn(int r1,int r2)
	{
		int t=f[r1]+f[r2];
		if(abs(f[r1])>abs(f[r2]))
		{
			f[r1]=t;
			f[r2]=r1;
		}
		else 
		{
			f[r1]=r2;
			f[r2]=t;
		}
	}
	void xuly()
	{
		int res=0;
		int sl=0;
		sort(v.begin(),v.end(),cmp);
		fr(i,1,n) f[i]=-1;
		fr(i,0,v.size()-1)
		{
			int r1=goc(v[i].x);
			int r2=goc(v[i].y);
			if(r1!=r2)
			{
				hn(r1,r2);
				sl++;
				res+=v[i].z;
			}
			if(sl==n-1) break;
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


















