class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if len(intervals) in [0,1]:
            return intervals
        intervals.sort(key=lambda x:x[0])
        start = intervals[0][0]
        end = intervals[0][1]
        result = []
        i = 1
        while i<len(intervals):
            if end>=intervals[i][0]:
                start = min(start, intervals[i][0])
                end = max(end, intervals[i][1])
            else:
                result.append([start,end])
                start = intervals[i][0]
                end = intervals[i][1]
            i+=1
        result.append([start,end])
        return result
        