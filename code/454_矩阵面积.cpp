#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

public class Rectangle {
    /*
     * Define two public attributes width and height of type int.
     */
    // write your code here
    int width;
    int height;

    /*
     * Define a constructor which expects two parameters width and height here.
     */
    // write your code here
    Rectangle(int a, int b) {
        width = a;
        height = b;
    }

    int getArea() {
        return width * height;
    }

    /*
     * Define a public method `getArea` which can calculate the area of the
     * rectangle and return.
     */
    // write your code here
}
