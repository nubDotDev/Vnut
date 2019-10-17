#pragma once

#include "Vnut/Core/Core.h"
#include "Event.h"

namespace Vnut {

	class VNUT_API WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() {}

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "WindowCloseEvent";
			return ss.str();
		}
	};

	class VNUT_API WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int height) : m_width(width), m_height(height) {}

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent: " << m_width << ", " << m_height;
			return ss.str();
		}
	private:
		unsigned int m_width, m_height;
	};

	class VNUT_API WindowMoveEvent : public Event
	{
	public:
		WindowMoveEvent(int xPos, int yPos) : m_xPos(xPos), m_yPos(yPos) {}

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "WindowMoveEvent: " << m_xPos << ", " << m_yPos;
			return ss.str();
		}
	private:
		int m_xPos, m_yPos;
	};

}