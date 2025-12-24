class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        // Total apples
        int totalApples = 0;
        for (int a : apple) {
            totalApples += a;
        }

        // Sort capacities in descending order
        sort(capacity.begin(), capacity.end(), greater<int>());

        int usedBoxes = 0;
        int currentCapacity = 0;

        // Pick boxes until capacity >= total apples
        for (int c : capacity) {
            currentCapacity += c;
            usedBoxes++;
            if (currentCapacity >= totalApples) {
                return usedBoxes;
            }
        }

        return usedBoxes; // safety return
    }
};
