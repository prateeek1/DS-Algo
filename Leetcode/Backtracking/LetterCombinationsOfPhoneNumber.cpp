class Solution {
public:
    vector<string> letterCombinations(string digits) {

        vector<string>possible = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
                                 };

        vector<string>ans;
        if (digits == "")
            return ans;
        permute("", digits, ans, 0, possible);
        return ans;
    }


    void permute(string currAns, string digits, vector<string>&ans, int length, vector<string>possible )
    {
        if (length == digits.length())
        {
            ans.push_back(currAns);
            return;
        }

        string alpha = possible[digits[length] - '2'];

        for (int i = 0; i < alpha.size(); i++)
        {
            permute(currAns + alpha[i], digits, ans, length + 1, possible);
        }


    }
};