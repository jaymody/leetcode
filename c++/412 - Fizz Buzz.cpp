// 412
// Fizz Buzz
// https://leetcode.com/problems/fizz-buzz/
// c++
// easy
// O(n)
// O(1)
// basic


// simple modulo (remainder) approach O(n) 
// time, O(1) space
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        
        for (int i = 1; i <= n; i++) {
            string s = "";
            bool m3 = i % 3 == 0;
            bool m5 = i % 5 == 0;
            
            if (!(m3 || m5)) s += to_string(i);
            else {
                if (m3) s += "Fizz";
                if (m5) s += "Buzz";
            }
            
            ans.push_back(s);
        }
        
        return ans;
    }
};
