#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;
typedef long long LL;
LL ju[15], jr[15];

LL u[15], r[15], t[15];
int n = 10;
int main(){
    for(int i = 0;i < n;i++){
        scanf("%lld%lld", &ju[i], &jr[i]);
    }
    for(int i = 0;i < n;i++){
        scanf("%lld%lld%lld", u + i, r + i, t + i);
    }
    LL now = 0;
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 10;j++){
            if(now < t[j]){
                now += ju[j];
                t[j] = max(t[j], now);
            }else{
                LL time = now - t[j];
                LL left = (time % (u[j] + r[j]));
                LL st = now - left;
                if(left <= u[j]){
                    now += u[j] - left + ju[j];
                    t[j] = max(st + u[j] + r[j], now);
                }
                else{
                    now += ju[j];
                    t[j] = max(now, st + u[j] + r[j]);
                }
            }
            if(i == 2 && j == 9){

            }else{
                now += jr[j];
            }
        }
    }
    cout << now << endl;
    return 0;
}
