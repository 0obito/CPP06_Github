#include "Serializer.hpp"

Serializer::Serializer() {
}

Serializer::Serializer(const Serializer& other) {
    (void)other;
}

Serializer& Serializer::operator=(const Serializer& other) {
    (void)other;
    return *this;
}

Serializer::~Serializer() {
}

uintptr_t Serializer::serialize(Data* ptr) {
    uintptr_t serialized;

    serialized = reinterpret_cast<uintptr_t>(ptr);
    return serialized;
}

Data* Serializer::deserialize(uintptr_t raw) {
    Data* deserialized;

    deserialized = reinterpret_cast<Data*>(raw);
    return deserialized;
}
