#pragma once

namespace Lacy2D {

#define LACY2D_ENGINE_VERSION_MAJOR 0
#define LACY2D_ENGINE_VERSION_MINOR 1
#define LACY2D_ENGINE_VERSION_PATCH 0
#define LACY2D_ENGINE_VERSION_ALPHA 1

	// Generates a string literal representation of the version number
#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)

// Full version string
#define LACY2D_ENGINE_VERSION "v" TOSTRING(LACY2D_ENGINE_VERSION_MAJOR) "." TOSTRING(LACY2D_ENGINE_VERSION_MINOR) "." TOSTRING(LACY2D_ENGINE_VERSION_PATCH) "-alpha"

}