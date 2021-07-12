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
#include <QException>
#include <string>

namespace QtExceptions
{
    class RunTimeError;   
}

class QtExceptions::RunTimeError
: public QException
{
    std::string err_str_;
    
public:
    RunTimeError() = delete;
    RunTimeError& operator=(const RunTimeError& run_time_error);
    RunTimeError(const RunTimeError& run_time_error);
    RunTimeError& operator=(RunTimeError&& run_time_error);
    RunTimeError(RunTimeError&& run_time_error);
    explicit RunTimeError(const std::string& str);
    virtual ~RunTimeError();
    
    void raise()const override;
    RunTimeError* clone()const override;
    virtual const char* what() const noexcept;
};
