/*DQN*/
#define TASK "harvest"
#define INPUT TASK".INP"
#define OUTPUT TASK".OUT"
bool mtt = 0 ;
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
const int maxn = 1e5+5 , oo = 2e9 ;

int n , m ;
int a[maxn] , b[maxn] ;

void doc(){
	// cin >> n >> m ;
	fok(i,1,n)	cin >> a[i] ;
	fok(i,1,m)	cin >> b[i] ;
	sort( a + 1 , a + n + 1 ) ;
	sort( b + 1 , b + m + 1 ) ;
}

namespace sub1{
	
	bool check( int t )
	{
		int j = 1 ; 
		fok(i,1,n)
		{
			if( j > m )	return 1 ; 
			if( b[j] >= a[i] )	j = upper_bound( b + 1 , b + m + 1 , a[i] + t ) - b ; 
			else {
				if( a[i] - b[j] > t )	return 0 ; 
				int pos = upper_bound( b + 1 , b + m + 1 , max( t + 2*b[j] - a[i] , ( t + a[i] + b[j] ) / 2 ) ) - b ;
				j = max( j , pos ) ;
			}
		}
		return j > m ; 
	}

	void solve()
	{
		int l = 0 , r = inf , res = -1 ; 
		while( l <= r )
		{
			int mid = ( l + r ) >> 1 ; 
			if( check( mid ) )	res = mid , r = mid-1 ; 
			else l = mid+1 ;
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
    // int subtask ; cin >> subtask ;
    if(mtt)	cin >> test;
    while( cin >> n >> m )
    {
    	if( n == 0 and m == 0 )	break ;
        doc() ;
        sub1::solve() ;
    }
    cerr << el << clock() << "ms" << el ;
}

