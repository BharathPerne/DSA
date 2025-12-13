// class Solution {
// public:
// bool isvalid(string str)
// {
//     if(str.size()<=0)
//     {
//         return false;
//     }
//     for(int i=0;i<str.size();i++)
//     {
//         if ( ('a' <= str[i] && str[i] <= 'z') || ('A' <= str[i] && str[i] <= 'Z') ||('0'<=str[i]&&str[i]<='9')||str[i] == '_' )
//         {
//             continue;
//         }
//         else
//         {
//             return false;
//         }
//     }
//     return true;
// }
//     vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
//         vector<string> electronics;
//         vector<string> grocery;
//         vector<string> pharmacy;
//         vector<string> restaurant;
//         for(int i=0;i<code.size();i++)
//         {
//             if(isvalid(code[i]))
//             {
//                 if(isActive[i])
//                 {
//                     if(businessLine[i]=="restaurant")
//                     {
//                         restaurant.push_back(code[i]);
//                     }
//                     else if(businessLine[i]=="grocery")
//                     {
//                         grocery.push_back(code[i]);
//                     }
//                     else if(businessLine[i]=="pharmacy")
//                     {
//                         pharmacy.push_back(code[i]);
//                     }
//                     else if(businessLine[i]=="electronics")
//                     {
//                         electronics.push_back(code[i]);
//                     }
//                 }
//             }
//         }
//         vector<string> result;
//         sort(electronics.begin(), electronics.end());
//     sort(grocery.begin(), grocery.end());
//     sort(pharmacy.begin(), pharmacy.end());
//     sort(restaurant.begin(), restaurant.end());
//     result.insert(result.end(), electronics.begin(), electronics.end());
//     result.insert(result.end(), grocery.begin(), grocery.end());
//     result.insert(result.end(), pharmacy.begin(), pharmacy.end());
//     result.insert(result.end(), restaurant.begin(), restaurant.end());
//     return result;
//     }
// };

class Solution {
public:
bool isValid(string str)
{
    if(str.size()<=0)
    {
        return false;
    }
    for(int i=0;i<str.size();i++)
    {
        if ( ('a' <= str[i] && str[i] <= 'z') || ('A' <= str[i] && str[i] <= 'Z') ||('0'<=str[i]&&str[i]<='9')||str[i] == '_' )
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive)
    {
        map<string, priority_queue<string, vector<string>, greater<string>>> categoryHeaps;
        for(int i=0;i<code.size();i++)
        {
            if(isValid(code[i]))
            {
                if(isActive[i])
                {
                    if(businessLine[i]=="restaurant")
                    {
                        categoryHeaps["restaurant"].push(code[i]);
                    }
                    else if(businessLine[i]=="grocery")
                    {
                        categoryHeaps["grocery"].push(code[i]);
                    }
                    else if(businessLine[i]=="pharmacy")
                    {
                        categoryHeaps["pharmacy"].push(code[i]);
                    }
                    else if(businessLine[i]=="electronics")
                    {
                        categoryHeaps["electronics"].push(code[i]);
                    }
                }
            }
        }
        vector<string> result;
        for (auto& [category, heap] : categoryHeaps) {
        while (!heap.empty()) {
            result.push_back(heap.top());
            heap.pop();
        }
    }
     return result;
    }
};