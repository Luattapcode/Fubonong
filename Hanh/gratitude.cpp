/*The best way to get something done is to begin*/
#include <bits/stdc++.h>
#define ll long long
#define openfile if(fopen("Data.inp","r")) {freopen("Data.inp", "r", stdin); freopen("Data.out", "w", stdout);}
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define frd(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define TASK "gratitude"
using namespace std;
/*Khai Bao*/
const long long inf=1e18;
const int LO=17;
const int CH=27;
const int N=1e5+5;
int cnt=0;
unordered_map <string,int> m;
set <string> s;
unordered_map <string,int> check;
struct bg{
	string x;
	int id;
	int vl;
};
int n,k;	
string p[N];
bool cmp(bg u,bg v)
{
	if(u.vl==v.vl) return u.id>v.id;
	else return u.vl>v.vl;
}
bg a[N];
/*END*/
void doc()
{
	cin>>n>>k;
	cin.ignore();
	fr(i,1,3*n)
	{
		getline(cin,p[i]);
		string x=p[i];
		m[x]++;
		check[x];
	}
	frd(i,3*n,1)
	{
		if(check[p[i]]==0)
		{
			a[++cnt]={p[i],i,m[p[i]]};
			check[p[i]]=1;
		}
	}
	sort(a+1,a+cnt+1,cmp);
	fr(i,1,min(k,cnt)) cout<<a[i].x<<'\n';
}
namespace sub1
{
	void xuly()
	{

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
	freopen(TASK".INP", "r", stdin);
	freopen(TASK".OUT", "w", stdout);
	doc();
	sub1::xuly();
	time();
}
/*
	Name of problem:
	Copyright: Luattapcode
	Author: Huynh Quoc Luat
*/















