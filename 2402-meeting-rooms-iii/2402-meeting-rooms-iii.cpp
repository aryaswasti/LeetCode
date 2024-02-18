class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        //store the number of meetings held in each room
        vector<int> ans(n, 0);
        //track available rooms
        priority_queue<int, vector<int>, greater<int>> available;
        //track busy rooms and their end times
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busy;
        
        // Initially, all rooms are available
        for (int i = 0; i < n; i++) {
            available.push(i);
        }
        
        // Sort meetings based on start time
        sort(meetings.begin(), meetings.end());

        // Iterate through each meeting
        for (auto &&meeting : meetings) {
            //current meeting
            long long start = meeting[0], end = meeting[1];

            // add busy rooms that got free into "available"
            while (busy.size() > 0 && busy.top().first <= start) {
                //add to available rooms
                available.push(busy.top().second);
                //remove from busy rooms
                busy.pop();
            }

            //ASSIGN ROOM TO MEETINGS
            //1. check if empty rooms
            if (available.size() > 0) {
                //get minimum(index) of available room
                int room = available.top();
                //increase count for room
                ans[room]++;
                //remove from available room as it is allocated to new meeting
                available.pop(); 
                //push current room to busy<end time, room allocated>
                busy.push({end, room});
                
            //2. If no room available => remove earliest ending meeting and allocate it's room to current meeting
            } else {
                //get next earliest ending meeting
                auto nextRoom = busy.top();
                long long end1 = nextRoom.first, room = nextRoom.second;
                //pop earliest ending meeting
                busy.pop();
                
                // Add current meeting to, earliest ending meeting room "room"
                // calculate the new end time by 
                // adding the difference between the end and start time of the current meeting (end - start) 
                // to the original end time of the meeting("end1". 
                busy.push({end1 + end - start, room});
                //increase count for room 
                ans[room]++;
            }
        }

        // Find the room with the maximum number of meetings
        return max_element(ans.begin(), ans.end()) - ans.begin();
    }
};
