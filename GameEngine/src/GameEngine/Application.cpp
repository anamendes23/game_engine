#include "gepch.h"
#include "Application.h"

#include "GameEngine/Log.h"
#include "Input.h"

#include <glad/glad.h>

namespace GameEngine {

	Application* Application::s_Instance = nullptr;

	Application::Application() {
		
		GE_CORE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(GE_BIND_EVENTS_FN(Application::OnEvent));

		unsigned int id;
		glGenVertexArrays(1, &id);
	}

	Application::~Application() {}

	void Application::PushLayer(Layer* layer) {
		
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* overlay) {
		
		m_LayerStack.PushOverlay(overlay);
		overlay->OnAttach();
	}

	void Application::OnEvent(Event& e) {

		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(GE_BIND_EVENTS_FN(Application::OnWindowClose));

		//GE_CORE_TRACE("{0}", e);

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); ) {
			(*--it)->OnEvent(e);
			if (e.Handled)
				break;
		}
	}

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

			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();

			/*
			auto [x, y] = Input::GetMousePosition();
			GE_CORE_TRACE("{0}, {1}", x, y);
			*/
			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e) {
		
		m_Running = false;
		return true;
	}
}
