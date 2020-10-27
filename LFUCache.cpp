struct Node{
    int freq;
    int key;
    int val;
};
class LFUCache {
public:
    int capacity = 0;
    int minfreq = 1;
    unordered_map<int, list<Node>::iterator> keytoit;
    unordered_map<int, list<Node>> freqtolist;
    LFUCache(int capacity) {
        this->capacity = capacity;
        keytoit.clear();
        freqtolist.clear();
    }
    
    int get(int key) {
        if(keytoit.find(key)!=keytoit.end()){
            auto it = keytoit[key];
            int value  = it->val;
            int freq = it->freq;
            freqtolist[freq].erase(it);
            
            if(freqtolist[freq].empty() and freq==minfreq){
                minfreq++;
            }
            freqtolist[++freq].push_front({freq, key, value});
            keytoit[key] = freqtolist[freq].begin();
            return value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(!capacity){
            return;
        }
        int freq = 1;
        if(keytoit.find(key)!=keytoit.end()){
            auto it = keytoit[key];
            freq = it->freq;
            freqtolist[freq].erase(it);
            if(freqtolist[freq].empty() and freq==minfreq){
                minfreq++;
            }
            freq++;
        } else if(keytoit.size()==capacity){
            int deletionkey = freqtolist[minfreq].back().key;
            int deletefreq = freqtolist[minfreq].back().freq;
            keytoit.erase(deletionkey);
            freqtolist[deletefreq].pop_back();
            if(freqtolist[deletefreq].empty()){
                minfreq++;
            }
        }
        minfreq = min(minfreq, freq);
        freqtolist[freq].push_front({freq, key, value});
        keytoit[key] = freqtolist[freq].begin();
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
