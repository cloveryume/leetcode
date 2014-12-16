class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> ret;
        std::unordered_map<int, int> umap(numbers.size());

        for (int i = 0; i < numbers.size(); ++i)
            umap.emplace(numbers[i], i);

        std::unordered_map<int, int>::const_iterator it;
        for (int i = 0; i < numbers.size(); ++i) {
            it = umap.find(target - numbers[i]);
            if (it != umap.end() && it->second != i) {
                ret.push_back(std::min(i, it->second) + 1);
                ret.push_back(std::max(i, it->second) + 1);
                break;
            }
        }
        return ret;
    }
};
