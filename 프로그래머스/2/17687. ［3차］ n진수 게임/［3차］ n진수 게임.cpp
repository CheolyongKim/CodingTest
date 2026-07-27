#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;
/*
    예제 1: 0 1 1 0 1 1 1 ... // 1, 3, 5, 7
*/

#define llog(a, b) log(b)/log(a)

string solution(int n, int t, int m, int p) {
    string answer = "0";
    string ret = "";
    
    vector<char> j = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    int aim = (t-1)*m + p-1 + 1; // answer 작성을 위해 총 알아야 하는 문자열 길이
    int count = 1; // (10진법 기준으로) 몇개나 구해놔야 aim 길이에 충분한지
    
    // debug
    // cout << "llog(n, 1): " << llog(10, 1000) << "\n";
    // cout << "floor(llog(n, 1)): " << floor(llog(10, 1000)) << "\n";
    // int temp = llog(10, 1000);
    // cout << floor(temp) << "\n";
    // cout << "pow(n, 0): " << pow(n, 0) << "\n";
    
    // 10진법 count 1000에서 A00 이라고 뜨는 문제
    
    for (; answer.length() < aim; count++){
        // 예를 들어 7진법이면 7부터 두자리, 49부터 세자리, ...
        double ll = (n!=10) ? llog(n, count) : log(count);
        int num = count;
        for (int pw = floor(llog(n, count)); num >= 0 && pw >= 0; --pw){
            int div = pow(n, pw);
            if (num == 0) {
                for (; pw>=0; --pw) answer += j.at(0);
                break;
            }
            else{
                int r = num%div, q = (num-r)/div;
                if (q >= n){
                    answer += "10";
                } else answer += j.at(q);
                num = r;
            }
        }
        // for debug
        // answer += " ";
    }
    
    for (int i = 0; i < t; i++){
        if (i*m + p-1 >= answer.size()){
            // debug
            cout << "index out of range; answer: " << answer << "\n";
            break;
        }
        ret += answer.at(i*m + p-1);
    }
    // cout << "answer: " << answer << ", count: " << count << "\n";
    
    return ret;
}