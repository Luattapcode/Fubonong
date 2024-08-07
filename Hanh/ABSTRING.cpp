/*The best way to get something done is to begin*/
#include <bits/stdc++.h>
#define ll long long
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define frd(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define fi first
#define se second
#define TASK "ABSTRING"
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
const int N=1e6+5;
string s;
ll f[N];//goi f[i] la do dai dai nhat cua xau con lien tiep ket thuc tai i ma k co 2 ky tu lien tiep nao giong nhau
int n;
/*END*/
void doc()
{
	cin>>n;
	cin>>s;
	s='!'+s;
}
namespace sub1
{
	void xuly()
	{
		if(s[1]=='a') f[1]=1;
		else f[1]=0;
		fr(i,2,n)
		{
			if(s[i]!=s[i-1]) f[i]=f[i-1]+1;
			else
			{
				if(s[i]=='a') f[i]=1;
				else f[i]=0;
			}
		}
		ll res=-inf;
		fr(i,1,n)
		{
			if(f[i]%2==1) res=max(res,f[i]);
		}
		cout<<'a';
		fr(i,1,res/2) cout<<"ba";
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


















