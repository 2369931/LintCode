#include <iostream>
#include <map>
#include <string>

using namespace std;

class CountingBloomFilter {
public:
    map<string,int> record;
    int length;
    CountingBloomFilter(int k) {
        length = k;
    }

    void add(const string &word) {
        map<string,int>::iterator it = record.find(word);
        if (it == record.end()) {
            record[word] = 1;
        }
        else {
            record[word] += 1;
        }
    }

    /*
     * @param word: A string
     * @return: nothing
     */
    void remove(const string &word) {
        map<string,int>::iterator it = record.find(word);
        if (it != record.end()) {
            it->second -= 1;
            if (it->second == 0) {
               record.erase(it);
            }
        }
    }

    /*
     * @param word: A string
     * @return: True if contains word
     */
    bool contains(const string &word) {
        map<string,int>::iterator it = record.find(word);
        if (it == record.end()) {
            return false;
        }
        else {
            return true;
        }
    }
};

int main() {
    CountingBloomFilter c(3);
    c.add("lint");
    c.add("code");
    c.add("lint");
    cout << c.contains("lint") << endl;
    c.remove("lint");
    cout << c.contains("lint") << endl;
    return 0;
}
