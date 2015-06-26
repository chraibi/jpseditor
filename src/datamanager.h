/**
 * \file        datamanager.h
 * \date        Jun 26, 2015
 * \version     v0.7
 * \copyright   <2009-2015> Forschungszentrum Jülich GmbH. All rights reserved.
 *
 * \section License
 * This file is part of JuPedSim.
 *
 * JuPedSim is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * JuPedSim is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with JuPedSim. If not, see <http://www.gnu.org/licenses/>.
 *
 * \section Description
 * The class is responsible for handling and organisation of rooms, walls and doors. Further more
 * it handles the reading and writing of dxf and xml files.
 *
 **/


#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include<QtGui>
#include <QApplication>
#include <QGraphicsView>
#include <QMessageBox>
#include "rooms.h"
#include "jpscrossing.h"
#include "jpsLineItem.h"
#include "jpsexit.h"
#include "jpsobstacle.h"
#include "GraphicView.h"


#include "../dxflib/src/dl_creationadapter.h"
#include "../dxflib/src/dl_dxf.h"


class jpsDatamanager: public DL_CreationAdapter
{
public:
    jpsDatamanager(QWidget* parent=0L, jpsGraphicsView* view=0L);
    ~jpsDatamanager();
    ///Room
    QList<jpsRoom *> get_roomlist();
    void new_room();
    void remove_room(jpsRoom* room);
    void change_roomName(jpsRoom* room, QString name);
    void remove_all_rooms();
    ///Obstacle
    QList<jpsObstacle *> get_obstaclelist();
    void new_obstacle();
    void remove_obstacle(jpsObstacle* obs);
    void change_obstacleName(jpsObstacle* obs, QString name);
    void remove_all_obstacles();
    ///Crossing
    QList<jpsCrossing *> get_crossingList();
    void new_crossing(QList<jpsLineItem *> newCrossing);
    void new_crossing(jpsLineItem* newCrossing);
    void remove_crossing(jpsCrossing* crossing);
    void change_crossingName(jpsCrossing* crossing, QString name);
    void remove_all_crossings();
    ///Exit
    QList<jpsExit *> get_exitList();
    void new_exit(QList<jpsLineItem *> newExits);
    void new_exit(jpsLineItem* newExit);
    void remove_exit(jpsExit* exit);
    void change_exitName(jpsExit* exit, QString name);
    void remove_all_exits();
    ///Landmark
    QList<jpsLandmark *> get_landmarks();
    void new_landmark(jpsLandmark * newlandmark);
    void remove_landmark(jpsLandmark* landmark);
    void change_LandmarkName(jpsLandmark* landmark, QString name);
    void remove_all_landmarks();
    ///
    void remove_all();
    void remove_marked_lines();
    void set_view(jpsGraphicsView* view);
    jpsGraphicsView* get_view();


    /// Auto Assign
    void AutoAssignCrossings();
    void AutoAssignExits();


    /// Read XML
    bool readXML(QFile &file);
    void parseSubRoom(QXmlStreamReader &xmlReader);
    void parseWalls(QXmlStreamReader &xmlReader,jpsRoom* room);
    void parseWalls(QXmlStreamReader &xmlReader,jpsObstacle* room);
    void parseCrossings(QXmlStreamReader &xmlReader);
    void parseTransitions(QXmlStreamReader &xmlReader);
    void parseObstacles(QXmlStreamReader &xmlReader, jpsRoom *room);

    /// Write XML
    void writeXML(QFile &file);
    void AutoSaveXML(QFile &file);
    void writeHeader(QXmlStreamWriter *stream);
    void writeRooms(QXmlStreamWriter *stream, QList<jpsLineItem* >& lines);
    void AutoSaveRooms(QXmlStreamWriter *stream, QList<jpsLineItem* >& lines);
    void writeCrossings(QXmlStreamWriter *stream, QList<jpsLineItem* >& lines);
    void writeTransitions(QXmlStreamWriter *stream, QList<jpsLineItem* >& lines);
    void writeObstacles(QXmlStreamWriter *stream, jpsObstacle *obs, QList<jpsLineItem *> &lines);
    void writeNotAssignedWalls(QXmlStreamWriter *stream, QList<jpsLineItem* >& lines);
    void writeNotAssignedDoors(QXmlStreamWriter *stream, QList<jpsLineItem* >& lines);
    void writeNotAssignedExits(QXmlStreamWriter *stream, QList<jpsLineItem* >& lines);
    void writeLandmarks(QXmlStreamWriter *stream, QList<jpsLandmark* > &landmarks);

    /// Read DXF
    bool readDXF(std::string filename);
    virtual void addLine(const DL_LineData& d);
    /// write DXF
    void writeDXF(std::string filename);
    void writeDXFHeader(DL_Dxf* dxf, DL_WriterA *dw);
    void writeDXFTables(DL_Dxf* dxf, DL_WriterA *dw);
    void writeDXFBlocks(DL_Dxf* dxf, DL_WriterA *dw);
    void writeDXFEntities(DL_Dxf* dxf, DL_WriterA *dw);
    void writeDXFObjects(DL_Dxf* dxf, DL_WriterA *dw);

    QString check_printAbility();

private:
    QList<jpsRoom *> roomlist;
    QList<jpsObstacle *> obstaclelist;
    QList<jpsCrossing *> crossingList;
    QList<jpsExit *> exitList;
    QList<jpsLandmark* > landmarks;
    int room_id_counter;
    int obs_id_counter;
    QWidget* parent_widget;
    jpsGraphicsView* mView;



};


#endif // DATAMANAGER_H
