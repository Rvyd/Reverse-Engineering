#include <Windows.h>
#include <iostream>

int main()
{
	char name[] = "Hello";
	SIZE_T memsize = atoi(name); //sabit tutulmalý, korunmalýdýr. Çok fazla alan kaplamamalý çünkü saldýrgan burada kod çalýþtýrabilir.
	          // hem iþlem yapýlacaðý hem de alan kullanýlacaðý. Bu alanda okuma yazma izni var. 
	LPVOID alloctedmemory = VirtualAlloc(NULL,memsize+1,MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE); //okuma hatasý olmasýn diye memsize 1 eklendi.

	if (alloctedmemory == NULL)
	{
		std::cout << "Error: " << GetLastError() << std::endl;
		return 1;
	}

	if (!memcpy(alloctedmemory, name, memsize)) { //bellekte ayýrdýðýmýz alana kopyalama iþlemi. Ayrýlan alan, buffer ve size 
		std::cout << GetLastError();
	
	}
	WaitForSingleObject(0,INFINITE);
	VirtualFree(alloctedmemory, memsize + 1, MEM_RELEASE);
	return 0;
}


