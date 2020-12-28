#pragma once

#include "GameEngine/Layer.h"

namespace GameEngine {

	class GAMEENGINE_API ImGuiLayer : public Layer {
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach();
		void OnDettach();
		void OnUpdate();
		void OnEvent(Event& event);
	private:
		float m_Time = 0.0f;
	};
}
