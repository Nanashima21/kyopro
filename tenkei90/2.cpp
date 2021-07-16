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
    if(n%2==1) {
        cout << endl;
        return 0;
    }
    vector<ll> v;
    for(int bit=0;bit<(1<<n);bit++) {
        int cnt=0;
        rep(i,n) if(1<<i&bit) cnt++;
        if(cnt==n/2) v.push_back(bit);
    }
    int x=v.size();
    vector<string> st;
    rep(i,x) {
        bool flag=true;
        string s;
        int cnt=0;
        rep(j,n) {
            if(!flag) break;
            if(1<<j&v[i]) {
                cnt++;
                s+=')';
            } else {
                if(cnt==0) flag=false;
                else {
                    cnt--;
                    s+='(';
                }
            }
        }
        if(flag) {
            reverse(all(s));
            st.push_back(s);
        }
    }
    for(string ans:st) cout << ans << endl;
    return 0;
}