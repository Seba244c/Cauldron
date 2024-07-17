//
// Created by Sebastian Snoer on 17/07/2024.
//

#pragma once
#include <hrpch.h>
#include "DnD/DnD.h"

namespace Heracles {
    typedef std::string Identifier;
    [[nodiscard]] static Identifier CreateIdentifier(const std::string &originLibrary, const std::string &type, const std::string &name);

    class ContentLibrary {
    public:
        explicit ContentLibrary(std::string name);

        void AddRace(const DnD::Race& race);
        [[nodiscard]] DnD::Race GetRace(Identifier& id);
        [[nodiscard]] std::vector<DnD::Race> ListRaces();
    private:
        std::unordered_map<Identifier, DnD::Race> m_Races;
        const std::string m_Name;
    };
} // Heracles
