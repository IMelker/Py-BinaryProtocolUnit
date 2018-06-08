import ctypes
pybpu = ctypes.cdll.LoadLibrary('./libbpu.so')

class BinaryProtocolUnit(object):
    def __init__(self):       
        pybpu.BinaryProtocolUnit_FieldsCount.argtypes = (ctypes.c_void_p,)
        pybpu.BinaryProtocolUnit_FieldsCount.restype = ctypes.c_int
        
        pybpu.BinaryProtocolUnit_Insert.argtypes = (ctypes.c_void_p, ctypes.c_char_p, ctypes.c_char_p)
        pybpu.BinaryProtocolUnit_Insert.restype = ctypes.c_void_p
        
        pybpu.BinaryProtocolUnit_IsInserted.argtypes = (ctypes.c_void_p, ctypes.c_char_p)
        pybpu.BinaryProtocolUnit_IsInserted.restype = ctypes.c_bool
        
        pybpu.BinaryProtocolUnit_Get.argtypes = (ctypes.c_void_p, ctypes.c_char_p)
        pybpu.BinaryProtocolUnit_Get.restype = ctypes.c_char_p
        
        pybpu.BinaryProtocolUnit_Remove.argtypes = (ctypes.c_void_p, ctypes.c_char_p)
        pybpu.BinaryProtocolUnit_Remove.restype = ctypes.c_int
        
        pybpu.BinaryProtocolUnit_FromBinary.argtypes = (ctypes.c_void_p, ctypes.c_char_p, ctypes.c_int)
        pybpu.BinaryProtocolUnit_FromBinary.restype = ctypes.c_void_p
        
        pybpu.BinaryProtocolUnit_ToBinary.argtypes = (ctypes.c_void_p,)
        pybpu.BinaryProtocolUnit_ToBinary.restype = ctypes.c_char_p
        self.obj = pybpu.BinaryProtocolUnit_New()
    
    def __enter__(self):
        return self

    def __exit__(self, exc_type, exc_value, traceback):
        pybpu.BinaryProtocolUnit_Del(self.obj)
            
    def FieldsCount(self):
        return pybpu.BinaryProtocolUnit_FieldsCount(self.obj)
        
    def Insert(self, key, value):
        pybpu.BinaryProtocolUnit_Insert(self.obj, key, value)
        
    def IsInserted(self, key):
        return pybpu.BinaryProtocolUnit_IsInserted(self.obj, key)
        
    def Get(self, key):
        return pybpu.BinaryProtocolUnit_Get(self.obj, key)
        
    def Remove(self, key):
        return pybpu.BinaryProtocolUnit_Remove(self.obj, key)
        
    def FromBinary(self, data, size):
        pybpu.BinaryProtocolUnit_FromBinary(self.obj, data, size)
        
    def ToBinary(self):
        return pybpu.BinaryProtocolUnit_ToBinary(self.obj)
