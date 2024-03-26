class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Array to store the frequency of each task
        int freq[26] = {0};
        
        // Count the frequency of each task
        for(char task : tasks){
            freq[task - 'A']++;
        }
        
        // Sort the frequencies in descending order
        sort(begin(freq), end(freq));
        
        // Calculate the number of intervals needed by considering the task with the maximum frequency
        int chunk = freq[25] - 1; // Maximum frequency - 1
        int idel = chunk * n; // Initial estimate of idle slots
        
        // Iterate from the second highest frequency to the lowest frequency
        for(int i = 24; i >= 0; i--){
            // Update the idle slots by subtracting the minimum of chunk and frequency of the current task
            // We use the minimum because we only need to insert idel when the remaining tasks are fewer than the chunk size
            // if we had 4 As and 2 Bs, so 3 chunks, here we can easily fill 2 bs in those 3 chunks while maintiang the rules
            // But in case Bs were more than the chunks, then the leftover B would be placed at the end
            idel -= min(chunk, freq[i]);
        }

        // We return different answers based on different cases:
        // If idel is less than 0, it means that all tasks can be scheduled without remaining idle slots
        // In this case, we return the total number of tasks
        // Otherwise, we return the total number of tasks plus the remaining idle slots
        return idel < 0 ? tasks.size() : tasks.size() + idel;
    }
};
