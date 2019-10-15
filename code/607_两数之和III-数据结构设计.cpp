class TwoSum {
public:
    vector<int> record;
    int flag;
    void add(int number) {
        record.push_back(number);
        flag = 1;
    }
    bool find(int value) {
        if (flag == 1) {
            sort(record.begin(),record.end());
            flag = 0;
        }
        int s = 0;
        int t = record.size()-1;
        while (s < t) {
            int sum = record[s] + record[t];
            if (sum == value) return true;
            if (sum > value) {
                t --;
            }
            else {
                s ++;
            }
        }
        return false;
    }
};
