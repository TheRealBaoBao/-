//Time complexity: O(m)
//Space complexity: O(m+n)

class Solution{
public:
    string encode(vector<string>& strs){
        string res;
        for(const strings&s : strs){
            res += to_string(s.size() + '#' + s);
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while (i<s.size()){
            int j = 1;
            while(s[j] != '#'){
                j++;
            }
            int length = stoi(s.substr(i, j-1));
            i = j+1;
            j = 1 + length;
            res.push_pack(s.substr(i, length));
            i = j;
        }
        return res;
    }
};
