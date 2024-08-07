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
const int N=700+5;
int n;
int a[N];
int f[N][N];
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
	int cal(int i,int j)
	{
		if(i>j) return 0;
		if(i==j) return 0;
		if(i+1==j) return 0;
		if(i+2==j)
		{
			f[i][j]=(a[i]+a[j])*a[i+1];
			return f[i][j];
		}
		if(f[i][j]) return f[i][j];
		fr(k,i+1,j-1)
		{
			maximize(f[i][j],cal(i,k)+cal(k,j)+(a[i]+a[j])*a[k]);
		}
		return f[i][j];
	}
	void xuly()
	{
		cout<<cal(1,n);
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
	sub2 ::xuly();
	time();
}
























