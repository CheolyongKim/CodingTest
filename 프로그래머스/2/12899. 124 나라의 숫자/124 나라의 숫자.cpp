#include <string>
#include <vector>
#include <cmath>
using namespace std;
/*
    쉬운 예:       지금 문제:
    ======      ======
    a, b, c
    ------      -----
    0 -> a      0 -> ?
    1 -> b      1 -> a
    2 -> c      2 -> b
    3 -> ba     3 -> c
    4 -> bb     4 -> aa
    5 -> bc     5 -> ab
    6 -> ca     6 -> ac
    7 -> cb     7 -> ba
    8 -> cc     8 -> bb
    9 -> baa    9 -> bc
    10 -> bab   10 -> ca
    ...         11 -> cb
                12 -> cc
                13 -> aaa
                ...
                (1~3) + 3*(1~3) + 3^2 *(1~3) + ...
*/
long long sum(int p){ // 등비수열합
    if (p == 0) return 1;
    else return 3*sum(p-1) + 1;
}

string solution(int n) {
    string answer = "";
    for (int p = 17; p > 0; --p){
        if (n < sum(p)) continue;
        
        long long s = sum(p-1);
        if (n >= s + pow(3, p)*3){
            n -= pow(3, p)*3;
            answer += "4";
        } else if (n >= s + pow(3, p)*2){
            n -= pow(3, p)*2;
            answer += "2";
        } else if (n >= s + pow(3, p)){
            n -= pow(3, p);
            answer += "1";
        }
    }
    if (n == 3) answer += "4";
    if (n == 2) answer += "2";
    if (n == 1) answer += "1";
    return answer;
}