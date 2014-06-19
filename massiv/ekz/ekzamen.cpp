#undef UNICODE
#include <windows.h>

#include <stdlib.h>

extern "C" void __cdecl binary(int, char*);
extern "C" int __cdecl proc(int*, int);
extern "C" int __cdecl number_of_1(char*);

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
BOOL InitApplication(HINSTANCE hInstance);
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow);

LPCSTR szClassName = "WinAPI";
LPCSTR szTitle =     "Создание окна Windows";

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow)
{
  MSG msg;
  /*хотя параметр hPrevInstance в Win32 всегда равно NULLпродолжаем проверять его значение */
  if (!hPrevInstance) 
  {  /* инициализируем приложение -  подготавливаем данные класса окна и регистрируем его */
    if (!InitApplication(hInstance)) 
      return (FALSE);
  }
   /* завершаем создание копии приложения -     создаем главное окно приложения */
  if (!InitInstance(hInstance, nCmdShow)) 
    return (FALSE);  
  
  /* Цикл обработки сообщений */
  while (GetMessage(&msg, NULL, 0, 0)) 
  {   	TranslateMessage(&msg);
    		DispatchMessage(&msg);
  }
  return (msg.wParam);
}

BOOL InitApplication(HINSTANCE hInstance)
{
  WNDCLASS  wc;
  // Заполняем структуру класса окна WNDCLASS
  wc.style         = CS_HREDRAW | CS_VREDRAW;
  wc.lpfnWndProc   = (WNDPROC)WndProc;
  wc.cbClsExtra    = 0;
  wc.cbWndExtra    = 0;
  wc.hInstance     = hInstance;
  wc.hIcon         = LoadIcon(NULL, IDI_ASTERISK);
  wc.hCursor       = LoadCursor(NULL, IDC_CROSS);
  wc.hbrBackground = (HBRUSH)(COLOR_APPWORKSPACE-1);
  wc.lpszMenuName  = NULL;
  wc.lpszClassName = szClassName;
  // Регистрируем класс окна
  return RegisterClass(&wc);
} 

 HWND btn;
 HWND textedit;
 HWND textedit2;
 HWND textedit3;
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
  HWND hWnd;
  hWnd = CreateWindow(
    szClassName,         // указатель на строку зарегистрированного имени класса
    szTitle,             // указатель на строку заголовка окна
    WS_OVERLAPPEDWINDOW, // стиль окна
    CW_USEDEFAULT,       // горизонтальная координата окна
    CW_USEDEFAULT,       // вертикальная координата окна
    CW_USEDEFAULT,       // ширина окна
    CW_USEDEFAULT,       // высота окна
    NULL,                // дескриптор родительского окна
    NULL,                // дескриптор меню окна
    hInstance,           // дескриптор экземпляра приложения
    NULL);               // указатель на дополнительные данные окна

   btn = CreateWindow("button","OK",WS_CHILD|WS_VISIBLE|BS_DEFPUSHBUTTON, 230, 150, 50, 20, hWnd, (HMENU)12345, hInstance, NULL);
   textedit = CreateWindow("Edit",NULL,WS_BORDER|WS_CHILD|WS_VISIBLE, 200, 20, 200, 20, hWnd, (HMENU)12346, hInstance, NULL);
   textedit2 = CreateWindow("Edit",NULL,WS_BORDER|WS_CHILD|WS_VISIBLE, 200, 60, 200, 20, hWnd, (HMENU)12347, hInstance, NULL);
    textedit3 = CreateWindow("Edit",NULL,WS_BORDER|WS_CHILD|WS_VISIBLE, 200, 100, 200, 20, hWnd, (HMENU)12348, hInstance, NULL);

  if (!hWnd)    return (FALSE); 
  ShowWindow(hWnd, nCmdShow);
  UpdateWindow(hWnd);
  return (TRUE);
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{  
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hDC;
	static char str[80];
	static char str1[80];
	static char str2[80];
	static int num[20];
	static char *ptr;
	const char separator[]=" \,";
	int a;
	static int i = 0;
  switch(message)
  {
	  case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case 12345:
			
			
			SendMessage (textedit,  WM_GETTEXT, 10, LPARAM(str));

			 ptr = strtok(str, " ");
			 i = 0;
 
			 while(ptr)
			{
				num[i] =atoi(ptr);
				ptr = strtok(NULL, " ");
				i++;
			 }

			/* num[0] = 1;
			 num[1] = 10;
			 num [2] =70;
			 num[3]= 18;*/
			 a = proc(num, i);
			itoa(a, str1, 10);
			
			SendMessage(textedit3, WM_SETTEXT, 80, LPARAM(str1));
		


			break;
		default:
			return DefWindowProc(hwnd, message, wParam, lParam);
		}
		break;

    case WM_PAINT:
      hDC = BeginPaint(hwnd, &ps);
     // TextOut(hDC, 250, 200, "Обработка сообщения WM_PAINT", 28);
      EndPaint(hwnd, &ps);
      break;
    case WM_DESTROY:
      PostQuitMessage(0);
      break;
    default:
      return DefWindowProc(hwnd, message, wParam, lParam);
  }
  return 0;
}
