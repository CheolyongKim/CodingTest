#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;

int dy[4]={-1,1,0,0}, dx[4]={0,0,-1,1};

vector<vector<bool>> visited;

int dfs(int y, int x, vector<string> maps){
    int sum=maps[y][x]-'0';
    visited[y][x]=true;
    for(int dir=0; dir<4; dir++){
        int Y=y+dy[dir], X=x+dx[dir];
        if (Y<0 || Y>=n || X<0 || X>=m) continue;
        else if (visited[Y][X]) continue;
        else if (maps[Y][X]=='X') continue;
        else sum += dfs(Y, X, maps);
    }
    return sum;
}

vector<int> solution(vector<string> maps) {
    // initialize
    vector<int> answer;
    n=maps.size();
    m=maps[0].size();
    vector<bool> v(m,false);
    visited.assign(n,v);
    
    // dfs
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (!visited[i][j] && maps[i][j]!='X') answer.push_back(dfs(i, j, maps));
        }
    }
    if (answer.size()==0) answer.push_back(-1);
    sort(answer.begin(), answer.end());
    return answer;
}