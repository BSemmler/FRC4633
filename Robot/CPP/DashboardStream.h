#ifndef DASHBOARDSTREAM_H
#define DASHBOARDSTREAM_H

/*
 *  DashboardStream dash;
 *
 *  dash(L1) << "Just like std::cout !" << std::endl;
 *  dash(L4) << "This is the 4th line." << std::endl;
 *  dash() << "This is the next line (5th)." << std::endl;
 */

#include <sstream>
#include "DriverStationLCD.h"

enum DashboardLine {
    L1 = DriverStationLCD::kUser_Line1,
    L2 = DriverStationLCD::kUser_Line2,
    L3 = DriverStationLCD::kUser_Line3,
    L4 = DriverStationLCD::kUser_Line4,
    L5 = DriverStationLCD::kUser_Line5,
    L6 = DriverStationLCD::kUser_Line6
};

class DashboardStream
{
public:
    typedef DashboardLine Line;
    
    DashboardStream();

    std::ostream& operator ()();
    std::ostream& operator ()(Line line);
    
private:
    class Buf : public std::stringbuf
    {
        DriverStationLCD* _lcd;
    public:
        Line _line;
        
        Buf();
        int sync();
        void printLine(const char*);
        void nextLine();
    } _buf;
    std::ostream _stream;
};

#endif
