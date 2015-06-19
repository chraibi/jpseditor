#include "jpscrossing.h"


jpsCrossing::jpsCrossing(jpsLineItem *line)
{
    cLine=line;
    _isExit=false;
}

QList<jpsRoom *> jpsCrossing::get_roomList()
{
    return roomList;
}


QString jpsCrossing::get_name()
{
    return cName;
}

int jpsCrossing::get_id()
{
    return cId;
}

void jpsCrossing::set_id(int id)
{
    cId=id;
}

jpsLineItem *jpsCrossing::get_cLine()
{
    return cLine;
}

void jpsCrossing::change_name(QString name)
{
    cName=name;
}

void jpsCrossing::add_rooms(jpsRoom *room1, jpsRoom *room2)
{
    roomList.clear();
    roomList.push_back(room1);
    if (room2!=0L)
    {
        roomList.push_back(room2);
    }


}

void jpsCrossing::SetStatExit(bool stat)
{
    _isExit=stat;
}

bool jpsCrossing::IsExit()
{
    return _isExit;
}
