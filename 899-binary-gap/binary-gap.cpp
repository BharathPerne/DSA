class Solution {
public:
    int binaryGap(int n) {
        int maxDistance = 0;
        int lastOnePos = -1;
        int currentPos = 0;
        
        while (n > 0) {
            // Check if the current least significant bit is 1
            if (n & 1) {
                // If we've seen a 1 before, calculate the distance
                if (lastOnePos != -1) {
                    maxDistance = max(maxDistance, currentPos - lastOnePos);
                }
                lastOnePos = currentPos;
            }
            
            // Shift right to check the next bit
            n >>= 1;
            currentPos++;
        }
        
        return maxDistance;
    }
};