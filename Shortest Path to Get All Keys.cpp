class Solution {
private:
    int ans, row, col, keys;
    vector<vector<int>> visited;
    map<char, bool> kt;

public:
    void out(int x, int y) {
        return x < 0 or x >= row or y < 0 or y >= col;
    }

    int shortestPathAllKeys(vector<string>& grid) {
        int idx, idy;
        row = grid.size(), col = grid[0].size(), ans = INT_MAX, keys = 0;
        vis.assign(row, vector<int> (col, 0));

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == '@') {
                    idx = i, idy = j;
                }
                if (grid[i][j] >= 'a' and grid[i][j] <= 'z')
                    keys++;
            }
        }

        queue<pair<int, int>> q;
        q.push({idx, idy});
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
        
        while (q.size()) {
            if (out(idx, idy)) continue;
            if (grid[i][j] == '#') continue;
            if (grid[i][j] >= 'a' and grid[i][j] <= 'z') k++, kt[grid[i][j]] = 1;
            if (k == keys) {
                ans = min(ans, steps);
                continue;
            }
            if (grid[i][j] >= 'A' and grid[i][j] <= 'Z')
                if (!kt[char(grid[i][j] + 32)]) continue;
            visited[idx][idy] = 1;
            for (int i = 0; i < 4; i++) {
                q.push(idx + dx[i], idy + dy[i]);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};