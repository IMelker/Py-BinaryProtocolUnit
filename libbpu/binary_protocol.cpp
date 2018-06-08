#include "binary_protocol.h"
#include "py_binary_protocol.h"
#include <iostream> //debug

BinaryProtocolUnit::BinaryProtocolUnit() {
    binary_unit_["test1"] = "test1";
    std::cout << binary_unit_["test1"] << "\n"; // ALL OK
    std::cout << "Init protocol file. \n";
    Insert("test2","test2");
    std::cout << Get("test2") << "\n"; //ALL OK
}

BinaryProtocolUnit::BinaryProtocolUnit(const char* data, size_t size) {
    FromBinary(data, size);
}

BinaryProtocolUnit::BinaryProtocolUnit(const std::string& data) {
    FromBinary(data.data(), data.size());
}

BinaryProtocolUnit::~BinaryProtocolUnit() {
    std::cout << "Delete protocol file. \n";
}

size_t BinaryProtocolUnit::FieldsCount() const {
    return binary_unit_.size();
}

void BinaryProtocolUnit::Insert(
        const std::string& key, const std::string& value) {
    std::cout << "Insert [" << key << " : " << value << "]. \n";
    binary_unit_[key] = value;      // SEGMENTATION FAULT
    std::cout << "Inserted [-----]. \n";
}

bool BinaryProtocolUnit::IsInserted(const std::string& key) const {
    return binary_unit_.find(key) != binary_unit_.end();
}

std::string BinaryProtocolUnit::Get(const std::string& key) const {
    std::map<std::string, std::string>::const_iterator
        it = binary_unit_.find(key);
    if (it != binary_unit_.end()) {
        return it->second;
    } else {
        return std::string();
    }
}

int BinaryProtocolUnit::Remove(const std::string& key) {
    return binary_unit_.erase(key);
}

void BinaryProtocolUnit::FromBinary(const char* data, size_t size) {
    const char* pointer = data;
    while (pointer < data + size) {
        std::string key = DecodeString(&pointer);
        std::string value = DecodeString(&pointer);
        Insert(key, value);
    }
}

std::string BinaryProtocolUnit::ToBinary() const {
    size_t size = binary_unit_.size() * 2 * sizeof(size_t);
    for (std::map<std::string, std::string>::const_iterator
            it = binary_unit_.begin(); it != binary_unit_.end(); ++it) {
        size += it->first.size() + it->second.size();
    }
    std::string data(size, 0);
    char* pointer = const_cast<char*>(data.data());
    for (std::map<std::string, std::string>::const_iterator
            it = binary_unit_.begin(); it != binary_unit_.end(); ++it) {
        EncodeString(it->first, &pointer);
        EncodeString(it->second, &pointer);
    }
    return data;
}

std::string BinaryProtocolUnit::DecodeString(const char** pointer) const {
    size_t length = *reinterpret_cast<const size_t*>(*pointer);
    *pointer += sizeof(size_t);
    std::string str(*pointer, *pointer + length);
    *pointer += length;
    return str;
}

void BinaryProtocolUnit::EncodeString(
        const std::string& str, char** pointer) const {
    *reinterpret_cast<size_t*>(*pointer) = str.size();
    *pointer += sizeof(size_t);
    std::copy(str.begin(), str.end(), *pointer);
    *pointer += str.size();
}
