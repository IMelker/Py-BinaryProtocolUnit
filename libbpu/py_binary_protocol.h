#include "binary_protocol.h"
#include <string>

extern "C" {
    BinaryProtocolUnit* BinaryProtocolUnit_New() {
        return new BinaryProtocolUnit();
    }
    
    void BinaryProtocolUnit_Del(BinaryProtocolUnit* u) {
        delete u;
    }
    
    size_t BinaryProtocolUnit_FieldsCount(BinaryProtocolUnit* u){
        return u->FieldsCount();
    }
    
    void BinaryProtocolUnit_Insert(BinaryProtocolUnit* u, const char* k, const char* v) {
        u->Insert(std::string(k), std::string(v));
    }
    
    bool BinaryProtocolUnit_IsInserted(BinaryProtocolUnit* u, const char* k){
        return u->IsInserted(std::string(k));
    }
    
    const char* BinaryProtocolUnit_Get(BinaryProtocolUnit* u, const char* k){
        return u->Get(std::string(k)).c_str();
    }
    
    int BinaryProtocolUnit_Remove(BinaryProtocolUnit* u, const char* k){
        return u->Remove(std::string(k));
    }
    
    void BinaryProtocolUnit_FromBinary(BinaryProtocolUnit* u, const char* d, size_t s){
        u->FromBinary(d, s);
    }
    
    const char* BinaryProtocolUnit_ToBinary(BinaryProtocolUnit* u){
        return u->ToBinary().c_str(); 
    }
}
