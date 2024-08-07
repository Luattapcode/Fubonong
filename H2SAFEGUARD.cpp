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
const int N=1e5+5;
struct bg{
	int x;
	int y;
};
bg a[N],b[N],h[N];
int n,m;
//void add(int &x,const int &y){x+=y;if(x>=sm)x-=sm;}
//void sub(int &x,const int &y){x-=y;if(x<0)x+=sm;}
/*END*/
void doc()
{
	cin>>n;
	fr(i,1,n)
	{
		cin>>a[i].x>>a[i].y;
	}
	cin>>m;
	fr(i,1,m)
	{
		cin>>b[i].x>>b[i].y;
	}
}
namespace sub1
{
	int v;
	int ccw(bg A,bg B,bg C)
	{
		return (B.x-A.x)*(C.y-B.y)-(C.x-B.x)*(B.y-A.y);
	}
	int dist(bg A,bg B)
	{
		return (A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y);
	}
	int S(bg A,bg B,bg C)
	{
		return abs((B.x-A.x)*(C.y-A.y)-(C.x-A.x)*(B.y-A.y));
	}
	bool cmp1(bg u,bg v)
	{
		if(u.y==v.y) return u.x<v.x;
		else return u.y<v.y;
	}
	bool cmp2(bg u,bg v)
	{
		if(ccw(a[1],u,v)==0) return dist(a[1],u)<dist(a[1],v);
		else return ccw(a[1],u,v)>0;
	}
	bool check(bg p)
	{
		int l=2;
		int r=v;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(ccw(h[1],h[mid],p)>0) l=mid+1;
			else r=mid-1;
		}
		int i=l-1;
		int stg=S(h[1],h[i],h[i+1]);
		int sn=S(h[1],h[i],p)+S(h[1],h[i+1],p)+S(h[i],h[i+1],p);
		return sn==stg;
	}
	void xuly()
	{
		sort(a+1,a+n+1,cmp1);
		sort(a+2,a+n+1,cmp2);
		h[1]=a[1];
		h[2]=a[2];
		a[n+1]=a[1];
		v=2;
		fr(i,2,n+1)
		{
			while(v>=2 and ccw(h[v-1],h[v],a[i])<=0) v--;
			v++;
			h[v]=a[i];
		}
		h[v+1]=h[1];
		int dientichbaoloi=0;
		fr(i,1,v)
		{
			dientichbaoloi+=h[i].x*h[i+1].y-h[i+1].x*h[i].y;
		}
		v--;
		if(dientichbaoloi==0)
		{
			cout<<0;
			return;
		}
		int cnt=0;
		fr(i,1,m)
		{
			if(check(b[i])) cnt++;
		}
		cout<<cnt;
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
























