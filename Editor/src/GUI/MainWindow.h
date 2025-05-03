#pragma once
#include <NestUI.h>

namespace EchoEditor {

	/// @brief 主窗口
	class MainWindow : public NestUI::NestMainWindow
	{
	public:
		MainWindow(const NestUI::sWindowProp& sProp, QWidget* parent = nullptr);
		virtual ~MainWindow() = default;

	public:
		/// @brief 获取窗口宽度
		virtual uint32_t GetWidth() const { return m_sProp.m_nWidth; }
		/// @brief 获取窗口高度
		virtual uint32_t GetHeight() const { return m_sProp.m_nHeight; }
		/// @brief 获取窗口标题
		virtual const QString& GetTitle() const override { return m_sProp.m_STitle; }

	private:
		/// @brief 初始化
		void Init();
		/// @brief 初始化控制台Dock
		void InitConsoleDockWidget();

		/// @brief 初始化RibbonBar
		void InitRibbonBar();

	private:
		NestUI::sWindowProp m_sProp;
		NestUI::DockWidgetManager* m_dockManager;
	};

}
