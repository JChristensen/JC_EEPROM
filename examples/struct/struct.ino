// Arduino JC_EEPROM Library
// https://github.com/JChristensen/JC_EEPROM
// Copyright (C) 2022 by Jack Christensen and licensed under
// GNU GPL v3.0, https://www.gnu.org/licenses/gpl.html
//
// Example sketch to write a struct to EEPROM and read it back.

#include <JC_EEPROM.h>      // https://github.com/JChristensen/JC_EEPROM
#include <Streaming.h>      // https://github.com/janelia-arduino/Streaming

struct myStruct {
    int       a;
    long      b;
    float     c;
    double    d;
    byte      e;
    bool      f;
};

JC_EEPROM eep(JC_EEPROM::kbits_256, 1, 64);     // 24LC256

void setup()
{
    eep.begin();
    Serial.begin(115200);
    Serial << F( "\n" __FILE__ "\n" __DATE__ " " __TIME__ "\n" );

    Serial << "Writing\n";
    myStruct w { 1, 2, 3, 4, 5, true };
    eep.write(0, reinterpret_cast<byte*>(&w), sizeof(w));
    printStruct(w);

    Serial << "Reading\n";
    myStruct r;
    eep.read(0, reinterpret_cast<byte*>(&r), sizeof(r));
    printStruct(r);
}

void loop() {}

void printStruct(myStruct s)
{
    Serial << s.a << ' ' << s.b << ' ' << s.c << ' ' << s.d << ' ';
    Serial << s.e << ' ' << s.f << endl;
}
