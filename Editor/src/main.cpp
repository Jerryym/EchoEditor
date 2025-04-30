#include <NestApp.h>
#include "SARibbonBar.h"
#include "GUI/MainWindow.h"

int main(int argc, char* argv[])
{
	SARibbonBar::initHighDpi();
	NestApp::Application app(argc, argv);

	//创建主窗口
	NestUI::sWindowProp sProp(1600, 900, "EchoEditor");
	EchoEditor::MainWindow* pMainWindow = new EchoEditor::MainWindow(sProp);
	app.SetMainWindow(pMainWindow);
	app.Run();

	return app.exec();
}
