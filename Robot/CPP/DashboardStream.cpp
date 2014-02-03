#include "WPILib.h"
#include "DashboardStream.h"

using namespace std;

DashboardStream::DashboardStream()
    :   _buf()
    ,   _stream(&_buf)
{
}

ostream& DashboardStream::operator () ()
{
    return _stream;
}

ostream& DashboardStream::operator () (Line line)
{
    _buf._line = line;
    return _stream;
}

DashboardStream::Buf::Buf()
    :   _lcd( DriverStationLCD::GetInstance() )
    ,   _line(L1)
{
}

int DashboardStream::Buf::sync()
{
    printLine(str().c_str());
    str("");
    return 0;
}

void DashboardStream::Buf::printLine(const char* sz)
{
    _lcd->PrintfLine((DriverStationLCD::Line)_line, "%s", sz);
    _lcd->UpdateLCD();
    nextLine();
}

void DashboardStream::Buf::nextLine()
{
    switch (_line)
    {
    default:
    case L6: _line = L1; break;
    case L1: _line = L2; break;
    case L2: _line = L3; break;
    case L3: _line = L4; break;
    case L4: _line = L5; break;
    case L5: _line = L6; break;
    }
}
