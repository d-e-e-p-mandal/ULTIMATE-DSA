```cpp
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(matrix[i][j] == 0)
                    matrix[i][j] = -100000001;
            }
        }

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(matrix[i][j] == -100000001){
                    for(int k=0; k < n; k++) {
                        if(j==k || matrix[i][k] != -100000001)matrix[i][k] = 0;
                    }
                    for(int k=0; k < m; k++) {
                        if(i==k || matrix[k][j] != -100000001)matrix[k][j] = 0;
                    }
                }
            }
        }

    }
};
```