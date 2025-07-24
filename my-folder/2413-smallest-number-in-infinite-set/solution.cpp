class SmallestInfiniteSet {
public:
    set<int> s;
    SmallestInfiniteSet() {
        for(int i = 1; i < 1001; ++i) this->s.insert(i);
    }
    
    int popSmallest() {
        if(this->s.size()){
            int popped = *(this->s.begin());
            this->s.erase(this->s.begin());
            return popped;
        }
        return -1;
    }
    
    void addBack(int num) {
        this->s.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
