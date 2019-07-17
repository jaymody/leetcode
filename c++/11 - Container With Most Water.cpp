// 11
// Container With Most Water
// https://leetcode.com/problems/container-with-most-water/
// c++
// medium
// O(n)
// O(1)
// array two pointers

class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int max = 0;
        int left = 0;
        int right = height.size()-1;
        
        while (left < right) {
            int area = (right - left)*(height[left] < height[right] ? height[left] : height[right]);
            max = area > max ? area : max;
            
            if (height[left] < height[right]) {
                left++;
            }
            else {
                right--;
            }
        }
        
        return max;
    }
};
