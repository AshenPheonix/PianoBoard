#include "pin.h"
    
bool unexportGP(){
    ofstream fout(UELOC)
    if(!fout){
        return false;
    }
    else{
        fout << controlled;
        fout.close();
        return true;
    }
}

bool exportGP(){
    ofstream fin(ELOC)
    if(!fin) return false;
    else{
        fin << controlled;
        fin.close();
        return true;
    }
}

bool setDirection(string whcih){
    ofstream fout.(GPDIR(controlled));
    if(!fout) return false;
    else{
        fout << which;
        fout.close();
        return true;
    }
}

bool setValue(string newVal){
    ofstream 
}

bool getVal(string&){
    
}
    
virtual ~pin(){}