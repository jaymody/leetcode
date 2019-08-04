// 657
// Robot Return to Origin
// https://leetcode.com/problems/robot-return-to-origin/
// java
// easy
// O(n)
// O(1)
// basic

class Solution {
    public boolean judgeCircle(String moves) {
        int h = 0, v = 0;
        
        for (char c : moves.toCharArray()) {
            switch (c) {
                case 'R': h++; break;
                case 'L': h--; break;
                case 'U': v++; break;
                default: v--; break;
            }
        }
        
        return h == 0 && v == 0;
    }
}
