#include "module1.h"
#include "module2.h"
#include "module3.h"
#include <iostream>

using std::cout;

int main(int argc, char** argv)
{
    cout <<  "Hello world!" << "\n";

    cout << Module1::getMyName() << "\n";
    cout << Module2::getMyName() << "\n";

    {
        using namespace Module1;
        cout << getMyName() << "\n"; // (A)
        cout << Module2::getMyName() << "\n";
    }

    using namespace Module2; // (B)
    cout << getMyName() << "\n"; // COMPILATION ERROR (C)

    using Module2::getMyName;
    cout << getMyName() << "\n"; // (D)

    cout << Module3::getMyName() << "\n";
    return 0;
}
/* (1) Сделано, в CLion файлы .obj создаются в папке /cmake-build-debug/CMakeFiles/Lab0.dir
 * (2) Сделано
 * (3) При выполнении строки (A) вызывается функция getMyName из пространства имен Module1, (D) - из Module2
 * (4) Эта ошибка происходит из-за наложения пространств имен. Мы можем исправить её, выделив using namespace Module1 в отдельный блок
 * (5) Сделано
 * (6) Чтобы каждый раз не писать std::cout мы можем написать using std::cout до начала main или подключить пространство имен std
 */