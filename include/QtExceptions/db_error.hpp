#pragma once

#include <QException>
#include <QSqlError>
#include <type_traits>

namespace QtExceptions
{
    class DbError;
}

class QtExceptions::DbError
: public QException
{
    QSqlError sql_error_;
    
public:
    DbError() = delete;
    DbError& operator=(const DbError& db_error);
    DbError(const DbError& db_error);
    DbError& operator=(DbError&& db_error);
    DbError(DbError&& db_error);
    explicit DbError(const QSqlError& sql_error);
    virtual ~DbError();
    
    void raise()const override;
    DbError* clone()const override;
    virtual const char* what()const noexcept;
    typename std::underlying_type<QSqlError::ErrorType>::type type()const;
};