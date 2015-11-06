#include "pin.h"
#include <string>
#include <iostream>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

struct locs {
  vector<string> v;
  int selected;
  rotate(){selected = ( (selected==v.length()-1)? 0:selected+1);}
  get(){return v[selected];}
};

int main (){

    vector<pin *> GPIOPins;
    GPIOPins.push_back(new pin(2));
    GPIOPins.push_back(new pin(3));
    GPIOPins.push_back(new pin(4));
    GPIOPins.push_back(new pin(14));
    GPIOPins.push_back(new pin(15));
    GPIOPins.push_back(new pin(17));
    GPIOPins.push_back(new pin(18));
    GPIOPins.push_back(new pin(27));
    GPIOPins.push_back(new pin(22));
    GPIOPins.push_back(new pin(23));
    GPIOPins.push_back(new pin(24));
    GPIOPins.push_back(new pin(10));
    GPIOPins.push_back(new pin(9));
    GPIOPins.push_back(new pin(25));
    GPIOPins.push_back(new pin(11));
    GPIOPins.push_back(new pin(8));
    GPIOPins.push_back(new pin(7));

    locs locations;

    for(auto &p: GPIOPins)
      p->setDirection("in");

    while (1) {
      usleep(10000);
      for(auto &p: GPIOPins){
        string getter;
        if(p->getVal(getter)) && getter != "0"){
          if(p == GPIOPins.back())
            locations.rotate();
          else
            
        }
      }

    }

  return 0;
}
