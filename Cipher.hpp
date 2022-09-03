#ifndef CIPHER
#define CIPHER

#include <string>
#include <iostream>

class SubstitutionCipher
{
public:
    SubstitutionCipher(const unsigned long &_key) : key(_key) {}
    virtual std::string encode(const std::string &) = 0;
    virtual std::string decode(const std::string &) = 0;
protected:
    const unsigned long key;
};

class SimpleCaesar : public SubstitutionCipher
{
public:
    std::string encode(const std::string &) override;
    std::string decode(const std::string &) override;
    using SubstitutionCipher::SubstitutionCipher;
};

class ExtendedCaesar : public SubstitutionCipher
{
public:
    using SubstitutionCipher::SubstitutionCipher;
};

#endif