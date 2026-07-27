#include <vector>
using namespace std;
/*
    1-2-3-4-... 똑바른 세로선으로 보면
*/

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> snail(n);
    for (int temp = 0; temp < n; temp++) snail.at(temp).resize(n, 0);
    
    
    int ci0, cj0, ci1, cj1;
    ci0 = cj0 = n/2;
    ci1 = ci0; cj1 = cj0-1;
    
    // moving pointer
    int pi = -1, pj = 0;
    // increasing
    int inc = 0;
    int dir = 0; // 0-down, 1-right, 2-diag up
    
    for (int leng = n; leng > 0; --leng){
        for (int mov = 0; mov < leng; mov++){
            switch (dir){
                case 0:
                    pi++;
                    break;
                case 1:
                    pj++;
                    break;
                case 2:
                    pi--; pj--;
                    break;
                default:
                    break;
            }
            snail.at(pi).at(pj) = ++inc;
        }
        dir = (dir+1)%3;
    }
//     while (snail.at(ci0).at(cj0) == 0 || snail.at(ci1).at(cj1) == 0){
        
//     }
    vector<int> sum(n, 0);
    for (int i = 0; i < snail.size(); i++)
        for (int j = 0; j < snail.at(i).size(); j++)
            if (snail.at(i).at(j) > 0)
                answer.push_back(snail.at(i).at(j));
    
    return answer;
}