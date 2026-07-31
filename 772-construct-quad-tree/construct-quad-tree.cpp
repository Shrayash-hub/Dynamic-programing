/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        // lets start building the quad tree for the whole grid
        return build(grid, 0, 0, grid.size());
    }
    Node* build(vector<vector<int>>& grid, int row, int col, int size) {
        // if the value in whole grid is same , then its a leaf node
        if (isAllSame(grid, row, col, size)) {
            return new Node(grid[row][col] == 1, true);
        }

        int half = size / 2;

        Node* root = new Node(true, false);
        // call for all four sections
        root->topLeft = build(grid, row, col, half);
        root->topRight = build(grid, row, col + half, half);
        root->bottomLeft = build(grid, row + half, col, half);
        root->bottomRight = build(grid, row + half, col + half, half);

        return root;
    }

    bool isAllSame(vector<vector<int>>& grid, int row, int col, int size){
        int value = grid[row][col];

        for (int i = row; i < row + size; i++) {
            for (int j = col; j < col + size; j++) {
                if (grid[i][j] != value) {
                    return false;
                }
            }
        }
        return true;
    }
};