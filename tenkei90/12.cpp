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

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

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
    int h,w;
    cin >> h >> w;
    UnionFind uf(h*w);
    bool color[2010][2010];
    int q;
    cin >> q;
    rep(i,q) {
        int t;
        cin >> t;
        if(t==1) {
            int r,c;
            cin >> r >> c;
            r--; c--;
            color[r][c]=1;
            rep(j,4) {
                int nx=r+dx[j],ny=c+dy[j];
                if(nx<0||ny<0) continue;
                if(color[nx][ny]==0) continue;
                uf.unite(w*r+c,w*nx+ny);
            }
        } else {
            int ra,ca,rb,cb;
            cin >> ra >> ca >> rb >> cb;
            ra--; ca--; rb--; cb--; 
            bool flag=false;
            if(color[ra][ca]==1&&color[rb][cb]==1) flag=true;
            if(uf.same(w*ra+ca,w*rb+cb)&&flag) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    } 
    return 0;
}