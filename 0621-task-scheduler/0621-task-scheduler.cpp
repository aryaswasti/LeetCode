class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> taskCount;
        for (char task : tasks) {
            taskCount[task]++;
        }
        
        int maxTask = 0;
        for (auto& kv : taskCount) {
            maxTask = max(maxTask, kv.second);
        }
        
        int maxRepeats = 0;
        for (auto& kv : taskCount) {
            if (kv.second == maxTask) {
                maxRepeats++;
            }
        }
        
        return max((int)tasks.size(), maxTask * (1 + n) - n + maxRepeats - 1);
    }
};