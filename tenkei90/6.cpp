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

int c[100010][26];

int main()
{
    int n,k;
    string s;
    cin >> n >> k >> s;
    rep(i,26) c[s.size()][i]=s.size();
    for(int i=s.size()-1;i>=0;i--) {
        rep(j,26) {
            if((int)(s[i]-'a')==j) c[i][j]=i;
            else c[i][j]=c[i+1][j];
        }
    }
    string ans;
    int cnt=0;
    for(int i=1;i<=k;i++) {
        rep(j,26) {
            int np=c[cnt][j];
            int len=s.size()-np-1+i;
            if(len>=k) {
                ans+=(char)'a'+j;
                cnt=np+1;
                break;
            }
        }
    }
    cout << ans << endl; 
    return 0;
}