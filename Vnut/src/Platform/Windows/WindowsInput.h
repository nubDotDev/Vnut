#pragma once

#include "GLFW/glfw3.h"

#include "Vnut/Core/Input.h"

namespace Vnut {

	class WindowsInput : public Input
	{
	public:
		WindowsInput() {};
		~WindowsInput() {};

		bool isKeyPressedImpl(int key) const override;
		bool isMouseButtonPressedImpl(int button) const override;
		std::pair<double, double> getMousePosImpl() const override;
	};

}