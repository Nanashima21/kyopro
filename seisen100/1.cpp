#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
typedef long long ll;

int main()
{
    while(true) {
        int a,b;
        cin >> a >> b;
        if(a==0&&b==0) break;
        int cnt=0;
        for(int i=1;i<=a;i++) {
            for(int j=i+1;j<=a;j++) {
                for(int k=j+1;k<=a;k++) {
                    if(i+j+k==b) cnt++;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}