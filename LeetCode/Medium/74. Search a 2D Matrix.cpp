class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i = 0; i < matrix.size(); i++)
        {
            int j = 0, k = matrix[i].size();
            while(j < k)
            {
                int mid = (j + k) / 2;
                if(matrix[i][mid] < target) j++;
                else if(matrix[i][mid] > target) k--;
                else return true;
            }
        }
        return false;
    }
};
