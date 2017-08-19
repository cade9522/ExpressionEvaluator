//
// Author: Christian Evans
//

#include "Express.hpp"

void eval(ItemStack& exprStack) {
   ItemStack reverseStack = exprStack;
   bool empty = true;
   int operands = 0;
   int operators = 1;
   while (reverseStack.size() > 0){
       if (reverseStack.top().getType() == VAL){
           operands++;
       }
       else{
           operators++;
       }
       reverseStack.pop();
   }
   if (operands != operators){
       throw std::runtime_error("Malformed expression.");
   }
   while (exprStack.size() > 0) {
      empty = false;
      Item next = exprStack.top();
      if (next.getType() == VAL){
         exprStack.pop();
         reverseStack.push(next);
      }
      else{
         if (reverseStack.size() < 2){
            throw std::runtime_error("Malformed expression.");
         }
         Item second = reverseStack.top();
         reverseStack.pop();
         Item first = reverseStack.top();
         reverseStack.pop();
         exprStack.pop();
         if (next.getType() == ADD){
            Item sum = Item(first.getVal() + second.getVal());
            reverseStack.push(sum);
         }
         else if (next.getType() == SUB){
            Item difference = Item(first.getVal() - second.getVal());
            reverseStack.push(difference);
         }
         else if (next.getType() == MUL){
            Item product = Item(first.getVal() * second.getVal());
            reverseStack.push(product);
         }
         else if (next.getType() == DIV) {
            if (second.getVal() == 0) {
               throw std::runtime_error("DIV by 0 error.");
            }
            Item quotient = Item(first.getVal() / second.getVal());
            reverseStack.push(quotient);
         }
      }
   }
   if ((reverseStack.size() != 1) || empty){
       throw std::runtime_error("Malformed expression.");
   }
   Item item = reverseStack.top();
   reverseStack.pop();
   exprStack.push(item);
}

ItemStack generateStack(ITNode* root) {
    ItemStack exprStack;
    std::stack<ITNode*> stack;
    Item item = root->_item;
    exprStack.push(item);
    while ((root->_left != nullptr) || (root->_right != nullptr) || (!stack.empty())){
        ITNode* swap = root;
        if(root->_right != nullptr){
            swap = root->_right;
            root->_right = nullptr;
            stack.push(root);
            root = swap;
            item = root->_item;
            exprStack.push(item);
        }
        else if(root->_left != nullptr){
            swap = root->_left;
            root->_left = nullptr;
            stack.push(root);
            root = swap;
            item = root->_item;
            exprStack.push(item);
        }
        else {
            delete swap;
            root = stack.top();
            stack.pop();
        }
    }
    return exprStack;
}
