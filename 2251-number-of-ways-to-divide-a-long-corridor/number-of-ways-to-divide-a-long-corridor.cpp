class Solution {
public:
    int numberOfWays(string corridor) {
        const long long MOD = 1e9 + 7;
        vector<int> seats;
        
        // Store indices of all seats
        for (int i = 0; i < corridor.size(); i++) {
            if (corridor[i] == 'S') {
                seats.push_back(i);
            }
        }
        
        // If seats are zero or odd, no valid division
        if (seats.size() == 0 || seats.size() % 2 != 0) {
            return 0;
        }
        
        long long ways = 1;
        
        // Process each pair of seat groups
        for (int i = 2; i < seats.size(); i += 2) {
            int plantsBetween = seats[i] - seats[i - 1] - 1;
            ways = (ways * (plantsBetween + 1)) % MOD;
        }
        
        return ways;
    }
};
