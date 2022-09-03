#include "Cipher.hpp"

std::string SimpleCaesar::encode(const std::string & message){
    std::string enc_msg;
    for (const char& c : message){
        enc_msg += encode_char(c, key);
    }
    return enc_msg;
}

std::string SimpleCaesar::decode(const std::string & message){
    std::string dec_msg;
    for (const char& c : message){
        dec_msg += decode_char(c, key);
    }
    return dec_msg;
}

char encode_char(const char& c, unsigned long shift){
    char pos = shift % 256;
    if (is_lower_case(c)){
        pos = ('a' - c + shift) % 52;
    } else if (is_upper_case(c)){
        pos = ('A' - c + shift) % 52;
    } else {
        throw CipherError;
    }
    return (pos < 26) ? 'a' + pos : 'A' + pos - 26;
}

char decode_char(const char& c, unsigned long shift){
    char pos = shift % 256;
    if (is_lower_case(c)){
        pos = ('a' - c - shift) % 52;
    } else if (is_upper_case(c)){
        pos = ('A' - c - shift) % 52;
    } else {
        throw CipherError;
    }
    return (pos < 26) ? 'a' + pos : 'A' + pos - 26;
}

boolean is_lower_case(const char& c){
    return 'a' <= c && 'z' >= c;
}

boolean is_upper_case(const char& c){
    return 'A' <= c && 'Z' >= c;
}