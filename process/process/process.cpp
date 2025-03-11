#include<Windows.h>  //kütüphanlerde fonksiyon çakýþmasý olmamasý için en baþta olmasý önemli  msdn den bak 
#include <iostream>

int main()
{
	STARTUPINFO si = { 0 };
	PROCESS_INFORMATION pi = { 0 };
	LPCWSTR filename = L"C:\ProgramData\Microsoft\Windows\Start Menu\Programs\Accessories\Notepad.exe";
	CreateProcess(filename,
		NULL, NULL, NULL,
		FALSE,
		0,
		NULL, NULL,
		&si, &pi);


	//CloseHandle(pi.hProcess);
	//CloseHandle(pi.hThread);

	std::cout << "Process ID :";
	std::cout << GetProcessId(pi.hProcess) << std::endl;


	//WaitForSingleObject(pi.hProcess, INFINITE);
	//TerminateProcess(pi.hProcess, 0);

	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);

	return 0;
}#include<Windows.h>  //kütüphanlerde fonksiyon çakýþmasý olmamasý için en baþta olmasý önemli  msdn den bak 
#include <iostream>

int main()
{
	STARTUPINFO si = { 0 };
	PROCESS_INFORMATION pi = { 0 };
	LPCWSTR filename = L"C:\ProgramData\Microsoft\Windows\Start Menu\Programs\Accessories\Notepad.exe";
	CreateProcess(filename, 
		NULL, NULL, NULL, 
		FALSE, 
       	0,
		NULL, NULL, 
		&si, &pi);


	//CloseHandle(pi.hProcess);
	//CloseHandle(pi.hThread);

	std::cout << "Process ID :";
	std::cout << GetProcessId(pi.hProcess) << std::endl ;


	//WaitForSingleObject(pi.hProcess, INFINITE);
	//TerminateProcess(pi.hProcess, 0);

	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);

	return 0;
}