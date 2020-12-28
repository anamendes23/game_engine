#include <GameEngine.h>

class ExampleLayer : public GameEngine::Layer {
public:
	ExampleLayer() : Layer("Example") {}

	void OnUpdate() override {
		GE_INFO("ExampleLayer::Update");
	}

	void OnEvent(GameEngine::Event& event) override {
		GE_TRACE("{0}", event);
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