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
#define TASK "H2METRO"
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
int n,a,x,b,y;
//void add(int &x,const int &y){x+=y;if(x>=sm)x-=sm;}
//void sub(int &x,const int &y){x-=y;if(x<0)x+=sm;}
/*END*/
void doc()
{
	cin>>n>>a>>x>>b>>y;
}
namespace sub1
{
	int kc(int x,int y)
	{
		return (y+n-x)%n;
	}
	void xuly()
	{
		if(kc(a,b)%2==0 and kc(a,x)>=kc(a,b)/2 and kc(y,b)>=kc(a,b)/2) cout<<"YES"<<'\n';
		else if((kc(a,b)+n)%2==0 and kc(a,x)>=(kc(a,b)+n)/2 and kc(y,b)>=((kc(a,b))+n)/2) cout<<"YES"<<'\n';
		else cout<<"NO"<<'\n';
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
	int t;
	cin>>t;
	while(t--)
	{
	doc();
	sub1::xuly();
	}
	time();
}
/* May man chi den voi nhung nguoi co thuc luc */






















