#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
typedef long long ll;

int main()
{
    string s;
    cin >> s;
    int ans=0,x=s.size();
    rep(i,x) {
        rep(j,x) {
            string t=s.substr(i,j+1);           
            int cnt=0;
            bool flag=true;
            for(char c:t) {
                if(c!='A'&&c!='G'&&c!='C'&&c!='T') flag=false; 
                cnt++;
            }
            if(flag) ans=max(cnt,ans);
        }
    }
    cout << ans << endl;
    return 0;
}