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
const int N=2e5+5;
int n,q;
set <int> s;
//void add(int &x,const int &y){x+=y;if(x>=sm)x-=sm;}
//void sub(int &x,const int &y){x-=y;if(x<0)x+=sm;}
/*END*/
void doc()
{
	cin>>n>>q;
}
namespace sub1
{
	void xuly()
	{
		set <int> ::iterator it;
		while(q--)
		{
			int x;
			cin>>x;
			it=s.lower_bound(x);
			if(s.empty()) s.insert(x);
			else
			{
			if(*it==x) s.erase(x);
			else s.insert(x);
			}
			int len;
			int ans=0;
			if(s.empty()) cout<<1<<'\n';
			else 
			{
			if(*s.begin()==1) len=0;
			else len=1;
			int pre=0;
			for(it=s.begin();it!=s.end();it++)
			{
				if(pre==0)
				{
					len++;
					pre=*it;
				}
				else 
				{
					if(pre==*it-2)
					{
						len+=2;
						pre=*it;
					}
					else
					{
						if(*it-1!=pre) maximize(ans,len+1),len=2;
						else maximize(ans,len),len=1;
						pre=*it;
					}
				}
			}
			if(*s.rbegin()==n) maximize(ans,len);
			else maximize(ans,len+1);
			cout<<ans<<'\n';
		}
	}
	}
}
namespace sub2
{
	struct bg{
		int l;
		int r;
		int len;
		int ma;
		int d;
		int c;
	};
	bg t[4*N];
	void update(int k,int l,int r,int v,int val)
	{
		if(v>r or v<l) return;
		if(l==r)
		{
			t[k].d=val;
			t[k].c=val;
			return;
		}
		int mid=(l+r)>>1;
		update(2*k,l,mid,v,val);
		update(2*k+1,mid+1,r,v,val);
		t[k].c=t[2*k+1].c;
		t[k].d=t[2*k].d;
		t[k].len=t[2*k+1].len+t[2*k].len;
		t[k].l=t[2*k].l;
		if(t[2*k].l==t[2*k].len and t[2*k].c!=t[2*k+1].d)
		{
			t[k].l=t[2*k].l+t[2*k+1].l;
		}
		t[k].r=t[2*k+1].r;
		if(t[2*k+1].r==t[2*k+1].len and t[2*k].c!=t[2*k+1].d)
		{
			t[k].r=t[2*k].r+t[2*k+1].r;
		}
		t[k].ma=max({t[2*k].ma,t[2*k+1].ma,t[k].l,t[k].r});
		if(t[2*k].c!=t[2*k+1].d) t[k].ma=max(t[k].ma,t[2*k].r+t[2*k+1].l);
	}
	void build(int k,int l,int r)
	{
		if(l==r)
		{
			t[k]={1,1,1,1,1,1};
			return;
		}
		else 
		{
			int mid=(l+r)>>1;
			build(2*k,l,mid);
			build(2*k+1,mid+1,r);
		t[k].c=t[2*k+1].c;
		t[k].d=t[2*k].d;
		t[k].len=t[2*k+1].len+t[2*k].len;
		t[k].l=t[2*k].l;
		if(t[2*k].l==t[2*k].len and t[2*k].c!=t[2*k+1].d)
		{
			maximize(t[k].l,t[2*k].l+t[2*k+1].l);
		}
		t[k].r=t[2*k+1].r;
		if(t[2*k+1].r==t[2*k+1].len and t[2*k].c!=t[2*k+1].d)
		{
			maximize(t[k].r,t[2*k].r+t[2*k+1].r);
		}
		t[k].ma=max({t[2*k].ma,t[2*k+1].ma,t[k].l,t[k].r});
		if(t[2*k].c!=t[2*k+1].d) t[k].ma=max(t[k].ma,t[2*k].r+t[2*k+1].l);
		}
	}
	int a[N];
	void xuly()
	{
		fr(i,1,n) a[i]=1;
		build(1,1,n);
		while(q--)
		{
			int u;
			cin>>u;
			a[u]=1-a[u];
			update(1,1,n,u,a[u]);
			cout<<t[1].ma<<'\n';
		}
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
	sub2::xuly();
	time();
}
























