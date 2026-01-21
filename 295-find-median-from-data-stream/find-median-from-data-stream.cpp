class MedianFinder {
public:
    priority_queue<int> leftMaxHeap;
    priority_queue<int,vector<int>,greater<int>> rightMinHeap;
    MedianFinder() {
        
    }
    void BalanceHeaps(){
        if(leftMaxHeap.size()>rightMinHeap.size()+1){
            rightMinHeap.push(leftMaxHeap.top());
            leftMaxHeap.pop();
        }
        else if(rightMinHeap.size()>leftMaxHeap.size()){
            leftMaxHeap.push(rightMinHeap.top());
            rightMinHeap.pop();
        }
    }
    void addNum(int num) {
        if(leftMaxHeap.empty() || num > leftMaxHeap.top()){
            rightMinHeap.push(num);
        }
        else{
            leftMaxHeap.push(num);
        }

        BalanceHeaps();
    }
    
    double findMedian() {
        if(leftMaxHeap.size() == rightMinHeap.size()){
                return double((leftMaxHeap.top() + rightMinHeap.top()) / 2.0);
            }
            else{
                return double(leftMaxHeap.top());
            }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */