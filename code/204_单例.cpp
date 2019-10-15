class Solution {
public:
    /**
     * @return: The same instance of this class every time
     */
    static Solution* getInstance() {
        static Solution* one;
        if (one == NULL) {
            one = new Solution();
        }
        return one;
    }
};
