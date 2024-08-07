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
const int N=2e6+5;
int n,k;
string s;
int res=0;
int dem[N][29];
//void add(int &x,const int &y){x+=y;if(x>=sm)x-=sm;}
//void sub(int &x,const int &y){x-=y;if(x<0)x+=sm;}
/*END*/
void doc()
{
	cin>>n>>k;
	cin>>s;
	s='s'+s;
}
//namespace sub1
//{
//	void xuly()
//	{
//		int res=0;
//		fr(i,1,n)
//		{
//			int ans=0;
//			fr(j,i,n)
//			{
//				ans+=2*dem[s[j]-'a']+1;
//				dem[s[j]-'a']++;
//				if(ans<=k) res++;
//				else break;
//			}
//			fr(j,0,26) dem[j]=0;
//		}
//		cout<<res;
//	}
//}
namespace sub2
{
	int sum[N];
	int check(int mid,int d)
	{
		int luat=0;
		fr(i,0,25)
		{
			int x=dem[mid][i]-dem[d-1][i];
			luat+=x*x;
		}
		return luat<=k;
	}
	void xuly()
	{
		fr(i,1,n)
		{
			fr(j,0,25)
			{
				dem[i][j]=dem[i-1][j];
			}
			dem[i][s[i]-'a']++;
		}
		ll res=0;
		fr(i,1,n)
		{
			int ans=i;
			int l=i;
			int r=n;
			while(l<=r)
			{
				int mid=(l+r)>>1;
				if(check(mid,i)) 
				{
					ans=mid;
					l=mid+1;
				}
				else r=mid-1;
			}
			res+=ans-i+1;
		}
		cout<<res;
	}
}
namespace sub3
{
	int dem[N];
	void xuly()
	{
		int j=0;
		int sum=0;
		int res=0;
		fr(i,1,n)
		{
			while(j<=n and sum<=k)
			{
				j++;
				sum+=dem[s[j]-'a']*2+1;
				dem[s[j]-'a']++;
			}
			res+=j-i;
			dem[s[i]-'a']--;
			sum-=dem[s[i]-'a']*2+1;
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
	sub3::xuly();
	time();
}
