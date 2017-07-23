"""

Subsets Total Accepted: 14658 Total Submissions: 53631 My Submissions
Given a set of distinct integers, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.

"""
import copy

class Solution:
    def subs(self, S, temp,  index, res):
        if(index == len(S)):
            res.append(copy.deepcopy(temp))
            print temp
            return
   
        Solution.subs(self, S, temp, index+1, res)
            
        temp.append(S[index])
        Solution.subs(self,  S, temp, index+1, res)
        temp.pop()

        
        
    # @param S, a list of integer
    # @return a list of lists of integer
    def subsets(self, S):
        res=[]
        temp=[]
        Solution.subs(self, S, temp, 0, res)
        return res

if __name__=="__main__":
    S=[1, 2, 3, 4]
    solution=Solution()
    res=solution.subsets(S)
    print res
