#include "gepch.h"
#include "Application.h"

#include "GameEngine/Events/ApplicationEvent.h"
#include "GameEngine/Log.h"

#include <GLFW/glfw3.h>

namespace GameEngine {
	Application::Application() {
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application() {}

	void Application::Run() {
		/*
		* Event testing
		WindowResizeEvent e(1280, 720);
		if(e.IsInCategory(EventCategoryApplication))
			GE_TRACE(e);
		if (e.IsInCategory(EventCategoryInput))
			GE_TRACE(e);
		*/

		while (m_Running) {
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}
}
