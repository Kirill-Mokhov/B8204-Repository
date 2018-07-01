// Приведенный ниже блок ifdef - это стандартный метод создания макросов, упрощающий процедуру 
// экспорта из библиотек DLL. Все файлы данной DLL скомпилированы с использованием символа CONSOLEAPPLICATION3_EXPORTS,
// в командной строке. Этот символ не должен быть определен в каком-либо проекте
// использующем данную DLL. Благодаря этому любой другой проект, чьи исходные файлы включают данный файл, видит 
// функции CONSOLEAPPLICATION3_API как импортированные из DLL, тогда как данная DLL видит символы,
// определяемые данным макросом, как экспортированные.
#ifdef CONSOLEAPPLICATION3_EXPORTS
#define CONSOLEAPPLICATION3_API __declspec(dllexport)
#else
#define CONSOLEAPPLICATION3_API __declspec(dllimport)
#endif

// Этот класс экспортирован из ConsoleApplication3.dll
class CONSOLEAPPLICATION3_API CConsoleApplication3 {
public:
	CConsoleApplication3(void);
	// TODO: Добавьте здесь свои методы.
};

extern CONSOLEAPPLICATION3_API int nConsoleApplication3;

CONSOLEAPPLICATION3_API int fnConsoleApplication3(void);
