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

template<int P>
struct MInt {
    int x;
    constexpr MInt(): x(0) {}
    template<class T>
    constexpr MInt(T x): x(norm(x%P)) {}
    constexpr static int norm(int x) {
        return x<0? x+P: x>=P? x-P: x;
    }
    constexpr MInt inv() const{
        int a=x, b=P, u=1, v=0;
        while(b) {
            int t = a/b;
            swap((a-=t*b), b);
            swap((u-=t*v), v);
        }
        return u;
    }
    constexpr MInt operator-() const{
        return MInt()-*this;
    }
    constexpr MInt& operator+=(const MInt& a) {
        x=norm(x+a.x);
        return *this;
    }
    constexpr MInt& operator-=(const MInt& a) {
        x=norm(x-a.x);
        return *this;
    }
    constexpr MInt& operator*=(const MInt& a) {
        x=1ll*x*a.x%P;
        return *this;
    }
    constexpr MInt& operator/=(const MInt& a) {
        return *this*=a.inv();
    }
    constexpr friend MInt operator+(MInt l,const MInt& r) {
        return l+=r;
    }
    constexpr friend MInt operator-(MInt l,const MInt& r) {
        return l-=r;
    }
    constexpr friend MInt operator*(MInt l,const MInt& r) {
        return l*=r;
    }
    constexpr friend MInt operator/(MInt l,const MInt& r) {
        return l/=r;
    }
    constexpr explicit operator bool()const {
        return x!=0;
    }
    constexpr bool operator!()const {
        return x==0;
    }
    friend ostream& operator<<(ostream& os,const MInt& a) {
        return os<<a.x;
    }
    string find_Fraction()const {
        for(int i=1; i<=1000000; ++i) {
            if((*this*i).x<=100) {
                return to_string((*this*i).x) + "/" + to_string(i);
            }
        }
        return "not find.";
    }
};
constexpr int P=1e9+7;
 
using Z=MInt<P>;


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
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
