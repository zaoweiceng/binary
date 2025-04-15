#ifndef BiNARY_H
#define BiNARY_H
#include <vector>
#include <iostream>
#include <string>
#include <memory>

enum StringType{
    BINARY, // 二进制
    ASCII,  // ASCII
    BASE64  // Base64
};
/*
* 二进制数据类
* 用于二进制数据的读写操作
* @author: zaoweiceng
* @data: 2025-03-18
*/
class Binary{
    friend Binary& operator<<(Binary&& dest, Binary&& src); 
    friend Binary& operator<<(Binary& dest, Binary& src); 
    public:
    //----------- 构造函数和析构函数 ------------
        // 构造函数，无参数
        explicit Binary();
        // 构造函数，参数为size_t类型
        explicit Binary(const size_t size);
        // 构造函数，参数为std::string类型
        Binary(const std::string& data, StringType type = StringType::BINARY);
        // 构造函数，参数为std::vector<std::byte>类型
        Binary(const std::vector<std::byte>& data);
        // 构造函数，参数为std::shared_ptr<std::vector<std::byte>>类型
        Binary(std::shared_ptr<std::vector<std::byte>> data);
        // 构造函数，参数为std::byte*类型和size_t类型
        Binary(const std::byte* data, const size_t size);
        // 构造函数，参数为Binary类型
        Binary(const Binary& other);
        // 赋值运算符，参数为Binary类型
        Binary& operator=(const Binary& other);
        // 移动构造函数，参数为Binary类型
        Binary(Binary&& other) = default;
        // 移动赋值运算符，参数为Binary类型
        Binary& operator=(Binary&& other) ;
        Binary& operator+=(Binary&& other);
        // 析构函数
        ~Binary() = default;
    // ----------- 运算符重载 ------------
        // 等于运算符，参数为Binary类型
        bool operator==(const Binary& other) const;
        // 不等于运算符，参数为Binary类型
        bool operator!=(const Binary& other) const;
        // 下标运算符，参数为size_t类型
        std::byte& operator[](const size_t index) const;
        // 加法运算符，参数为Binary类型
        Binary operator+(const Binary& other);
        // TODO: &运算符
        Binary operator^(const Binary& other);
    
    // ----------- 成员函数 ------------
    
    // ------------ 读数据 -------------
        // 读取数据，参数为size_t类型
        virtual std::vector<std::byte> read(const size_t index, const size_t size) const;
        // 读取数据，参数为size_t类型
        virtual std::vector<std::byte> read(const size_t index) const;
        // 读取数据，无参数
        virtual std::vector<std::byte> read() const;
        // 获取数据，参数为size_t类型
        virtual std::byte get(const size_t index) const;
        
    // ------------ 写数据 -------------
        // 写入数据，参数为size_t类型和std::byte类型
        virtual void set(const size_t index, const std::byte data);
        // 写入数据，参数为size_t类型和std::byte*类型
        virtual bool write(const size_t index, const size_t size, const std::byte* data);
        // 写入数据，参数为size_t类型和std::vector<std::byte>类型
        virtual bool write(const size_t index, const size_t size, std::vector<std::byte>& data);
        // 写入数据，参数为size_t类型和std::vector<std::byte>类型
        virtual bool write(const size_t index, const std::vector<std::byte>& data);
        // 写入数据，参数为std::byte*类型
        virtual bool write(const std::byte* data, size_t size);
        // 写入数据，参数为std::vector<std::byte>类型
        virtual bool write(const std::vector<std::byte>& data);
    // ------------ 追加写 -------------
        // 追加数据，参数为size_t类型和std::byte*类型
        virtual Binary& append(const size_t size, const std::byte* data);
        // 追加数据，参数为std::vector<std::byte>类型
        virtual Binary& append(const std::vector<std::byte>& data);

    // ------------ 其他操作 -------------
        // 清空数据
        virtual Binary& clear();
        // 获取数据大小
        virtual size_t size() const;
        // 调整数据大小，参数为size_t类型
        virtual Binary& resize(const size_t size);
        // 将数据转换为字符串，参数为size_t类型
        virtual std::string to_hex_string(const size_t index, const size_t size) const;
        // 将数据转换为字符串，无参数
        virtual std::string to_hex_string() const;
        //将数据转换为Ascll字符串，参数为size_t类型
        virtual std::string to_ascll_string(const size_t index, const size_t size) const;
        // 将数据转换为Ascll字符串，无参数
        virtual std::string to_ascll_string() const;
        // 将数据转换为Base64字符串，无参数
        virtual std::string to_base64_string() const;
        // 判断数据是否为空
        virtual bool empty() const;
        // 判断数据指针是否为空
        virtual bool is_null() const;

    // ----------- 静态函数 ------------
        // 将std::byte*类型的数据转换为字符串
        const static std::string BINARY_TO_STRING(const std::vector<std::byte>& data, const size_t size);
        // 将字符串转换为std::vector<std::byte>类型的数据
        const static std::vector<std::byte> STRING_TO_BINARY(const std::string& data);
        // 将std::byte*类型的数据转换为Ascll字符串
        const static std::string BINARY_TO_ASCll(const std::vector<std::byte>& data, const size_t size);
        // 将Ascll字符串转换为std::vector<std::byte>类型的数据
        const static std::vector<std::byte> ASCll_TO_BINARY(const std::string& data);
        // 将std::vector<std::byte>类型的数据转换为Base64字符串
        const static std::string BINARY_TO_BASE64(const std::vector<std::byte>& data);
        // 将Base64字符串转换为std::vector<std::byte>类型的数据
        const static std::vector<std::byte> BASE64_TO_BINARY(const std::string& data);
        // 将多个Binary对象连接起来
        const static Binary contact(std::initializer_list<Binary>&& args);
    
    private:
    // ----------- 成员变量 ------------
        // 二进制数据数组
        std::shared_ptr<std::vector<std::byte>>  binary_array;
};

// 重载<<运算符
// 要用 operator<< 进行合并，必须定义为非成员函数，否则会因为隐式 this 参数导致编译错误。
Binary& operator<<(Binary&& dest, Binary&& src);
// 重载<<运算符
// 要用 operator<< 进行合并，必须定义为非成员函数，否则会因为隐式 this 参数导致编译错误。
Binary& operator<<(Binary& dest, Binary& src);
#endif

#include "config.h"
#include "node/binary.h"
#include <iostream>
#include <string>
#include <cstddef>
#include <sstream>
#include <vector>
#include <iomanip>
#include <memory>
#include <array>
#include <utility>
#include <algorithm>
#include <iterator>
#include "util/log.h"

using BwtFS::Util::Logger;

Binary::Binary(){
    this->binary_array = std::make_shared<std::vector<std::byte>>(0); 
}

Binary::Binary(const std::string& data, StringType type){
    if(type == StringType::BINARY){
        this->binary_array = std::make_shared<std::vector<std::byte>>(STRING_TO_BINARY(data));
    }else if (type == StringType::ASCII){
        this->binary_array = std::make_shared<std::vector<std::byte>>(ASCll_TO_BINARY(data));
    }else if (type == StringType::BASE64){
        this->binary_array = std::make_shared<std::vector<std::byte>>(BASE64_TO_BINARY(data));
    }
}

Binary::Binary(const std::vector<std::byte>& data){
    this->binary_array = std::make_shared<std::vector<std::byte>>(data);
}

Binary::Binary(std::shared_ptr<std::vector<std::byte>> data){
    this->binary_array = data;
}

Binary::Binary(const std::byte* data, const size_t size){
    this->binary_array = std::make_shared<std::vector<std::byte>>(data, data + size);
}
Binary::Binary(const Binary& other){
    if (other.binary_array == nullptr){
        LOG_ERROR << "constructor: Other Binary array is null";
        throw std::runtime_error(std::string("constructor: Other Binary array is null") + __FILE__ + ":" + std::to_string(__LINE__));
    }
    this->binary_array = other.binary_array;
}

Binary& Binary::operator=(const Binary& other){
    if (this == &other)
        return *this;
    if (other.binary_array == nullptr){
        LOG_ERROR << "operator=: Other Binary array is null";
        throw std::runtime_error(std::string("operator=: Other Binary array is null") + __FILE__ + ":" + std::to_string(__LINE__));
    }
    this->binary_array = other.binary_array; 
    return *this;
}

Binary::Binary(const size_t size){
    this->binary_array = std::make_shared<std::vector<std::byte>>(size);
}

Binary& Binary::operator=(Binary&& other){
    if (this != &other){
        if(other.binary_array == nullptr){
            LOG_ERROR << "operator=: Other Binary array is null";
            throw std::runtime_error(std::string("operator=: Other Binary array is null") + __FILE__ + ":" + std::to_string(__LINE__));
        }
        this->binary_array = other.binary_array;
        other.binary_array = nullptr;
    }
    return *this;
}

Binary& Binary::operator+=(Binary&& other){
    if (this != &other){
        if(other.binary_array == nullptr){
            LOG_ERROR << "operator+=: Other Binary array is null";
            throw std::runtime_error(std::string("operator+=: Other Binary array is null") + __FILE__ + ":" + std::to_string(__LINE__));
        }
        this->binary_array->insert(this->binary_array->end(), other.binary_array->begin(), other.binary_array->end());
        other.binary_array = nullptr;
    }
    return *this;
}

// std::make_move_iterator 是一种高效的方式，可以移动大型对象而不会产生额外的内存拷贝开销。
Binary &operator<<(Binary &&dest, Binary &&src){
    if (dest.binary_array == nullptr || src.binary_array == nullptr){
        LOG_ERROR << "operator<<: Binary array is null";
        throw std::runtime_error(std::string("operator<<: Binary array is null") + __FILE__ + ":" + std::to_string(__LINE__));
    }
    dest.binary_array->insert(dest.binary_array->end(), std::make_move_iterator(src.binary_array->begin()), std::make_move_iterator(src.binary_array->end()));
    return dest;
}

Binary &operator<<(Binary &dest, Binary &src){
    if (dest.binary_array == nullptr || src.binary_array == nullptr){
        LOG_ERROR << "operator<<: Binary array is null";
        throw std::runtime_error(std::string("operator<<: Binary array is null") + __FILE__ + ":" + std::to_string(__LINE__));
    }
    dest.binary_array->insert(dest.binary_array->end(), std::make_move_iterator(src.binary_array->begin()), std::make_move_iterator(src.binary_array->end()));
    return dest;
}

std::byte& Binary::operator[](const size_t index) const{
    if (this->binary_array == nullptr){
        LOG_ERROR << "operator[]: Binary array is null";
        throw std::runtime_error(std::string("operator[]: Binary array is null") + __FILE__ + ":" + std::to_string(__LINE__));
    }
    if (index >= this->binary_array->size()){
        LOG_ERROR << "operator[]: Index out of range";
        throw std::runtime_error(std::string("operator[]: Index out of range") + __FILE__ + ":" + std::to_string(__LINE__));
    }
    return this->binary_array->at(index);
}

Binary Binary::operator+(const Binary& other){
    if (other.binary_array == nullptr){
        LOG_ERROR << "operator+: Other Binary array is null";
        throw std::runtime_error(std::string("operator+: Other Binary array is null") + __FILE__ + ":" + std::to_string(__LINE__));
    }
    if (this->binary_array == nullptr){
        LOG_ERROR << "operator+: Binary array is null";
        throw std::runtime_error(std::string("operator+: Binary array is null") + __FILE__ + ":" + std::to_string(__LINE__));
    }
    std::shared_ptr<std::vector<std::byte>> new_array = std::make_shared<std::vector<std::byte>>(this->binary_array->size() + other.binary_array->size());
    std::copy(this->binary_array->begin(), this->binary_array->end(), new_array->begin());
    std::copy(other.binary_array->begin(), other.binary_array->end(), new_array->begin() + this->binary_array->size());
    return Binary(new_array->data(), new_array->size());
}

bool Binary::operator==(const Binary& other) const{
    if (this->binary_array == nullptr || other.binary_array == nullptr)
        return false;
    return this->to_hex_string() == other.to_hex_string();
}

bool Binary::operator!=(const Binary& other) const{
    if (this->binary_array == nullptr || other.binary_array == nullptr)
        return true;
    return this->to_hex_string() != other.to_hex_string();
}

std::vector<std::byte> xorVectors(const std::shared_ptr<std::vector<std::byte>>& v1, const std::shared_ptr<std::vector<std::byte>>& v2){
    if (v1->size() < v2->size()) {
        return xorVectors(v2, v1);
    }
    std::vector<std::byte> result;
    int j = 0;
    for (size_t i = 0; i < v1->size(); i++, j++) {
        if (j == v2->size()) {
            j = 0;
        }
        result.push_back(v1->at(i) ^ v2->at(j));
    }
    return result;
}
Binary Binary::operator^(const Binary& other){
    if (this->binary_array == nullptr) {
        LOG_ERROR << "operator^: Binary array is null";
        throw std::runtime_error(std::string("operator^: Binary array is null") + __FILE__ + ":" + std::to_string(__LINE__));
    }
    if (other.binary_array == nullptr) {
        LOG_ERROR << "operator^: Other Binary array is null";
        throw std::runtime_error(std::string("operator^: Other Binary array is null") + __FILE__ + ":" + std::to_string(__LINE__));
    }
    return xorVectors(this->binary_array, other.binary_array);
}

std::vector<std::byte> Binary::read(const size_t index, const size_t size) const{
    if (this->binary_array == nullptr){
        LOG_ERROR << "Binary::read: Binary array is null";
        throw std::runtime_error(std::string("Binary::read: Binary array is null") + __FILE__ + ":" + std::to_string(__LINE__));
    }
    size_t read_size = size;
    if (index + size > this->binary_array->size())
        read_size = this->binary_array->size() - index;
    if (read_size <= 0)
        return {};
    return std::vector<std::byte>(this->binary_array->begin() + index, this->binary_array->begin() + index + read_size);
}

std::vector<std::byte> Binary::read(const size_t index) const{
    if (this->binary_array == nullptr){
        LOG_ERROR << "Binary::read: Binary array is null";
        throw std::runtime_error(std::string("Binary::read: Binary array is null") + __FILE__ + ":" + std::to_string(__LINE__));
    }
    return read(index, this->binary_array->size() - index);
}

std::vector<std::byte> Binary::read() const{
    if (this->binary_array == nullptr){
        LOG_ERROR << "Binary::read: Binary array is null";
        throw std::runtime_error(std::string("Binary::read: Binary array is null") + __FILE__ + ":" + std::to_string(__LINE__));
    }
    return read(0, this->binary_array->size());
}

std::byte Binary::get(const size_t index) const{
    if (this->binary_array == nullptr){
        LOG_ERROR << "Binary::get: Binary array is null";
        throw std::runtime_error(std::string("Binary::get: Binary array is null") + __FILE__ + ":" + std::to_string(__LINE__));
    }
    if (index >= this->binary_array->size()){
        LOG_ERROR << "Binary::get: Index out of range";
        throw std::runtime_error(std::string("Binary::get: Index out of range") + __FILE__ + ":" + std::to_string(__LINE__));
    }
    return this->binary_array->at(index);
}

void Binary::set(const size_t index, const std::byte data){
    if (this->binary_array == nullptr){
        LOG_ERROR << "Binary::set: Binary array is null";
        throw std::runtime_error(std::string("Binary::set: Binary array is null") + __FILE__ + ":" + std::to_string(__LINE__));
    }
    if (index >= this->binary_array->size()){
        LOG_ERROR << "Binary::set: Index out of range";
        throw std::runtime_error(std::string("Binary::set: Index out of range") + __FILE__ + ":" + std::to_string(__LINE__));
    }
    if (index < 0){
        LOG_ERROR << "Binary::set: Index out of range";
        throw std::runtime_error(std::string("Binary::set: Index out of range") + __FILE__ + ":" + std::to_string(__LINE__));
    }
    this->binary_array->at(index) = data;
}

bool Binary::write(const size_t index, const size_t size, const std::byte* data){
    if (this->binary_array == nullptr){
        LOG_ERROR << "Binary::write: Binary array is null";
        throw std::runtime_error(std::string("Binary::write: Binary array is null") + __FILE__ + ":" + std::to_string(__LINE__));
    }
    if (index + size > this->binary_array->size() || index < 0 || size < 0)
        return false;
    std::copy(data, data + size, this->binary_array->begin() + index);
    return true;
}

bool Binary::write(const size_t index, const size_t size, std::vector<std::byte>& data){
    return write(index, size, data.data());
}

bool Binary::write(const size_t index, const std::vector<std::byte>& data){
    if (this->binary_array == nullptr){
        LOG_ERROR << "Binary::write: Binary array is null";
        throw std::runtime_error(std::string("Binary::write: Binary array is null") + __FILE__ + ":" + std::to_string(__LINE__));
    }
    return write(index, data.size(), data.data());
}

bool Binary::write(const std::byte* data, const size_t size){
    if (this->binary_array == nullptr){
        LOG_ERROR << "Binary::write: Binary array is null";
        throw std::runtime_error(std::string("Binary::write: Binary array is null") + __FILE__ + ":" + std::to_string(__LINE__));
    }
    return write(0, size, data);
}

bool Binary::write(const std::vector<std::byte>& data){
    if (this->binary_array == nullptr){
        LOG_ERROR << "Binary::write: Binary array is null";
        throw std::runtime_error(std::string("Binary::write: Binary array is null") + __FILE__ + ":" + std::to_string(__LINE__));
    }
    return write(0, data.size(), data.data());
}

Binary& Binary::append(const size_t size, const std::byte* data){
    if (this->binary_array == nullptr){
        LOG_ERROR << "Binary::append: Binary array is null";
        throw std::runtime_error(std::string("Binary::append: Binary array is null") + __FILE__ + ":" + std::to_string(__LINE__));
    }
    this->binary_array->insert(this->binary_array->end(), data, data + size);
    return *this;
}

Binary& Binary::append(const std::vector<std::byte>& data){
    if (this->binary_array == nullptr){
        LOG_ERROR << "Binary::append: Binary array is null";
        throw std::runtime_error(std::string("Binary::append: Binary array is null") + __FILE__ + ":" + std::to_string(__LINE__));
    }
    this->binary_array->insert(this->binary_array->end(), data.begin(), data.end());
    return *this;
}

Binary& Binary::clear(){
    if (this->binary_array == nullptr){
        LOG_WARNING << "Binary::clear: Binary array is null";
    }
    this->binary_array->clear();
    return *this;
}

size_t Binary::size() const{
    if (this->binary_array == nullptr){
        LOG_WARNING << "Binary::size: Binary array is null";
        return 0;
    }
    return this->binary_array->size();
}

std::string byteToHex(std::byte b) {
    std::stringstream ss;
    ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(b);
    return ss.str();
}

std::string byteArrayToHexString(const std::vector<std::byte>& data, size_t size) {
    std::string hexString;
    for (size_t i = 0; i < size; i++) {
        hexString += byteToHex(data[i]);
    }
    return hexString;
}

std::byte hexCharToByte(char c) {
    if (c >= '0' && c <= '9') return static_cast<std::byte>(c - '0');
    if (c >= 'a' && c <= 'f') return static_cast<std::byte>(c - 'a' + 10);
    if (c >= 'A' && c <= 'F') return static_cast<std::byte>(c - 'A' + 10);
    return static_cast<std::byte>(0);
}

std::vector<std::byte> hexStringToByteArray(const std::string& hexString) {
    if (hexString.length() % 2 != 0) {
        return {}; // 返回空数组，因为十六进制字符串长度必须是偶数
    }

    std::vector<std::byte> byteArray;
    for (size_t i = 0; i < hexString.length(); i += 2) {
        std::byte high = hexCharToByte(hexString[i]);
        std::byte low = hexCharToByte(hexString[i + 1]);
        byteArray.push_back(static_cast<std::byte>(static_cast<unsigned char>(high) << 4 | static_cast<unsigned char>(low)));
    }
    return byteArray;
}

Binary& Binary::resize(const size_t size){
    if (this->binary_array == nullptr){
        this->binary_array = std::make_shared<std::vector<std::byte>>(size);
        return *this;
    }
    if (size <= this->size())
        return *this;
    this->binary_array->resize(size);
    return *this;
}

const std::string Binary::BINARY_TO_STRING(const std::vector<std::byte>& data, const size_t size){
    return byteArrayToHexString(data, size);
}
const std::vector<std::byte> Binary::STRING_TO_BINARY(const std::string& data){
    return hexStringToByteArray(data);
}

std::string Binary::to_hex_string(const size_t index, const size_t size) const{
    if (this->binary_array == nullptr){
        LOG_ERROR << "Binary::to_string: Binary array is null";
        throw std::runtime_error(std::string("Binary::to_string: Binary array is null") + __FILE__ + ":" + std::to_string(__LINE__));
    }
    if (index + size > this->binary_array->size())
        return BINARY_TO_STRING(*this->binary_array, this->binary_array->size());
    if (index < 0 || size < 0)
        return BINARY_TO_STRING(*this->binary_array, this->binary_array->size());
    return BINARY_TO_STRING(*this->binary_array, size);
}

std::string Binary::to_hex_string() const{
    if (this->binary_array == nullptr){
        LOG_ERROR << "Binary::to_string: Binary array is null";
        throw std::runtime_error(std::string("Binary::to_string: Binary array is null") + __FILE__ + ":" + std::to_string(__LINE__));
    }
    if (this->binary_array->size() == 0)
        return "";
    return BINARY_TO_STRING(*this->binary_array, this->binary_array->size());
}

const std::string Binary::BINARY_TO_ASCll(const std::vector<std::byte>& data, const size_t size){
    std::string str;
    for (size_t i = 0; i < size; i++){
        str += static_cast<char>(data[i]);
    }
    return str;
}

const std::vector<std::byte> Binary::ASCll_TO_BINARY(const std::string& data){
    std::vector<std::byte> binary;
    for (size_t i = 0; i < data.size(); i++){
        binary.push_back(static_cast<std::byte>(data[i]));
    }
    return binary;
}

std::string Binary::to_ascll_string(const size_t index, const size_t size) const{
    if (this->binary_array == nullptr){
        LOG_ERROR << "Binary::to_ascll_string: Binary array is null";
        throw std::runtime_error(std::string("Binary::to_ascll_string: Binary array is null")  + __FILE__ + ":" + std::to_string(__LINE__));
    }
    if (index + size > this->binary_array->size())
        return BINARY_TO_ASCll(*this->binary_array, this->binary_array->size());
    return BINARY_TO_ASCll(*this->binary_array, size);
}

std::string Binary::to_ascll_string() const{
    if (this->binary_array == nullptr){
        LOG_ERROR << "Binary::to_ascll_string: Binary array is null";
        throw std::runtime_error(std::string("Binary::to_ascll_string: Binary array is null") + __FILE__ + ":" + std::to_string(__LINE__));
    }
    if (this->binary_array->size() == 0)
        return "";
    return BINARY_TO_ASCll(*this->binary_array, this->binary_array->size());
}

std::string base64_encode(const std::vector<std::byte>& input) {
    static constexpr char base64_chars[] = 
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "0123456789+/";

    const unsigned char* data = reinterpret_cast<const unsigned char*>(input.data());
    size_t input_len = input.size();
    std::string output;
    output.reserve(4 * ((input_len + 2) / 3)); // 预分配空间
    for (size_t i = 0; i < input_len; i += 3) {
        unsigned char a = data[i];
        unsigned char b = (i + 1 < input_len) ? data[i + 1] : 0;
        unsigned char c = (i + 2 < input_len) ? data[i + 2] : 0;

        unsigned char group1 = (a >> 2) & 0x3F;
        unsigned char group2 = ((a & 0x03) << 4) | ((b >> 4) & 0x0F);
        unsigned char group3 = ((b & 0x0F) << 2) | ((c >> 6) & 0x03);
        unsigned char group4 = c & 0x3F;

        output.push_back(base64_chars[group1]);
        output.push_back(base64_chars[group2]);
        output.push_back(base64_chars[group3]);
        output.push_back(base64_chars[group4]);
    }
    // 处理填充
    size_t mod = input_len % 3;
    if (mod == 1) {
        // 替换最后两个字符为 '=='
        output[output.size() - 2] = '=';
        output[output.size() - 1] = '=';
    } else if (mod == 2) {
        // 替换最后一个字符为 '='
        output[output.size() - 1] = '=';
    }
    return output;
}

std::vector<std::byte> base64_to_bytes(const std::string& input) {
    const std::string base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    
    // 创建解码表（字符到6位值）
    std::array<int, 256> decode_table{};
    for (auto& elem : decode_table) elem = -1;
    for (int i = 0; i < 64; ++i) {
        decode_table[static_cast<unsigned char>(base64_chars[i])] = i;
    }

    const size_t len = input.size();
    if (len % 4 != 0) {
        LOG_ERROR << "base64_to_bytes: Base64 string length must be a multiple of 4";
        throw std::invalid_argument(std::string("base64_to_bytes: Base64 string length must be a multiple of 4") + __FILE__ + ":" + std::to_string(__LINE__));
    }

    // 计算填充符数量（0/1/2）
    size_t padding = 0;
    if (len > 0 && input[len - 1] == '=') padding++;
    if (len > 1 && input[len - 2] == '=') padding++;

    std::vector<std::byte> result;
    result.reserve((len / 4) * 3 - padding); // 预分配内存优化

    for (size_t i = 0; i < len; i += 4) {
        // 提取四字符组中的6位值
        uint32_t sextet_a = decode_table[static_cast<unsigned char>(input[i])];
        uint32_t sextet_b = decode_table[static_cast<unsigned char>(input[i+1])];
        uint32_t sextet_c = 0, sextet_d = 0;

        // 处理第三个字符（允许为=）
        if (input[i+2] != '=') {
            sextet_c = decode_table[static_cast<unsigned char>(input[i+2])];
            if (sextet_c == -1){
                LOG_ERROR << "base64_to_bytes: Invalid character in Base64 string";
                throw std::invalid_argument(std::string("base64_to_bytes: Invalid character in Base64 string") + __FILE__ + ":" + std::to_string(__LINE__));
            }
        }

        // 处理第四个字符（允许为=）
        if (input[i+3] != '=') {
            sextet_d = decode_table[static_cast<unsigned char>(input[i+3])];
            if (sextet_d == -1){
                LOG_ERROR << "base64_to_bytes: Invalid character in Base64 string";
                throw std::invalid_argument(std::string("base64_to_bytes: Invalid character in Base64 string") + __FILE__ + ":" + std::to_string(__LINE__));
            }
        }

        if (sextet_a == -1 || sextet_b == -1) {
            LOG_ERROR << "base64_to_bytes: Invalid character in Base64 string";
            throw std::invalid_argument(std::string("base64_to_bytes: Invalid character in Base64 string") + __FILE__ + ":" + std::to_string(__LINE__));
        }

        // 组合四字符为24位整数
        const uint32_t triplet = 
            (sextet_a << 18) | (sextet_b << 12) | 
            (sextet_c << 6)  | sextet_d;

        // 提取三个字节
        result.push_back(static_cast<std::byte>((triplet >> 16) & 0xFF));
        if (input[i+2] != '=') {  // 非填充情况
            result.push_back(static_cast<std::byte>((triplet >> 8) & 0xFF));
            if (input[i+3] != '=') {
                result.push_back(static_cast<std::byte>(triplet & 0xFF));
            }
        } else {
            // 第三个字符是=，第四个必须也是=
            if (input[i+3] != '=') {
                LOG_ERROR << "base64_to_bytes: Invalid padding with '='";
                throw std::invalid_argument(std::string("base64_to_bytes: Invalid padding with '='") + __FILE__ + ":" + std::to_string(__LINE__));
            }
        }
    }
    return result;
}



const std::string Binary::BINARY_TO_BASE64(const std::vector<std::byte>& data){
    return base64_encode(data);
}

const std::vector<std::byte> Binary::BASE64_TO_BINARY(const std::string& data){
    return base64_to_bytes(data);
}

std::string Binary::to_base64_string() const{
    if (this->binary_array == nullptr){
        LOG_ERROR << "Binary::to_base64_string: Binary array is null";
        throw std::runtime_error(std::string("Binary::to_base64_string: Binary array is null") + __FILE__ + ":" + std::to_string(__LINE__));
    }
    if (this->binary_array->size() == 0)
        return "";
    return BINARY_TO_BASE64(*this->binary_array);
}

const Binary Binary::contact(std::initializer_list<Binary>&& args){
    Binary binary(0);
    for (auto arg : args){
        if (arg.binary_array == nullptr){
            LOG_ERROR << "Binary::contact: Binary array is null";
            throw std::runtime_error(std::string("Binary::contact: Binary array is null") + __FILE__ + ":" + std::to_string(__LINE__));
        }
        binary += std::move(arg);
    }
    return binary;
}

bool Binary::empty() const{
    if (this->binary_array == nullptr){
        LOG_ERROR << "Binary::empty: Binary array is null";
        throw std::runtime_error(std::string("Binary::empty: Binary array is null") + __FILE__ + ":" + std::to_string(__LINE__));
    }
    return this->binary_array->empty();
}

bool Binary::is_null() const{
    return this->binary_array == nullptr;
}