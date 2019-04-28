#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int maxn = 15000 + 5;
char s[maxn];

int main(){
    while(scanf("%s", s + 1) != EOF){
        int n = strlen(s + 1);
        int r0 = 0, r1 = 0;
        for(int i = 1;i <= n / 2;i++){
            r0 += s[i] - 'A';
            r1 += s[n / 2 + i] - 'A';
        }
        for(int i = 1;i <= n / 2;i++){
            s[i] = (s[i] - 'A' + r0) % 26 + 'A';
            s[i + n / 2] = (s[i + n / 2] - 'A' + r1) % 26 + 'A';
        }
        for(int i = 1;i <= n / 2;i++){
            s[i] = (s[i] - 'A' + (s[i + n / 2] - 'A')) % 26 + 'A';
        }
        s[n / 2 + 1] = 0;
        printf("%s\n", s + 1);
    }
    return 0;
}
