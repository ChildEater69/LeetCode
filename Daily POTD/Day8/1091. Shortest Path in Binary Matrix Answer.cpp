class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        //solving this question using BFS traversal
        int n = grid.size();
        int m = grid[0].size();

        if(n==m && n==1){  //for the edge cases such as [[0]] && [[1]]
            if(grid[0][0]) return -1;
            return 1;
        }
        if(grid[0][0]!=0 || grid[n-1][n-1]!=0) return -1;

        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;  //to store grid location and dist simultaneously
        q.push({{0,0},1}); //src and initializing dist as 1
        vis[0][0]=1;
        int ans = INT_MAX;

        int dRow[]= {-1,0,1,0,-1,-1,1,1};  //since it is 8 directional connected so all the cases etc. (-1,0),(0,-1)
        int dCol[] ={0,-1,0,1,-1,1,1,-1};

        while(!q.empty()){
            int row = q.front().first.first;  
            int col = q.front().first.second;  //generating all the possible grid rows and colums
            int dist = q.front().second;
            q.pop();
            for(int i = 0;i<8;i++){
                int nxtRow = row + dRow[i];
                int nxtCol = col + dCol[i];
                if(nxtRow>=0 && nxtRow<n && nxtCol>=0 && nxtCol<m && !vis[nxtRow][nxtCol] && grid[nxtRow][nxtCol]==0)
                { //checking the boundaries and whether node is visited or not and if grid is already 0
                    vis[nxtRow][nxtCol]=1;
                    if(nxtRow==n-1 && nxtCol==m-1) return min(ans,dist+1); //the destination node
                    q.push({{nxtRow,nxtCol},dist+1}); //if the node is not the destination (n-1,m-1) then push it to to queue with increasing the distance
                }
            }
        }
        return -1;

    }
};