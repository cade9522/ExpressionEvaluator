//
// Author: Andrew Hughes, modified comments and layout by Christian Evans
//


#include "Express.hpp"
#include <vector>
#include <iostream>

void validate(int expected, int actual) {
    if (expected != actual) {
        std::cerr << "Incorrect evaluation. Expected value = " << expected << ", Actual value = " << actual << std::endl;
    }
    else {
        std::cout << "Evaluated expression stack correctly." << std::endl;
    }
}

void deleteExprTree(ITNode* tree) {
    if(tree != nullptr) {
        deleteExprTree(tree->_left);
        deleteExprTree(tree->_right);
        delete tree;
    }
}

int main() {
    /* Change the expression and expected values here to test your code */

    // exprTree will hold a tree with the expression (3 + 4) * (2 - 5)
    ITNode* exprTree = new ITNode(Item('*'));
    exprTree->_left = new ITNode(Item('+'));
    exprTree->_right = new ITNode(Item('-'));
    ITNode* current = exprTree->_left;
    current->_left = new ITNode(Item(3));
    current->_right = new ITNode(Item(4));
    ITNode* next = exprTree->_right;
    next->_left = new ITNode(Item(2));
    next->_right = new ITNode(Item(5));

    // This is the expression (3 + 4) * (2 - 5)
    // Only use if testing just eval(), comment out otherwise
    /*
    std::vector<Item> expr = {{3},{4},{'+'},{2},{5},{'-'},{'*'}};
    */

    // This is the expected result
    int expected = -21;

    // Should an exception be thrown? Yes = True, No = False
    bool expectException = false;

    //////////////////////////////////////////////////////////////////////

    /**
     *
     * USE THE FOLLOWING TO TEST THE EVAL() AND GENERATESTACK() METHODS
     * COMMENT OUT IF TESTING JUST THE EVAL() FUNCTION
     *
     */

    try {
        ItemStack s = generateStack(exprTree);

        // Evaluate expression in stack.

        eval(s);

        // After eval, top of stack should be result.
        int actual = s.top().getVal();
        std::cout << actual << std::endl;


        if (expectException) {
            std::cerr << "Expected exception but did not throw one" << std::endl;
        }
        else {
            validate(expected, actual);
        }


    }
    catch (const std::runtime_error& e) {
        if (!expectException) {
            std::cerr << "Caught unexpected exception" << std::endl;
        }
        std::cout << e.what() << std::endl;
    }

    // Clean up tree memory.
    deleteExprTree(exprTree);

    ///////////////////////////////////////////////////////////////////////

    /**
     *
     * USE THE FOLLOWING TO TEST JUST THE EVAL() METHOD
     * COMMENT OUT IF TESTING BOTH FUNCTIONS
     *
     */

    /*
    ItemStack s;

    // Notice that we push the RPN to the stack in reverse order.
    // This gives us the _leftmost item in the RPN formula on top.

    for (auto it = expr.rbegin(); it != expr.rend(); ++it) {
        s.push(*it);
    }
    try {
        // Evaluate expression in stack.
        eval(s);

        // After eval, top of stack should be result.
        int actual = s.top().getVal();
        std::cout << actual << std::endl;
        std::cout << expected << std::endl;


        if (expectException) {
            std::cerr << "Expected exception but did not throw one" << std::endl;
        }
        else {
            validate(expected, actual);
        }

    }
    catch (const std::runtime_error& e) {
        if (!expectException) {
            std::cerr << "Caught unexpected exception" << std::endl;
        }
        std::cout << e.what() << std::endl;
    }
    */

    //////////////////////////////////////////////////////////////////////

    return 0;
}
