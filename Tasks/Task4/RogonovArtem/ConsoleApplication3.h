// ����������� ���� ���� ifdef - ��� ����������� ����� �������� ��������, ���������� ��������� 
// �������� �� ��������� DLL. ��� ����� ������ DLL �������������� � �������������� ������� CONSOLEAPPLICATION3_EXPORTS,
// � ��������� ������. ���� ������ �� ������ ���� ��������� � �����-���� �������
// ������������ ������ DLL. ��������� ����� ����� ������ ������, ��� �������� ����� �������� ������ ����, ����� 
// ������� CONSOLEAPPLICATION3_API ��� ��������������� �� DLL, ����� ��� ������ DLL ����� �������,
// ������������ ������ ��������, ��� ����������������.
#ifdef CONSOLEAPPLICATION3_EXPORTS
#define CONSOLEAPPLICATION3_API __declspec(dllexport)
#else
#define CONSOLEAPPLICATION3_API __declspec(dllimport)
#endif

// ���� ����� ������������� �� ConsoleApplication3.dll
class CONSOLEAPPLICATION3_API CConsoleApplication3 {
public:
	CConsoleApplication3(void);
	// TODO: �������� ����� ���� ������.
};

extern CONSOLEAPPLICATION3_API int nConsoleApplication3;

CONSOLEAPPLICATION3_API int fnConsoleApplication3(void);
