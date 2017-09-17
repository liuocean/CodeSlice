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
    def __init__(self, label):#labelΪ��ʵ�����ӵ�ʵ��������
        self.label = label
    def __get__(self, instance, owner):
        #dict.get(k[,d]) -> D[k] if k in D, else d.  d defaults to None.
        return instance.__dict__.get(self.label)  #��ȡ��������ͬ����ʵ�����Ե�ֵ 

    def __set__(self, instance, value):
        #ע������,Ҫ��ôд,����дinstance.x = val������ʽ,�������γ������ѭ������
        instance.__dict__[self.label] = value     #�޸���������ͬ����ʵ�����Ե�ֵ  

class Foo(list):
    x = descriptor('x') #ע�������ʼ��ֵΪҪ��ʵ�����ӵ�ʵ����������Ҫ������������ͬ����
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
