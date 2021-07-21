class FrontMiddleBackQueue {
public:
    vector<int> vec;
    FrontMiddleBackQueue() {
    }
    
    void pushFront(int val) {
        vec.insert(vec.begin(),val);
    }
    
    void pushMiddle(int val) {
        vec.insert(vec.begin()+vec.size()/2,val);
    }
    
    void pushBack(int val) {
        vec.push_back(val);
    }
    
    int popFront() {
        if(vec.size() == 0)
            return -1;
        int value = vec[0];
        vec.erase(vec.begin());
        return value;
    }
    
    int popMiddle() {
        if(vec.size() == 0)
            return -1;
        int value = vec[(vec.size()-1)/2];
        vec.erase(vec.begin()+(vec.size()-1)/2);
        return value;
    }
    int popBack() {
        if(vec.size() == 0)
            return -1;
        int value = vec[vec.size() -1];
        vec.pop_back();
        return value; 
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */