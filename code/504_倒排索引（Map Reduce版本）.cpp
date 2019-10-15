#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

template<class T>
class Input {
public:
    bool done();
        // Returns true if the iteration has elements or false.
    void next();
        // Move to the next element in the iteration
        // Runtime error if the iteration has no more elements
    T value();
       // Get the current element, Runtime error if
       // the iteration has no more elements
}

class Document {
public:
    int id; // document id
    string content; // document content
}

class InvertedIndexMapper: public Mapper {
public:
    void Map(Input<Document>* input) {
        while (!input->done()) {
            stringstream ss;
            string word;
            ss << input->value().content;
            while (ss >> word)
                output(word,input->value().id);
            input->next();
        }
    }
};


class InvertedIndexReducer: public Reducer {
public:
    void Reduce(string &key, Input<int>* input) {
        vector<int> idList;
        while (!input->done()) {
            if (idList.size() == 0 || input->value() != idList.back()) {
                idList.push_back(input->value());
            }
            input->next();
        }
        output(key,idList);
    }
};

int main() {
}
