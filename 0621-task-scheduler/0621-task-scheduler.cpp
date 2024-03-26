class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mpp;
        for(auto task : tasks){
            mpp[task]++;
        }
        
        priority_queue<int> pq;
        for(auto i : mpp){
            pq.push(i.second);
        }
        
        queue<pair<int,int>> q;
        int time = 0;
        while(pq.size() > 0 or q.size() > 0){
            if(pq.size() > 0){
                int count = pq.top();
                pq.pop();
                time += 1;
                --count;
                if(count != 0) {
                    q.push({count,time+n});   
                }
            }
            if(q.size() > 0 and q.front().second <= time){
                auto temp = q.front();q.pop();
                pq.push(temp.first);
            }
            else if(pq.size()==0){
                time++; // We need to do time -1 in the end because it will be increamenting it even when all task done
            }
        }
        return time-1; 
    }
};