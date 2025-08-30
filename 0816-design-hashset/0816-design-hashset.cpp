class MyHashSet {
    public:
    vector<int> data;
public:
    MyHashSet() {
        
    }
    
    void add(int key) {
        if(find(data.begin(),data.end(),key)==data.end()){
            data.push_back(key);
        }
        
    }
    
    void remove(int key) {
        auto i=find(data.begin(),data.end(),key);
        if(i!=data.end())data.erase(i);
        
    }
    
    bool contains(int key) {
        return find(data.begin(),data.end(),key)!=data.end();
        
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */