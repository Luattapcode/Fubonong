#include <bits/stdc++.h>
#define ll long long
#define boxanglua ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define fr(i,a,b) for(long long i=a;i<=b;i++)
#define frd(i,a,b) for(long long i=a;i>=b;i--)
using namespace std;
ll x,y,a,b,m;
vector<ll> v;
int f[5005][5005];
void doc()
{
	cin>>x>>a>>y>>b>>m;
	fr(i,1,x) v.push_back(a);
	fr(i,1,y) v.push_back(b);
	sort(v.begin(),v.end());
}
    bool check(int w){
        fr(i,0,x) fr(j,0,y) f[i][j] = 0;
        fr(i,0,x){
            fr(j,0,y){
                fr(k,0,i){
                    int dd = w - k*a;
                    int cur ;
                    if(dd<0) cur = 0;
                    else cur = dd/b + (dd%b!=0);
                    if(j>=cur)f[i][j] = max(f[i][j],f[i-k][j-cur] + 1);
                }
            }
        }
        return (f[x][y]>=m);
    }
void xuly()
{
	ll d=0;
	ll c=x*a+b*y;
	while(d+1<c)
	{
		ll mid=(d+c)/2;
		if(check(mid)==1) d=mid;
		else c=mid;
	}
	if(check(c)==1)
	{
		cout<<c;
		return;
	}
	else cout<<d;
}
int main()
{
	//freopen(".INP", "r", stdin);
	//freopen(".OUT", "w", stdout);
	boxanglua
	doc();
	xuly();
}
