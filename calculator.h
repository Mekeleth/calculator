#ifndef CALCULATOR
#define CALCULATOR

#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <gtkmm/box.h>
#include <gtkmm/separator.h>
#include <gtkmm/textview.h>
#include <gtkmm/textbuffer.h>
#include <glibmm/refptr.h>
#include <iostream>
#include <string>
#include "radio_buttons.h"

using namespace std;

class Calculator: public Gtk::Window {
public:
    Calculator();
    ~Calculator();
protected:
    Gtk::Box topBox, radioBox;
    RadioButtons buttons1, buttons2;
    Gtk::TextView output;
    Glib::RefPtr<Gtk::TextBuffer> textBuffer;
    Gtk::Separator mSeparator;
    Gtk::Button mButton;
    void convertNumber();
    void fillBuffers();
};

Calculator::Calculator(): mButton("Convert"), topBox(Gtk::ORIENTATION_VERTICAL,Gtk::PACK_SHRINK), radioBox(Gtk::ORIENTATION_VERTICAL) {
    set_title("Engineer's Calculator");
    set_border_width(20);

    add(topBox);

    mButton.signal_clicked().connect(sigc::mem_fun(*this,&Calculator::convertNumber));
    mButton.set_size_request(50,30);

    radioBox.pack_start(buttons1);
    radioBox.pack_start(buttons2);
    topBox.pack_start(radioBox);
    topBox.pack_start(output);
    topBox.pack_start(mSeparator);
    topBox.pack_start(mButton);


    // Show all children of the window
    show_all_children();
}

Calculator::~Calculator(){
}

void Calculator::fillBuffers(){

}

void Calculator::convertNumber(){
    int button1 = buttons1.whichButton();
    int button2 = buttons2.whichButton();
    string text = buttons1.getNumber();
    cout << button1 << endl << button2 << endl << text.length() << endl;
    if(button1 = button2){

    }
    else if(button1 < button2){

    }
    else{

    }
}
#endif
