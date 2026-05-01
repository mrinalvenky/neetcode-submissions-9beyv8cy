class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        if (meetings.empty()) return 0;
        sort(meetings.begin(), meetings.end(),
            [](vector<int>& a, vector<int>& b) {
                return (a[0] == b[0]) ? a[1] < b[1] : a[0] < b[0];
            }
        );
        priority_queue<int, vector<int>, greater<int>> available;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> used;
        vector<int> count(n, 0);
        for (int i = 0; i < n; i++) {
            available.push(i);
        }

        for (vector<int>& meet: meetings) {
            int start = meet[0];
            int end = meet[1];
            while (!used.empty() && used.top().first <= start) {
                int room = used.top().second;
                used.pop();
                available.push(room);
            }
            if (available.empty()) {
                auto current = used.top();
                used.pop();
                end = current.first + (end - start);
                available.push(current.second);
            }
            int room = available.top();
            available.pop();
            used.push({end, room});
            count[room]++;
        }
        int maxRoom = 0;
        for (int i = 0; i < n; i++) {
            if (count[i] > count[maxRoom]) maxRoom = i;
        }
        return maxRoom;
    }
};