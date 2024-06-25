#ifndef GSTD_COMMONWIRE
#define GSTD_COMMONWIRE

#include <Arduino.h>


class commonFUNC

{
private:
public:
    commonFUNC( int gpio,int temp);
    void blink();
    void fade();
};

#endif