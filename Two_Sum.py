#!/usr/bin/env  python

class Solution:

    # @return a tuple, (index1, index2)   Time Limited
    def twoSum(self, num, target):
        length=len(num)
        print length
        ll=[]
        for i in range(length):
            print i, num[i]
            ll.append({"key":num[i], "value":i})
            #ll[i]={"key":num[i], "value":i}

        def cmp(ll):
            return ll['key']
        
        ll=sorted(ll, key=cmp)

        i=0;
        j=length-1
        while i<j :
            if ll[i]['key'] + ll[j]['key'] < target :
                i+=1
            elif ll[i]['key'] + ll[j]['key'] > target :
                j-=1
            else :
                return (ll[i]['value']+1, ll[j]['value']+1)
        if(i == j):
            return None
""" Accepted

    def twoSum(self, num, target):
        tmp_num = {}
        for i in range(len(num)):
            if target - num[i] in tmp_num:
                # here do not need to deal with the condition i = target-i
                return (tmp_num[target-num[i]]+1, i+1)
            else:
                tmp_num[num[i]] = i
        return (-1, -1)
"""
	
if __name__ == "__main__":
	so=Solution()
	num=[2, 11, 7, 15]
	target=9
	tup=so.twoSum(num, target)
	print tup[0], tup[1]

		
	
