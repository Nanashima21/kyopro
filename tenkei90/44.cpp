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
    int n,q;
    cin >> n >> q;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    int cnt=0;
    rep(i,q) {
        int t,x,y;
        cin >> t >> x >> y;
        x--; y--;
        int nx=(n+x-cnt%n)%n;
        int ny=(n+y-cnt%n)%n;
        if(t==1) swap(a[nx],a[ny]); 
        else if(t==2) cnt++; 
        else cout << a[nx] << endl;
    }
    return 0;
}