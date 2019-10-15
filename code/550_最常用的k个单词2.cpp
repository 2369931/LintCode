#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <algorithm>

using namespace std;

struct word {
    string name;
    int number;
    word(int n) {number = n;}
};

bool cmp(word &a, word &b) {
    if (a.number != b.number) {
        return a.number > b.number;
    }
    else {
        return a.name < b.name;
    }
}

int mid_find (vector<struct word> &record, map<string,int> book, string target,int start, int end) {
    int mid = (start + end) / 2;
    //cout << mid << endl;
    if (record[mid].name == target) {
        return mid;
    }
    else if (start < end) {
        if (book[record[mid].name] > book[target]) {
            mid_find(record,book,target,mid+1,end);
        }
        else if (book[record[mid].name] < book[target]){
            mid_find(record,book,target,start,mid);
        }
        else {
            if (record[mid].name > target) {
                mid_find(record,book,target,mid+1,end);
            }
            else {
                mid_find(record,book,target,start,mid);

            }
        }
    }
    return -1;
}


class TopK {
public:
    vector<struct word> record;
    map<string,int> book;
    int length;
    TopK(int k) {
        length = k;
    }
    void add(const string &word) {
        map<string,int>::iterator it = book.find(word);
        if (it != book.end()) {
            book[word] ++;
        }
        else{
            book[word] = 1;
        }
        int flag = 0;
        /*for (vector<struct word>::iterator it = record.begin();it != record.end();it++) {
            if ((*it).name == word) {
                (*it).number ++;
                flag = 1;
                sort(record.begin(),record.end(),cmp);
                break;
            }
        }*/
        int index = -1;
        if (record.size() >= 1) {
            index = mid_find(record,book,word,0,record.size()-1);
            /*for (int i = 0;i < record.size();i++) {
                cout << record[i].name << " : " << record[i].number << " ";
            }
            cout << endl;
            cout << index << " ''' " << word << endl;*/
            if (index != -1) {
                flag = 1;
                record[index].number = book[word];
                sort(record.begin(),record.end(),cmp);
            }
        }
        if (flag == 0) {
            struct word w(book[word]);
            w.name = word;
            if (record.size() < length) {
                record.push_back(w);
                sort(record.begin(),record.end(),cmp);
            }
            else {
                record.push_back(w);
                sort(record.begin(),record.end(),cmp);
                record.erase(record.end());
            }
        }
    }

    vector<string> topk() {
        vector<string> res;
        //sort(record.begin(),record.end(),cmp);
        for (int i = 0;i < record.size();i++) {
            res.push_back(record[i].name);
        }
        return res;
    }
};

int main() {
    TopK t(4);
    t.add("yes");
    t.add("lint");
    t.add("code");
    t.add("yes");
    t.add("code");
    t.add("baby");
    t.add("you");
    t.add("baby");
    vector<string> test = t.topk();
    /*vector<word> test;
    struct word w1(1);
    struct word w2(1);
    struct word w3(2);
    struct word w4(3);
    w1.name = "aa";
    w2.name = "ab";
    w3.name = "abc";
    w4.name = "ac";
    test.push_back(w1);
    test.push_back(w2);
    test.push_back(w3);
    test.push_back(w4);
    sort(test.begin(),test.end(),cmp);*/
    for (int i = 0;i < test.size();i++) {
        cout << test[i] << " ";
    }
    return 0;
}
