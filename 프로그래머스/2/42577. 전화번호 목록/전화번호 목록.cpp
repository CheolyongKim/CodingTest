#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int min_length;

bool cmp_by_len(string a, string b){
    return a.length() < b.length();
}

void sort_by_length(vector<string> &p){
    sort(p.begin(), p.end(), cmp_by_len);
}

void reg_prefix(map<string, bool> &p, string s){
    p[s] = true;
}

bool does_prefix_exist(vector<map<string, bool>> &p, string s){
    for (int l=min_length; l<=s.length(); l++){
        if (p[l].find(s.substr(0, l))!=p[l].end()) return true;
    }
    reg_prefix(p[s.length()], s);
    return false;
}

bool solution(vector<string> phone_book) {
    // use map: length 1 ~ 20
    vector<map<string, bool>> p(21);
    
    // sort by length asc
    sort_by_length(phone_book);
    
    // for in phone_book, for in range(length), compare
    min_length = phone_book[0].length();
    for (int i=0; i<phone_book.size(); i++){
        string &s = phone_book[i];
        if (s.length()==min_length) reg_prefix(p[s.length()], s);
        else{
            if (does_prefix_exist(p, s)) return false;
        }
    }
    
    return true;
}