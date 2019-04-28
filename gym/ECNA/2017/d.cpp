#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <stack>
using namespace std;


int n,k;

bool is_digit(char s){
    return s >= '0' && s <= '9';
}

int string_to_int(string s){
    int now = 0;
    int sign = 1;
    int i = 0;
    if(s[i] == '-'){
        sign = -1;
        i++;
    }
    for(;i < s.length();i++){
        now = now * 10 + (s[i] - '0');
    }
    return sign * now;
}


int main(){
    while(cin >> n >> k){
        stack<int> s;
        for(int i = 1;i <= k;i++){
            string op;
            cin >> op;
            if(op[0] == 'u'){
                int x;
                cin >> x;
                while(x--){
                    s.pop();
                }
            }else{
                int num = string_to_int(op);
                s.push(num);
            }
        }
        int now = 0;
        while(!s.empty()){
            int num = s.top();s.pop();
            now = (now + num % n + n) % n;
        }
        cout << now << endl;
    }
    return 0;
}
