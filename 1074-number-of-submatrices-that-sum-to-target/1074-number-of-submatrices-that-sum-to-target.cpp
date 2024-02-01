class Solution {
private:
    int subarraySum(vector<int>& nums, int k) {
        //store all possible sum(to left of current element) of array
        //<sum, no. of occurance of sum>
        unordered_map<int, int> umap;
    
        int currSum = 0;
        int ans = 0;

        for(int i=0; i<nums.size(); i++){
            //calculating total sum to the left of element
            currSum += nums[i];
            //if current sum is eqaual to target
            if(currSum == k){
                ans++;
            }
            //similar to kadane's algorithm
            //currentNumber - target = number needed to reach target
            //if number to reach target exist => add umap count of the number to answer
            if (umap.find(currSum-k) != umap.end()){
                ans += umap[currSum-k];
            }
            //add current sum to the map
            umap[currSum]++;
        }
        return ans;
    };
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        //keeps track of total submatrix
        int count = 0;
        
        //we will calculate target sum of each row(using subarraySum)
        //see eg 1, for 3x3 we will iterate and find prefix sum of i-n rows
        // loop 1. 1-3 rows -> prefix sum [[0 1 1][1 3 4][1 4 5]]
        // loop 2. 2-3 rows -> prefix sum [[1 2 3][1 3 3]]
        // loop 3. 3-3 rows -> prefix sum [[0 1 0]]
        
        //this loop gives i value
        for(int i=0; i<matrix.size(); i++){
            //vector stores prefix sum of current row
            //stores first row prefix sum(sum of elements to the left)
            //same sum vector used for next row
            //this helps to find prefixsum of next row by adding sum of elements above it(in case of 2-D matrix)
            vector<int> sum(matrix[0].size(), 0);
            
            //iterates down the matrix from current row(i)
            for(int j=i; j<matrix.size(); j++){
                for(int k=0; k<matrix[0].size(); k++){
                    //calculate prefix sum
                    sum[k] += matrix[j][k];
                }
                //calculate sum array in the row using prefix sum
                count += subarraySum(sum, target);
            }
        }
        return count;
    }
};