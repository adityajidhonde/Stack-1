// Time Complexity : O(N) # of days
// Space Complexity : O(N) size of stack 
// Did this code successfully run on Leetcode : Yes


// Your code here along with comments explaining your approach:
// 1. Here we check if for each element is it nearest greater element for any previous temperature.
// 2. Using stack we store temperature index(day number) if it's lower than we just store it in stack else we say stack's top index has next greater as current index.
// 3. We pop top of stack and store current index.

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        s.push(0);
        int n=temperatures.size();
        for(int i=1;i<n;i++){
            while( (!s.empty()) && temperatures[s.top()]<temperatures[i]){
                temperatures[s.top()]= (i-s.top()); s.pop();
            }
            s.push(i);
        }
        while( (!s.empty()) ){
                temperatures[s.top()]= 0; s.pop();
            }
        return temperatures;
    }
};