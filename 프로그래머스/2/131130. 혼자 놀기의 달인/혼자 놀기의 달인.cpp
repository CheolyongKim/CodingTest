#include <string>
#include <vector>
#include <queue>
using namespace std;


int solution(vector<int> cards) {
    priority_queue<int> pq;
    int n = cards.size();
    vector<bool> visited(n, false);
    
    for (int i = 0; i < n; i++) cards.at(i)--;
    
    int idx = 0;
    while (true){
        bool flag = true;
        for (bool v : visited){
            if (!v) {
                flag = false;
                break;
            }
        }
        if (flag) break;
        
        int count = 0;
        while (!visited.at(idx)){
            visited.at(idx) = true;
            count++;
            idx = cards.at(idx);
        }
        pq.push(count);
        idx = (idx+1)%n;
    }    
    
    if (pq.size() == 1) return 0;
    int a = pq.top();
    pq.pop();
    int b = pq.top();
    return a*b;
}