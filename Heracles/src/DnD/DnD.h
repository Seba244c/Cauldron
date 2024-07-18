//
// Created by Sebastian Snoer on 17/07/2024.
//

#pragma once

#include "Heracles/Utils/Serializer.h"

namespace Heracles::DnD {
    struct Race final : Serializable {
        [[nodiscard]] SerializedObject Serialize() const override;

        std::string Name;
    };
} // Heracles::DnD
