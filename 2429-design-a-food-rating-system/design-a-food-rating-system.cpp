#include <vector>
#include <string>
#include <unordered_map>
#include <set>
using namespace std;

class FoodRatings {
private:
    
    unordered_map<string, pair<string, int>> foodInfo;
    unordered_map<string, set<pair<int, string>>> cuisineMap;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; i++) {
            string food = foods[i];
            string cuisine = cuisines[i];
            int rating = ratings[i];
            foodInfo[food] = {cuisine, rating};
            cuisineMap[cuisine].insert({-rating, food});
        }
    }
    
    void changeRating(string food, int newRating) {
       
        auto& info = foodInfo[food];
        string cuisine = info.first;
        int oldRating = info.second;
        info.second = newRating;
        cuisineMap[cuisine].erase({-oldRating, food});
        cuisineMap[cuisine].insert({-newRating, food});
    }
    
    string highestRated(string cuisine) {
        return cuisineMap[cuisine].begin()->second;
    }
};