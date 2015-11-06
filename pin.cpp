#include "pin.h"

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

bool pin::setDirection(string whcih){
    ofstream fout(GPDIR(controlled));
    if(!fout) return false;
    else{
        fout << which;
        fout.close();
        return true;
    }
}

bool pin::setValue(string newVal){
    ofstream fout(GPVAL(controlled));
    if(fout) return false;
    else{
      fout << which;
      fout.close();
      return true;
    }
}

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

virtual pin::~pin(){
  unexportGP();
}
