/*The best way to get something done is to begin*/
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define frd(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define fi first
#define se second
#define TASK "P"
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
const int N=6e6+5;
int n,delta;
int p,q,m;
int a[2*N];
int b[2*N];//goi b[i] la thoi gian hoan thanh bai cua nguoi thu i
/*END*/
void doc()
{
	cin>>n>>delta;
	cin>>p>>q>>m;
	fr(i,1,n)
	{
		a[i]=(p*i)%m+q;
	}
	fr(i,n+1,2*n) a[i]=a[i-n];
	fr(i,1,2*n) b[i]=a[i]+i*delta;
}
namespace sub1
{
	void xuly()
	{
		fr(i,1,n)
		{
			b[i]=a[i]+i*delta;
		}
		deque <int> q;
		int res=inf;
		fr(i,1,2*n)
		{
			while(!q.empty() and b[i]>=b[q.back()]) q.pop_back();
			q.push_back(i);
			while(!q.empty() and i-q.front()+1>n) q.pop_front();
			if(i>=n)	res=min(res,b[q.front()]-(i-n)*delta);
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



















