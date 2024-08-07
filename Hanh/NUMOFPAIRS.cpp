/*The best way to get something done is to begin*/
#include <bits/stdc++.h>
#define ll long long
//#define int long long
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
const int N=5e5+5;
int n;
int a[N];
int t[4*N];
int t1[4*N];
int cnt=0;
int v[N];
//void add(int &x,const int &y){x+=y;if(x>=sm)x-=sm;}
//void sub(int &x,const int &y){x-=y;if(x<0)x+=sm;}
/*END*/
void doc()
{
	cin>>n;
	fr(i,1,n) cin>>a[i];
}
namespace sub1
{
	int rmq1[4*N][20];
	int rmq[4*N][20];
	void update(int k,int l,int r,int v,int val)
	{
		if(v<l or v>r) return;
		if(l==r)
		{
			t[k]+=val;
			t1[k]+=val;
			return;
		}
		int mid=(l+r)>>1;
		update(2*k,l,mid,v,val);
		update(2*k+1,mid+1,r,v,val);
		t[k]=__gcd(t[2*k],t[2*k+1]);
		t1[k]=min(t1[2*k],t1[2*k+1]);
	}
	void buildrmq()
	{
		fr(i,1,n) rmq1[i][0]=a[i],rmq[i][0]=a[i];
		for(int j=1;(1<<j)<=n;j++)
		{
			for(int i=1;i+(1<<j)-1<=n;i++)
			{
				rmq[i][j]=__gcd(rmq[i][j-1],rmq[i+(1<<(j-1))][j-1]);
				rmq1[i][j]=min(rmq1[i][j-1],rmq1[i+(1<<(j-1))][j-1]);
			}
		}
	}
	int get(int l,int r)
	{
		int k=log2(r-l+1);
		return __gcd(rmq[l][k],rmq[r-(1<<k)+1][k]);
	} 
	int get1(int l,int r)
	{
		int k=log2(r-l+1);
		return min(rmq1[l][k],rmq1[r-(1<<k)+1][k]);
	}
	void build(int id,int l,int r)
	{
		if(l==r)
		{
			t[id]=a[l];
			t1[id]=a[l];
		}
		else
		{
			int mid=(l+r)>>1;
			build(2*id,l,mid);
			build(2*id+1,mid+1,r);
			t[id]=__gcd(t[2*id],t[2*id+1]);
			t1[id]=min(t1[2*id],t1[2*id+1]);
		}
	}
	bool check(int len)
	{
		fr(i,1,n-len)
		{
			int g=get1(i,i+len);
			int c=get(i,i+len);
			if(g==c) return 1;
		}
		return 0;
	}
	void xuly()
	{
		int length;
		buildrmq();
		int l=0;
		int r=n;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(check(mid))
			{
				length=mid;
				l=mid+1;
			}
			else r=mid-1;
		}
		fr(i,1,n-length)
		{
			int g=get1(i,i+length);
			int c=get(i,i+length);
			if(g==c)
			{
				v[++cnt]=i;
			}
		}
		cout<<cnt<<" "<<length;
		cout<<'\n';
		fr(i,1,cnt) cout<<v[i]<<" ";
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
























