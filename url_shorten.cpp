class Solution {
public:
    string store = "0123456789acbdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    unordered_map<string, string> cache;
    string prefix  = "http://tinyurl.com/";
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string t  = prefix;
        for(int i = 0 ; i < 6; i++){
            t += store[rand() % (store.size() - 1)];
        }
        cache[t] = longUrl;
        return t;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return cache[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
