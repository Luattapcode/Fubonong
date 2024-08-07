/*The best way to get something done is to begin*/
#include <bits/stdc++.h>
#define ll long long
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define frd(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define fi first
#define se second
#define TASK "FBCL"
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
const int N=1e5+5;
string x="";
int n;
char s[N];
/*END*/
void doc()
{
	cin>>n;
	fr(i,1,n) cin>>s[i];
}
namespace sub1
{
	void xuly()
	{
		int d=1;
		int c=n;
		while(d<=c)
		{
			if(s[d]<s[c])
			{
				x+=s[d];
				d++;
			}
			else if(s[d]>s[c])
			{
				x+=s[c];
				c--;
			}
			else 
			{
				int ok=0;
				int l=d+1;
				int r=c-1;
				while(s[l]==s[r])
				{
					l++;
					r--;
					if(l==r)
					{
						ok=1;
						break;
					}
					if(r-1==l) break;
					if(s[l]!=s[r]) break;
				}
				if(ok==1)
				{
					d++;
					x+=s[d];
				}
				else 
				{
					if(s[l]>s[r])
					{
						x+=s[c];
						c--;
					}
					else 
					{
						x+=s[d];
						d++;
					}
				}
			}
		}
		x='^'+x;
		fr(i,1,x.size()-1)
		{
			cout<<x[i];
			if(i%80==0) cout<<'\n';
		}
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


















