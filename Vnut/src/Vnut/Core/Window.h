#pragma once

#include "vnutpch.h"

namespace Vnut {

	class Window
	{
	public:
		virtual ~Window() {}

		virtual void onUpdate() = 0;

		virtual std::string getTitle() const = 0;
		virtual unsigned int getWidth() const = 0;
		virtual unsigned int getHeight() const = 0;
		virtual bool isVSync() const = 0;
		virtual void setVSync(bool enabled) = 0;
	};

}