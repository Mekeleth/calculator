#include <gtkmm/application.h>
#include "calculator.h"

int main(int argc, char *argv[]){
    auto app = Gtk::Application::create(argc, argv,"org.gtkmm.examples.base"); // our application

    Calculator calc_window; // an instance of Calculator class, which is a window
    calc_window.set_default_size(400,600); // set default size of a calc_window window
    return app->run(calc_window); // run the app with calc_window window
}
