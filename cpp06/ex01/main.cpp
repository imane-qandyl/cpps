#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main() {
    // Create a Data object
    Data myData(42, "Hello, World!");

    // Print the original data
    std::cout << "Original data: ";
    myData.display();

    // Serialize the pointer to myData
    uintptr_t raw = Serializer::serialize(&myData);

    // Deserialize the uintptr_t back into a Data pointer
    Data* deserializedData = Serializer::deserialize(raw);

    // Print the deserialized data
    std::cout << "Deserialized data: ";
    deserializedData->display();

    // Check if the original pointer is equal to the deserialized pointer
    if (&myData == deserializedData) {
        std::cout << "Success! The deserialized pointer matches the original pointer." << std::endl;
    } else {
        std::cout << "Failure! The deserialized pointer does not match the original pointer." << std::endl;
    }

    return 0;
}
