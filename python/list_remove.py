# -*- coding: utf-8 -*-

a = [1, 2, 3, 4, 5]
for i in a:
	if i % 2 == 0:
		a.remove(i)
	print a, i

a = [1, 2, 3, 4, 5]
for i, d in enumerate(a):
	if d % 2 == 0:
		del a[i]
	print a, i, d


a = [1, 2, 3, 4, 5]
for i in range(len(a)):
	if a[i] == 4:
		del a[i]
	print a, i


###output 
# [1, 2, 3, 4, 5] 1
# [1, 3, 4, 5] 2
# [1, 3, 5] 4
# [1, 2, 3, 4, 5] 0 1
# [1, 3, 4, 5] 1 2
# [1, 3, 5] 2 4
# [1, 2, 3, 4, 5] 0
# [1, 2, 3, 4, 5] 1
# [1, 2, 3, 4, 5] 2
# [1, 2, 3, 5] 3
# Traceback (most recent call last):
#   File "G:\Python\CodeSlice\python\list_remove.py", line 16, in <module>
#     if a[i] == 4:
# IndexError: list index out of range