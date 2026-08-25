class Solution {
public:
    vector<string> generateParenthesis(int n) {
        std::string curr;
        curr.reserve(n * 2);
        std::vector<std::string> res;
        backtrace(n, 0, 0, res, curr);
        return res;
    }

    void backtrace(int n, int open, int close, std::vector<string>& res, std::string& curr) {
        if (open == close && curr.length() == (n * 2)) {
            res.push_back(curr);
            return;
        }

        if (open < n) {
            curr.push_back('(');
            backtrace(n, open + 1, close, res, curr);
            curr.pop_back();
        }

        if (close < open) {
            curr.push_back(')');
            backtrace(n, open, close + 1, res, curr);
            curr.pop_back();
        }

    }
};
