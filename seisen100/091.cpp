#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;
typedef tuple<ll,ll,ll> tupl;

int main()
{
    int a,b,x;
    cin >> a >> b >> x;
    double y=(x*2.0)/(a*b*1.0);
    double ans=atan(y/b);
    ans*=180.0/M_PI;
    ans=90-ans;
  	if(x>a*a*b/2) {
		x=a*a*b-x;
        y=(x*2.0)/(a*a*1.0);
        ans=atan(y/a);
        ans*=180.0/M_PI;
    }
    printf("%.10f\n",ans);
    return 0;
}
