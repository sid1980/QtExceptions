#include <QtExceptions/db_error.hpp>
#include <utility>

QtExceptions::DbError& QtExceptions::DbError::operator=(const QtExceptions::DbError& db_error)
{
    this->sql_error_ = db_error.sql_error_;
    return *this;
}

QtExceptions::DbError::DbError(const QtExceptions::DbError& db_error)
{
    *this = db_error;
}

QtExceptions::DbError& QtExceptions::DbError::operator=(QtExceptions::DbError&& db_error)
{
    this->sql_error_ = std::move(db_error.sql_error_);
    return *this;
}

QtExceptions::DbError::DbError(QtExceptions::DbError&& db_error)
{
    *this = std::move(db_error);
}

QtExceptions::DbError::DbError(const QSqlError& sql_error)
{
    this->sql_error_ = sql_error;
}

QtExceptions::DbError::~DbError()
{
    
}

void QtExceptions::DbError::raise()const
{
    throw *this; 
}

QtExceptions::DbError* QtExceptions::DbError::clone()const
{
    return new QtExceptions::DbError(*this);
}

const char* QtExceptions::DbError::what() const noexcept
{
    return this->sql_error_.text().toLocal8Bit().data();
}

typename std::underlying_type<QSqlError::ErrorType>::type QtExceptions::DbError::type()const
{
    return this->sql_error_.type();
}