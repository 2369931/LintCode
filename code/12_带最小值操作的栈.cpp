#include <iostream>
#include <queue>

using namespace std;

class MinStack {
public:
    MinStack() {
    }

queue<int> q_a;
queue<int> q_b;

void push(int number) {
    if (q_a.empty()&&!q_b.empty()) {
        q_b.push(number);
        return;
    }
    else if (q_b.empty()&&!q_a.empty()) {
        q_a.push(number);
        return;
    }
    else if (q_a.empty()&&q_b.empty()) {
        q_a.push(number);
        return;
    }
}

int pop() {
    if (!q_a.empty()&&q_b.empty()) {
        int num = q_a.size();
        for (int i = 0;i < num - 1;i++) {
            int temp = q_a.front();
            q_a.pop();
            q_b.push(temp);
        }
        int result = q_a.front();
        q_a.pop();
        return result;
    }
    else if (q_a.empty()&&!q_b.empty()) {
        int num = q_b.size();
        for (int i = 0;i < num - 1;i++) {
            int temp = q_b.front();
            q_b.pop();
            q_a.push(temp);
        }
        int result = q_b.front();
        q_b.pop();
        return result;
    }
}

int min() {
    int result = 99999999;
    if (!q_a.empty()) {
        int num = q_a.size();
        for (int i = 0;i < num;i++) {
            int temp = q_a.front();
            q_a.pop();
            q_b.push(temp);
            if (temp < result) {
                result = temp;
            }
        }
        return result;
    }
    else {
        int num = q_b.size();
        for (int i = 0;i < num;i++) {
            int temp = q_b.front();
            q_b.pop();
            q_a.push(temp);
            if (temp < result) {
                result = temp;
            }
        }
        return result;
    }
}
};

int main() {
   MinStack s;
   s.push(1);
   //cout << s.q_a.size() << " :: " << s.q_b.size() << endl;
   cout << s.pop() <<endl;
   //cout << s.q_a.size() << " :: " << s.q_b.size() << endl;
   s.push(2);
   s.push(3);
   //s.push(4);
   //cout << s.q_a.size() << " :: " << s.q_b.size() << endl;
   //s.pop();
   //cout << s.q_a.size() << " :: " << s.q_b.size() << endl;
   cout << s.min() << endl;
   //cout << s.q_a.size() << " :: " << s.q_b.size() << endl;
   s.push(1);
   //cout << s.q_a.size() << " :: " << s.q_b.size() << endl;
   cout << s.min() << endl;
   return 0;
}
