#include "Cipher.hpp"
#include <iostream>

int main(int arc, char** argv){
    const std::string message = "StrengGeheimeZeichen";
    const int shift = 12;
    const std::string key = "Password";
    Cipher::SubstitutionCipher sc = Cipher::make_simple_caesar_code(shift);
    std::string enc_msg = sc.encode(message);
    std::string dec_msg = sc.decode(enc_msg);
    std::cout << "Simple Caesar with shift = " << shift << std::endl;
    std::cout << "Message: " << message << std::endl;
    std::cout << "Enc Msg: " << enc_msg << std::endl;
    std::cout << "Dec Msg: " << dec_msg << std::endl;
    Cipher::SubstitutionCipher ec = Cipher::make_extended_caesar_code(key, shift);
    enc_msg = ec.encode(message);
    dec_msg = ec.decode(enc_msg);
    std::cout << "Extended Caesar with shift = " << shift << " and key = " << key << std::endl;
    std::cout << "Message: " << message << std::endl;
    std::cout << "Enc Msg: " << enc_msg << std::endl;
    std::cout << "Dec Msg: " << dec_msg << std::endl;
    return 0;
}