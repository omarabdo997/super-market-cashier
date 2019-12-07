#include "timestamp.h"

TimeStamp::TimeStamp()
{

}
QString TimeStamp::get_formate()
{
    return date.currentDate().toString("dd.MM.yyyy")+"-"+time.currentTime().toString("hh:mm ap");
}
