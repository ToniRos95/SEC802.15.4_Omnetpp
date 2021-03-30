/*
 * MICSec.h
 *
 *  Created on: Mar 27, 2021
 *      Author: lollo
 */

#ifndef MICSEC_H_
#define MICSEC_H_

class MICSec {

private:
    char mic32[5];  //4char + /0
    char mic64[9];
    char mic128[17];
    void checkLength(char* mic);
    int type;

public:

    MICSec();
    MICSec(int type);
    virtual ~MICSec();

    int getType();
    char* getMicAuth();
    void setMic(char* mic);
    //void checkLength(char* mic);

};

#endif /* MICSEC_H_ */

