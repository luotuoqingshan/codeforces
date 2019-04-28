#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int dp[105][105][3];

int eat[105];

int n, m;
void upd(int &a, int b){
    a = max(a, b);
}
int a[105];

int main(){
    while(cin >> n >> m){
        for(int i = 1;i <= n;i++){
            scanf("%d", &a[i]);
        }
        eat[0] = m;
        eat[1] = m;
        for(int i = 2;i <= n;i++){
            eat[i] = eat[i - 1] * 2 / 3;
        }
        memset(dp, -1, sizeof(dp));
        dp[0][0][0] = 0;
        dp[0][0][1] = 0;
        dp[0][0][2] = 0;
        for(int i = 0;i <= n;i++){
            for(int j = 0;j <= n;j++){
                if(dp[i][j][0] != -1){
                    upd(dp[i + 1][j + 1][0], dp[i][j][0] + min(a[i + 1], eat[j + 1]));
                    upd(dp[i + 1][j][1], dp[i][j][0]);
                    //cout << i << " " << j << " " << 0 << " " << dp[i][j][0] << endl;
                }
                if(dp[i][j][1] != -1){
                    if(j > 0)upd(dp[i + 1][j][0], dp[i][j][1] + min(a[i + 1], eat[j]));
                    upd(dp[i + 1][j][2], dp[i][j][1]);
                    //cout << i << " " << j << " " << 1 << " " << dp[i][j][1] << endl;
                }
                if(dp[i][j][2] != -1){
                    upd(dp[i + 1][1][0], dp[i][j][2] + min(a[i + 1], eat[1]));
                    upd(dp[i + 1][j][2], dp[i][j][2]);
                    //cout << i << " " << j << " " << 2 << " " << dp[i][j][2] << endl;
                }
            }
        }
        int ans = 0;
        for(int j = 0;j <= n;j++){
            ans = max(ans, dp[n][j][0]);
            ans = max(ans, dp[n][j][1]);
            ans = max(ans, dp[n][j][2]);
        }
        cout << ans << endl;
    }
    return 0;
}
