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
#include <QTest>
#include <run_time_error.hpp>
#include <db_error.hpp>

int main(int argc, char** argv)
{   
    int status = 0;
    
    {
        RunTimeErrorTest tc;
        status |= QTest::qExec(&tc, argc, argv);
    }
    
    {
        DbErrorTest tc;
        status |= QTest::qExec(&tc, argc, argv);
    }
    
    return status;
}
