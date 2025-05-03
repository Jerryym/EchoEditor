#include "editorpch.h"
#include "ConsoleDock.h"

namespace EchoEditor {

	ConsoleDock::ConsoleDock(QWidget* parent)
		: NestUI::DockWidget(parent)
	{
		//设置标题
		setWindowTitle("Console");

		//初始化LogWidget
		m_LogWidget = new QTextEdit(this);
		m_LogWidget->setReadOnly(true);

		//设置栅格布局
		QWidget* dockWidgetContents = new QWidget(this);
		QGridLayout* layout = new QGridLayout(dockWidgetContents);
		layout->addWidget(m_LogWidget, 0, 0, 1, 1);
		setWidget(dockWidgetContents);

		//初始化Log
		NestApp::Log::Init(m_LogWidget);
		NEST_CORE_WARN("Initialiazed Log!");
		NEST_CLIENT_INFO("Hello Echo Engine!");
	}

	void ConsoleDock::clearWidget()
	{
		m_LogWidget->clear();
	}

	void ConsoleDock::refreshWidget()
	{

	}
}
