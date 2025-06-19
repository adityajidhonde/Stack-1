// Time Complexity : O(N) # of element in array
// Space Complexity : O(N) size of stack 
// Did this code successfully run on Leetcode : Yes


// Your code here along with comments explaining your approach:
// 1. Find maximum element index and start traversing from that index.
// 2. Using stack find if current element is next greater element for stack top. Here stack stores elements who don't have next greater element till current element.
// 3. After one circular traversal, stack has element with whose next greater is not present as it is max or whose next greater is maximum element in array.

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
         int n=nums.size();
        int t=0,min=0,max=0;
        for(int i=0;i<n;i++){
            if( nums[i]>nums[min] ){
                min=i;
            }
        }
        max=nums[min];
        s.push(min);min=(min+1)%n;
        if(min==0){t=n-1;}else{t=min-1;}

        for(int i=min;i!=t ;i=(i+1)%n){
            while( !s.empty() && nums[s.top()]<nums[i] ){
                nums[s.top()]=nums[i];s.pop();
            }
            s.push(i);
        }
        
        while( !s.empty() ){
            if( nums[s.top()] < max ){nums[s.top()]= max;}
            else{nums[s.top()]=-1;}
            s.pop();
        }

        return nums;
    }
};