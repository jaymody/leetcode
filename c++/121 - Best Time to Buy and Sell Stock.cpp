// 121
// Best Time to Buy and Sell Stock
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// c++
// easy
// O(n)
// O(1)
// basic

// linear solution
// time: O(n)
// space: O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int min = INT_MAX;
        
        for (int& p : prices) {
            ans = p - min > ans ? p - min : ans;
            min = p < min ? p : min;
        }
        
        return ans;
    }
};