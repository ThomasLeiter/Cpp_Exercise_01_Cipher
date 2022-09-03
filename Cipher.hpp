#ifndef CIPHER
#define CIPHER

#include <string>

class SubstitutionCipher
{
public:
    SubstitutionCipher(const unsigned long &_key) : key(_key) {}
    virtual std::string encode(const std::string &) = 0;
    virtual std::string decode(const std::string &) = 0;
    class CipherError{};
private:
    const unsigned long key;
};

class SimpleCaesar : public SubstitutionCipher
{
public:
    using SubstitutionCipher::SubstitutionCipher;
};

class ExtendedCaesar : public SubstitutionCipher
{
public:
    using SubstitutionCipher::SubstitutionCipher;
};

#endif