#ifndef __BINARY_PROTOCOL_H__
#define __BINARY_PROTOCOL_H__

#include <map>

class BinaryProtocolUnit {
public:
    BinaryProtocolUnit();
    BinaryProtocolUnit(const char* data, size_t size);
    BinaryProtocolUnit(const std::string& data);
    ~BinaryProtocolUnit();
    size_t FieldsCount() const;
    void Insert(const std::string& key, const std::string& value);
    bool IsInserted(const std::string& key) const;
    std::string Get(const std::string& key) const;
    int Remove(const std::string& key);
    void Clear();
    void FromBinary(const char* data, size_t size);
    std::string ToBinary() const;
private:
    std::string DecodeString(const char** pointer) const;
    void EncodeString(const std::string& str, char** pointer) const;
    std::map<std::string, std::string> binary_unit_;
};

#endif
