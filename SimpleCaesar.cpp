#include "Cipher.hpp"

    Cipher::SubstitutionCipher Cipher::make_simple_caesar_code(const int &shift)
    {
        return Cipher::make_simple_caesar_code(Cipher::Alphabet::LOWER_UPPER, shift);
    }

    Cipher::SubstitutionCipher Cipher::make_simple_caesar_code(const std::string &alphabet, const int &shift)
    {
        std::string alpha_code{alphabet.substr(shift) + alphabet.substr(0, shift)};
        return Cipher::SubstitutionCipher(alphabet, alpha_code);
    }
