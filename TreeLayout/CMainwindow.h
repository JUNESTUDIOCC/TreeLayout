#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_CMainwindow.h"

class CMainwindow : public QMainWindow
{
	Q_OBJECT

public:
	CMainwindow(QWidget *parent = Q_NULLPTR);

private:
	Ui::CMainwindowClass ui;
};
