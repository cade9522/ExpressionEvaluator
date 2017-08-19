# ExpressionEvaluator
Utilize data structures to evaluate expressions and provide a result

### Objectives
1. Evaluate an expression represented in reverse polish notation (explained below)
2. Generate an expression stack based on an equation represented by a binary tree (explained below)

### Reverse Polish Notation (RPN)
Consider an expression:
'''
(2 + 2) * (3 + 3)
'''
This results in 4 * 6, which equals 24.
Now let's take out the parentheses and you get:
'''
2 + 2 * 3 + 3
'''
This gives us a very different scenario.
We are left with 2 + 6 + 3, equalling 11.
An easy way that we can erase this confusion is by using RPN.
RPN places two or more operands followed by one total less operator. Restructuring the above equations:
'''
2 2 + 3 3 + * = 4 6 * = 24
'''
'''
2 2 3 * 3 + + = 2 6 3 + + = 2 9 + = 11
'''
