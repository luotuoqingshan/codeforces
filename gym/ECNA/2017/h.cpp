#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int maxn = 105;


bool vis[maxn][maxn];

int n, m;

bool in(int x, int y){
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

char s[maxn][maxn];

void bfs(int x, int y){
    queue<pair<int, int> > q; 
    vis[x][y] = true;
    q.push(make_pair(x, y));
    while(!q.empty()){
        pair<int, int> now = q.front();
        q.pop();
        int xx = now.first, yy = now.second;
        for(int dx = -1;dx <= 1;dx++){
            for(int dy = -1;dy <= 1;dy++){
                if(dx == 0 && dy == 0) continue;
                int nx = xx + dx;
                int ny = yy + dy;
                if(in(nx, ny) && !vis[nx][ny] && s[nx][ny] == '#'){
                    q.push(make_pair(nx, ny));
                    vis[nx][ny] = true;
                }
            }
        } 
    }
}


int main(){
    while(cin >> n >> m){
        memset(vis, 0, sizeof(vis));
        for(int i = 1;i <= n;i++){
            scanf("%s", s[i] + 1);
        } 
        int ans = 0;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                if(s[i][j] == '#' && !vis[i][j]){
                    bfs(i, j);
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
