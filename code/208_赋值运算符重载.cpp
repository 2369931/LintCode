#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    char *m_pData;
    Solution() {
        this->m_pData = NULL;
    }
    Solution(char *pData) {
        this->m_pData = pData;
    }

    // Implement an assignment operator
    Solution operator=(Solution &object) {
        if (this != &object) {
            delete[] this->m_pData;
            if (object.m_pData != NULL) {
                this->m_pData = new char[strlen(object.m_pData) + 1];
                strcpy(this->m_pData, object.m_pData);
            }
        }
        return *this;
    }
};

