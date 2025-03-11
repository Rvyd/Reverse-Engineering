#include <Windows.h>
#include <iostream>

int main()
{
	char name[] = "Hello";
	SIZE_T memsize = atoi(name); //sabit tutulmal�, korunmal�d�r. �ok fazla alan kaplamamal� ��nk� sald�rgan burada kod �al��t�rabilir.
	          // hem i�lem yap�laca�� hem de alan kullan�laca��. Bu alanda okuma yazma izni var. 
	LPVOID alloctedmemory = VirtualAlloc(NULL,memsize+1,MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE); //okuma hatas� olmas�n diye memsize 1 eklendi.

	if (alloctedmemory == NULL)
	{
		std::cout << "Error: " << GetLastError() << std::endl;
		return 1;
	}

	if (!memcpy(alloctedmemory, name, memsize)) { //bellekte ay�rd���m�z alana kopyalama i�lemi. Ayr�lan alan, buffer ve size 
		std::cout << GetLastError();
	
	}
	WaitForSingleObject(0,INFINITE);
	VirtualFree(alloctedmemory, memsize + 1, MEM_RELEASE);
	return 0;
}


