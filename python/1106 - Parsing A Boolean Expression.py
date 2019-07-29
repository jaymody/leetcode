# 1106
# Parsing A Boolean Expression
# https://leetcode.com/problems/parsing-a-boolean-expression/
# python
# hard
# O(n)
# O(n)
# string

# O(n) O(n) solution that is messy to read
# but fast and uses very little space
class Solution:
    def iterate(self, expression):
        op = expression[0]
        
        ops = ['!','|','&']
        terms = []
        
        idx = 2
        
        while expression[idx] != ')' and idx<len(expression): 
            if expression[idx] in ops:
                b,i = self.iterate(expression[idx:])
                terms.append(b)
                idx += i
                continue
            terms.append(expression[idx] == 't')
            idx += 1
        
        if op == '!':
            out_b = not terms[0]
        elif op == '&':
            out_b = not False in terms
        else:
            out_b = True in terms
        
        # print(op, terms, " ----> ", out_b) 
        return out_b, idx+1
            
    
    def parseBoolExpr(self, expression: str) -> bool:
        if len(expression) == 1:
            return expression == 't'
        return self.iterate(expression.replace(',',''))[0]
