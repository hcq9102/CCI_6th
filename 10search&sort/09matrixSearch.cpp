class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0;
        int col = matrix[0].size()-1;

        while(row>=0 && col >=0 && row<matrix.size() && col <matrix[0].size()){
            if(matrix[row][col] > target){
                col--;
            }else if(matrix[row][col] < target){
                row++;
            }else if(target == matrix[row][col]){
                return true;
            }
        }
        return false;
    }
};


、、、、、、、、、、、、、method2

// binary //该方法还适用于每行元素数量不固定时
class Solution {
    public boolean searchMatrix(int[][] A, int target) {
        int m = A.length;
        int n = A[0].length;
        
        int up = 0;
        int down = m-1;
        int targetRow = 0;
        // binary col 0
        while(up<down){
            int mid = up + (down -up+1)/2;
            if(A[mid][0] == target){
                return true;
            }else if(A[mid][0] > target){
                down = mid -1;
            }else{
                up = mid;
                targetRow = up;
            }
        }
        
        int l = 0, r = n-1;
        while(l<=r){
            int mid = l +(r-l) /2;
            if(A[targetRow][mid] == target){
                return true;
            }else if(A[targetRow][mid] > target){
                r = mid -1;
            }else{
                l = mid+1;
            }
        }
       return false; 
    }
}
