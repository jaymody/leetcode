// 509
// Fibonacci Number
// https://leetcode.com/problems/fibonacci-number/
// c++
// easy
// basic

class Solution {
public:
    int fib(int N) {
        int a=0;
        int b=1;
        for (int i=0; i < N; i++) {
            b=a+b;
            a=b-a;
        }
    
        return a;
    }
};