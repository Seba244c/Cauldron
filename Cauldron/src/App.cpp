//
// Created by Sebastian Snoer on 17/07/2024.
//
#include "Cauldron.h"
#include <gtkmm/application.h>

int main(int argc, char **argv) {
    const auto cauldron = Gtk::Application::create("dk.sebsa.Cauldron");
    return cauldron->make_window_and_run<Cauldron>(argc, argv);
}
