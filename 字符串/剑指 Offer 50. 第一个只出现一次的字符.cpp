class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char,int> map;
        for(int i=0;i<s.size();i++){
            map[s.at(i)]++;
        }
        for(int i=0;i<s.size();i++){
            if(map[s.at(i)]==1) return s.at(i);
        }
        return ' ';
    }
};
