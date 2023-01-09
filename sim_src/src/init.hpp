#pragma once
#include <cstdlib>

#ifndef NVBOARD_HOME
  #define NVBOARD_HOME ""
#else
  #define HAS_NVBOARD true
#endif
namespace nvboard{
static void init(){
	putenv(const_cast<char *>("NVBOARD_HOME=" NVBOARD_HOME));
}
}