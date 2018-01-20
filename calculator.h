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
#include "conversion.h"

using namespace std;

class Calculator: public Gtk::Window { // class that extends Gtk::Window - important
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
    void fillBuffer(string);
};

Calculator::Calculator(): mButton("Convert"), topBox(Gtk::ORIENTATION_VERTICAL,Gtk::PACK_SHRINK), radioBox(Gtk::ORIENTATION_VERTICAL) {
    set_title("Engineer's Calculator");
    set_border_width(20);

    add(topBox);

    mButton.signal_clicked().connect(sigc::mem_fun(*this,&Calculator::convertNumber)); // connect click signal to function
    mButton.set_size_request(50,30); // set minimum size of width and height of this button

    // add two radio buttons to one radioBox
    radioBox.pack_start(buttons1);
    radioBox.pack_start(buttons2);
    // add everything to topBox (window can only display one widget, so we pack everything into it)
    topBox.pack_start(radioBox);
    topBox.pack_start(output);
    topBox.pack_start(mSeparator);
    topBox.pack_start(mButton);
    // show all children of the window
    show_all_children();
}

Calculator::~Calculator(){
}

void Calculator::fillBuffer(string text){
    // TextView must have a TextBuffer which will refresh every single time we click "Convert" button
    // (see: Calculator::convertNumber())
    textBuffer = Gtk::TextBuffer::create();
    textBuffer->set_text(text);
    output.set_buffer(textBuffer);
}

void Calculator::convertNumber(){
    bool check = true;
    int button1 = buttons1.whichButton(); // input base: 2, 10 or 16
    int button2 = buttons2.whichButton(); // output base: 2, 10 or 16
    string text = buttons1.getText(); // get text from Gtk::Entry in input section
    if(!text.empty()){
        if(button1 == 2){ // error check for base = 2
            for(int i=0; i<text.length(); ++i){
                if((int)text[i] != 48 && (int)text[i] != 49){
                    this->fillBuffer("Error!");
                    check = false;
                    break;
                }
            }
        }
        else if(button1 == 10){ // error check for base = 10
            for(int i=0; i<text.length(); ++i){
                if((int)text[i] < 48 || (int)text[i] > 57){
                    this->fillBuffer("Error!");
                    check = false;
                    break;
                }
            }
        }
        else if(button1 == 16){ // error check for base = 16
            for(int i=0; i<text.length(); ++i){
                if((int)text[i] < 48 || ((int)text[i] > 57 && (int)text[i] < 65) || (int)text[i] > 70){
                    this->fillBuffer("Error!");
                    check = false;
                    break;
                }
            }
        }
        // conversion
        if(check){
            if(button1 == button2) this->fillBuffer(text); // trivial case - no conversion needed
            else{
                int formattedNumber = stoi(text /* string to be parsed */, nullptr, button1 /* base */); //string to integer - auto conversion form string to number with given base
                string formattedText;
                if(button2 == 10) formattedText = to_string(formattedNumber); // formattedNumber is already converted in base 10
                else formattedText = convert(formattedNumber, button2); // see: conversion.h
                this->fillBuffer(formattedText);
            }
        }
    }
    else this->fillBuffer("No number means no conversion...");

}
#endif
