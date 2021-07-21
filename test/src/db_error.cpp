#include <db_error.hpp>
#include <cstring>

DbErrorTest::DbErrorTest()
: sql_error_("driver_text", "data_base_text", QSqlError::ConnectionError, "code")
, test_target_(this->sql_error_)
{

}
    
DbErrorTest::~DbErrorTest()
{

}

/*----------------------
    今回は使用しない
*///--------------------
void DbErrorTest::initTestCase()
{
    
}

/*---------------------------
    raiseメソッドのテスト
*///-------------------------
void DbErrorTest::raise_test()
{
    try{
        this->test_target_.raise();
        QVERIFY(false);
    }catch(const QtExceptions::DbError& err)
    {
        QVERIFY(true);
    }
}

/*---------------------------
    cloneメソッドのテスト
*///-------------------------
void DbErrorTest::clone_test()
{
    auto* temp = this->test_target_.clone();
    QVERIFY(!std::strcmp(this->test_target_.what(), temp->what()));
    QVERIFY(this->test_target_.type() == temp->type());
    delete temp;
}

/*--------------------------
    whatメソッドのテスト
*///------------------------
void DbErrorTest::what_test()
{
    auto str = QStringLiteral("data_base_text") + QStringLiteral(" ") + QStringLiteral("driver_text");
    QVERIFY(str == this->test_target_.what());
}

/*--------------------------
    typeメソッドのテスト
*///------------------------
void DbErrorTest::type_test()
{
    QVERIFY(this->test_target_.type() == QSqlError::ConnectionError);
}

/*----------------------
    今回は使用しない
*///--------------------
void DbErrorTest::cleanupTestCase()
{

}
