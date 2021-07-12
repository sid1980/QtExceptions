#include <QTest>
#include <run_time_error_test.hpp>

int main(int argc, char** argv)
{   
    int status = 0;
    
    {
        RunTimeErrorTest tc;
        status |= QTest::qExec(&tc, argc, argv);
    }
    //{
    //    MyTest2 tc;
    //    status |= QTest::qExec(&tc, argc, argv);
    //}
    
    return status;
}
