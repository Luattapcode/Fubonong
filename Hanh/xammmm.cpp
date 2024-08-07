  /*DQN*/
    #define TASK "changedir"
    #define INPUT TASK".INP"
    #define OUTPUT TASK".OUT"
    bool mtt = 0 ;
    int test = 1 ;

    #include<bits/stdc++.h>
    using namespace std;

    #define             ll  long long
    // #define         int  long long
    #define             db  double
    #define             iv  vector<int>
    #define            str  string
    #define             pb  push_back
    #define             pk  pop_back
    #define             el  '\n'
    #define             ii  pair<int,int>
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

    int fx[] = {0,1,1,2,1} ;
    int fy[] = {1,0,1,1,2} ;

    const ll inf = 1e18 ;
    const int sm = 998244353 ;
    const int maxn = 2207+5 , oo = 2e9 ;

    int n , m ;
    bool a[maxn][maxn] ;

    void doc(){
        cin >> n >> m ;
        fok(i,1,n)  fok(j,1,m)
        {
            char x ; 
            cin >> x ; 
            a[i][j] = ( x == '.' ) ;
        }   
    }

    namespace sub1{
        
        int f[maxn][maxn][6] ;

        bool in( int x , int y )    { return 1 <= x and 1 <= y and x <= n and y <= m and a[x][y]==1;  }

        void solve()
        {
            if( n == 1 and m == 1 ) { cout << 1 ; return ; }
            fok(i,0,4)
		{
			ll dx=fx[i]+1;
			ll dy=fy[i]+1;
			if(dx>=1 and dx<=n and dy>=1 and dy<=m and a[dx][dy])
			{
				f[dx][dy][i]=1;
			}
		}
            fok(i,1,n)  fok(j,1,m)  if( a[i][j] )
            {
                fok(p,0,4)
                {
                    int x = i - fx[p] ;
                    int y = j - fy[p] ;
                    if( !in( x , y ) )  continue ;
                    fok(q,0,4)  if( p != q )    f[i][j][p] = ( f[i][j][p] + f[x][y][q] ) % sm ;
                }
            }
            ll res = 0 ;
            fok(k,0,4)  res=(res+f[n][m][k])%sm;
            cout << res ;
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
        if(mtt) cin >> test;
        fok(i,1,test)
        {
            doc() ;
            sub1::solve() ;
        }
        // cerr << el << clock() << "ms" << el ;
    }
