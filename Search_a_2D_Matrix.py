class Solution(object):
    def binarySearch(self, matrix, i , ncol, target):
        left = 0 
        right = ncol - 1
        while(left<=right):
            mid = int((left+right)/2)
            if matrix[i][mid] == target:
                return 1 
            elif matrix[i][mid]>target:
                right = mid - 1
            else:
                left = mid + 1
        return 0       
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        nrow = len(matrix)
        if not nrow:
            return 0
        ncol = len(matrix[0])
        if not ncol:
            return 0
        for i in range(0,nrow):
            if target>=matrix[i][0] and target<=matrix[i][ncol-1]:
                return self.binarySearch(matrix , i, ncol, target)