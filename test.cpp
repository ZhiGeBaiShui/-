#include<bits/stdc++.h>
#include<fstream>
#include<random>

using namespace std;

//#define endl '\n'
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
const double eps=1e-10;

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

struct Point
{
    double x, y;
    Point() {}
    Point(double x, double y) :x(x), y(y) {}
};

typedef Point Vector;
Vector operator+(Vector a,Vector b)
{
	return {a.x+b.x,a.y+b.y};
}
Vector operator-(Vector a,Vector b)
{
	return {a.x-b.x,a.y-b.y};
}
Vector operator-(Vector a)
{
    return {-a.x,-a.y};
}

Vector operator*(Vector a,Vector b)
{
	return {a.x*b.x,a.y*b.y};
}
//附加：求垂直向量

Vector get_NomalVector(Vector a)
{
	return {-a.y,a.x};
}

struct node{
	double x,y;
};
Vector operator+(node a,node b)
{
	return {a.x+b.x,a.y+b.y};
}
Vector operator-(node a,node b)
{
	return {a.x-b.x,a.y-b.y};
}

double cross(Vector a,Vector b){
  return a.x*b.y-a.y*b.x;
}//向量叉集

double len(Vector v1)
{
    return sqrt(v1.x*v1.x+v1.y*v1.y);
}

double distance_line(node p,node a,node b)
{
	Vector v1 = b - a,v2 = p - a;
	return fabs(cross(v1,v2) / len(v1));		//cross是v1和v2的叉积
}

bool check_point_line(node p,node a,node b)//判断点是否在直线上
{
    if(distance_line(p,a,b)<=eps)return 1;//distance_line函数为求p到直线ab的距离，点到直线的距离为0，返回1，说明在直线上
    return 0;
}

Vector Vector_len(Vector a,double ld)
{
    double now=ld/len(a);//len为求向量长度的函数
    return {a.x*now,a.y*now};
}

node Get_point(Vector a,node p)
{
    return {p.x+a.x,p.y+a.y};
}

void solve()
{
    double x0,y0,r;
    cin>>x0>>y0>>r;
    int n,k;
    cin>>n>>k;
    vector<pair<double,double>>ans;
    for(int i=1;i<=n;i++)
    {
        double x,y,u,v,s;
        cin>>x>>y>>u>>v>>s;
        u=u-x;
        v=v-y;
        node p1={x,y},p2={x+u,y+v};
        double nowd=distance_line({x0,y0},p1,p2);
        if(nowd>r+eps)continue;
        Vector gt=get_NomalVector({u,v});
        gt=Vector_len(gt,nowd);
        node p={x0+gt.x,y0+gt.y};
        if(check_point_line(p,p1,p2)==0)
        {
            gt=-gt;
            p={x0+gt.x,y0+gt.y};
        }
        gt=Vector_len({u,v},sqrt(r*r-len(gt)*len(gt)));
        node a=Get_point(gt,p),b=Get_point(-gt,p);
        p={x,y};
        if(len(p-a)>=len(p-b))
        {
            swap(a,b);
        }
        if((a.x-x)*u<0||(a.y-y)*v<0)continue;
        //cout<<a.x<<" "<<a.y<<" "<<b.x<<" "<<b.y<<endl;
        double now=len(p-a)/s,nowp=now+len(b-a)/s+k;
        ans.push_back({now,nowp});
    }
    sort(ans.begin(),ans.end());
    double sum=0;
    double l1=-1,r1=-1;
    for(int i=0;i<ans.size();i++)
    {
        if(l1==-1)
        {
            l1=ans[i].first;
            r1=ans[i].second;
        }
        r1=max(ans[i].second,r1);
        if(i==ans.size()-1||r1<ans[i+1].first)
        {
            //cerr<<l1<<" "<<r1<<endl;
            sum+=r1-l1;
            l1=r1=-1;
        }
        //cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
    printf("%.12lf",sum);
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
