class MyHashSet {
   private:
    vector<int> HashSet;

   public:
    MyHashSet() {}

    void add(int key) {
        if (HashSet.size() != 10000 && !contains(key)) {
            HashSet.push_back(key);
        }
    }

    void remove(int key) {
        for (int i = 0; i < HashSet.size(); i++) {
            if (HashSet[i] == key) {
                HashSet.erase(HashSet.begin() + i);
                return;
            }
        }
    }

    bool contains(int key) {
        int n = HashSet.size();
        for (int i = 0; i < n; i++) {
            if (HashSet[i] == key) return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */