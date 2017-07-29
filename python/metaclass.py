# -*- coding: utf-8 -*-

Person = type('Person', (object,), {'name':'baby', 'age':20})
print type(Person())

class UpperMetaClass(type):

	def __new__(cls, name, bases, attrs):
		print '__new__', cls, name, bases, attrs
		# attrs['**'] = 'OO' # new attr
		attrs_tuple = ((attr, val) for attr, val in attrs.iteritems() if not attr.startswith('__'))
		upper_attrs = dict((attr.upper(), val) for attr, val in attrs_tuple) 
		# return type.__new__(cls, name, bases, attrs)
		return super(UpperMetaClass, cls).__new__(cls, name, bases, attrs)

class UpperClass(object):
	__metaclass__ = UpperMetaClass

upper = UpperClass()


def upper_func(name, bases, attrs):
	attrs_tuple = ((attr, val) for attr, val in attrs.iteritems() if not attr.startswith('__'))
	upper_attrs = dict((attr.upper(), val) for attr, val in attrs_tuple) 
	return type(name, bases, attrs)

class UpperClass1(object):
	__metaclass__ = upper_func


__metaclass__ = upper_func  #作用到模块中的所有类

class classA(list): 
	pass