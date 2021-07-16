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
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll l=0,r=0,cnt=0,ans=0;
    map<ll,int> m;
    deque<ll> q; 
    rep(i,n) {
        if(m[a[i]]==0) cnt++;
        q.push_back(a[i]);
        m[a[i]]++;
        r++;
        while(cnt>k) {
            l++;
            ll u=q.front();
            q.pop_front();
            m[u]--;
            if(m[u]==0) cnt--;
        }
        ans=max(ans,r-l);
    }
    cout << ans << endl;
    return 0;
}