class Solution(object):
    def findMinDifference(self, A):
        def convert(time):
            return int(time[:2]) * 60 + int(time[3:])
        minutes = map(convert, A)
        minutes.sort()

        return min( (y - x) % (24 * 60) 
                    for x, y in zip(minutes, minutes[1:] + minutes[:1]) )
