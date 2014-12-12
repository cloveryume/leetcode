class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ret;
        ret.push_back(1);

        for (int i = 0; i < rowIndex; ++i)
            generateNext(ret);

        return ret;
    }
private:
    void generateNext(vector<int> &vec) {
        vector<int> next;
        next.push_back(1);
        for (int i = 1; i < vec.size(); ++i) 
            next.push_back(vec[i] + vec[i - 1]);
        next.push_back(1);
        vec.swap(next);
    }
};
