class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> answer(temperatures.size(), 0);
        vector<int> stack;
        for (int i = 0; i < temperatures.size(); ++i) {
            while (!stack.empty() && temperatures[stack.back()] < temperatures[i]) {
                answer[stack.back()] = i - stack.back();
                stack.pop_back();
            }
            stack.push_back(i);
        }
        return answer;
    }
};