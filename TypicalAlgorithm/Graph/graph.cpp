#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void 连通块数量(vector<vector<int>> matrix);

void bfs求最短路径(vector<vector<int>> vector);

int main() {
    //1.dfs求连通块数量
    // vector<vector<int>> matrix(10,vector<int>(10,3));
    vector<vector<int>> matrix;
    matrix.push_back(vector<int>{0, 0, 0, 0, 1});
    matrix.push_back(vector<int>{0, 1, 1, 0, 1});
    matrix.push_back(vector<int>{0, 1, 0, 0, 1});
    matrix.push_back(vector<int>{1, 1, 1, 0, 1});
    matrix.push_back(vector<int>{1, 1, 0, 0, 1});
    连通块数量(matrix);

    cout << endl;
    //2.bfs求最短路径(路径距离、路径点)
    matrix.clear();
    matrix.push_back(vector<int>{0, 0, 1, 0, 0});
    matrix.push_back(vector<int>{0, 1, 0, 0, 0});
    matrix.push_back(vector<int>{0, 1, 0, 1, 1});
    matrix.push_back(vector<int>{0, 1, 0, 0, 0});
    matrix.push_back(vector<int>{0, 0, 0, 1, 0});
    matrix.push_back(vector<int>{0, 0, 0, 0, 0});
    bfs求最短路径(matrix);
}

void bfs求最短路径(vector<vector<int>> matrix) {
    vector<vector<int>> direct(matrix.size(), vector<int>(matrix[0].size(), 0));
    vector<vector<int>> steps(matrix.size(), vector<int>(matrix[0].size(), 0));
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    while (!q.empty()) {
        pair<int,int> pos=q.front();
        q.pop();
        if (pos.first==0 && pos.second==4){
            break;
        }
    }
}


void dfs连通块数量(int i, int j, vector<vector<int>> matrix, vector<vector<bool>> &visited) {
    if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size() || visited[i][j])return;
    visited[i][j] = true;
    if (matrix[i][j] == 0) return;
    dfs连通块数量(i - 1, j, matrix, visited);
    dfs连通块数量(i + 1, j, matrix, visited);
    dfs连通块数量(i, j - 1, matrix, visited);
    dfs连通块数量(i, j + 1, matrix, visited);
}

void 连通块数量(vector<vector<int>> matrix) {
    int count = 0;
    vector<vector<bool>> visited(matrix.size(), vector<bool>(matrix[0].size(), false));
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            if (visited[i][j]) continue;
            if (matrix[i][j] == 1) {
                dfs连通块数量(i, j, matrix, visited);
                count++;
            }
        }
    }
    cout << "count:" << count;
}




