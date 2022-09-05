#include "Cipher.hpp"

    /*
     * Makes a unique string from a random string str.
     * All double characters will be removed, the rest 
     * is left unchanged in order.
     * e.g.: unique_string("Hello") -> "Helo"
     */
    std::string unique_string(const std::string &str){
        std::string us;
        for (char c : str){
            if (us.find(c) == std::string::npos){
                us += c;
            }
        }
        return us;
    }

    Cipher::SubstitutionCipher Cipher::make_extended_caesar_code(const std::string &key, const int &shift)
    {
        return make_extended_caesar_code(Cipher::Alphabet::LOWER_UPPER, key, shift);
    }

    Cipher::SubstitutionCipher Cipher::make_extended_caesar_code(const std::string &_alphabet, const std::string &key, const int &shift)
    {
        // Make sure the key consists of unique characters
        std::string ukey = unique_string(key);
        std::string alphabet{_alphabet};
        // Delete key characters from alphabet 
        for (char c : ukey){
            int pos = alphabet.find(c);
            alphabet = alphabet.substr(0,pos) + alphabet.substr(pos+1);
        }
        // Build coding table
        std::string alpha_code{alphabet.substr(shift) + ukey + alphabet.substr(0, shift)};
        return Cipher::SubstitutionCipher(_alphabet, alpha_code);
    }