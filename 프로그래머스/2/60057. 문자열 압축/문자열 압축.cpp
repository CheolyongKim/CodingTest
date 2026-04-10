#include <string>
#include <vector>

using namespace std;

int dp(int n, string s, int rep){
    int ret = 0;
    if (s.size() <= 1) return rep == 0 ? s.size() : to_string(rep + 1).size() + n;

    string first, second;
    if (s.size() >= n) first = s.substr(0, n);
    if (s.size() >= n * 2) second = s.substr(n, n);

    if (second.size() == 0) {
        if (rep == 0) ret = s.size();
        else ret = to_string(rep+1).size() + n + dp(n, s.substr(n), 0);
    }
    else if (first.compare(second) == 0) {
        ret = dp(n, s.substr(n), rep + 1);
    }
    else {
        if (rep == 0) ret = n + dp(n, s.substr(n), 0);
        else ret = to_string(rep+1).size() + n + dp(n, s.substr(n), 0);
    }
    return ret;
}

int solution(string s) {
    int answer = s.size();
    for (int i=1; i<=s.size()/2; i++){
        int a = dp(i, s, 0);
        if (a<answer) answer = a;
    }
    return answer;
}