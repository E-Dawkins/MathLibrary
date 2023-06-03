#pragma once

#ifdef MATHLIBRARY_EXPORTS
#define MATHLIBRARY_API _declspec(dllexport)
#else
#define MATHLIBRARY_API _declspec(dllimport)
#endif