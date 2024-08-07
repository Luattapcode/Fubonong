/*The best way to get something done is to begin*/
#include <bits/stdc++.h>
#define ll long long
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define frd(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define fi first
#define se second
#define TASK "MATOT"
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
const int N=100+5;
int xm[] = {0,-2,-2,-1,1,2,2,1,-1}; 
int ym[] = {0,-1,1,2,2,1,-1,-2,-2};
int xt[]={0,-1,-1,0,1,1,1,0,-1};
int yt[]={0,0,1,1,1,0,-1,-1,-1};
int n,m;
char a[N][N];
pair <int,int> ma,tot;
ll f[N][N][5];
ll g[N][N][5];
struct bg{
	int x;
	int y;
	bool t;
};
/*END*/
void doc()
{
	cin>>n>>m;
	fr(i,1,n)
	{
		fr(j,1,m)
		{
			cin>>a[i][j];
			if(a[i][j]=='M') 
			{
				ma={i,j};
			}
			else if(a[i][j]=='T')
			{
				tot={i,j};
			}
		}
	}
}
namespace sub1
{
	bool F1[N][N],F2[N][N];
	bool inside(int x,int y)
	{
		return x>=1 and x<=n and y>=1 and y<=m;
	}
	void bfs(int u,int v,ll f[N][N][5],int xx[],int yy[],bool F[N][N])
	{
		fr(i,1,n)
		{
			fr(j,1,m)
			{
				fr(t,0,1)
				{
					f[i][j][t]=inf;
				}
			}
		}
		queue <bg> q;
		q.push({u,v,0});
		f[u][v][0]=0;
		while(!q.empty())
		{
			int x=q.front().x;
			int y=q.front().y;
			bool t=q.front().t;
			q.pop();
			fr(i,1,8)
			{
				int nx=x+xx[i];
				int ny=y+yy[i];
				bool w=1-t;
				if(inside(nx,ny) and a[nx][ny]!='#' and f[nx][ny][w]>f[x][y][t]+1)
				{
					f[nx][ny][w]=f[x][y][t]+1;
					q.push({nx,ny,w});
				}
			}
		}
		fr(i,1,n)
		{
			fr(j,1,m)
			{
				fr(k,1,8)
				{
					int nx=i+xx[k];
					int ny=j+yy[k];
					if(inside(nx,ny) and a[nx][ny]!='#')
					{
						F[i][j]=1;
						break;
					}
				}
			}
		}
	}
	void xuly()
	{
		if(ma==tot)
		{
			cout<<0;
			return;
		}
		bfs(ma.fi,ma.se,f,xm,ym,F1);
		bfs(tot.fi,tot.se,g,xt,yt,F2);
		ll res=inf;
		fr(i,1,n)
		{
			fr(j,1,m)
			{
				fr(t,0,1)
				{
					if(a[i][j]!='#' and f[i][j][t]!=inf and g[i][j][t]!=inf)
					{
						if(f[i][j][t]==g[i][j][t])
						{
							res=min(res,f[i][j][t]);
						}
							else if(F1[i][j]==F2[i][j])
							{
								res=min(res,max(f[i][j][t],g[i][j][t]));
							}
						}
					}
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


















