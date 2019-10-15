#include <iostream>
#include <map>
#include <string>

using namespace std;

class StandardBloomFilter {
public:
    /*
    * @param k: An integer
    */
    map<string,int> record;
    int length;
    StandardBloomFilter(int k) {
        length = k;
    }

    /*
     * @param word: A string
     * @return: nothing
     */
    void add(string &word) {
        map<string,int>::iterator it = record.find(word);
        if (it == record.end()) {
            record[word] = 1;
        }
    }

    /*
     * @param word: A string
     * @return: True if contains word
     */
    bool contains(string &word) {
        map<string,int>::iterator it = record.find(word);
        if (it == record.end()) {
            return false;
        }
        else {
            return true;
        }
    }
};
