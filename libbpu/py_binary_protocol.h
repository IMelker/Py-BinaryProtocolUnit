#include "binary_protocol.h"
#include <string.h>
#include <algorithm>

extern "C" {
    BinaryProtocolUnit* BinaryProtocolUnit_New() {
        return new BinaryProtocolUnit();
    }
    
    void BinaryProtocolUnit_Del(void *ptr) {
        BinaryProtocolUnit* u = reinterpret_cast<BinaryProtocolUnit *>(ptr);
        delete u;
    }
    
    size_t BinaryProtocolUnit_FieldsCount(void *ptr) {
        BinaryProtocolUnit* u = reinterpret_cast<BinaryProtocolUnit *>(ptr);
        return u->FieldsCount();
    }
    
    void BinaryProtocolUnit_Insert(void *ptr, const char* k, const char* v) {
        BinaryProtocolUnit* u = reinterpret_cast<BinaryProtocolUnit *>(ptr);
        u->Insert(std::string(k), std::string(v));
    }
    
    bool BinaryProtocolUnit_IsInserted(void *ptr, const char* k){
        BinaryProtocolUnit* u = reinterpret_cast<BinaryProtocolUnit *>(ptr);
        return u->IsInserted(std::string(k));
    }
    
    const char* BinaryProtocolUnit_Get(void *ptr, const char* k){
        BinaryProtocolUnit* u = reinterpret_cast<BinaryProtocolUnit *>(ptr);
        return u->Get(std::string(k)).c_str();
    }
    
    int BinaryProtocolUnit_Remove(void *ptr, const char* k){
        BinaryProtocolUnit* u = reinterpret_cast<BinaryProtocolUnit *>(ptr);
        return u->Remove(std::string(k));
    }
    
    void BinaryProtocolUnit_Clear(void *ptr){
        BinaryProtocolUnit* u = reinterpret_cast<BinaryProtocolUnit *>(ptr);
        u->Clear();
    }
    
    void BinaryProtocolUnit_FromBinary(void *ptr, const char* d, int size){
        BinaryProtocolUnit* u = reinterpret_cast<BinaryProtocolUnit *>(ptr);
        u->FromBinary(d, static_cast<size_t> (size));
    }
    
    size_t BinaryProtocolUnit_ToBinary(void *ptr, char* buf){
        BinaryProtocolUnit* u = reinterpret_cast<BinaryProtocolUnit *>(ptr);
        std::string str = u->ToBinary();
        copy_n(str.begin(), str.length(), buf);
        return str.length();
    }
}
