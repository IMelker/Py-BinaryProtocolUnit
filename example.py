#!/usr/bin/env python
# -*- coding: utf-8 -*-

from pybpu import BinaryProtocolUnit

one_key  = 'one_key'
one_value = 'one_value'
two_key = 'two_key'
two_value = 'two_value'

bpu = BinaryProtocolUnit()
bpu.Insert(one_key, one_value)
bpu.Insert(two_key, two_value)
print('Fields size: ' + str(bpu.FieldsCount()))
print(one_key + ' = ' + bpu.Get(one_key))
print(two_key + ' = ' + bpu.Get(two_key))
print('Removing ' + two_key + ': ' + str(bpu.Remove(two_key)))
print('Fields size: ' +  str(bpu.FieldsCount()))
binary_string = bpu.ToBinary()
print('To binary: ' + repr(binary_string))
bpu.Clear()
print('Clear all. Fields size: ' +  str(bpu.FieldsCount()))

load_bpu = BinaryProtocolUnit()
load_bpu.FromBinary(binary_string)
print(load_bpu.FieldsCount())
print(load_bpu.Get(one_key))
