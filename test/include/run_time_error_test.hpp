#pragma once
#include <QTest>
#include <QObject>
#include <QtExceptions/qt_exceptions.hpp>

class RunTimeErrorTest
: public QObject
{
    Q_OBJECT
    
    QtExceptions::RunTimeError test_target_;

public:
    RunTimeErrorTest();
    ~RunTimeErrorTest();

private slots:
    void raise_test();
    void clone_test();
    void what_test();

};