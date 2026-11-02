class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:

        ans1 = version1.split('.')
        ans2 = version2.split('.')

        n = len(ans1)
        m = len(ans2)

        for i in range(max(n, m)):

            num1 = int(ans1[i]) if i < n else 0
            num2 = int(ans2[i]) if i < m else 0

            if num1 > num2:
                return 1

            elif num1 < num2:
                return -1

        return 0