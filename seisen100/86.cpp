#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
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
    vector<int> a(m),b(m);
    rep(i,m) {
       cin >> a[i] >> b[i];
       a[i]--; b[i]--;
    }
    int ans=0;
    rep(i,m) {
        UnionFind uf(n);
        rep(j,m) {
            if(i==j) continue;
            uf.unite(a[j],b[j]);
        }
        int cnt=0;
        rep(j,n) if(j==uf.find(j)) cnt++;
        if(cnt>1) ans++;
    }
    cout << ans << endl;
    return 0;
}