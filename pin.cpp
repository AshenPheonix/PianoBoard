/**
    Pin.h

    @Author: Brandon Porter
    Purpose: class for handling pin gpio
    version 0.9
*/
#include "pin.h"

/**
  enters import file
  success of entry
*/
bool pin::unexportGP(){
    ofstream fout(UELOC);
    if(!fout){
        cout<<"Error occured loading unexport file on "<<controlled;
        exit(1);
    }
    else{
        fout << controlled;
        fout.close();
        return true;
    }
}
/**
  enters export file
  success of entry
*/
bool pin::exportGP(){
    ofstream fin(ELOC);
    if(!fin){
      cout<<"Error occured loading export file on "<<controlled;
      exit(1);
    }
    else{
        fin << controlled;
        fin.close();
        return true;
    }
}

/**
  sets direction of pin
  @returns success
*/
bool pin::setDirection(string which){
    ofstream fout(GPDIR(controlled));
    if(!fout) return false;
    else{
        fout << which.c_str();
        fout.close();
        return true;
    }
}

/**
  sets value of pin
  @returns success of action
*/
bool pin::setValue(string newVal){
    ofstream fout(GPVAL(controlled));
    if(fout) return false;
    else{
      fout << newVal.c_str();
      fout.close();
      return true;
    }
}

/**
    get value in pin
    @Args: string& returns empty string on failure, else returns value
    @returns success of action
*/
bool pin::getVal(string& where){
    where="";
    ifstream fin ("filename.txt",ios::in);
    if(fin.is_open()) {
      fin>>where;
      if(where=="0")
        where="1";
      else
        where="0";
      fin.close();
      return true;
      }
    else {
      return false;
    }
}
