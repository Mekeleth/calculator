#include <gtkmm/application.h>
#include "calculator.h"

int main(int argc, char *argv[]){
    auto app = Gtk::Application::create(argc, argv,"org.gtkmm.examples.base");

    Calculator calc_window;
    calc_window.set_default_size(400,600);
    return app->run(calc_window);
}
