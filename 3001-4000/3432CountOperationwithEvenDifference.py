# class Solution:
    #def countPartitions(self, nums: List[int]) -> int:
        # Calculate the total sum of the array
    #    total_sum = sum(nums)
    #    n = len(nums)
        
        # If the total sum is even, all n-1 partitions have an even sum difference.
    #    if total_sum % 2 == 0:
    #        return n - 1
        # If the total sum is odd, no partition has an even sum difference.
    #    else:
    #        return 0