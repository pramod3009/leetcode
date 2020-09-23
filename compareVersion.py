class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        version1 = version1.strip().split(".")
        version2 = version2.strip().split(".")
        v1 = [int(x) for x in version1]
        v2 = [int(x) for x in version2]
        n1 = len(v1)
        n2 = len(v2)
        if v1.count(0)==n1 and v2.count(0)==n2:
            return 0
        for i in range(0, min(n1, n2)):
            if v1[i] > v2[i]:
                return 1
            elif v2[i] > v1[i]:
                return -1
        for i in range(min(n1, n2), n1):
            if v1[i] > 0:
                return 1
        for i in range(min(n1,n2), n2):
            if v2[i] > 0:
                return -1
        return 0
