//Brute Force Approach....
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<pair<int,int>> zeroes;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    zeroes.push_back({i,j});
                }
            }
        }
        int s=zeroes.size();
        for(int k=0;k<s;k++){
            int r =zeroes[k].first;
            int c =zeroes[k].second;
            for(int j=0;j<n;j++){
                matrix[r][j]=0;
            }
            for(int i=0;i<m;i++){
                matrix[i][c]=0;
            }  
        }
    }
};

// Optimal Approach... O(m*n) time and O(1) space complexity

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool zeroInTop = false;
        bool zeroInLeft = false;
        for(int j = 0; j < n; j++) {
            if(matrix[0][j] == 0) {
                zeroInTop = true;
                break;
            }
        }
        for(int i = 0; i < m; i++) {
            if(matrix[i][0] == 0) {
                zeroInLeft = true;
                break;
            }
        }
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        if(zeroInTop) {
            for(int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }
        if(zeroInLeft) {
            for(int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};