class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if ((int)hand.size() % groupSize != 0) return false;
        vector<int> count(1001, 0);

        for (int i : hand) {
            count[i]++;
        }

        sort(hand.begin(), hand.end());

        int small = hand[0];
        int big = hand[hand.size() - 1];

        for (int card : hand) {
            if (count[card] == 0) continue;
            for (int j = 0; j < groupSize; j++) {
                int next = card + j;
                if (next > 1000 || count[next] == 0) return false;
                count[next]--;
            }
        }

        return true;

    }
};
