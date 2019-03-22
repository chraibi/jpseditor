/**
 * \file       sourcewidget.cpp
 * \date        Mar-13-2019
 * \version     v0.8.8
 * \author      Tao Zhong
 * \copyright   <2009-2019> Forschungszentrum Jülich GmbH. All rights reserved.
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
 * This class define a dock widget for sources
 *
 **/


#include "sourcewidget.h"
#include "ui_sourcewidget.h"
#include "src/models/jpssourcelistmodel.h"

#include <QDebug>

SourceWidget::SourceWidget(QWidget *parent, jpsGraphicsView *view, jpsDatamanager *dmanager) :
    QWidget(parent),
    ui(new Ui::SourceWidget)
{
    ui->setupUi(this);

    currentView = view;

    //Set-up model and listview for sources widget
    model = new JPSSourceListModel();
    model->setSourceList(currentView->getSources());
    ui->sourcesListView->setModel(model);
    ui->sourcesListView->setEditTriggers(QAbstractItemView::DoubleClicked );
    showSource();

    connect(currentView, SIGNAL(sourcesChanged()), this, SLOT(showSource()));
    connect(ui->sourcesListView, SIGNAL(clicked(const QModelIndex &)), this, SLOT(showSourceInformation()));
    connect(ui->applyButton, SIGNAL(clicked(bool)),this, SLOT(applySourceInformation()));
}

SourceWidget::~SourceWidget()
{
    delete ui;
}

void SourceWidget::showSource()
{
    model->setSourceList(currentView->getSources());
    ui->sourcesListView->setModel(model);
}

void SourceWidget::showSourceInformation()
{
    qDebug(">> Enter showSourceInfomation::showSourceInformation");
    if(ui->sourcesListView->currentIndex().isValid())
    {
//        ui->sourcesListView->setFocus(Qt::MouseFocusReason);

        QModelIndex index = ui->sourcesListView->currentIndex();
        auto source = currentView->getSources().at(index.row());

        ui->IDlineEdit->setText(QString::number(source->getId()));
        ui->agents_maxLineEdit->setText(source->getAgents_max());
        ui->captionLineEdit->setText(source->getCaption());
        ui->frequencyLineEdit->setText(source->getFrequency());
        ui->group_IDLineEdit->setText(source->getGroup_id());
        ui->N_createLineEdit->setText(source->getN_create());
        ui->percentLineEdit->setText(source->getPercent());
        ui->rateLineEdit->setText(source->getRate());
        ui->startYLineEdit->setText(source->getStartY());
        ui->startXLineEdit->setText(source->getStartX());
        ui->timeLineEdit->setText(source->getTime());
        ui->time_minLineEdit->setText(source->getTime_min());
        ui->time_maxLineEdit->setText(source->getTime_max());
        ui->greedyLineEdit->setText(source->getGreedy());
        ui->X_MinLineEdit->setText(QString::number(source->getX_min()));
        ui->X_MaxllneEdit->setText(QString::number(source->getX_max()));
        ui->Y_MinLineEdit->setText(QString::number(source->getY_min()));
        ui->Y_MaxLineEdit->setText(QString::number(source->getY_max()));

        if(source->isBeSaved())
        {
            ui->isSaveButton->setChecked(true);
        } else
        {
            ui->isSaveButton->setChecked(false);
        }
    }
    qDebug("<< Leave showSourceInfomation::showSourceInformation");
}

void SourceWidget::applySourceInformation()
{
    qDebug(">> Enter SourceWidget::applySourceInformation");
    QModelIndex index = ui->sourcesListView->currentIndex();
    auto source = currentView->getSources().at(index.row());

    if(ui->sourcesListView->currentIndex().isValid())
    {
        source->setId(ui->IDlineEdit->text().toInt());
        source->setAgents_max(ui->agents_maxLineEdit->text());
        source->setCaption(ui->captionLineEdit->text());
        source->setFrequency(ui->frequencyLineEdit->text());
        source->setGroup_id(ui->group_IDLineEdit->text());
        source->setN_create(ui->N_createLineEdit->text());
        source->setPercent(ui->percentLineEdit->text());
        source->setRate(ui->rateLineEdit->text());
        source->setStartX(ui->startXLineEdit->text());
        source->setStartY(ui->startYLineEdit->text());
        source->setTime(ui->timeLineEdit->text());
        source->setTime_max(ui->time_maxLineEdit->text());
        source->setTime_min(ui->time_minLineEdit->text());
        source->setX_min(ui->X_MinLineEdit->text().toFloat());
        source->setX_max(ui->X_MaxllneEdit->text().toFloat());
        source->setY_min(ui->Y_MinLineEdit->text().toFloat());
        source->setY_max(ui->Y_MaxLineEdit->text().toFloat());

        if(ui->isSaveButton->isChecked())
        {
            source->setBeSaved(true);
        } else
        {
            source->setBeSaved(false);
        }
    }

    qDebug("<< Leave SourceWidget::applySourceInformation");
}
