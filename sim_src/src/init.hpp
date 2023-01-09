#pragma once
#include <cstdlib>
#define NVBOARD_HOME "/home/iplee/Main/Proj/nscscc2023/proj_main/NVBoard"

namespace nvboard{
static void init(){
	putenv(("NVBOARD_HOME=" NVBOARD_HOME));
}
}