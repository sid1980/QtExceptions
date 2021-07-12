#pragma once
#include <QException>
#include <QString>

namespace QtExceptions
{
    class RunTimeError;   
}

class QtExceptions::RunTimeError
: public QException
{
    QString err_str_;
    
public:
    explicit RunTimeError(const QString& str);
    virtual ~RunTimeError();
    void raise()const override;
    RunTimeError* clone()const override;
    virtual const char* what() const noexcept;
};
