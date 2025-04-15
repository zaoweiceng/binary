#include "binary.hpp"


int main(void){
    Binary binary1("Hello World", StringType::ASCII);
    Binary binary2("SGVsbG8gV29ybGQ=", StringType::BASE64);
    Binary binary3("48656c6c6f20576f726c64", StringType::BINARY);
    std::cout << "binary1 hex string: " << binary1.to_hex_string() << std::endl;
    std::cout << "binary2 hex string: " << binary2.to_hex_string() << std::endl;
    std::cout << "binary3 hex string: " << binary3.to_hex_string() << std::endl;
    std::cout << "binary1 ascii string: " << binary1.to_ascll_string() << std::endl;
    std::cout << "binary2 ascii string: " << binary2.to_ascll_string() << std::endl;
    std::cout << "binary3 ascii string: " << binary3.to_ascll_string() << std::endl;
    std::cout << "binary1 base64 string: " << binary1.to_base64_string() << std::endl;
    std::cout << "binary2 base64 string: " << binary2.to_base64_string() << std::endl;
    std::cout << "binary3 base64 string: " << binary3.to_base64_string() << std::endl;
    std::cout << "------------------------------------------------------"<< std::endl;
    Binary binary4 = binary1 + Binary("Hello World", StringType::ASCII) + Binary(binary2);
    std::cout << "binary4 ascll string: " << binary4.to_ascll_string() << std::endl;
    std::cout << "-------------------------------------------------"<< std::endl;
    Binary binary5(14);
    binary5.write(0, 14, binary4.read(0, 14).data());
    std::cout << "binary5 ascll string: " << binary5.to_ascll_string() << std::endl;
    std::cout << "-------------------------------------------------"<< std::endl;
    Binary binary6 = binary1 ^ Binary("abcabcabcabc", StringType::BINARY);
    std::cout << "binary6 ascll string: " << binary6.to_ascll_string() << std::endl;
    Binary binary7 = binary6 ^ Binary("abcabcabcabc", StringType::BINARY);
    std::cout << "binary7 ascll string: " << binary7.to_ascll_string() << std::endl;
    std::cout << "-------------------------------------------------"<< std::endl;
    std::cout << Binary::contact({std::move(binary1), std::move(binary2), std::move(binary3)} ).to_ascll_string() << std::endl;
    return 0;
}