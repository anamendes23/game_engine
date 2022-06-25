#pragma once

#ifdef GE_PLATFORM_WINDOWS

extern GameEngine::Application* GameEngine::CreateApplication();

int main(int argc, char** argv) {

	GameEngine::Log::Init();
	GE_CORE_WARN("Initialized Log!");
	int a = 5;
	GE_INFO("Hello! Var={0}", a);

	GameEngine::Application* app = GameEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif