/*
 * MICSec.cc
 *
 *  Created on: Mar 27, 2021
 *      Author: lollo
 */

#include "MICSec.h"
#include <stdio.h>
#include <string.h>
#include <omnetpp.h>

MICSec::MICSec(){}

MICSec::MICSec(int type){
    this->type=type;
}

MICSec::~MICSec(){}

int MICSec::getType(){
    return this->type;
}

char* MICSec::getMicAuth() {
    switch (type) {
    case 4:
        return mic32;
        break;
    case 8:
        return mic64;
        break;
    case 16:
        return mic128;
        break;
    }
}

void MICSec::setMic(char* mic) {
    checkLength(mic);
    switch (type) {
    case 4:
        strncpy(mic32,mic,5);
        break;
    case 8:
        strncpy(mic64,mic,9);
        break;
    case 16:
        strncpy(mic128,mic,17);
        break;
    }
}

void MICSec::checkLength(char* mic) {
    if(type!=4 && type!=8 && type!=16){
        EV << "\n NO TYPE SET \n";
        return;
    }
    switch (type) {
    case 4:
        if (strlen(mic) != 4)
            //throw cRuntimeError("MIC length error");
            EV << "Mic length error!";
        break;
    case 8:
        if (strlen(mic) != 8)
            EV << "Mic length error!";
            //throw cRuntimeError("MIC length error");

        break;
    case 16:
        if (strlen(mic) != 16)
            EV << "Mic length error!";
            //throw cRuntimeError("MIC length error");
        break;
    }
}


