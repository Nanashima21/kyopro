#include <bits/stdc++.h>
using namespace std;
//using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;
//typedef tuple<ll,ll,ll> tupl;

int main()
{
    while(true) {
        int n,w1,d1;
        cin >> n >> w1 >> d1;
        if(n==0&&w1==0&&d1==0) break;
        vector<pair<int,int> > v;
        v.push_back({w1*d1,w1});
        rep(i,n) {
            int p,s;
            cin >> p >> s;
            p--;
            int w=v[p].second,d=v[p].first/v[p].second;
            if(s>=w+d) s%=w+d;
            v.erase(v.begin()+p);
            if(0<s&&s<w) {
                if(w-s>s) {
                    v.push_back({s*d,s});
                    v.push_back({abs(w-s)*d,w-s});
                } else {
                    v.push_back({abs(w-s)*d,w-s});
                    v.push_back({s*d,s});
                }
            } else if(w<s&&s<w+d) {
                if(s-w>w+d-s) {
                    v.push_back({abs(w+d-s)*w,w});
                    v.push_back({abs(s-w)*w,w});
                } else {
                    v.push_back({abs(s-w)*w,w});
                    v.push_back({abs(w+d-s)*w,w});
                }
            } 
        }
        sort(all(v));
        int x=v.size();
        rep(i,x) {
            if(i) cout << " ";
            cout << v[i].first;
        }
        cout << endl;
    }
    return 0;
}