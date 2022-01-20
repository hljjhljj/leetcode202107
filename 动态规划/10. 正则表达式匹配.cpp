class Solution {
public:
    //https://mp.weixin.qq.com/s/rnaFK05IcFWvNN1ppNf2ug
    map<string,bool> memory;//备忘录，string是i,j
    bool isMatch(string s, string p) {
        return dp(s,0,p,0);
    }
    //s串从i开始，p串从j开始，是否匹配
    bool dp(string s, int i, string p,int j){
        if(j==p.size()){//p串结束，判断s串是否也结束，结束为真
            return i==s.size();
        }
        if(i==s.size()){//s串结束,判断p串的后续必须是a*b*c*等形式才有可能匹配
            if((p.size()-j)%2==1) return false;//剩余长度是奇数的话肯定不行
            for(;j+1<p.size();j=j+2){
                if(p[j+1]!='*') return false;
            }
            return true;
        }
        //接下来处理两个指针都没到尽头的情况，先判断是不是已经计算过，在备忘录里
        string temp=to_string(i)+","+to_string(j);
        if(memory.count(temp)) return memory[temp];
        //否则就要进行计算
        bool res=false;
        if(s[i]==p[j] || p[j]=='.'){//能够匹配成功的话
            if(j+1<p.size() && p[j+1]=='*'){//后一个是*,有可能需要匹配多次
                res=dp(s,i+1,p,j)||dp(s,i,p,j+2);
                //dp(s,i+1,p,j)，i前进1，j不前进，这是指匹配了一次以上
                //dp(s,i,p,j+2)，i不前进，j前进2，这是指匹配了0次，跳过当前字符和*
            }
            else res=dp(s,i+1,p,j+1);//下一个不是*,不需要考虑多次匹配的问题
        }
        else{//当前字符匹配失败
            if(j+1<p.size() && p[j+1]=='*'){//下一个字符是*的话，可以让p的当前字符重复0次
                res=dp(s,i,p,j+2);
            }
            else{
                return false;//救不了了，匹配失败
            }
        }
        memory[temp]=res;//保存结果
        return res;
    }
};
