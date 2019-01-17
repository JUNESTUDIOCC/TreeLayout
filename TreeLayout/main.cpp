#include "CMainwindow.h"
#include <QtWidgets/QApplication>



int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	CMainwindow w;
	w.show();

	return a.exec();
}
