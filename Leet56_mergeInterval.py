class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        sortedInterval = sorted(intervals, key=lambda i: i[0])

        output = []
        for interval in sortedInterval:
            if not output or (output[-1][1] < interval[0]):
                output.append(interval)
            else:
                output[-1][1] = max(interval[1], output[-1][1])

        return output