#include <bits/stdc++.h>
using namespace std;

class TaskManager {
    priority_queue<tuple<int,int,int>> pq;
    unordered_map<int, pair<int,int>> taskMap;
    
public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto &t : tasks) {
            int userId = t[0], taskId = t[1], priority = t[2];
            add(userId, taskId, priority);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        taskMap[taskId] = {userId, priority};
        pq.push({priority, taskId, userId});
    }
    
    void edit(int taskId, int newPriority) {
        if (taskMap.find(taskId) == taskMap.end()) return;
        int userId = taskMap[taskId].first;
        taskMap[taskId] = {userId, newPriority};
        pq.push({newPriority, taskId, userId});
    }
    
    void rmv(int taskId) {
        taskMap.erase(taskId);
    }
    
    int execTop() {
        while (!pq.empty()) {
            auto [priority, taskId, userId] = pq.top();
            if (taskMap.find(taskId) == taskMap.end()) {
                pq.pop();
                continue;
            }
            auto [uid, currPriority] = taskMap[taskId];
            if (currPriority != priority) {
                pq.pop();
                continue;
            }
            pq.pop();
            taskMap.erase(taskId);
            return userId;
        }
        return -1; 
    }
};
