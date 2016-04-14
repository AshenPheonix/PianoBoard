/**
  @author Brandon Porter
  @version .9 Open Beta

  Purpose: Driver for a PianoBoard via a Pi.
*/
#include "pin.h"
#include <string>
#include <iostream>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

/**
  Unimplemented, for adding additional libraries of sounds
*/
struct locs {
  vector<string> v;
  int selected;
  /**
    moves the structure around like a ring
  */
  void rotate(){selected = ( (selected==v.size()-1)? 0:selected+1);}
  /**
    @return String associated with location
  */
  string get(){return v[selected];}
};


//actual operation
int main (){

    vector<pin *> GPIOPins;
    //Pin list, controlled for order
    GPIOPins.push_back(new pin(4));
    GPIOPins.push_back(new pin(14));
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

    //locs locations; //placeholder for future implementations

    for(auto &p: GPIOPins){
      p->setDirection("out");
      string temp;
      p->getVal(temp);
      cout<<temp<<endl;
    }

    GPIOPins[0]->setValue("0");
	  GPIOPins[1]->setValue("0");
	  GPIOPins[4]->setValue("0");

    while (1) {
      usleep(100000);
      for(auto &p: GPIOPins){
        string getter;
        if(p->getVal(getter) && getter != "0"){
	         cout<<"word::"<<p->getNum()<<endl; //for on the spot debugging of filesystem, physical board, and pin operation
          if(p == GPIOPins.back())
            locations.rotate();
          else{
            bool temp(true);
            while(temp){
		          string player="aplay /home/pi/pianoboard/music/"+p->getNum()+".wav";
            	system(player.c_str());
            	temp = ( (p->getVal(getter) && getter!="0")?true:false);
	          }
          }
        }
      }
    }

  return 0;
}
