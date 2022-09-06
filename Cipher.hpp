#ifndef CIPHER_HPP
#define CIPHER_HPP

#include <string>

namespace Cipher
{

    /*
     * Holds constants for useful basic alphabets.
     *
     * LOWER_CASE
     * UPPER_CASE
     * LOWER_UPPER
     */
    class Alphabet {
    public:
        static const std::string LOWER_CASE; // Lower case chars "abcdefghijklmnopqrstuvwxyz"
        static const std::string UPPER_CASE; // Upper case chars "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        static const std::string LOWER_UPPER; // Lower and upper case chars "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
    };

    /*
     * A simple substitution cipher.
     * 
     * Messages will be encrypted and decoded
     * by substituting all chars in a given
     * alphabet A by chars from a (possibly different)
     * alphabet B.
     */
    class SubstitutionCipher
    {
    public:
        SubstitutionCipher(const std::string &);
        SubstitutionCipher(const std::string &, const std::string &);
        std::string encode(const std::string &) const;
        std::string decode(const std::string &) const;

    protected:
        const std::string alphabet;
        const std::string alpha_code;
    };

    SubstitutionCipher make_simple_caesar_code(const unsigned int &);
    SubstitutionCipher make_simple_caesar_code(const std::string&, const unsigned int &);

    SubstitutionCipher make_extended_caesar_code(const std::string&, const unsigned int &);
    SubstitutionCipher make_extended_caesar_code(const std::string&, const std::string&, const unsigned int &);

}

#endif