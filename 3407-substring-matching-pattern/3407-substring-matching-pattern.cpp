class Solution {
public:
    bool hasMatch(string s, string p) {
        int pos = p.find('*');

        string left = p.substr(0, pos);
        string right = p.substr(pos + 1);

        int l = s.find(left);

        if(l == string::npos)
            return false;

        int r = s.find(right, l + left.size());

        return r != string::npos;
    }
};