#ifndef RADIO_BUTTONS
#define RADIO_BUTTONS

// #include <gtkmm.h>
#include <gtkmm/radiobutton.h>
#include <gtkmm/button.h>
#include <gtkmm/box.h>
#include <gtkmm/frame.h>
#include <gtkmm/entry.h>
#include <string>

using std::string;

extern bool io = true;

class RadioButtons : public Gtk::Frame {
public:
    RadioButtons();
    ~RadioButtons();
    int whichButton();
    string getNumber();

protected:
    Gtk::Box topBox, box;
    Gtk::RadioButton radioButton1, radioButton2, radioButton3;
    Gtk::Entry input;
};

RadioButtons::RadioButtons() :
  topBox(Gtk::ORIENTATION_VERTICAL, 10),
  box(Gtk::ORIENTATION_HORIZONTAL),
  radioButton1("binary"),
  radioButton2("decimal"),
  radioButton3("hexadecimal"){

  set_size_request(300, 50);
  set_border_width(10);
  this->set_label(io ? "Number format: input" : "Number format: output");

  if(io){
      input.set_max_length(50);
      topBox.pack_start(input);
  }
  // Put radio buttons 2 and 3 in the same group as 1:
  radioButton2.join_group(radioButton1);
  radioButton3.join_group(radioButton1);

  // Put the radio buttons in topBox1:
  box.pack_start(radioButton1);
  box.pack_start(radioButton2);
  box.pack_start(radioButton3);
  topBox.pack_start(box);

  // Set the first button active
  radioButton2.set_active();

  add(topBox);

  show_all_children();
  io = !io;
}

RadioButtons::~RadioButtons(){
}

int RadioButtons::whichButton(){
    int value;
    if(this->radioButton1.get_active()) value = 2;
    else if(this->radioButton2.get_active()) value = 10;
    else value = 16;
    return value;
}

string RadioButtons::getNumber(){
    return this->input.get_text();
}
#endif
