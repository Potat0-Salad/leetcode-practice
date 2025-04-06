class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        i = 0
        j = 0

        while(i < len(nums)):
            while(j < len(nums)):
                if nums[i] == nums[j] and i != j:
                    nums.pop(j)
                else:
                    j += 1
            j = 0
            i += 1

        return(len(nums)) 