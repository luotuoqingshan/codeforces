#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 10005;

int sz[maxn];
int ans[maxn];
vector<int> G[maxn];

int n, m;
void dfs(int u, int fa){
    int pre = 0;
    sz[u] = 1;
    for(auto v : G[u]){
        if(v == fa) continue;
        dfs(v, u);
        sz[u] += sz[v];
        ans[u] += pre * sz[v];
        pre += sz[v];
    }
    ans[u] += (m + 1 - sz[u]) * pre;
}

int main(){
    while(cin >> n){
        for(int i = 0;i <= n;i++){
            G[i].clear();
        }
        m = 0;
        for(int i = 1;i <= n;i++){
            int u, v;
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
            m = max(m, u);
            m = max(m, v);
        }
        dfs(0, 0);
        int ans1 = ans[0];
        int id = 0;
        for(int i = 1;i <= m;i++){
            if(ans[i] > ans1){
                ans1 = ans[i];
                id = i;
            }
        }
        dfs(id, id);
        int max1 = 0, max2 = 0;
        for(auto v : G[id]){
            if(sz[v] > max1){
                max2 = max1;
                max1 = sz[v];
            }else{
                if(sz[v] > max2){
                    max2 = sz[v];
                }
            } 
        }
        int ans2 = ans1 - max1 * max2;
        cout << ans1 << " " << ans2 << endl;
    } 
    return 0;
}
