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
    int n;
    cin >> n;
    ll sum=0,cnt=0;
    rep(i,n) {
        ll d,c;
        cin >> d >> c;
        sum+=d*c;
        cnt+=c;
    }
    cnt--;
    sum--;
    cout << cnt+sum/9 << endl;
    return 0;
}