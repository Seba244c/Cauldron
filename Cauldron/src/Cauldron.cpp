#include "Cauldron.h"
#include <iostream>

Cauldron::Cauldron() : m_Button("Hello GTK") {
    set_title("Cauldron");
    set_default_size(1280, 900);

    m_Button.set_margin(10);
    m_Button.signal_clicked().connect(sigc::mem_fun(*this, &Cauldron::onButtonClicked));
    set_child(m_Button);
}

Cauldron::~Cauldron() = default;

void Cauldron::onButtonClicked() {
    std::cout << "HEllo World!" << std::endl;
}