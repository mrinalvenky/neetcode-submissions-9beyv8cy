class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> pos_speed;
        stack<double> st;
        for (int i = 0; i < position.size(); i++) {
            pos_speed.push_back({position[i], speed[i]});
        }
        sort(pos_speed.rbegin(), pos_speed.rend());
        for(auto& p: pos_speed) {
            st.push((double)(target - p.first)/p.second);
            if (st.size() >= 2) {
                double t = st.top();
                st.pop();
                if (t > st.top()) st.push(t);
            }
        }
        return st.size();
    }
};
