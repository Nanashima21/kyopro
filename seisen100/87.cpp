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

struct UnionFind {
   vector<int> v;
   UnionFind(int n=0): v(n,-1) {}
   int find(int x) {
       if(v[x]<0) return x;
       return v[x]=find(v[x]);
   }
   bool unite(int x,int y) {
       x=find(x);
       y=find(y);
       if(x==y) return false;
       if(v[x]>v[y]) swap(x,y);
       v[x]+=v[y];
       v[y]=x;
       return true;
   }
   bool same(int x,int y) { return find(x)==find(y); }
   int size(int x) { return -v[find(x)]; }
   //UnionFind uf(n);
};

int main()
{
    int n,m;
    cin >> n >> m;
    vector<ll> a(m),b(m);
    rep(i,m) {
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
    }
    vector<ll> ans;
    ll tot=1LL*n*(n-1)/2;
    ans.push_back(tot);
    UnionFind uf(n);
    rep(i,m-1) {
        int j=m-i-1;
        ll x=uf.size(a[j]),y=uf.size(b[j]);
        if(!uf.same(a[j],b[j])) {
            tot-=1LL*x*y;
            uf.unite(a[j],b[j]);
        }
        ans.push_back(tot);
    }
    reverse(all(ans));
    rep(i,m) cout << ans[i] << endl;
    return 0;
}