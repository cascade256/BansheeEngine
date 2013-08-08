#pragma once

#include "BsEditorPrerequisites.h"
#include <boost/signal.hpp>

namespace BansheeEditor
{
	class EditorWidgetContainer
	{
	public:
		EditorWidgetContainer(BS::GUIWidget* parent);
		virtual ~EditorWidgetContainer();

		void add(EditorWidget& widget);
		void remove(EditorWidget& widget);
		void move(EditorWidget& widget, CM::UINT32 newPosition);

		void setSize(CM::UINT32 width, CM::UINT32 height);
		void setPosition(CM::INT32 x, CM::INT32 y);

		CM::UINT32 getNumWidgets() const { return (CM::UINT32)mWidgets.size(); }
		BS::GUIWidget& getParentWidget() const { return *mParent; }

		void _notifyWidgetDestroyed(EditorWidget* widget);

		boost::signal<void()> onWidgetClosed;
	private:
		GUITabbedTitleBar* mTitleBar;
		BS::GUIWidget* mParent;
		CM::INT32 mX, mY;
		CM::UINT32 mWidth, mHeight;
		CM::Vector<EditorWidget*>::type mWidgets;
		CM::INT32 mActiveWidget;

		static const CM::UINT32 TitleBarHeight;

		void setActiveWidget(CM::UINT32 idx);
		void tabActivated(CM::UINT32 idx);
		void tabClosed(CM::UINT32 idx);
	};
}