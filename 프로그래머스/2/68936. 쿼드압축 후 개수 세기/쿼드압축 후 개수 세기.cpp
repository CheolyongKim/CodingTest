#include <vector>
#include <cmath>
using namespace std;
/*
    예시1) 큰것(2*2)부터 보고, 그 다음 더 작게 쪼개서(1*1) 보기
    ...
    2^10^2 * 10 => 거의 10^7 => 괜찮나..?
*/
int log(int r, int n){
    if (n == 1) return 0;
    else return 1 + log(r, n/r);
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2, 0);
    int n = arr.size();
    int p = log(2, n);
    
    vector<vector<bool>> done(n);
    for (int temp = 0; temp < done.size(); temp++) done.at(temp).resize(n, false);
    
    for (int split = 0; split <= p; split++){
        // split: 몇 번 쪼갰나
        int num_s = pow(2, split); // num of squares 가로, 세로 같음
        for (int ci = 0; ci < num_s; ci++){
            for (int cj = 0; cj < num_s; cj++){
                // 한 정사각형 안에 모두 같은지 확인
                int ws = pow(2, p - split); // 정사각형 한 변의 길이
                int ri = ws * ci, rj = ws * cj;
                if (done.at(ri).at(rj)) continue;
                int root = arr.at(ri).at(rj);
                bool flag = true;
                
                for (int di = 0; (di < ws) && flag; di++){
                    for (int dj = 0; (dj < ws) && flag; dj++){
                        int i = ri+di, j = rj+dj;
                        if (arr.at(i).at(j) != root) flag = false;
                    }
                }
                
                if (flag){
                    for (int ti = 0; ti < ws; ti++)
                        for (int tj = 0; tj < ws; tj++)
                            done.at(ri+ti).at(rj+tj) = true;
                    answer.at(root)++;
                }
            }
        }
    }
    
    return answer;
}