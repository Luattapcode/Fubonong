#include <bits/stdc++.h>
#define ll long long
#define openfile if(fopen("Data.inp","r")) {freopen("Data.inp", "r", stdin); freopen("Data.out", "w", stdout);}
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define frd(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
using namespace std;
int b,a,u,v;
const int dx[] = {-1, -2, 1, 2, -1, -2,  1,  2};
const int dy[] = {-2, -1, 2, 1,  2,  1, -2, -1};
short d[2201][2201];
#define dist(x,y) d[(x)+100][(y)+100]
bool inside(int x,int y)
{
	return -100<=x and x<=2100 and -100<=y and y<=2100;
}
void xuly()
{
	memset(d,-1,sizeof(d));
	dist(0,0)=0;
	queue <pair<int,int>> q;
	q.push(make_pair(0,0));
	while(!q.empty())
	{
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		fr(i,0,7)
		{
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(inside(nx,ny) and dist(nx,ny)<0)
			{
				dist(nx,ny)=dist(x,y)+1;
				q.push(make_pair(nx,ny));
			}
		}
	}
}
void time()
{
	cerr<< endl<<"Time: "<<clock()<<"ms"<<endl;
}
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("KNIGHT.INP", "r", stdin);
	freopen("KNIGHT.OUT", "w", stdout);
	xuly();
	int q;
	cin>>q;
	fr(i,1,q)
	{
		ll a,b,u,v;
		cin>>a>>b>>u>>v;
		int x=abs(u-a);
		int y=abs(v-b);
		cout<<dist(x,y)<<" ";
	}
	time();
}


