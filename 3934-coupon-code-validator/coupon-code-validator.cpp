class Solution {
public:
    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {
        
        unordered_map<string, int> order = {
            {"electronics", 0},
            {"grocery", 1},
            {"pharmacy", 2},
            {"restaurant", 3}
        };
        
        vector<pair<int, string>> validCoupons;
        
        for (int i = 0; i < code.size(); i++) {
            // Condition 3: must be active
            if (!isActive[i]) continue;
            
            // Condition 2: valid business line
            if (order.find(businessLine[i]) == order.end()) continue;
            
            // Condition 1: valid code
            if (code[i].empty()) continue;
            bool ok = true;
            for (char c : code[i]) {
                if (!isalnum(c) && c != '_') {
                    ok = false;
                    break;
                }
            }
            if (!ok) continue;
            
            validCoupons.push_back({order[businessLine[i]], code[i]});
        }
        
        // Sort by businessLine order, then by code
        sort(validCoupons.begin(), validCoupons.end(),
             [](auto &a, auto &b) {
                 if (a.first != b.first)
                     return a.first < b.first;
                 return a.second < b.second;
             });
        
        vector<string> result;
        for (auto &p : validCoupons) {
            result.push_back(p.second);
        }
        
        return result;
    }
};
