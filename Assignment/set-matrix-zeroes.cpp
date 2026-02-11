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