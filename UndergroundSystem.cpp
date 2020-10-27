typedef pair<string, string> p;
class UndergroundSystem {
public:
    unordered_map<int, pair<int, string>> m1;
    unordered_map<string, unordered_map<string,pair<int,int>>> m2;
        
    UndergroundSystem() {
    }
    
    void checkIn(int id, string stationName, int t) {
        m1[id] = {t, stationName};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto it = m1[id];
        int starttime = it.first;
        string source = it.second;
        int sum = 0;
        int times = 0;
        if(m2.find(source) != m2.end() and m2[source].find(stationName) != m2[source].end()){
            sum = m2[source][stationName].first;
            times = m2[source][stationName].second;
        }
        sum = sum + t - starttime;
        times++;
        m2[source][stationName] = {sum, times};
        m1.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        if(m2.find(startStation) != m2.end() and m2[startStation].find(endStation)!=m2[startStation].end()){
            int sum = m2[startStation][endStation].first;
            int times = m2[startStation][endStation].second;
            return double(sum)/times;
        }
        return 0.0;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
