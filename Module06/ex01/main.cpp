#include "Serializer.hpp"

int main()
{
    Data *data = new Data;
    data->_id = 42;
    data->_name = "hamid";

    std::cout << "Original data - Address: " << data << ", Name: " << data->_name << ", id: " << data->_id << std::endl;

    uintptr_t ser = Serializer::serialize(data);
    std::cout << "ser: " << ser << std::endl;

    Data *deser = Serializer::deserialize(ser);
    std::cout << "Deserialized data - Address: " << deser << ", Name: " << deser->_name << ", id: " << deser->_id << std::endl;

    std::cout << "Pointers are equal: " << (data == deser ? "true" : "false") << std::endl;

    delete data;
    return 0;
}
