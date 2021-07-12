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
#include <run_time_error_test.hpp>
#include <QtExceptions/qt_exceptions.hpp>
#include <QString>
#include <cstring>

const static char err_reason_[] = "err_reason_";

RunTimeErrorTest::RunTimeErrorTest()
: test_target_(err_reason_)
{

}

RunTimeErrorTest::~RunTimeErrorTest()
{

}

void RunTimeErrorTest::raise_test()
{
    try{
        this->test_target_.raise();
        QVERIFY(false);
    }catch(const QtExceptions::RunTimeError& err)
    {
        QVERIFY(true);
    }
}

void RunTimeErrorTest::clone_test()
{
    auto temp1 = QtExceptions::RunTimeError("abcde");
    auto* temp2 = temp1.clone();
    QVERIFY(!std::strcmp(temp1.what(), temp2->what()));
    delete temp2;
}

void RunTimeErrorTest::what_test()
{
    QVERIFY(!std::strcmp(err_reason_, this->test_target_.what()));
}