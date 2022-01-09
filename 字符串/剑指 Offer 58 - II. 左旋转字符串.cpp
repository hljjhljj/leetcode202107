//方法1：三次reverse()
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        int len=s.size();
        n=n%len;
        reverse(s.begin(),s.begin()+n);
        reverse(s.begin()+n,s.end());
        reverse(s.begin(),s.end());
        return s;
    }
};

//方法2：重复一次后取子串
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        int len=s.size();
        s+=s;
        n=n%len;
        return s.substr(n,len);
    }
};
