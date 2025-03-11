#include <Windows.h>
#include <iostream>

void IamThread() {
    for (int i {0} ; i<10;i++){
        std::cout << i << std::endl;
    }

    Sleep(50000);
}
int main()
{
    HANDLE thread1, thread2;

    thread1 = CreateThread(NULL, 0, LPTHREAD_START_ROUTINE(IamThread), NULL, 0, NULL);
    thread2= CreateThread(NULL, 0, LPTHREAD_START_ROUTINE(IamThread), NULL, 0, NULL);

    WaitForSingleObject(thread1, INFINITE);
    WaitForSingleObject(thread2, INFINITE);

    Sleep(10000000);
}


