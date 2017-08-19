# ExpressionEvaluator
Utilize data structures to evaluate expressions and provide a result

### Objectives
1. Evaluate an expression represented in reverse polish notation (explained below)
2. Generate an expression stack based on an equation represented by a binary tree

### Reverse Polish Notation (RPN)
Consider an expression:

```
(2 + 2) * (3 + 3)
```

This results in
```
4 * 6
```
which equals 24.

Now let's take out the parentheses and you get
```
2 + 2 * 3 + 3
```
This gives us a very different scenario. We are left with 
```
2 + 6 + 3
```
equalling 11.

An easy way that we can erase this confusion is by using RPN.

RPN places two or more operands followed by one total less operator. Restructuring the above equations:
```
2 2 + 3 3 + *     =    4 6 *    =    24
```
and
```
2 2 3 * 3 + +    =    2 6 3 + +    =    2 9 +    =    11
```
There is only one way to interpret each RPN equation, therefore reducing the syntax and coding effort involved

### Files
- [Express.hpp](lib/Express.hpp), function declarations
- [Express.cpp](lib/Express.cpp), function definitions
- [driver.cpp](lib/driver.cpp), main() method
- [Item.hpp](lib/Item.hpp), [Item.cpp](lib/Item.cpp), and [ITNode.hpp](lib/ITNode.cpp), supporting types

### Defined Functions
**in Express.hpp/Express.cpp*

- **void eval(ItemStack& exprStack):** 
  - Evaluate an expression based on characters placed in RPN on a stack
  - Remaining exprStack variable is a stack of one int, the result
- **ItemStack generateStack(ITNode\* root):**
  - Transform a normal expression in the form of a binary tree into a stack in RPN

### Instructions of Use
- To run, open your favorite C++ compiler (I used JetBrains CLion)
- Add all files within the /docs folder
- Modify values and add/remove comments in driver.cpp file to create new scenarios
- Compile, and check out the results in the display console!

---
*Skeleton code and documentation written by Professor Andrew Hughes of the 
SUNY University at Buffalo. For more information, view the detailed
assignment documentation ([A5.pdf](docs/A5.pdf)).*
