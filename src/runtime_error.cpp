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
#include <QtExceptions/runtime_error.hpp>
#include <utility>

QtExceptions::RunTimeError::RunTimeError(const std::string& str)
: err_str_(str)
{
    
}

QtExceptions::RunTimeError& QtExceptions::RunTimeError::operator=(const QtExceptions::RunTimeError& run_time_error)
{
    this->err_str_ = run_time_error.err_str_;
    return *this;
}

QtExceptions::RunTimeError::RunTimeError(const QtExceptions::RunTimeError& run_time_error)
{
    *this = run_time_error;
}

QtExceptions::RunTimeError& QtExceptions::RunTimeError::operator=(QtExceptions::RunTimeError&& run_time_error)
{
    this->err_str_ = std::move(run_time_error.err_str_);
    return *this;
}

QtExceptions::RunTimeError::RunTimeError(QtExceptions::RunTimeError&& run_time_error)
{
    *this = std::move(run_time_error);
}

QtExceptions::RunTimeError::~RunTimeError()
{

}

void QtExceptions::RunTimeError::raise()const
{ 
    throw *this; 
}

QtExceptions::RunTimeError* QtExceptions::RunTimeError::clone()const
{ 
    return new QtExceptions::RunTimeError(*this); 
}

const char* QtExceptions::RunTimeError::what() const noexcept
{ 
    return this->err_str_.c_str(); 
}
