// header.h: 표준 시스템 포함 파일
// 또는 프로젝트 특정 포함 파일이 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>
// C 런타임 헤더 파일입니다.
#include <iostream>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>


// TODO: 프로그램에 필요한 추가 헤더는 여기에서 참조합니다.
#include <list>
#include <map>
#include <vector>
#include <set>
#include <tuple>
#include <array>
#include <cmath>
#include <algorithm>
#include <functional>
#include <sstream>

#include <Vfw.h>
#pragma comment(lib, "vfw32.lib")

// 라이브러리 : 바이너리로 번역(컴파일)된 함수들을 모아 놓은 파일

//- 코드 재사용을 위한 초창기 방법 중 하나, 다른 프로그램에서 사용할 수 있도록 운영체제나 소프트웨어 개발자에 의해 제공
//- 라이브러리의 대다수의 함수들은 함수의 선언 및 정의들을 필요로 하기 때문에 링크되기 전인 전처리기 시점에 해당 헤더파일을 원시 프로그램에서 포함시켜야 한다.
//- 라이브러리들은 사용자의 프로그램과 링크되어 실행이 가능한 완전한 프로그램을 이루게 된다.

// 사운드 라이브러리
#include "fmod.h"
#include "fmod.hpp"
#include "fmod_errors.h"
#include "fmod_studio.h"
#include "fmod_studio.hpp"
#pragma comment(lib, "fmodL_vc.lib")
#pragma comment(lib, "fmodstudioL_vc.lib")

#include <io.h>
#include "fmod_common.h"

// gdiplus 그래픽 라이브러리
#include <ole2.h>
#pragma comment(lib, "gdiplus.lib") //gdiplus라이브러리
#include <gdiplus.h> //gdiplus사용을 위한 헤더

namespace Gdp = Gdiplus;

// 디버그
#ifdef _DEBUG

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifndef DBG_NEW 

#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) 
#define new DBG_NEW 

#endif
#endif

using namespace std;