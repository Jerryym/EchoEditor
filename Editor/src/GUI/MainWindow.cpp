#include "MainWindow.h"
#include "ConsoleDock.h"

namespace EchoEditor {

	MainWindow::MainWindow(const NestUI::sWindowProp& sProp, QWidget* parent)
		: NestUI::NestMainWindow(parent), m_sProp(sProp)
	{
		m_dockManager = NestUI::DockWidgetManager::GetDockManager(this);
		Init();
	}

	void MainWindow::Init()
	{
		//设置窗口标题
		setWindowTitle(m_sProp.m_STitle);
		//设置ICON
		setWindowIcon(QIcon(":/icons/EchoEngine.png"));
		//初始化窗口大小
		resize(QSize(m_sProp.m_nWidth, m_sProp.m_nHeight));
		//最大化
		showMaximized();

		//初始化Console
		InitConsoleDockWidget();
		NEST_CLIENT_INFO("DockWidgetNum = {0}", m_dockManager->GetDockWidgetNum());

		//初始化RibbonBar
		InitRibbonBar();
	}

	void MainWindow::InitConsoleDockWidget()
	{
		ConsoleDock* pConsole = new ConsoleDock(this);
		NEST_CORE_ASSERT(pConsole == nullptr, "Create Console DockWidget Fail!");
		m_dockManager->AddDockWidget("ConSole", pConsole, Qt::BottomDockWidgetArea);
	}

	void MainWindow::InitRibbonBar()
	{
		SARibbonBar* pRibbon = ribbonBar();
		pRibbon->setContentsMargins(5, 0, 5, 0);
	}

}
