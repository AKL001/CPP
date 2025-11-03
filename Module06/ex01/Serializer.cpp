#include "Serializer.hpp"
#include <cstdint>


Serializer::Serializer(){}
Serializer::Serializer(const Serializer& cp){*this = cp;}
Serializer::~Serializer(){}
Serializer& Serializer::operator=(const Serializer& cp){(void)cp;return *this;}

uintptr_t serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}