#pragma once

#include "vnutpch.h"

#include "Core.h"

namespace Vnut {

	class VNUT_API Window
	{
	public:
		virtual ~Window() {}

		virtual void onUpdate() = 0;

		virtual std::string getTitle() const = 0;
		virtual unsigned int getWidth() const = 0;
		virtual unsigned int getHeight() const = 0;

		virtual bool isVSync() const = 0;
		virtual void setVSync(bool enabled) = 0;
		
		virtual void* getNativeWindow() const = 0;
	};

}