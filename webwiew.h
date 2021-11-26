#pragma once

#include <QtCore/qurl.h>
#include <QtWebEngineWidgets/qwebengineview.h>
#include <QtGui/qpainter.h>
#include <QtWidgets/qwidget.h>
#include <QtWidgets/QApplication>

#define DllExport   __declspec( dllexport )
#define EXTERN_DLL_EXPORT extern "C" __declspec(dllexport)

class webwiew  :public QWidget
{
	Q_OBJECT
public:
	 webwiew(QWidget* parent = Q_NULLPTR);
	 DllExport void loadpage(std::string url);

public slots:
	void ticking(bool isOk);
private:

	QWebEngineView* m_webView;
	QTimer* times;
};
EXTERN_DLL_EXPORT int leweb(std::string curl);
EXTERN_DLL_EXPORT webwiew* ww();

