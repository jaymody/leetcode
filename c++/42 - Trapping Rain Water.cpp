// 42
// Trapping Rain Water
// https://leetcode.com/problems/trapping-rain-water/
// c++
// hard
// O(n)
// O(n)
// array two_pointers dynamic

// O(n), O(1) solution
// Better than my initial solution (found below this one)
// Unlike my intial approach (found below this solution), 
// this solution iterates through the list once, instead of twice,
// and uses O(1) memory instead of O(n)
class Solution {
public:
    int trap(vector<int>& height) {
        int total = 0;
        
        int left = 0;
        int leftmax = 0;
        
        int right = height.size() - 1;
        int rightmax = 0;
        
        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] >= leftmax)
                    leftmax = height[left];
                else
                    total += leftmax - height[left];
                left++;
            }
            else {
                if (height[right] >= rightmax)
                    rightmax = height[right];
                else
                    total += rightmax - height[right];
                right--;
            }
        }
        
        return total;
    }
};


// My first initial O(n) O(n) solution
// For a given int n in the list, the amount of water it
// contributes to the total is equivalent to:
//      relu(min(max(leftlist), max(rightlist)) - n)
class Solution {
public:
    int relu(int n) {
        if (n < 0)
            return 0;
        else
            return n;
    }
    int trap(vector<int>& height) {
        vector<int> lefts;
        int leftmax = 0;
        int rightmax = 0;
        int total = 0;
        int size = height.size();
        
        for (int i = 0 ; i < size; i++) {
            lefts.push_back(leftmax);
            if (height[i] > leftmax)
                leftmax = height[i];
        }
        
        for (int i = size-1; i >= 0; i--) {
            total += lefts[i] < rightmax ? relu(lefts[i]-height[i]) : relu(rightmax-height[i]);
            if (height[i] > rightmax)
                rightmax = height[i];
            // cout << height[i] << "\t"<< lefts[i] << "\t" << rightmax << "\t" << total << endl;
        }
        
        return total;
        
    }
};
