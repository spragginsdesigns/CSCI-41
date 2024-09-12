#include <iostream>
#include <sstream>
#include <string>
using namespace std;

#include "box.h"

void assertTrue(bool b, string description) {
    if (!b) {
        cout << "FAILED: " + description << endl;
    } else {
        cout << "PASSED: " + description << endl;
    }
}

// Function prototypes
void runBoxTestEmpty();
void runBoxTestSize1();
void runBoxTestSize3();
void runBoxTestSetBoxChar();
void runBoxTestIncDec();
void runBoxTestLargeSize();
void runBoxTestDefaultConstructor();
void runBoxTestIncrementFromZero();
void runBoxTestDecrementToZero();
void runBoxTestNegativeIncrement();
void runBoxTestChainedOperations();

int main() {
    runBoxTestEmpty();
    runBoxTestSize1();
    runBoxTestSize3();
    runBoxTestSetBoxChar();
    runBoxTestIncDec();
    runBoxTestLargeSize();
    runBoxTestDefaultConstructor();
    runBoxTestIncrementFromZero();
    runBoxTestDecrementToZero();
    runBoxTestNegativeIncrement();
    runBoxTestChainedOperations();

    return 0;
}

// Existing tests
void runBoxTestEmpty() {
    Box b;
    stringstream ss;
    ss << b;
    assertTrue(b.getWidth() == 0 && b.getBoxChar() == '*' && ss.str() == "",
               "empty box");
}

void runBoxTestSize1() {
    Box b(1, '$');
    stringstream ss;
    ss << b;
    assertTrue(b.getWidth() == 1 && b.getBoxChar() == '$' && ss.str() == "$\n",
               "size 1 box");
}

void runBoxTestSize3() {
    Box b(3, '%');
    stringstream ss;
    ss << b;
    assertTrue(b.getWidth() == 3 && b.getBoxChar() == '%' &&
               ss.str() == "%%%\n%%%\n%%%\n",
               "size 3 box");
}

void runBoxTestSetBoxChar() {
    Box b(1, '$');
    b.setBoxChar('%');
    stringstream ss;
    ss << b;
    assertTrue(b.getWidth() == 1 && b.getBoxChar() == '%' && ss.str() == "%\n",
               "setBoxChar");
}

void runBoxTestIncDec() {
    Box b(1);
    bool isCorrect = true;
    // try to make the width 3
    b += 2;
    isCorrect = isCorrect && b.getWidth() == 3;
    stringstream ss;
    ss << b;
    isCorrect = isCorrect && ss.str() == "***\n***\n***\n";
    // clear out ss
    ss.str("");
    ss.clear();
    // try to make the width 1 again
    b -= 2;
    isCorrect = isCorrect && b.getWidth() == 1;
    ss << b;
    isCorrect = isCorrect && ss.str() == "*\n";
    assertTrue(isCorrect, "inc/dec");
}
