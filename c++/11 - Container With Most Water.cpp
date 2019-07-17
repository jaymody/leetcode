// 11
// Container With Most Water
// https://leetcode.com/problems/container-with-most-water/
// c++
// medium
// O(n)
// O(1)
// array two_pointers

class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int max = 0;

        int left = 0;
        int right = height.size()-1;

        int maxLeft = left;
        int maxRight = right;
        
        while (left < right) {
            int area = (right - left)*(height[left] < height[right] ? height[left] : height[right]);
            if (area > max) {
                max = area;
                maxLeft = left;
                maxRight = right;
            }

            
            if (height[left] < height[right]) {
                do {
                    left++;
                } while (left < right && height[maxLeft] >= height[left]);
            }
            else {
                do {
                    right--;
                } while (left < right && height[maxRight] >= height[right]);
            }
        }
        
        return max;
    }
};
