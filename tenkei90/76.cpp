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
    ll sum=0;
    vector<ll> a(n);
    rep(i,n) {
        cin >> a[i];
        sum+=a[i];
    }
    sum/=10;
    rep(i,n) a.push_back(a[i]);
    ll cnt=0,tot=0;
    deque<ll> dq;
    rep(i,2*n) {
        tot+=a[i];
        dq.push_back(a[i]);
        cnt++;
        if(tot==sum) {
            cout << "Yes" << endl;
            return 0;
        } 
        while(tot>sum) {
            ll u=dq.front();
            dq.pop_front();
            tot-=u;
            cnt--;
        }
    }
    cout << "No" << endl;
    return 0;
}