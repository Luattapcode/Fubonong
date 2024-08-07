/*The best way to get something done is to begin*/
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define frd(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define fi first
#define se second
#define TASK "PRE_MINE"
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
struct bg1{
	int id;
	int vl;
};
int ma[N];
bg1 b[N];
bg a[N];
int s[N];
int sum[N];
bool cmp(bg u,bg v)
{
	return u.x<v.x;
}
bool cmp1(bg1 u,bg1 v)
{
	return u.vl<v.vl;
}
int n;
/*END*/
void doc()
{
	cin>>n;
	fr(i,1,n)
	{
		cin>>a[i].x>>a[i].y>>a[i].z;
	}
	sort(a+1,a+n+1,cmp);
	fr(i,1,n)
	{
		s[i]=s[i-1]+a[i].y;
	}
	fr(i,1,n)
	{
		sum[i]=sum[i-1]+a[i].z;
	}
}
namespace sub1
{
	void xuly()
	{
		int res=0;
		fr(i,1,n)
		{
			fr(j,i,n)
			{
				if(sum[j]-sum[i-1]>=a[j].x-a[i].x)
				{
					res=max(res,s[j]-s[i-1]);
				}
			}
		}
		cout<<res;
	}
}
namespace sub2
{
	int tknp(int x)
	{
		int d=1;
		int c=n;
		while(d+1<c)
		{
			int mid=(d+c)/2;
			if(b[mid].vl>=x) c=mid;
			else d=mid;
		}
		if(b[d].vl>=x) return d;
		else if(b[c].vl>=x) return c;
		else return -1;
	}
	int sum1[N];
	void xuly()
	{
		fr(i,1,n) sum1[i]=sum[i]-a[i].x;
		fr(i,1,n) b[i]={i,sum1[i]};
		ma[n+1]=0;
		sort(b+1,b+n+1,cmp1);
		frd(i,n,1)
		{
			ma[i]=max(ma[i+1],s[b[i].id]);
		}
		int res=0;
		fr(i,1,n)
		{
			int j=tknp(sum[i-1]-a[i].x);
			if(j==-1) continue;
			res=max(res,ma[j]-s[i-1]);
		}
		cout<<res;
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
	if(n<=5000) sub1::xuly();
	else sub2::xuly();
	time();
}



















