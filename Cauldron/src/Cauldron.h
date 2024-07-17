//
// Created by Sebastian Snoer on 17/07/2024.
//
#pragma once
#include <gtkmm/button.h>
#include <gtkmm/window.h>

class Cauldron : public Gtk::Window {
public:
    Cauldron();
    ~Cauldron() override;
protected:
    // Signal Handlers
    void onButtonClicked();

    // Widgets
    Gtk::Button m_Button;
};
