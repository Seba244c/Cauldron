//
// Created by Sebastian Snoer on 17/07/2024.
//

#include "Content.h"

namespace Heracles {
    Identifier CreateIdentifier(const std::string &originLibrary, const std::string &type, const std::string &name) {
        return std::format("{}.{}.{}", originLibrary, type, name);
    }

    ContentLibrary::ContentLibrary(std::string name) : m_Name(std::move(name)) {
    }

    void ContentLibrary::AddRace(const DnD::Race& race) {
        const Identifier id = CreateIdentifier( m_Name, "Race", race.Name);
        if(m_Races.contains(id)) return;

        m_Races[id] = race;
    }

    DnD::Race ContentLibrary::GetRace(Identifier &id) {
        HR_ASSERT(m_Races.contains(id), "ContentLibrary {}, doest not contain race: {}", m_Name, id);

        return m_Races[id];
    }

    std::vector<DnD::Race> ContentLibrary::ListRaces() {
        std::vector<DnD::Race> races;
        std::pair<std::string, DnD::Race> pair;

        BOOST_FOREACH(pair, m_Races)
            races.push_back(pair.second);

        return races;
    }
} // Heracles