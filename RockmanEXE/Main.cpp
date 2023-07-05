// RockmanEXE.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "Define.h"

#include "Main.h"
#include "MainGame.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.
HWND	g_hWnd;
bool    g_bWinActivate;

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
#ifdef _DEBUG
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.
    g_bWinActivate = true;

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_ROCKMANEXE, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_ROCKMANEXE));

    MSG msg;

    CMainGame		MainGame;
    MainGame.Initialize();

    // GetTickCount : 운영 체제가 시작된 후로 흐른 시간을 정수 형태로 반환하는 함수
    // 1 / 1000초의 DWORD 정수 값으로 반환(밀리 세컨드)

    ULONGLONG	ulTime = GetTickCount64();	// 30
    srand(unsigned int(time(NULL)));

    while (true)
    {
        // PeekMessage : 메세지를 읽어오면 TRUE, 읽을 메세지가 없으면 FALSE를 반환

        // PM_REMOVE	  : 메세지를 읽어옴과 동시에 메세지 큐에서 제거
        // PM_NOREMOVE    : 메세지 큐에 메세지가 존재하는지만 파악, 메세지를 읽어오기 위해선 GetMessage를 다시 호출해줘야 함

        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            if (WM_QUIT == msg.message)
                break;

            if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
        else
        {
            ULONGLONG ulCurTime;
            ulCurTime = GetTickCount64();
            if (ulTime + FRAME_DELAY < ulCurTime)
            {
                // 1초를 기준으로 현재 시간에 과거 시간을 뺀 값을 
                float fDeltaTime = (static_cast<float>(ulCurTime) - static_cast<float>(ulTime)) / 1000.f;
                MainGame.Update(fDeltaTime);
                MainGame.Late_Update(fDeltaTime);
                MainGame.Render();

                ulTime = ulCurTime;
            }
        }
    }

    return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ROCKMANEXE));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = NULL;
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   RECT	rc{ 0,0,WINCX, WINCY };

   // rc = rc + 기본 윈도우창 스타일 + 메뉴바 크기 고려 여부
   AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);

   HWND hWnd = CreateWindowW(szWindowClass, // 앞서 정의한 윈도우 클래스의 전달한 클래스의 이름을 넣어준다,.
                               szTitle,     //윈도우창 상단에 출력할 문자열의 이름
                               WS_OVERLAPPEDWINDOW, // 만들고자 하는 창의 스타일을 지정하는 매개 변수, WS_OVERLAPPEDWINDOW 기본 값으로 창 모양 생성 
                               CW_USEDEFAULT, 0, // 창이 생성되는 X,Y 좌표
                               rc.right - rc.left,
                               rc.bottom - rc.top, // 가로, 세로 사이즈
                               nullptr, // 부모 윈도우가 있다면 부모 윈도우의 핸들을 지정
                               nullptr, // 윈도우에서 사용할 메뉴의 핸들을 지정
                               hInstance,  // 윈도우를 만드는 주체, 프로그램의 핸들을 지정
                               nullptr); // 운영체제가 특수한 목적으로 사용하므로 건드릴 일 없음

   if (!hWnd)
   {
       return FALSE;
   }

   g_hWnd = hWnd;

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);

            RECT rect;
            GetClientRect(hWnd, &rect);

            HBRUSH hBrush = CreateSolidBrush(RGB(0, 0, 0)); // 검은색 브러시 생성
            FillRect(hdc, &rect, hBrush); // 영역을 검은색으로 채우기

            DeleteObject(hBrush); // 브러시 삭제

            EndPaint(hWnd, &ps);
        }
        break;
    case WM_KEYDOWN:
        switch (wParam)
        {
        case VK_ESCAPE:
            DestroyWindow(g_hWnd);
            break;
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    case WM_SIZE:
    {
        int iNewWidth = LOWORD(lParam);
        int iNewHeight = LOWORD(lParam);

        float fAspectRatio = (float)WINCX / (float)WINCY;

        int iTargetWidth, iTargetHeight;
        if ((float)iNewWidth / (float)iNewHeight > fAspectRatio)
        {
            iTargetWidth = static_cast<int>(iNewHeight * fAspectRatio);
            iTargetHeight = iNewHeight;
        }
        else
        {
            iTargetHeight = static_cast<int>(iNewWidth / fAspectRatio);
            iTargetWidth = iNewWidth;
        }

        RECT rect = { 0, 0, iTargetWidth, iTargetHeight };
        AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, FALSE);
        SetWindowPos(g_hWnd, NULL, 0, 0, rect.right - rect.left, rect.bottom - rect.top, SWP_NOMOVE | SWP_NOZORDER);

        // 깜빡거리는거 거슬려
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

        RECT rcClient;
        GetClientRect(hWnd, &rcClient);

        HBRUSH hBrush = CreateSolidBrush(RGB(0, 0, 0)); // 검은색 브러시 생성
        FillRect(hdc, &rcClient, hBrush); // 영역을 검은색으로 채우기

        DeleteObject(hBrush); // 브러시 삭제

        EndPaint(hWnd, &ps);
        break;
    }
    case WM_ACTIVATE:
    {
        int iActivate = LOWORD(wParam);

        if (iActivate == WA_INACTIVE)
            g_bWinActivate = false;
        else 
            g_bWinActivate = true;

        break;
    }
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
