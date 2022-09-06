#include "Cipher.hpp"

Cipher::SubstitutionCipher Cipher::make_simple_caesar_code(const unsigned int &shift)
{
    return Cipher::make_simple_caesar_code(Cipher::Alphabet::LOWER_UPPER, shift);
}

Cipher::SubstitutionCipher Cipher::make_simple_caesar_code(const std::string &alphabet, const unsigned int &shift)
{
    // Make sure shift is not longer than length of alphabet
    const unsigned int split_pos = shift % alphabet.length();
    // Build coding table
    std::string alpha_code{alphabet.substr(split_pos) + alphabet.substr(0, split_pos)};
    return Cipher::SubstitutionCipher(alphabet, alpha_code);
}
