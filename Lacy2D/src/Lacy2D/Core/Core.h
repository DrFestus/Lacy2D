#pragma once

#include <memory>

#ifdef LACY2D_PLATFORM_WINDOWS
#if LACY2D_DYNAMIC_LINK
	#ifdef LACY2D_BUILD_DLL
		#define LACY2D_API __declspec(dllexport)
	#else
		#define LACY2D_API __declspec(dllimport)
	#endif
#else
	#define LACY2D_API
#endif
#else
	error Lacy only supports Windows!
#endif

#ifdef LACY2D_ENABLE_ASSERTS
	#define LACY2D_ASSERT(x, ...) { if(!(x)) { LACY2D_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define LACY2D_CORE_ASSERT(x, ...) { if(!(x)) { LACY2D_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define LACY2D_ASSERT(x, ...)
	#define LACY2D_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define LACY2D_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

namespace Lacy2D {

	template<typename T>
	using Scope = std::unique_ptr<T>;

	template<typename T>
	using Ref = std::shared_ptr<T>;

}