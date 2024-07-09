#include<bits/stdc++.h>
#include<fstream>
#include<random>

using namespace std;

#define endl '\n'
#define PII pair<int,int>
#define F(i,a,b) for(register int i=a;i<=b;++i)
#define PLL pair<long long,long long>
#define lowbit(x) (x&(-x))

mt19937_64 rng(random_device{}());
long long myRand(long long l,long long r) {
    uniform_int_distribution<long long> uid(l,r);
    return uid(rng);
}

const int key=1337;
const int N=1e6+10;
const int MAXN = 5100;
const long long INF=(1ll<<60);
const long long inf=(1ll<<30);
const int mod1=myRand(8e8,1e9);
const int mod2=998244353;
const int mod=1e9+7;

long long qpow(long long x,long long y)
{
	long long tmp=1;
	while(y)
	{
		if(y&1)
		{
			tmp=tmp*x%mod;
		}
		x=x*x%mod;
		y/=2;
	}
	return tmp;
}



void solve()
{
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t=1;
	//cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
