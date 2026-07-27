#include <vector>
#include <cmath>
#include <iostream>
#include <numeric>
using namespace std;
/*
    ex)
    2, 3
    >> y = 2/3 * x
    0 -> 0
    1 -> 0.?
    2 -> 1.?
    3 -> 2
    
    0~1 -> y=0 사각형 제외
    1~2 -> y=0~1 사각형 제외
    ...
*/


long long solution(int w,int h) {
    long long ww = w, hh = h;
    long long answer = ww*hh; //cout << answer << "\n";
    long double w0 = w, h0 = h;
    double tan = hh/w0;
    
    // y = h/w * x
    // for (long long i = 0LL; i <= ww; i++){
    //     v.at(i) = (hh/w0) * i;
    // }
    int g = gcd(w, h);
    long long minus = 0;
    for (int i = 0; i < w/g; i++){
        long double a = tan*i, b = tan*(i+1);
        
        long long rs = floor(a);
        long long re = ceil(b);
        
        // debug
        //cout << "i: " << i << ", s: " << s << ", e: " << e << ", rs: " << rs << ", re: "<< re << "\n";
        // if (i == w-1){
        //     cout << re << " " << rs << "\n";
        // }
        minus += re - rs;
        
        a += tan;
    }
    
    return answer - g*minus;
}