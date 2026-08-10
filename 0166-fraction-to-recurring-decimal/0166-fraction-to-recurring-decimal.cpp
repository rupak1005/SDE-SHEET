class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0)
            return "0";

        string ans;

        // Handle negative sign
        if ((numerator < 0) ^ (denominator < 0))
            ans += "-";

        // Convert to long long to avoid INT_MIN overflow
        long long num = llabs((long long)numerator);
        long long den = llabs((long long)denominator);

        // Integer part
        ans += to_string(num / den);

        long long rem = num % den;

        // No decimal part
        if (rem == 0)
            return ans;

        ans += ".";

        // remainder -> position in answer
        unordered_map<long long, int> seen;

        while (rem != 0) {

            // Repeating remainder found
            if (seen.count(rem)) {
                ans.insert(seen[rem], "(");
                ans += ")";
                break;
            }

            seen[rem] = ans.size();

            rem *= 10;

            ans += to_string(rem / den);

            rem %= den;
        }

        return ans;
    }
};