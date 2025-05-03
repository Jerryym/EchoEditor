#pragma once
#include <QTextEdit>
#include <NestUI.h>

namespace EchoEditor {

	/// @brief 控制台Dock: 一般用于Log输出
	class ConsoleDock : public NestUI::DockWidget
	{
	public:
		ConsoleDock(QWidget* parent = nullptr);
		virtual ~ConsoleDock() = default;

	public:
		/// @brief 清空LogWidget中的数据
		virtual void clearWidget() override;
		/// @brief 刷新DockWidget
		virtual void refreshWidget() override;

		/// @brief 获取Log输出控件
		/// @return 
		inline QTextEdit* getLogWidget() { return m_LogWidget; }

	private:
		QTextEdit* m_LogWidget;
	};

}
