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
int n;
struct bg{
	int x;
	int y;
	int z;
};
bool cmp(bg u,bg v)
{
	return u.x<v.x;
}
bg a[N];
int mi=inf;
int ma=-inf;
//void add(int &x,const int &y){x+=y;if(x>=sm)x-=sm;}
//void sub(int &x,const int &y){x-=y;if(x<0)x+=sm;}
/*END*/
void doc()
{
	cin>>n;
	fr(i,1,n)
	{
		cin>>a[i].x>>a[i].y>>a[i].z;
		mi=min(mi,a[i].x);
		ma=max(ma,a[i].x);
	}
}
namespace sub1
{
	int cal(int x)
	{
		int sum=0;
		fr(i,1,n)
		{
			if(a[i].x>x)
			{
				int d=max(x,a[i].x-a[i].z);
				sum+=abs(x-d)*a[i].y;
			}
			else
			{
				int d=min(a[i].x+a[i].z,x);
				sum+=abs(x-d)*a[i].y;
			}
		}
		return sum;
	}
	void xuly()
	{
		int l=mi;
		int res=0;
		int r=ma;
		while(l<r)
		{
			int m1=l+(r-l)/3;
			int m2=r-(r-l)/3;
			int r1=cal(m1);
			int r2=cal(m2);
			if(r1<r2)
			{
				res=r1;
				r=m2-1;
			}
			else 
			{
				res=r2;
				l=m1+1;
			}
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
























