# 二进制封装类

## 主要作用
Binary 类是一个用于处理二进制数据的封装类，提供了对二进制数据的各种操作，包括读写、转换、拼接和位运算等功能。它使用 `std::byte` 类型来表示二进制数据，并通过智能指针 `std::shared_ptr` 管理数据存储。

## 核心功能

### 1. 数据存储与管理
- 使用 `std::shared_ptr<std::vector<std::byte>>` 存储二进制数据
- 提供多种构造函数支持不同数据源的初始化
- 支持拷贝和移动语义

### 2. 数据读写操作
- **读取操作**：
  - `read()`: 读取全部或指定范围的二进制数据
  - `get()`: 获取指定位置的字节
- **写入操作**：
  - `set()`: 设置指定位置的字节
  - `write()`: 写入数据到指定位置
  - `append()`: 追加数据

### 3. 数据转换
- **字符串转换**：
  - `to_hex_string()`: 转换为十六进制字符串
  - `to_ascll_string()`: 转换为ASCII字符串
  - `to_base64_string()`: 转换为Base64编码字符串
- **静态转换方法**：
  - `BINARY_TO_STRING`/`STRING_TO_BINARY`: 十六进制字符串与二进制互转
  - `BINARY_TO_ASCII`/`ASCII_TO_BINARY`: ASCII字符串与二进制互转
  - `BINARY_TO_BASE64`/`BASE64_TO_BINARY`: Base64字符串与二进制互转

### 4. 数据操作
- `resize()`: 调整数据大小
- `clear()`: 清空数据
- `size()`: 获取数据大小
- `empty()`: 检查是否为空
- `is_null()`: 检查指针是否为空

### 5. 运算符重载
- `operator[]`: 下标访问
- `operator+`: 二进制数据拼接
- `operator^`: 二进制数据异或运算
- `operator<<`: 数据流式拼接
- `operator==`/`operator!=`: 相等性比较

### 6. 实用功能
- `contact()`: 静态方法，连接多个Binary对象
- 错误检查：对空指针和越界访问进行检查并抛出异常

## 特点
1. **安全性**：对空指针和越界访问进行了严格检查
2. **灵活性**：支持多种数据源的初始化和转换
3. **高效性**：使用智能指针管理内存，支持移动语义减少拷贝
4. **扩展性**：提供了丰富的接口满足不同二进制处理需求

## 适用场景
- 二进制数据的存储和处理
- 协议解析和构建
- 数据加密和解密
- 文件读写操作
- 网络通信中的数据打包和解包

## 注意事项
1. 所有方法都对空指针进行了检查，会抛出`std::runtime_error`异常
2. 下标访问会检查越界情况
3. 移动操作后源对象会被置为无效状态
4. 十六进制字符串转换要求长度为偶数