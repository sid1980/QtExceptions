#include <QtExceptions/runtime_error.hpp>

QtExceptions::RunTimeError::RunTimeError(const QString& str)
: err_str_(str)
{}

QtExceptions::RunTimeError::~RunTimeError()
{}

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
    return this->err_str_.toLocal8Bit().constData(); 
}
