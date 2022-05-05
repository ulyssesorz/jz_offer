class MedianFinder {
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(max_heap.size() == min_heap.size()){ //小根堆+1
            max_heap.push(num);
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        else{   //大根堆+1
            min_heap.push(num);
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }
    
    double findMedian() {
        if(max_heap.size() == min_heap.size())
            return (min_heap.top() + max_heap.top()) / 2.0;
        else
            return min_heap.top();
    }
private:
    priority_queue<int, vector<int>, less<int>> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
};