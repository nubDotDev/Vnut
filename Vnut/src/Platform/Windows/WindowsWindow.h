#pragma once

#include <GLFW/glfw3.h>

#include "Vnut/Core/Window.h"

namespace Vnut {

	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(std::string title = "Vnut Engine", unsigned int width = 1280, unsigned int height = 720);

		void onUpdate() override;

		inline std::string getTitle() const override { return m_data.title; }
		inline unsigned int getWidth() const override { return m_data.width; }
		inline unsigned int getHeight() const override { return m_data.height; }

		inline bool isVSync() const override { return m_data.vSync; }
		void setVSync(bool enabled) override;

		inline void* getNativeWindow() const override { return m_window; }
	private:
		struct WindowData
		{
			std::string title;
			unsigned int width, height;
			bool vSync;
		};

		GLFWwindow* m_window;
		WindowData m_data;
	};

}