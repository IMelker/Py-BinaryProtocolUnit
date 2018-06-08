#!/usr/bin/env python
# -*- coding: utf-8 -*-

from pybpu import BinaryProtocolUnit

one_key  = 'one_key'
one_value = 'one_value'
two_key = 'two_key'
two_value = 'two_value'

binary_string = ''
with BinaryProtocolUnit() as bpu:
    bpu.Insert(one_key, one_value)
    print(bpu.FieldsCount())
    print(bpu.Get(one_key))
    bpu.Insert(two_key, two_value)
    print(bpu.Get(two_key))
    print(bpu.FieldsCount())
    print(bpu.Remove(two_key))
    print(bpu.FieldsCount())
    print(bpu.Get(two_key))
    binary_string = bpu.ToBinary()
    print(binary_string)

with BinaryProtocolUnit() as load_bpu:
    load_bpu.FromBinary(binary_string)
    print(load_bpu.FieldsCount())
    print(load_bpu.Get(one_key))
