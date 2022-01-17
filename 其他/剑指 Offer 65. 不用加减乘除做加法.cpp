class Solution {
public:
    int add(int a, int b) {
        //a+b=(a&b)<<1+a^b;
        int c;
        while(b!=0){
            c=(unsigned int)(a&b)<<1;//保存进位
            a=a^b;//非进位和
            b=c;
        }
        return a;
    }
};
