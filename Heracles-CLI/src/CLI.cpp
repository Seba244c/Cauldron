//
// Created by Sebastian Snoer on 17/07/2024.
//

#include "Heracles.h"
#include <iostream>

static Heracles::ContentLibrary s_ContentLib{"HeraclesCLI"};

int main(int argc, char **argv) {
    s_ContentLib.AddRace(Heracles::DnD::Race{"Dragonborn"});

    for(Heracles::DnD::Race race : s_ContentLib.ListRaces()) {
        std::cout << race.Name;
    }
}