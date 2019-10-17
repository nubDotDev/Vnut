#pragma once

#include "vnutpch.h"

#include "Core.h"

namespace Vnut {

	class VNUT_API Input
	{
	public:
		static inline bool isKeyPressed(int key) { return s_instance->isKeyPressedImpl(key); }
		static inline bool isMouseButtonPressed(int button) { return s_instance->isMouseButtonPressedImpl(button); }
		static inline std::pair<double, double> getMousePos() { return s_instance->getMousePosImpl(); }
	protected:
		virtual bool isKeyPressedImpl(int key) const = 0;
		virtual bool isMouseButtonPressedImpl(int button) const = 0;
		virtual std::pair<double, double> getMousePosImpl() const = 0;
	private:
		static Input* s_instance;
	};

}