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
const int N=3e5+5;
struct bg{
	int x;
	int y;
};
bg a[N];
bool cmp(bg u,bg v)
{
	return u.x<v.x;
}
int n,A,B;
//void add(int &x,const int &y){x+=y;if(x>=sm)x-=sm;}
//void sub(int &x,const int &y){x-=y;if(x<0)x+=sm;}
/*END*/
void doc()
{
	cin>>n>>A>>B;
	fr(i,1,n)
	{
		cin>>a[i].x>>a[i].y;
	}
	sort(a+1,a+n+1,cmp);
}
namespace sub1
{
	int dem[5];
	int res=inf;
	void xuly()
	{
		int d=1;
		fr(i,1,n)
		{
			dem[a[i].y]++;
			while(dem[1]>=A and dem[2]>=B)
			{
				minimize(res,a[i].x-a[d].x);
				dem[a[d].y]--;
				d++;
			}
		}
		if(res==inf) cout<<-1;
		else cout<<res;	
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
























