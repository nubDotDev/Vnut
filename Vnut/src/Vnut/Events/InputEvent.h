#pragma once

#include "Vnut/Core/Core.h"
#include "Event.h"

namespace Vnut {

	// Key events

	class VNUT_API KeyEvent : public Event
	{
	public:
		inline int getKey() { return m_key; }
	protected:
		KeyEvent(int key) : m_key(key) {}

		int m_key;
	};

	class VNUT_API KeyPressEvent : public KeyEvent
	{
	public:
		KeyPressEvent(int key) : KeyEvent(key) {}

		inline std::string toString() const override
		{
			std::stringstream ss;
			ss << "KeyPressEvent: " << m_key;
			return ss.str();
		}
	};

	class VNUT_API KeyReleaseEvent : public KeyEvent
	{
	public:
		KeyReleaseEvent(int key) : KeyEvent(key) {}

		inline std::string toString() const override
		{
			std::stringstream ss;
			ss << "KeyReleaseEvent: " << m_key;
			return ss.str();
		}
	};

	class VNUT_API KeyTypeEvent : public KeyEvent
	{
	public:
		KeyTypeEvent(int key) : KeyEvent(key) {}

		inline std::string toString() const override
		{
			std::stringstream ss;
			ss << "KeyTypeEvent: " << m_key;
			return ss.str();
		}
	};

	// Mouse events

	class VNUT_API MouseMoveEvent : public Event
	{
	public:
		MouseMoveEvent(double xPos, double yPos) : m_xPos(xPos), m_yPos(yPos) {}

		inline double getXPos() { return m_xPos; }
		inline double getYPos() { return m_yPos; }

		inline std::string toString() const override
		{
			std::stringstream ss;
			ss << "MouseMoveEvent: " << m_xPos << ", " << m_yPos;
			return ss.str();
		}
	private:
		double m_xPos, m_yPos;
	};

	class VNUT_API MouseScrollEvent : public Event
	{
	public:
		MouseScrollEvent(double xOffset, double yOffset) : m_xOffset(xOffset), m_yOffset(yOffset) {}

		inline double getXOffset() { return m_xOffset; }
		inline double getYOffset() { return m_yOffset; }

		inline std::string toString() const override
		{
			std::stringstream ss;
			ss << "MouseScrollEvent: " << m_xOffset << ", " << m_yOffset;
			return ss.str();
		}
	private:
		float m_xOffset, m_yOffset;
	};

	class VNUT_API MouseButtonEvent : public Event
	{
	public:
		inline int getButton() { return m_button; }
	protected:
		MouseButtonEvent(int button) : m_button(button) {}

		int m_button;
	};

	class VNUT_API MouseButtonPressEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressEvent(int button) : MouseButtonEvent(button) {}

		inline std::string toString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressEvent: " << m_button;
			return ss.str();
		}
	};

	class VNUT_API MouseButtonReleaseEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleaseEvent(int button) : MouseButtonEvent(button) {}
		
		inline std::string toString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleaseEvent: " << m_button;
			return ss.str();
		}
	};

}