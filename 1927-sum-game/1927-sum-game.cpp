class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
        int sum_left = 0, sum_right = 0;
        int q_left = 0, q_right = 0;
        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?') {
                q_left++;
            } else {
                sum_left += num[i] - '0';
            }
        }

        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?') {
                q_right++;
            } else {
                sum_right += num[i] - '0';
            }
        }

        int sum_diff = sum_left - sum_right;
        int q_diff = q_left - q_right;

        if ((q_left + q_right) % 2 != 0) {
            return true;
        }

        return sum_diff * 2 != -q_diff * 9;
    }
};