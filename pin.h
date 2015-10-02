/*
    Author: Brandon Porter
    class for handling pin gpio
*/
#pragma once
#include <fstream>
#include <gpio.h>
#include <sstream>
#include <string>
#define ELOC "/sys/class/gpio/export"
#define UELOC "/sys/class/gpio/uexport"
#define GPDIR(x) "/sys/class/gpio/gpio/"+x+"/direction"
#define GPVAL(x) "/sys/class/gpio/gpio/"+x+"/value"

using namespace std;

//note, this is a p1 board.

class pin{
public:
    //constuctors, all, c++ 11+
    pin():pin(0) {}
    pin(int which){stringstream ss; ss<<which; controlled=ss.str();}
    pin(string which):controlled(which){}
    
    //enters import file 
    //@returns success of entry
    bool unexportGP();
    //enters export file
    ///@returns success of entry
    bool exportGP();
    //sets direction of pin
    //@returns success
    bool setDirection(string);
    /*sets value of pin
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
};