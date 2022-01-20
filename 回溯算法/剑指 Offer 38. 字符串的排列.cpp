//用set去重有点无赖
class Solution {
public:
    set<string> res;
    vector<string> permutation(string s) {
        vector<bool> used(s.size(),false);
        myfunction("",s,used);
        vector<string> res1;
        for(auto s:res) res1.push_back(s);//去重
        return res1;
    }
    void myfunction(string temp,string s,vector<bool>& used){
        if(temp.size()==s.size()){
            res.insert(temp);
            return;
        }
        for(int i=0;i<s.size();i++){
            if(used[i]==true) continue;
            temp+=s[i];
            used[i]=true;
            myfunction(temp,s,used);
            temp=temp.substr(0,temp.size()-1);
            used[i]=false;

        }
    }
};

//和全排列II类似，可以看那个
class Solution {
public:
    vector<string> res;
    vector<string> permutation(string s) {
        vector<bool> used(s.size(),false);
        sort(s.begin(),s.end());
        myfunction("",s,used);
        return res;
    }
    void myfunction(string temp,string s,vector<bool>& used){
        if(temp.size()==s.size()){
            res.push_back(temp);
            return;
        }
        for(int i=0;i<s.size();i++){
            if(used[i] || i-1>=0 && s[i-1]==s[i] && !used[i-1]) continue;
            temp+=s[i];
            used[i]=true;
            myfunction(temp,s,used);
            temp=temp.substr(0,temp.size()-1);
            used[i]=false;

        }
    }
};
