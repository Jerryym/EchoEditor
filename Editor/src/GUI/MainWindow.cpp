#include "MainWindow.h"

namespace EchoEditor {

	MainWindow::MainWindow(const NestUI::sWindowProp& sProp, QWidget* parent)
		: NestUI::NestMainWindow(parent), m_sProp(sProp)
	{
		//设置窗口标题
		setWindowTitle(sProp.m_STitle);
		//设置ICON
		setWindowIcon(QIcon(":/icons/EchoEngine.png"));
		//初始化窗口大小
		resize(QSize(sProp.m_nWidth, sProp.m_nHeight));
		showMaximized();
	}

}
