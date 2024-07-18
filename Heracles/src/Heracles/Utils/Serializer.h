#include <utility>

//
// Created by Sebastian Snoer on 18/07/2024.
//

#pragma once

namespace Heracles {
    typedef const char* FieldName;
    typedef std::string FieldValue;

    enum FieldType {
        Text = 0,
        Object = 1,
        Array,
    };

    struct SerialiedField {
        FieldName Name;
        FieldType Type;
        FieldValue Value;
    };

    struct SerializedObject {
        std::string TypeName;

        std::vector<SerialiedField> Fields;
    };

    struct Serializable {
        virtual ~Serializable() = default;

        [[nodiscard]] virtual SerializedObject Serialize() const = 0;
    };

    class Serializer {
    public:
        static std::string Serialize(const Serializable &obj);

        static std::string SerializeField(const SerialiedField &field);
    };

    class SerializedObjectBuilder {
    public:
        explicit SerializedObjectBuilder(std::string typeName) : m_TypeName(std::move(typeName)) {}
        [[nodiscard]] SerializedObject Build() const;

        void addString(FieldName fieldName, const std::string &value);
        void addObject(FieldName fieldName, const Serializable &value);
        template <typename T,
            std::enable_if_t<std::is_base_of_v<Serializable,T>, bool> =true>
        void addObjects(FieldName fieldName, const std::vector<T> &values);

    private:
        const std::string m_TypeName;
        std::vector<SerialiedField> m_Fields;
    };

    template<typename T, std::enable_if_t<std::is_base_of_v<Serializable, T>, bool>>
    void SerializedObjectBuilder::addObjects(FieldName fieldName, const std::vector<T> &values) {
        std::string out;

        for(size_t i = 0; i < values.size(); ) {
            const auto &value = Serializer::Serialize(values[i]);

            out += value;
            if(++i < values.size()) out += ",";
        }

        m_Fields.emplace_back(SerialiedField{fieldName, Array, out});
    }
} // Heracles
