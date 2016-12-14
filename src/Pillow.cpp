#include "Pillow.h"

void Pillow::setup() {
    static string prefix = "cu.usbmodem";

    // print device list
    serial.listDevices();

    // get devices
    vector <ofSerialDeviceInfo> deviceList = serial.getDeviceList();

    // look for a device that sounds like an arduino
    for(ofSerialDeviceInfo d: deviceList) {
        if(d.getDeviceName().compare(0, prefix.size(), prefix) == 0) {
            serial.setup(d.getDeviceID(), 9600);
            connected = true;
            return;
        }
    }
    
    ofLog(OF_LOG_NOTICE, "No Arduino connected!");
}

string Pillow::readString() {
    static string str;
    stringstream ss;
    int ch;

    // read until zero
    while ((ch=serial.readByte()) > 0 && ch != '\n') {
        ss << ch;
    }

    // get string
    str += ss.str();

    // finish on newline
    if (ch=='\n') {
        string tmp=str;
        str="";
        return tmp;
    }

    // otherwise return empty string
    return "";
}

void Pillow::update() {
    // skip if not connected
    if(!connected) {
        return;
    }

    // read string
    string str = readString();

    // return if empty
    if(str == "") {
        return;
    }

    // split on comma
    vector<string> values = ofSplitString(str, ",");

    // check list size
    if(values.size() != 5) {
        return;
    }

    // read and set values
    for(int i=0; i<4; i++) {
        int v = ofToInt(values[i]);
        
        switch(i){
            case 0:
                forceLeft = v;
                break;
            case 1:
                forceRight = v;
                break;
            case 2:
                angleLeft = v;
                break;
            case 3:
                angleRight = v;
                break;
        }
    }
}

int Pillow::averageForce() {
    return (forceLeft + forceRight) / 2;
}

int Pillow::tilt() {
    return angleLeft - angleRight;
}

int Pillow::smoothTilt() {
    return (int)ofMap(averageForce(), 0, 100, tilt(), 0);
}
