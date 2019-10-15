#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class WordCountMapper: public Mapper {
public:
    void Map(Input<string>* input) {
        while(!input->done()) {
            stringstream ss;
            ss << input->value();
            string str;
            while (ss >> str) {
                output(str,1);
            }
            input->next();
        }
    }
};


class WordCountReducer: public Reducer {
public:
    void Reduce(string &key, Input<int>* input) {
        int count = 0;
        while(!input->done()) {
            count += input->value();
            input->next();
        }
        output(key,count);
    }
};
