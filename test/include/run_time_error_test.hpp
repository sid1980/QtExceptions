/*-------------------------------------------------------------------------------
                           Copyright (c) 2021 DIODE.
    
    This file is part of QtExceptions.
    
    QtExceptions is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    QtExceptions is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.
    You should have received a copy of the GNU Lesser General Public License
    along with QtExceptions.  If not, see <https://www.gnu.org/licenses/>.
*///-----------------------------------------------------------------------------
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