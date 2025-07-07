#include "Serializer.hpp"
#include "Data.hpp"

int main() {
    // Create a Data object
    Data* originalData = new Data();
    originalData->id = 42;
    originalData->name = "Test Data";
    
    std::cout << "Original Data:" << std::endl;
    std::cout << "Address: " << originalData << std::endl;
    std::cout << "ID: " << originalData->id << std::endl;
    std::cout << "Name: " << originalData->name << std::endl;
    
    // Serialize the pointer
    uintptr_t serialized = Serializer::serialize(originalData);
    std::cout << "\nSerialized value: " << serialized << std::endl;
    
    // Deserialize back to pointer
    Data* deserializedData = Serializer::deserialize(serialized);
    
    std::cout << "\nDeserialized Data:" << std::endl;
    std::cout << "Address: " << deserializedData << std::endl;
    std::cout << "ID: " << deserializedData->id << std::endl;
    std::cout << "Name: " << deserializedData->name << std::endl;
    
    // Check if addresses match
    std::cout << "\nPointers match: " << (originalData == deserializedData ? "Yes" : "No") << std::endl;
    
    delete originalData;
    return 0;
}