



class Solution {
public:

    bool sameValue(vector<vector<int>>& grid, int r, int c, int n) {
        for(int i = r; i < r + n; i++) {
            for(int j = c; j < c + n; j++) {
                if(grid[i][j] != grid[r][c]) {
                    return false;
                }
            }
        }
        return true;
    }

    Node* solve(vector<vector<int>>& grid, int r, int c, int n) {
        if(sameValue(grid, r, c, n)) {
            return new Node(grid[r][c], true);
        } else {
            Node* root = new Node(false, false);

            int lengthHalf = n/2;

            root->topLeft = solve(grid, r, c, lengthHalf);
            root->topRight = solve(grid, r, c + lengthHalf, lengthHalf);
            root->bottomLeft = solve(grid, r + lengthHalf, c, lengthHalf);
            root->bottomRight = solve(grid, r + lengthHalf, c + lengthHalf, lengthHalf);
            return root;
        }
    }
    Node* construct(vector<vector<int>>& grid) {
        return solve(grid, 0, 0, grid.size());
    }
};
