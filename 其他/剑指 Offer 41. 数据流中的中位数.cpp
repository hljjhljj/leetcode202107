class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int,vector<int>,less<int>> maxint;//大顶堆，等于priority_queue<int>
    priority_queue<int,vector<int>,greater<int>> minint;//小顶堆
    //始终保证大顶堆size等于或比小顶堆size大1。
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(maxint.size()==minint.size()){
            minint.push(num);
            num=minint.top();
            minint.pop();
            maxint.push(num);
        }
        else{
            maxint.push(num);
            num=maxint.top();
            maxint.pop();
            minint.push(num);
        }
    }
    
    double findMedian() {
        if(maxint.size()==minint.size()){
            return (maxint.top()+minint.top())/2.0;
        }
        else return maxint.top();
    }
};
