class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        merged = []
        c1 = 0
        c2 = 0

        while c1 < m and c2 < n:
            if nums1[c1] <= nums2[c2]:
                merged.append(nums1[c1])
                c1 += 1
            else:
                merged.append(nums2[c2])
                c2 += 1
        
        while c1 < m:
            merged.append(nums1[c1])
            c1 += 1
        
        while c2 < n:
            merged.append(nums2[c2])
            c2 += 1

        for i in range(len(merged)):
            nums1[i] = merged[i]