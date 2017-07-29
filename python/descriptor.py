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
