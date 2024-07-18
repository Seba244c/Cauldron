//
// Created by Sebastian Snoer on 18/07/2024.
//

#include "Serializer.h"

namespace Heracles {
    SerializedObject SerializedObjectBuilder::Build() const {
        SerializedObject out{};
        out.TypeName = m_TypeName;
        out.Fields = m_Fields;

        return out;
    }

    void SerializedObjectBuilder::addString(const FieldName fieldName, const std::string &value) {
        m_Fields.emplace_back(SerialiedField{fieldName, Text, value.c_str()});
    }

    void SerializedObjectBuilder::addObject(FieldName fieldName, const Serializable &value) {
        const auto obj = Serializer::Serialize(value);
        const char *serializedValue = obj.c_str();

        m_Fields.emplace_back(SerialiedField{fieldName, Object, serializedValue});
    }

    std::string Serializer::Serialize(const Serializable &obj) {
        const auto serialized = obj.Serialize();

        std::string out = serialized.TypeName;
        out += "{";

        for(size_t i = 0; i < serialized.Fields.size(); ) {
            const auto &field = serialized.Fields[i];

            out += std::format("{}={}", field.Name, SerializeField(field));
            if(++i < serialized.Fields.size()) out += ",";
        }

        out += "}";

        return out;
    }

    std::string Serializer::SerializeField(const SerialiedField &field) {
        std::string out;

        switch (field.Type) {
            case Text: out += "txt"; break;
            case Object: out += "obj"; break;
            case Array: out += "list"; break;
        }

        out += "{";
        out += field.Value;
        out += "}";

        return out;
    }
} // Heracles