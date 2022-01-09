class Solution {
public:
    string replaceSpace(string s) {
        string res;
        for(int i=0;i<s.size();i++){
            if(s.at(i)==' ') res+="%20";
            else res+=s.at(i);
        }
        return res;
    }
};
