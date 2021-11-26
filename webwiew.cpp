#include "webwiew.h"
#include <QtWidgets/QApplication>
#include <QtGui/qpixmap.h>
#include <QtCore/qtimer.h>
#include <QtCore/qsize.h>
#include <iostream>
#include <QtWebEngineCore/qwebenginepage.h>
#include <QtWebEngineCore/qwebenginesettings.h>

     webwiew::webwiew(QWidget* parent)
        : QWidget(parent)
    {
        setAttribute(Qt::WA_DontShowOnScreen, true);
        ui.setupUi(this);
        m_webView = new QWebEngineView(parent);
        m_webView->setAttribute(Qt::WA_DontShowOnScreen, true);
        m_webView->setAttribute(Qt::WA_DeleteOnClose, true);
        m_webView->page()->settings()->setAttribute(QWebEngineSettings::JavascriptEnabled, true);
        m_webView->page()->settings()->setAttribute(QWebEngineSettings::ScreenCaptureEnabled, true);
        m_webView->page()->settings()->setAttribute(QWebEngineSettings::FullScreenSupportEnabled, true);

        connect(m_webView, SIGNAL(loadFinished(bool)), this, SLOT(ticking(bool)));

    }
     //extern "C" __declspec(dllexport) int __stdcall Add(int a, int b) { ... }
      void webwiew::loadpage(std::string url)
     {
         m_webView->load(QUrl(QString::fromStdString(url)));
         m_webView->show();
     }

     void webwiew::ticking(bool isOk)
    {

        if (isOk == true)
        {

            m_webView->activateWindow();
            m_webView->page()->triggerAction(QWebEnginePage::SelectAll);
            std::cout << "load is finished" << std::endl;
            QSize scize = m_webView->page()->contentsSize().toSize();
            m_webView->resize(scize);
            QImage img(scize.width(), scize.height(), QImage::Format_ARGB32);
            QPainter p(&img);
            QPixmap img1 = QPixmap(scize.width(), scize.height());
            m_webView->render(&img1);
            m_webView->render(&p);  // render the webEngineView
            img.save("html2.png");
            img1.save("html12.png");
            p.end();
        }
    }

     webwiew* ww()
     {
         webwiew* leweb = new webwiew();
         return leweb;
     }

     int leweb(std::string curl)
     {
         try
         {
         int argc = 0;
         char* argv[] = { (char*)"" };
         QApplication a(argc, argv);
         webwiew* w= new webwiew();
         w->show();
         w->loadpage(curl);
         return a.exec();
         }
         catch (std::exception* ex)
         {
             std::cout << ex->what() << std::endl;
             return 0;
         }
         system("PAUSE");
     }