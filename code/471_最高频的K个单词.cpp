#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

struct Word {
    string name;
    int times;
};

bool compare(Word a, Word b) {
    if (a.times > b.times) {
        return false;
    }
    else if (a.times < b.times) {
        return true;
    }
    else {
        return a.name > b.name;
    }
}

vector<string> topKFrequentWords(vector<string> &words, int k) {
    int n = words.size();
    vector<string> result;
    map<string,int> record;
    if (n == 0|| k == 0) {
        return result;
    }
    for (int i = 0;i < n;i++) {
        map<string,int>::iterator it = record.find(words[i]);
        if (it == record.end()) {
            record[words[i]] = 1;
        }
        else {
            record[words[i]] += 1;
        }
    }
    vector<Word> book;
    for (map<string,int>::iterator it = record.begin();it != record.end();it++) {
        Word w;
        w.name = it->first;
        w.times = it->second;
        book.push_back(w);
    }
    book.sort(book.begin(),book.end(),compare);
    /*for (int i = 0;i < book.size();i++) {
        for (int j = i;j < book.size();j++) {
            if (compare(book[j],book[i])) {
                Word a = book[i];
                book[i] = book[j];
                book[j] = a;
            }
        }
    }*/
    for (int i = 0;i < k;i++) {
        result.push_back(book[book.size()-1-i].name);
    }
    return result;
}

int main() {
    string a[15] = {"yes", "lint", "code",
    "yes", "code", "baby",
    "you", "baby", "chrome",
    "safari", "lint", "code",
    "body", "lint", "code"};
    vector<string> test(a,a+15);
    vector<string> result = topKFrequentWords(test,4);
    for (int i = 0;i < result.size();i++) {
        cout << result[i] << " ";
    }
    return 0;
}

