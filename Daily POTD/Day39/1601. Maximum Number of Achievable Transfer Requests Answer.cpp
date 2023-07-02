
class Solution {
public:
    int maximumRequests(int n, std::vector<std::vector<int>>& req) {
        for (int k = req.size(); k > 0; k--) {
            std::vector<std::vector<int>> combinations = generateCombinations(req.size(), k);
            for (const std::vector<int>& c : combinations) {
                std::vector<int> degree(n, 0);
                for (int i : c) {
                    degree[req[i][0]]--;
                    degree[req[i][1]]++;
                }
                if (allZeroes(degree)) {
                    return k;
                }
            }
        }
        return 0;
    }

private:
    std::vector<std::vector<int>> generateCombinations(int n, int k) {
        std::vector<std::vector<int>> combinations;
        std::vector<int> current;
        backtrack(combinations, current, 0, n, k);
        return combinations;
    }

    void backtrack(std::vector<std::vector<int>>& combinations, std::vector<int>& current, int start, int n, int k) {
        if (k == 0) {
            combinations.push_back(current);
            return;
        }
        for (int i = start; i < n; i++) {
            current.push_back(i);
            backtrack(combinations, current, i + 1, n, k - 1);
            current.pop_back();
        }
    }

    bool allZeroes(const std::vector<int>& arr) {
        for (int num : arr) {
            if (num != 0) {
                return false;
            }
        }
        return true;
    }
};