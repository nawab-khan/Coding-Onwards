class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int result = 0;

        int targetSetBitsCount = num2;
        int setBitsCount = 0;
        int currentBit = 31;

        while (setBitsCount < targetSetBitsCount) {
            // If the current bit of num1 is set or we must set all remaining bits in result
            if (isSet(num1, currentBit) || (targetSetBitsCount - setBitsCount > currentBit)) {
                setBit(result, currentBit);
                res |= (1 << currentBit);
                setBitsCount++;
            }
            currentBit--;  // Move to the next bit.
        }

        return res;
    }

    bool isSet(int x, int bit) { 
        return x & (1 << bit); 
    }

    void setBit(int &x, int bit) { 
        x |= (1 << bit); 
    }
};