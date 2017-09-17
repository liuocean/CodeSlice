# -*- coding: utf-8 -*-

class Descriptor(object):

	def __init__(self, value = None):
		self.value = value

	def __get__(self, instance, owner):
		print 'Descriptor.__get__', instance, owner
		return self.value

	def __set__(self, instance, value):
		self.value = value


class A(object):
	d = Descriptor()


class NonDescriptor(object):

	def __init__(self, value = None):
		self.value = value

	def __get__(self, instance, owner):
		print 'Descriptor.__get__', instance, owner


class B(object):
	d = NonDescriptor()


class Descriptor1(object):
	def __init__(self, label):
		self.label = label

	def __get__(self, instance, owner):
		return getattr(instance, self.label)

	def __set__(self, instance, value):
		setattr(instance, self.label, value)

class C(object):
	a = Descriptor1('a')

	def __init__(self, val):
		self.a = val


class Descriptor2(object):
	def __init__(self, label):#label为给实例增加的实例属性名
		self.label = label

	def __get__(self, instance, owner):
		return instance.__dict__.get(self.label)  #获取与描述符同名的实例属性的值 

	def __set__(self, instance, value):
		#不能写instance.x = val这种形式, 对自身的循环调用！！！
		instance.__dict__[self.label] = value     #修改与描述符同名的实例属性的值  

class D(object):
	a = Descriptor2('a') #注意这个初始化值为要给实例增加的实例属性名，要和描述符对象同名。

	def __init__(self, val): 
		'''
		只有调用了__set__函数才会建立一个与描述符同名的实例属性，所以可以在__init__()函数中对描述符赋值。
		无此函数访问x也没trace，打印为空。
		'''
		self.a = val  


class WorksWithDictAndSlotsDescriptor(object):
# class WorksWithDictAndSlotsDescriptor: # 旧式类，不可用, e.a = <__main__.WorksWithDictAndSlotsDescriptor instance at 0x0000000002E25408>

	def __init__(self, attr_name):
		self.attr_name = attr_name

	def __get__(self, instance, owner):
		try:
			return instance.__dict__[self.attr_name]
		except AttributeError:
			return getattr(instance, self.attr_name)

	def __set__(self, instance, value):
		try:
			instance.__dict__[self.attr_name] = value
		except AttributeError:
			setattr(instance, self.attr_name, value)



class E(object):
	__slots__ = ('a',)
	a = WorksWithDictAndSlotsDescriptor('a')

	def __init__(self, val): 
		self.a = val 


	# >>> e = E(1)

	# Traceback (most recent call last):
	#   File "<pyshell#0>", line 1, in <module>
	#     e = E(1)
	#   File "G:\Python\CodeSlice\python\descriptor.py", line 97, in __init__
	#     self.a = val
	#   File "G:\Python\CodeSlice\python\descriptor.py", line 88, in __set__
	#     setattr(instance, self.attr_name, value)
	#   File "G:\Python\CodeSlice\python\descriptor.py", line 88, in __set__

	#   .
	#   setattr(instance, self.attr_name, value)
	#   RuntimeError: maximum recursion depth exceeded while calling a Python object

class E2(object):
	__slots__ = ('_a',)
	a = WorksWithDictAndSlotsDescriptor('_a')

	def __init__(self, val): 
		self.a = val 