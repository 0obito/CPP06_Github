#include "Data.hpp"
#include "Serializer.hpp"

int main() {
    Data emptyDatum;
    Data fullDatum('f', 333, "F333");

    // serialize emptyDatum
    uintptr_t emptyAdd = Serializer::serialize(&emptyDatum);
    std::cout << "emptyDatum has been serialized\n";
    std::cout << "emptyDatum address is: " << emptyAdd << "\n";

    // deserialize emptyDatum
    Data* emptyPtr = Serializer::deserialize(emptyAdd);
    std::cout << "emptyDatum has been deserialized\n";
    std::cout << "emptyDatum address (emptyPtr) is: " << emptyPtr << "\n";
    std::cout << "emptyDatum elements are: \n";
    std::cout << "char: " << emptyPtr->getChar() << "\n";
    std::cout << "int: " << emptyPtr->getInt() << "\n";
    std::cout << "str: " << emptyPtr->getStr() << "\n\n";



    // serialize fullDatum
    uintptr_t fullAdd = Serializer::serialize(&fullDatum);
    std::cout << "fullDatum has been serialized\n";
    std::cout << "fullDatum address is: " << fullAdd << "\n";

    // deserialize fullDatum
    Data* fullPtr = Serializer::deserialize(fullAdd);
    std::cout << "fullDatum has been deserialized\n";
    std::cout << "fullDatum address (fullPtr) is: " << fullPtr << "\n";
    std::cout << "fullDatum elements are: \n";
    std::cout << "char: " << fullPtr->getChar() << "\n";
    std::cout << "int: " << fullPtr->getInt() << "\n";
    std::cout << "str: " << fullPtr->getStr() << "\n";
}
