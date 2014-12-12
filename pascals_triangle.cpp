class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > ret;
        if (numRows == 0) return ret;

        ret.push_back(vector<int>(1, 1));
        for (int i = 1; i < numRows; ++i)
            generateNext(ret);

        return ret;
    }

private:
    void generateNext(vector<vector<int> >& vecs) {
        const vector<int>& prev = vecs.back();
        vector<int> vec;

        vec.push_back(1);
        for (int i = 1; i < prev.size(); ++i) 
            vec.push_back(prev[i] + prev[i-1]);
        vec.push_back(1);
        
        vecs.push_back(vec);
    }
};
