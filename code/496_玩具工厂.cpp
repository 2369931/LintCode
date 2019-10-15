#include <iostream>
#include <vector>

using namespace std;

class Toy {
public:
    virtual void talk() const=0;
};

///当const在函数名前面的时候修饰的是函数返回值，在函数名后面表示是常成员函数，该函数不能修改对象内的任何成员，只能发生读操作，不能发生写操作。
class Dog: public Toy {
public:
    void talk() const {
        cout << "Wow" << endl;
    }
};

class Cat: public Toy {
public:
    void talk() const {
        cout << "Meow" << endl;
    }
};

class ToyFactory {
public:
    /**
     * @param type a string
     * @return Get object of the type
     */
    Toy* getToy(string& type) {
        if (type == "Cat") {
            Toy * toy = new Cat();
            return toy;
        }
        if (type == "Dog") {
            Toy * toy = new Dog();
            return toy;
        }
    }
};

