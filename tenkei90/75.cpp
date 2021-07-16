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

vector<pair<ll,ll>> prime_factorize(ll N) {
   vector<pair<ll,ll>> res;
   for (ll a = 2; a * a <= N; ++a) {
       if (N % a != 0) continue;
       ll ex = 0;
       while (N % a == 0) {
           ++ex;
           N /= a;
       }
       res.push_back({a, ex});
   }
   if (N != 1) res.push_back({N, 1});
   return res;
   //const auto &res = prime_factorize(n);
}

int main()
{
    ll n;
    cin >> n;
    const auto &res = prime_factorize(n);
    ll cnt=0,ans=0;
    for(auto x:res) cnt+=x.second;
    for(int i=0;;i++) {
        if(cnt==1) {
            cout << 0 << endl;
            return 0;
        } else if(pow(2,i)<cnt&&cnt<=pow(2,i+1)) {
            ans=i+1;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}