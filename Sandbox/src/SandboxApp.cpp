#include <GameEngine.h>

class ExampleLayer : public GameEngine::Layer {
public:
	ExampleLayer() : Layer("Example") {	}

	void OnUpdate() override {

		//GE_INFO("ExampleLayer::Update");

		if (GameEngine::Input::IsKeyPressed(GE_KEY_TAB))
			GE_TRACE("Tab key is pressed (poll)!");
	}

	void OnEvent(GameEngine::Event& event) override {

		//GE_TRACE("{0}", event);

		if (event.GetEventType() == GameEngine::EventType::KeyPressed) {
			
			GameEngine::KeyPressedEvent& e = (GameEngine::KeyPressedEvent&)event;

			if (e.GetKeyCode() == GE_KEY_TAB)
				GE_TRACE("Tab key is pressed (event)!");

			GE_TRACE("{0}", (char)e.GetKeyCode());
		}
	}
};
	

class Sandbox : public GameEngine::Application {
public:
	Sandbox() {

		PushLayer(new ExampleLayer());
		PushOverlay(new GameEngine::ImGuiLayer());
	}
	~Sandbox() {}
};

GameEngine::Application* GameEngine::CreateApplication() {

	return new Sandbox();
}