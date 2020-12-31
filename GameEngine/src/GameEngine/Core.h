#pragma once

#ifdef GE_PLATFORM_WINDOWS
	#ifdef GE_BUILD_DLL
		#define GAMEENGINE_API __declspec(dllexport)
	#else
		#define GAMEENGINE_API __declspec(dllimport)
	#endif
#else
	#error This game engine only supports windows!
#endif
/*
#ifdef GE_DEBUG
	#define	GE_ENABLE_ASSERTS
#endif
*/
#ifdef GE_ENABLE_ASSERTS
	#define GE_ASSERT(x, ...) { if(!(x)) {GE_ERROR("Assertion Failed: {0}", __VA_ARGS__}; __debugbreak(); } }
	#define GE_CORE_ASSERT(x, ...) { if(!(x)) {GE_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__}; __debugbreak(); } }
#else
	#define GE_ASSERT(x, ...)
	#define GE_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define GE_BIND_EVENTS_FN(fn) std::bind(&fn, this, std::placeholders::_1)
