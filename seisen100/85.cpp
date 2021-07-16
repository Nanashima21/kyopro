#include <bits/stdc++.h>
using namespace std;
//using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
typedef long long ll;
typedef pair<ll,ll> pl;
//typedef tuple<ll,ll,ll> tupl;

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
    int n,q;
    cin >> n >> q;
    UnionFind uf(n);
    rep(i,q) {
        int c,x,y;
        cin >> c >> x >> y;
        if(c==1) cout << uf.same(x,y) << endl;
        else uf.unite(x,y);
    }
    return 0;
}