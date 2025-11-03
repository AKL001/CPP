#include "Serializer.hpp"

int main()
{
    Data *data = new Data;
    data->_id = 42;
    data->_name = "hamid";

    std::cout << "Original data - Address: " << data << ", Name: " << data->_name << ", id: " << data->_id << std::endl;

    uintptr_t serialized = Serializer::serialize(data);
    std::cout << "Serialized: " << serialized << std::endl;

    Data *deserialized = Serializer::deserialize(serialized);
    std::cout << "Deserialized data - Address: " << deserialized << ", Name: " << deserialized->_name << ", id: " << deserialized->_id << std::endl;

    std::cout << "Pointers are equal: " << (data == deserialized ? "true" : "false") << std::endl;

    delete data;
    return 0;
}
