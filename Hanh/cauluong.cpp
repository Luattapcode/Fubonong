/*The best way to get something done is to begin*/
#include <bits/stdc++.h>
#define ll long long
#define openfile if(fopen("Data.inp","r")) {freopen("Data.inp", "r", stdin); freopen("Data.out", "w", stdout);}
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define frd(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define TASK "cauluong"
using namespace std;
/*Khai Bao*/
const long long inf=1e18;
const int LO=17;
const int CH=27;
const int N=150000;
ll n,l,m,r;
ll p[N];
/*END*/
void doc()
{
	cin>>n>>m>>l>>r;
	fr(i,1,m)
	{
		cin>>p[i];
	}
}
namespace sub1
{
	void xuly()
	{
		sort(p+1,p+m+1);
		ll ans=0;
		fr(i,2,m)
		{
			if(p[i]<l or p[i-1]>r) continue;
			if(p[i]==p[i-1]+1) continue;
			if(p[i-1]<=l and p[i]>=r)
			{
				ll mid=(p[i-1]+p[i])/2;
				if(mid>=l and mid<=r) ans=max(ans,min(abs(mid-p[i]),abs(mid-p[i-1])));
				else 
				if(mid>=r)
				{
					ans=max(ans,r-p[i-1]);
				}
				else if(mid<=l)
				{
					ans=max(ans,p[i]-l);
				}
			}
			else if(p[i]>=l and p[i]<=r and p[i-1]<l)
			{
				ll mid=(p[i]+p[i-1])/2;
				if(mid>=l)
				{
					ans=max(ans,min(abs(mid-p[i]),abs(mid-p[i-1])));
				}
				else 
				{
					ans=max(ans,min(abs(l-p[i]),abs(l-p[i-1])));
				}
			}
			else if(p[i]>r and p[i-1]>=l and p[i-1]<=r)
			{
				ll mid=(p[i]+p[i-1])/2;
				if(mid<=r)
				{
					ans=max(ans,min(abs(mid-p[i]),abs(mid-p[i-1])));
				}
				else 
				{
					ans=max(ans,min(abs(r-p[i]),abs(r-p[i-1])));
				}
			}
			else if(p[i-1]>=l and p[i-1]<=r and p[i]>=l and p[i]<=r)
			{
				ll mid=(p[i]+p[i-1])/2;
				ans=max(ans,min(abs(mid-p[i]),abs(mid-p[i-1])));
			}
		}
		cout<<ans<<" ";
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
	ll X,T;
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen(TASK".INP", "r", stdin);
	freopen(TASK".OUT", "w", stdout);
	cin>>X>>T;
	while(T--)
	{
	doc();
	sub1::xuly();
}
	time();
}
/*
	Name of problem:
	Copyright: Luattapcode
	Author: Huynh Quoc Luat
*/
/*
	#define TASK "cauluong"
	#define INPUT TASK".INP"
	#define OUTPUT TASK".OUT"
	bool mtt = 1 ;
	int test = 1 ;

	#include<bits/stdc++.h>
	using namespace std;

	#define             ll  long long
	#define 		   int  long long
	#define             db  double
	#define             iv  vector<int>
	#define            str  string
	#define             pb  push_back
	#define             pk  pop_back
	#define             el  '\n'
	#define            	ii  pair<int,int>
	#define             mp  make_pair
	#define             fi  first
	#define             se  second
	#define     fok(i,a,b)  for(int i=(int)(a);i<=(int)(b);i++)
	#define     fod(i,a,b)  for(int i=(int)(a);i>=(int)(b);i--)
	#define         all(a)  a.begin(),a.end()
	#define     BIT(msk,i)  (msk>>(i)&1)
	#define        Mask(i)  (1ll<<(i))
	#define           btpc  __builtin_popcountll
	#define            ctz  __builtin_ctzll

	int fx[] = {0,-1,0,1} ;
	int fy[] = {-1,0,1,0} ;

	const int inf = 1e18 , sm = 1e9+7;
	const int maxn = 1e6+5 , oo = 2e9 ;

	int n , m , l , r ;
	int p[maxn] ;

	void doc(){
		cin >> n >> m >> l >> r ;
		fok(i,1,m)	cin >> p[i] ;	
	}

	namespace sub1
	{
			
		void solve()
		{
			sort( p + 1 , p + m + 1 ) ;
			int res = 0 ; 
			int u = lower_bound( p + 1 , p + m + 1 , l ) - p ;
			if( u == 1 )	res = max( res , p[u] - l  ) ;
			else res = max( res , min( p[u] - l , l - p[u-1] ) ) ;
			int v = upper_bound( p + 1 , p + m + 1 , r ) - p - 1 ; 
			if( v == m )	res = max( res , r - p[v] ) ;
			else res = max( res , min( r - p[v] , p[v+1] - r ) ) ;
			fok(i,1,m-1)
			{
				if( p[i] + 1 == p[i+1] )	continue ;
				int mid = ( p[i] + p[i+1] ) / 2 ; 
				if( l <= mid and mid <= r )	res = max( res , min( mid - p[i] , p[i+1] - mid ) ) ;
			}
			cout << res << ' ' ; 
		}

	}

	namespace sub2 {
		
		void solve() {

		}

	}

	signed main()
	{
	    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0));
	    if(fopen(INPUT,"r"))
	    {
	        freopen(INPUT ,"r",stdin) ;
	        freopen(OUTPUT,"w",stdout);
	    }
	    int subtask ; 
	    cin >> subtask ;
	    if(mtt)	cin >> test;
	    fok(i,1,test)
	    {
	        doc() ;
	        sub1::solve() ;
	    }
	    cerr << el << clock() << "ms" << el ;
	}
/*















