//
// Created by Sebastian Snoer on 18/07/2024.
//
#include "DnD.h"

namespace Heracles::DnD {
    SerializedObject Race::Serialize() const {
        SerializedObjectBuilder builder {"DnD::Race"};
        builder.addString("Name", Name);

        return builder.Build();
    }
}
