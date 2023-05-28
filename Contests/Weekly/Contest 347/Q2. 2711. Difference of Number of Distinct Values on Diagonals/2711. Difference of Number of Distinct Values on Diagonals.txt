class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> answer(m, vector<int>(n, 0));

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                unordered_set<int> topLeft;
                unordered_set<int> bottomRight;

                for (int i = 0; i < r; i++) {
                    if (i < m && c - r + i >= 0) {
                        topLeft.insert(grid[i][c - r + i]);
                    }
                }

                for (int i = r + 1; i < m; i++) {
                    if (i < m && c + i - r < n) {
                        bottomRight.insert(grid[i][c + i - r]);
                    }
                }

                answer[r][c] = std::abs(static_cast<int>(topLeft.size()) - static_cast<int>(bottomRight.size()));
            }
        }

        return answer;
    }
};
