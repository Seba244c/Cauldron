#include "gtkmm/application.h"
#include <iostream>
#include <gtkmm.h>

class Cauldron : public Gtk::Window {
public:
    Cauldron();
};

Cauldron::Cauldron() {
    set_title("Cauldron");
    set_default_size(1280, 900);
}

int main(int argc, char **argv) {
    auto cauldron = Gtk::Application::create("dk.sebsa.Cauldron");
    
    return cauldron->make_window_and_run<Cauldron>(argc, argv);
}
