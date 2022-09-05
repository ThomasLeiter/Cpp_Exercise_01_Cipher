#include "Cipher.hpp"

const std::string Cipher::Alphabet::LOWER_CASE = "abcdefghijklmnopqrstuvwxyz";
const std::string Cipher::Alphabet::UPPER_CASE = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const std::string Cipher::Alphabet::LOWER_UPPER = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

Cipher::SubstitutionCipher::SubstitutionCipher(const std::string &alpha_code) : alphabet(Alphabet::LOWER_UPPER), alpha_code(alpha_code)
{
}

Cipher::SubstitutionCipher::SubstitutionCipher(const std::string &alphabet, const std::string &alpha_code) : alphabet(alphabet), alpha_code(alpha_code)
{
}

/*
 * Encode a give message by substituting its characters
 * with their corresponding characters in the code alphabet.
 */
std::string Cipher::SubstitutionCipher::encode(const std::string &message)
{
    std::string enc_msg;
    for (char c : message)
    {
        enc_msg += alpha_code.at(alphabet.find(c));
    }
    return enc_msg;
}

/*
 * Decode a give encrypted message by substituting its characters
 * with their corresponding characters in the base alphabet.
 */
std::string Cipher::SubstitutionCipher::decode(const std::string &enc_msg)
{
    std::string message;
    for (char c : enc_msg)
    {
        message += alphabet.at(alpha_code.find(c));
    }
    return message;
}