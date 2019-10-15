#include <iostream>
#include <vector>

using namespace std;

class Toy {
public:
    virtual void talk() const=0;
};

///��const�ں�����ǰ���ʱ�����ε��Ǻ�������ֵ���ں����������ʾ�ǳ���Ա�������ú��������޸Ķ����ڵ��κγ�Ա��ֻ�ܷ��������������ܷ���д������
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

