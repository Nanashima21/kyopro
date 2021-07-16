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
    int n,k;
    cin >> n >> k;
    priority_queue<ll> pq;
    rep(i,n) {
        ll a,b;
        cin >> a >> b;
        pq.push(a-b);
        pq.push(b);
    }
    ll sum=0;
    while(k>0) {
        ll x=pq.top();
        pq.pop();
        sum+=x;
        k--;
    }
    cout << sum << endl;
    return 0;
}