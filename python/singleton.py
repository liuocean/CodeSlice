# -*- coding: utf-8 -*-

class Singleton(object):
	_instance = None

	def __new__(cls, *args, **kwargs):
		if not cls._instance:
			cls._instance = super(Singleton, cls).__new__(cls, *args, **kwargs)
		return cls._instance

	def __init__(self, x):
		self.x = x

class MyClass(Singleton):
	pass


class Singleton1(type):

	# def __init__(self, name, bases, attrs):
	def __init__(self, *args, **kwargs):
		super(Singleton1, self).__init__(*args, **kwargs)
		self._instance = None

	def __call__(self, *args, **kwargs):
		if not self._instance:
			self._instance = super(Singleton1, self).__call__(*args, **kwargs)
		return self._instance

class MySingleton1(object):
	__metaclass__ = Singleton1

# class MySingleton1(metaclass = Singleton1)
# 	pass

class Singleton2(type):
	_instances = {}

	def __call__(self, *args, **kwargs):
		if self not in self._instances:
			self._instances[self] = super(Singleton2, self).__call__(*args, **kwargs)
		return self._instances[self]

class MySingleton2(object):
	__metaclass__ = Singleton2


from functools import wraps

def singleton(cls):
	_instances = {}

	@wraps(cls)
	def wrapper(*args, **kwargs):
		if cls not in _instances:
			_instances[cls] = cls(*args, **kwargs)
		return _instances[cls]

	return wrapper

@singleton
class Singleton3(object):
	pass


if __name__ == '__main__':
	pass