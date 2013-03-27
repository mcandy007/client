#pragma once

#include "../Shared.h"
#include "ui_InspectorAudioWidget.h"

#include "Commands/AudioCommand.h"
#include "Models/LibraryModel.h"

#include <QtCore/QEvent>
#include <QtCore/QObject>
#include <QtCore/QString>

#include <QtGui/QWidget>

class WIDGETS_EXPORT InspectorAudioWidget : public QWidget, Ui::InspectorAudioWidget
{
    Q_OBJECT

    public:
        explicit InspectorAudioWidget(QWidget* parent = 0);

    protected:
        virtual bool eventFilter(QObject* target, QEvent* event);

    private:
        LibraryModel* model;
        AudioCommand* command;

        void loadDirection();
        void loadTransition();
        void loadTween();
        void blockAllSignals(bool block);

        Q_SLOT void transitionChanged(QString);
        Q_SLOT void durationChanged(int);
        Q_SLOT void directionChanged(QString);
        Q_SLOT void tweenChanged(QString);
        Q_SLOT void loopChanged(int);
        Q_SLOT void useAutoChanged(int);
        Q_SLOT void triggerOnNextChanged(int);
        Q_SLOT void resetTransition(QString);
        Q_SLOT void resetDuration(QString);
        Q_SLOT void resetDirection(QString);
        Q_SLOT void resetTween(QString);
        Q_SLOT void resetLoop(QString);
        Q_SLOT void resetTriggerOnNext(QString);
        Q_SLOT void resetUseAuto(QString);
};
