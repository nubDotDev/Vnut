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
	};

	class VNUT_API KeyReleaseEvent : public KeyEvent
	{
	public:
		KeyReleaseEvent(int key) : KeyEvent(key) {}
	};

	// Mouse events

	class VNUT_API MouseMoveEvent : public Event
	{
	public:
		MouseMoveEvent(float x, float y) : m_x(x), m_y(y) {}

		inline float getX() { return m_x; }
		inline float getY() { return m_y; }
	private:
		float m_x, m_y;
	};

	class VNUT_API MouseScrollEvent : public Event
	{
	public:
		MouseScrollEvent(float xOffset, float yOffset) : m_xOffset(xOffset), m_yOffset(yOffset) {}

		inline float getXOffset() { return m_xOffset; }
		inline float getYOffset() { return m_yOffset; }
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
	};

	class VNUT_API MouseButtonReleaseEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleaseEvent(int button) : MouseButtonEvent(button) {}
	};

}