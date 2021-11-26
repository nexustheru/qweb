#include <QtWidgets/QApplication>
#include "webwiew.h"
#include "ultra.h"

using namespace std;

int main(int argc, char* argv[])
{
   // QApplication a(argc, argv);
   
       // webwiew w;
       // w.show();
    ultra* ul = new ultra();
    ul->start();
    ul->loadlink("http://www.google.com");
    while (!ul->loaded())
    {
         ul->update();
    }

    ul->takescreenshoot();
    //return a.exec();
    
    system("PAUSE");
}
