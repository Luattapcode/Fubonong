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
const int sm=1e9+7;
int n;
int a[N];
void add(int &x,const int &y){x+=y;if(x>=sm)x-=sm;}
//void sub(int &x,const int &y){x-=y;if(x<0)x+=sm;}
/*END*/
void doc()
{
	cin>>n;
	fr(i,1,n) cin>>a[i];
}
namespace sub1
{
	int l[N];
	int g[N];
	int f[N];
	stack <int> s;
	void xuly()
	{
		a[0]=inf;
		s.push(0);
		fr(i,1,n)
		{
			while(!s.empty() and a[s.top()]<=a[i]) s.pop();
			f[i]=(i-s.top())*a[i]%sm+f[s.top()];
			f[i]=f[i]%sm;
			s.push(i);
		}
		while(!s.empty()) s.pop();
		fr(i,1,n) l[i]=(l[i-1]+f[i])%sm;
		a[n+1]=-inf;
		s.push(n+1);
		frd(i,n,1)
		{
			while(!s.empty() and a[s.top()]>=a[i]) s.pop();
			g[i]=(s.top()-i)*a[i]%sm+g[s.top()];
			g[i]=g[i]%sm;
			s.push(i);
		}
		int res=0;
		fr(i,1,n-1)
		{
			int x=l[i]*g[i+1]%sm;
			add(res,x);
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
























