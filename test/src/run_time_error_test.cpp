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
    QtExceptions::RunTimeError temp1("abcde");
    QtExceptions::RunTimeError* temp2 = temp1.clone();
    QVERIFY(!std::strcmp(temp1.what(), temp2->what()));
    delete temp2;
}

void RunTimeErrorTest::what_test()
{
    QVERIFY(!std::strcmp(err_reason_, this->test_target_.what()));
}