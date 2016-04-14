/*
    Pin.h

    @Author: Brandon Porter
    class for handling pin gpio
    version 0.9
*/
#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#define ELOC "/sys/class/gpio/export"
#define UELOC "/sys/class/gpio/uexport"
#define GPDIR(x) "/sys/class/gpio/gpio/"+x+"/direction"
#define GPVAL(x) "/sys/class/gpio/gpio/"+x+"/value"

using namespace std;

//note, this is a p1 board. Controlls pins and returns data about them

class pin{
public:
    //constuctors, all, c++ 11+
    pin():pin(0) {}
    pin(int which){stringstream ss; ss<<which; controlled=ss.str(); exportGP();}
    pin(string which):controlled(which){exportGP();}
    //sets direction of pin
    //@returns success
    bool setDirection(string);
    /*
      sets value of pin
      @returns success of action
    */
    bool setValue(string);
    /*
        get value in pin
        @Args: string& returns empty string on failure, else returns value
        @returns success of action
    */
    bool getVal(string&);
    /*
        @returns number of pin controlled.
    */
    string getNum(){return controlled;}

    //destructor
    virtual ~pin(){}

private:
    string controlled;
    // enters import file
    // success of entry
    void unexportGP();
    //enters export file
    // success of entry
    void exportGP();
};
