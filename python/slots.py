# -*- coding: cp936 -*-
class A(object):
    __slots__ = ('v')

    
class B(object):
    __slots__ = ('v')

    v = 1
    

class C(object):
    __slots__ = ('v', '__weakref__')

    v = 1    

class descriptor(object):
    def __init__(self, label):#label为给实例增加的实例属性名
        self.label = label
    def __get__(self, instance, owner):
        #dict.get(k[,d]) -> D[k] if k in D, else d.  d defaults to None.
        return instance.__dict__.get(self.label)  #获取与描述符同名的实例属性的值 

    def __set__(self, instance, value):
        #注意这里,要这么写,不能写instance.x = val这种形式,这样会形成自身的循环调用
        instance.__dict__[self.label] = value     #修改与描述符同名的实例属性的值  

class Foo(list):
    x = descriptor('x') #注意这个初始化值为要给实例增加的实例属性名，要和描述符对象同名。
    y = descriptor('y')


class MyDescriptor(object):
    def __init__(self, name):
        self.name = name
    def __get__(self, instance, owner):
        return getattr(instance, self.name)
    def __set__(self, instance, value):
        setattr(instance, self.name, value)

class D(object):
    __slots__ = ['_a']
    a = MyDescriptor('_a')
    def __init__(self, val):
        self.a = val    
