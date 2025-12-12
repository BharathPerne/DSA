// class Solution {
// public:
//     vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
//         vector<int> result(numberOfUsers,0);
//         map<int,int> offline;
//         map<int,int> online;

//         std::sort(events.begin(), events.end(), 
//         [](const std::vector<std::string>& a, const std::vector<std::string>& b) {
//             // First compare timestamps as numbers
//             int timeA = std::stoi(a[1]);
//             int timeB = std::stoi(b[1]);
            
//             if (timeA != timeB) {
//                 return timeA < timeB;  // Sort by timestamp ascending
//             }
            
//             // If timestamps are equal, prioritize "OFFLINE" first
//             // Define priority: OFFLINE comes before everything else
//             if (a[0] == "OFFLINE" && b[0] != "OFFLINE") {
//                 return true;  // a (OFFLINE) comes before b
//             }
//             if (b[0] == "OFFLINE" && a[0] != "OFFLINE") {
//                 return false;  // b (OFFLINE) comes before a
//             }
            
//             // If both are OFFLINE or neither is OFFLINE, use natural order
//             return a[0] < b[0];
//         });
//         for(int i=0;i<events.size();i++)
//         {
//             int timestamp=stoi(events[i][1]);
//             for(auto num:offline)
//             {
//                 if((timestamp-(num.second+num.second))>=0)
//                 {
//                     // online[num.first]=num.second;
//                     offline.erase(num.first);
//                 }
//             }
//             if(events[i][0]=="MESSAGE")
//             {
//                 if(events[i][2]=="ALL")
//                 {
//                     for(int j=0;j<result.size();j++)
//                     {
//                         result[j]++;
//                     }
//                 }
//                 else if(events[i][2]=="HERE")
//                 {
//                     for(auto num:offline)
//                     {
//                         result[num.first]--;
//                     }
//                     for(int j=0;j<result.size();j++)
//                     {
//                         std::cout<<result[j]++<<endl;
//                     }
//                 }
//                 else
//                 {
//                     string idString = events[i][2];
        
//                     // Go through each character
//                     for(int j = 0; j < idString.size(); j++) {
//                         std::string str = "";
                        
//                         // Extract consecutive digits
//                         while(j < idString.size() && isdigit(idString[j])) {
//                             str += idString[j];
//                             j++;
//                         }
//                         if(!str.empty())
//                         {
//                         result[stoi(str)]++;
//                         }
//                     }
//                 }
//             }
//             else
//             {
//                 int id=stoi(events[i][2]);
//                 offline[id]=stoi(events[i][1]);
//             }
//         }
//         return result;
//     }
// };

class Solution {
public:
    void applyMessageEvent(vector<string>event, vector<int>&mentionCount, vector<int>&offlineTime){

        int timestamp = stoi(event[1]);

        vector<string> ids;

        stringstream ss(event[2]);

        string token;
        while(ss >> token){
            ids.push_back(token);
        }

        //Process all IDs
        for(string id : ids) {
            if(id == "ALL") {
                for(int i = 0; i<mentionCount.size(); i++) {
                    mentionCount[i]++;
                }
            } else if(id == "HERE") {
                for(int i = 0; i < mentionCount.size(); i++){
                    if(offlineTime[i] == 0 || offlineTime[i] + 60 <= timestamp){
                        mentionCount[i]++;
                    }
                }
            } else {
                mentionCount[stoi(id.substr(2))]++; //fetch id value i.e. x from idx (id0, id1 etc)
            }
        }

    }

    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int>mentionCount(numberOfUsers);
        vector<int>offlineTime(numberOfUsers);

        auto lambda=[](vector<string>& vec1, vector<string>& vec2) {
            int t1 = stoi(vec1[1]);
            int t2 = stoi(vec2[1]);

            if(t1 == t2) {
                return vec1[0][1] > vec2[0][1]; //comparing 'O' of "OFFLINE" with 'M' of "MESSAGE"
                //OFFLINE should come first
            }

            return t1 < t2;
        };

        sort(events.begin(), events.end(), lambda);

        for(vector<string>event: events){
            if(event[0] == "MESSAGE") {
                applyMessageEvent(event, mentionCount, offlineTime);
            }
            else if(event[0] == "OFFLINE") {
                int timestamp = stoi(event[1]);
                int id = stoi(event[2]);
                offlineTime[id] = timestamp;
            }
        }

        return mentionCount;
    }
};