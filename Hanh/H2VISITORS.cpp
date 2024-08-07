/*The best way to get something done is to begin*/
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define frd(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define fi first
#define se second
#define dembit1(x) __builtin_popcount(x)
#define TASK "H2VISITORS"
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
const int N=1e5+6;
struct bg{
	int x;
	int y;
};
int n;
int a[N];
int s[N];
//void add(int &x,const int &y){x+=y;if(x>=sm)x-=sm;}
//void sub(int &x,const int &y){x-=y;if(x<0)x+=sm;}
/*END*/
void doc()
{
	cin>>n;
	fr(i,1,n) cin>>a[i];
}
//namespace sub1
//{
//	const int N=1e3+5;
//	int w[N][N];//goi wij la quang duong di tu nha i-j 1 xe
//	int f[N];//fi la quang duong it nhat de dii het tu nha 1-i 1 xe 
//	void xuly()
//	{
//		fr(i,1,n) s[i]=s[i-1]+abs(a[i]-a[i-1]);
//		fr(i,0,n)
//		{
//			fr(j,0,n)
//			{
//				w[i][j]=abs(s[j]-s[i]);
//			}
//		}
//		fr(i,1,n)
//		{
//			f[i]=w[0][i];
//			fr(j,1,i-1)
//			{
//				f[i]=min(f[i],f[j]+abs(a[i]-a[j-1])+w[j][i-1]);
//			}
//		}
//		int res=inf;
//		fr(i,1,n)
//		{
//			res=min(res,f[i]+w[i][n]);
//		}
//		fr(i,1,n) cout<<f[i]<<" ";
//		cout<<'\n';
//	}
//}
namespace sub2
{
	const int N=1e6+6;
	int t1[4*N];
	int t2[4*N];
	int f[N];
	int s[N];
	void update1(ll k,ll l,ll r,ll v,ll val)
	{
		if(v<l or v>r) return;
		if(l==r)
		{
			t1[k]=min(val,t1[k]);
			return;
		}
		ll mid=(l+r)/2;
		update1(2*k,l,mid,v,val);
		update1(2*k+1,mid+1,r,v,val);
		t1[k]=min(t1[2*k],t1[2*k+1]);
	}
	void update2(ll k,ll l,ll r,ll v,ll val)
	{
		if(v<l or v>r) return;
		if(l==r)
		{
			t2[k]=min(val,t2[k]);
			return;
		}
		ll mid=(l+r)/2;
		update2(2*k,l,mid,v,val);
		update2(2*k+1,mid+1,r,v,val);
		t2[k]=min(t2[2*k],t2[2*k+1]);
	}
	ll get1(ll k,ll l,ll r,ll u,ll v)
	{
		if(v<l or u>r) return inf;
		if(u<=l and v>=r) return t1[k];
		ll mid=(l+r)/2;
		ll m1=get1(2*k,l,mid,u,v);
		ll m2=get1(2*k+1,mid+1,r,u,v);
		return min(m1,m2);
	}
	ll get2(ll k,ll l,ll r,ll u,ll v)
	{
		if(v<l or u>r) return inf;
		if(u<=l and v>=r) return t2[k];
		ll mid=(l+r)/2;
		ll m1=get2(2*k,l,mid,u,v);
		ll m2=get2(2*k+1,mid+1,r,u,v);
		return min(m1,m2);
	}
	vector <int> ve;
	unordered_map <int,int> mp;
	void nen()
	{
		fr(i,0,n) ve.push_back(a[i]);
		sort(ve.begin(),ve.end());
		ve.resize(unique(ve.begin(),ve.end())-ve.begin());
		fr(i,0,ve.size()-1) mp[ve[i]]=i+1;
	}
	void xuly()
	{
		fr(i,1,n) s[i]=s[i-1]+abs(a[i]-a[i-1]);
		nen();
		fr(k,1,4*ve.size()) t1[k]=inf,t2[k]=inf;
		f[1]=abs(a[1]);
		update1(1,1,ve.size(),mp[a[0]],f[1]-s[1]-a[0]);//x[i]>=x[j-1]
		update2(1,1,ve.size(),mp[a[0]],f[1]-s[1]+a[0]);//x[i]<x[j-1]
		fr(i,2,n)
		{
			int res1=get1(1,1,ve.size(),1,mp[a[i]])+s[i-1]+a[i];
			int res2=get2(1,1,ve.size(),mp[a[i]]+1,ve.size())+s[i-1]-a[i];
			f[i]=min(res2,res1);
			update1(1,1,ve.size(),mp[a[i-1]],f[i]-s[i]-a[i-1]);
			update2(1,1,ve.size(),mp[a[i-1]],f[i]-s[i]+a[i-1]);
		}
		int res=inf;
		fr(i,1,n)
		{
			res=min(res,f[i]+s[n]-s[i]);
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
	sub2::xuly();
	time();
}
/* May man chi den voi nhung nguoi co thuc luc */






















