#include "Cipher.hpp"

bool is_upper_case(const char&);
bool is_lower_case(const char&);
char encode_char(const char&, unsigned long);
char decode_char(const char&, unsigned long);
char mod (const char& a, const char& b){
    return (b + a%b) %b;
}


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
    char pos = mod(shift, 52);
    if (is_lower_case(c)){
        pos = (c - 'a' + pos);
    } else if (is_upper_case(c)){
        pos = (c - 'A' + pos + 26);
    } else {
        std::cerr << "Something went wrong.\n";
    }
    pos = mod(pos, 52);
    return (pos < 26) ? 'a' + pos : 'A' + pos - 26;
}

char decode_char(const char& c, unsigned long shift){
    char pos = mod(shift, 52);
    if (is_lower_case(c)){
        pos = (c - 'a' - pos);
    } else if (is_upper_case(c)){
        pos = (c - 'A' - pos + 26);
    } else {
        std::cerr << "Something went wrong.\n";
    }
    pos = mod(pos, 52);
    return (pos < 26) ? 'a' + pos : 'A' + pos - 26;
}

bool is_lower_case(const char& c){
    return 'a' <= c && 'z' >= c;
}

bool is_upper_case(const char& c){
    return 'A' <= c && 'Z' >= c;
}