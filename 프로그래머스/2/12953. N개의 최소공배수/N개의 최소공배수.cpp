#include <vector>
#include <numeric>
using namespace std;

int solution(vector<int> arr) {
    int answer = arr.at(0);
    for (int i = 1; i < arr.size(); i++) answer = lcm(answer, arr.at(i));
    return answer;
}