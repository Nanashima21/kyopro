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
    int q;
    cin >> q;
    deque<ll> dq;
    rep(i,q) {
        ll t,x;
        cin >> t >> x;
        if(t==1) dq.push_front(x);
        else if(t==2) dq.push_back(x);
        else cout << dq.at(x-1) << endl;
    }
    return 0;
}