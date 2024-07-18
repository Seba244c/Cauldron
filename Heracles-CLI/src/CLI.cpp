//
// Created by Sebastian Snoer on 17/07/2024.
//

#include "Heracles.h"
#include <iostream>

static Heracles::ContentLibrary s_ContentLib{"HeraclesCLI"};

int main(int argc, char **argv) {
    Heracles::DnD::Race dragonborn;
    dragonborn.Name = "Dragonborn";
    s_ContentLib.AddRace(dragonborn);

    std::cout << Heracles::Serializer::Serialize(s_ContentLib);
}