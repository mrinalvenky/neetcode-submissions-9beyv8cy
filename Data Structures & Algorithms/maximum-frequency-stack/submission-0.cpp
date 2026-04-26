class FreqStack {
private:
    unordered_map<int, int> count_map;
    unordered_map<int, vector<int>> count_list;
    int max_count;
public:
    FreqStack() {
        max_count = 0;
    }
    
    void push(int val) {
        int cur_count = count_map[val]++;
        cur_count++;
        count_list[cur_count].push_back(val);
        max_count = max(max_count, cur_count);
    }
    
    int pop() {
        int ret = count_list[max_count].back();
        count_list[max_count].pop_back();
        if (count_list[max_count].empty()) {
            max_count--;
        }
        count_map[ret]--;
        return ret;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */