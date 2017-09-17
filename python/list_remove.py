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


# a = [1, 2, 3, 4, 5]
# for i in range(len(a)):
# 	if a[i] == 4:
# 		del a[i]
# 	print a, i


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



class Fib(object):
    def __init__(self):
        self.a, self.b = 0, 1 # 初始化两个计数器a，b

    def __iter__(self):
        return self # 实例本身就是迭代对象，故返回自己

    def next(self):
    	return 2


# fib = Fib()
# print fib
# print 1 in fib


class A(object):

	def __init__(self):
		self._name = None

	@property
	def name(self):
		return self._name

	@name.setter
	def name(self, val):
		self._name = val

	@name.deleter
	def name(self):
		print 'deltter'


class C(object):

	def func(self):
		print 'func'

	@classmethod
	def cfunc(cls):
		print 'cfunc'

	@staticmethod
	def sfunc():
		print 'sfunc'

	

