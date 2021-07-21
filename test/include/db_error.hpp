#pragma once
#include <QTest>
#include <QObject>
#include <QSqlError>
#include <QString>

#include <QtExceptions/qt_exceptions.hpp>

class DbErrorTest
: public QObject
{
    Q_OBJECT
    
    const QSqlError sql_error_;
    QtExceptions::DbError test_target_;

public:
    DbErrorTest();
    ~DbErrorTest();

private slots:
    void initTestCase();// 今回は使用しない
    void raise_test();// raiseメソッドのテスト
    void clone_test();// cloneメソッドのテスト
    void what_test();// whatメソッドのテスト
    void type_test();// typeメソッドのテスト
    void cleanupTestCase();// 今回は使用しない
};
