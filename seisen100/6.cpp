#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans=0;
    rep(i,1000) {
        int num=i;
        vector<int> v;
        v.push_back(num/100);
        v.push_back((num/10)%10);
        v.push_back(num%10);
        int l=0;
        for(char y:s) {
            if(v[l]==y-'0') l++;
            if(l==3) {
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}