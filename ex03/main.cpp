#include "Fixed.hpp"
#include "Point.hpp"

int main () {
    if (bsp(1, 2, 3, 4))
        std::cout << "the point is inside the triangle" << std::endl;
    else
        std::cout << "if the point is a vertex or on edge or outside" << std::endl;
    return 0;
}