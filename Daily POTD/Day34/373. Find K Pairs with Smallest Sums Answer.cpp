#define pp pair<int, pair<int, int>>

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<vector<int>> ans;  
         
        // Create a min-heap to store pairs of indices and their sums
        priority_queue<pp, vector<pp>, greater<pp>> pq;
            
        // Push the initial pairs into the priority queue
        for (int i = 0; i < k && i < n1; i++)
            pq.push({nums1[i] + nums2[0], {i, 0}});

        // Process the pairs until k pairs are obtained or the priority queue is empty
        while (k > 0 && !pq.empty()) {
            // Extract the pair with the smallest sum from the priority queue
            auto curr = pq.top();
            pq.pop();

            int firstArrayIndex = curr.second.first;
            int secondArrayIndex = curr.second.second;

            // Add the pair to the answer vector
            ans.push_back({nums1[firstArrayIndex], nums2[secondArrayIndex]});

            // Push the next pair with the same first index but the next second index
            if (secondArrayIndex + 1 < n2) {
                pq.push({nums1[firstArrayIndex] + nums2[secondArrayIndex + 1], {firstArrayIndex, secondArrayIndex + 1}});
            }
          
            k--;
        }

        return ans;
    }
};