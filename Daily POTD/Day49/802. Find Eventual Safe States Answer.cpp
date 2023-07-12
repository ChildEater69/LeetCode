class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> graphRev(n);
        vector <int> indegree(n, 0);
        for (int i = 0; i < n; i++) {
            if (graph[i].size() == 0)
                continue;
            for (auto it: graph[i]) {
                graphRev[it].push_back(i);
                indegree[i]++;
            }
        }
        queue <int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }
        vector <int> res;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            res.push_back(node);
            for (auto it: graphRev[node]) {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};