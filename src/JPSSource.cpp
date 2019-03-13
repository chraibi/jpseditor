//
// Created by sainho93 on 2019-03-13.
//

#include "jpssource.h"

JPSSource::JPSSource(QGraphicsRectItem *source)
{
    sourceRect = source;
    caption="Source " + QString::number(id);
    agents_max = "0";
    frequency = "0";
    group_id = "0";
    N_create = "0";
    percent = "0";
    rate = "0";
    startX = "0";
    startY = "0";
    time = "0";
    time_max = "0";
    time_min = "0";
    greedy = "false";

}

JPSSource::~JPSSource()
{

}

void JPSSource::setId(int id) {
    JPSSource::id = id;
}

QGraphicsRectItem *JPSSource::getSourceRect() const {
    return sourceRect;
}

void JPSSource::setSourceRect(QGraphicsRectItem *sourceRect) {
    JPSSource::sourceRect = sourceRect;
}

const QString &JPSSource::getFrequency() const {
    return frequency;
}

void JPSSource::setFrequency(const QString &frequency) {
    JPSSource::frequency = frequency;
}

const QString &JPSSource::getN_create() const {
    return N_create;
}

void JPSSource::setN_create(const QString &N_create) {
    JPSSource::N_create = N_create;
}

const QString &JPSSource::getPercent() const {
    return percent;
}

void JPSSource::setPercent(const QString &percent) {
    JPSSource::percent = percent;
}

const QString &JPSSource::getRate() const {
    return rate;
}

void JPSSource::setRate(const QString &rate) {
    JPSSource::rate = rate;
}

const QString &JPSSource::getTime_min() const {
    return time_min;
}

void JPSSource::setTime_min(const QString &time_min) {
    JPSSource::time_min = time_min;
}

const QString &JPSSource::getTime_max() const {
    return time_max;
}

void JPSSource::setTime_max(const QString &time_max) {
    JPSSource::time_max = time_max;
}

const QString &JPSSource::getAgents_max() const {
    return agents_max;
}

void JPSSource::setAgents_max(const QString &agents_max) {
    JPSSource::agents_max = agents_max;
}

const QString &JPSSource::getGroup_id() const {
    return group_id;
}

void JPSSource::setGroup_id(const QString &group_id) {
    JPSSource::group_id = group_id;
}

const QString &JPSSource::getCaption() const {
    return caption;
}

void JPSSource::setCaption(const QString &caption) {
    JPSSource::caption = caption;
}

const QString &JPSSource::getGreedy() const {
    return greedy;
}

void JPSSource::setGreedy(const QString &greedy) {
    JPSSource::greedy = greedy;
}

const QString &JPSSource::getTime() const {
    return time;
}

void JPSSource::setTime(const QString &time) {
    JPSSource::time = time;
}

const QString &JPSSource::getStartX() const {
    return startX;
}

void JPSSource::setStartX(const QString &startX) {
    JPSSource::startX = startX;
}

const QString &JPSSource::getStartY() const {
    return startY;
}

void JPSSource::setStartY(const QString &startY) {
    JPSSource::startY = startY;
}

qreal JPSSource::getX_min() const {
    return x_min;
}

void JPSSource::setX_min(qreal x_min) {
    JPSSource::x_min = x_min;
}

qreal JPSSource::getX_max() const {
    return x_max;
}

void JPSSource::setX_max(qreal x_max) {
    JPSSource::x_max = x_max;
}

qreal JPSSource::getY_min() const {
    return y_min;
}

void JPSSource::setY_min(qreal y_min) {
    JPSSource::y_min = y_min;
}

qreal JPSSource::getY_max() const {
    return y_max;
}

void JPSSource::setY_max(qreal y_max) {
    JPSSource::y_max = y_max;
}


