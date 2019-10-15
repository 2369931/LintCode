#include <iostream>
#include <vector>

using namespace std;

char lowercaseToUppercase(char character) {
    return (char)(character-32);
}


int main() {
    cout << lowercaseToUppercase('a') << endl;
    return 0;
}
