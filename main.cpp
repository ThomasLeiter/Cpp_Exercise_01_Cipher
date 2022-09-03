#include "Cipher.hpp"

int main(int arc, char** argv){
    const std::string message = "StrengGeheimeZeichen";
    const unsigned long key = 1ul;
    SimpleCaesar sc(key);
    std::string enc_msg = sc.encode(message);
    std::string dec_msg = sc.decode(enc_msg);
    std::cout << "Message: " << message << std::endl;
    std::cout << "Enc Msg: " << enc_msg << std::endl;
    std::cout << "Dec Msg: " << dec_msg << std::endl;
    return 0;
}