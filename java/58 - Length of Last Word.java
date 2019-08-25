// 58
// Length of Last Word
// https://leetcode.com/problems/length-of-last-word/
// java
// easy
// O(n)
// O(1)
// string

// time: O(n)  (where n is the length of the last word + any trailing whitespace)
// space: O(1)
class Solution {
    public int lengthOfLastWord(String s) {
        int count = 0;
        int i = s.length()-1;
        
        while (i >= 0 && s.charAt(i) == ' ')
            i--;
        while (i >= 0 && s.charAt(i) != ' ') {
            count++;
            i--;
        }

        return count;
    }
}