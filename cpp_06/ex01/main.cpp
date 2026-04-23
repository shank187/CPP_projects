#include "Serializer.hpp"
#include <stdint.h>
#include <iostream>


int main(void)
{
    Data obj;
    std::cout << "address of the obj: " << &obj << std::endl;
    uintptr_t raw = Serializer::serialize(&obj);
    std::cout << "serialized address: " << raw << std::endl;
    std::cout << "deserialized address: " << Serializer::deserialize(raw) << std::endl;
}