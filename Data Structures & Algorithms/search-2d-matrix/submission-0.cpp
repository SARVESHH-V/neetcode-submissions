class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        int l=0,r=row*col-1;

        while(l<=r){
            int m = l+(r-l)/2;

            int rr = m/col,cc = m%col;

            if(target>matrix[rr][cc]){
                l=m+1;
            }
            else if(target<matrix[rr][cc]){
                r=m-1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};
