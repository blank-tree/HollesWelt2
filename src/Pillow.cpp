#include "Pillow.h"

void Pillow::setup() {
    static string prefix = "cu.usbmodem";

    serial.listDevices();
    
    vector <ofSerialDeviceInfo> deviceList = serial.getDeviceList();
    
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
    char ch;
    int ttl=1000;
    
    while ((ch=serial.readByte()) > 0 && ttl > 0 && ch != '\n') {
        ss << ch;
    }
    
    str += ss.str();
    
    if (ch=='\n') {
        string tmp=str;
        str="";
        return tmp;
    }
    
    return "";
}

void Pillow::update() {
    if(!connected) {
        return;
    }
    
    string str = readString();
    
    if(str == "") {
        return;
    }
    
    vector<string> values = ofSplitString(str, ",");
    
    if(values.size() != 5) {
        return;
    }
    
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

int Pillow::betterTilt() {
    return (int)ofMap(averageForce(), 0, 100, tilt(), 0);
}
