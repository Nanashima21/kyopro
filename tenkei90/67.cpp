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
    string s;
    int n;
    cin >> s >> n;
    rep(i,n) {
        int x=s.size();
        reverse(all(s));
        ll sum=0,k=1;
        rep(j,x) {
            sum+=k*(s[j]-'0');
            k*=8;
        }
        string res;
        if(sum==0) res='0';
        while(sum>0) {
            if(sum%9==8) res+='5';
            else res+=(char)(sum%9)+'0';
            sum/=9;
        }
        reverse(all(res));
        s=res;
    }
    cout << s << endl;
    return 0;
}