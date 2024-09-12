#include "box.h"

Box::Box(int width, char boxChar) : width(width), boxChar(boxChar) {}

int Box::getWidth() const {
    return width;
}

char Box::getBoxChar() const {
    return boxChar;
}

void Box::setBoxChar(char newChar) {
    boxChar = newChar;
}

void Box::operator+=(int offset) {
    width += offset;
    if (width < 0) width = 0;
}

void operator-=(Box& b, int offset) {
    b.width -= offset;
    if (b.width < 0) b.width = 0;
}

std::ostream& operator<<(std::ostream& out, const Box& b) {
    for (int i = 0; i < b.width; ++i) {
        for (int j = 0; j < b.width; ++j) {
            out << b.boxChar;
        }
        out << std::endl;
    }
    return out;
}