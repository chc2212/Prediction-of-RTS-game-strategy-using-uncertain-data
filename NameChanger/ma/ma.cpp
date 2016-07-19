#include<stdio.h>
#include<windows.h>
void main(){
	int num_100=1;
	int num_10=0;
	int num_1=1;

	int start;
	scanf("%d",&start);

	num_100 = start / 100;
	num_10 = (start-num_100*100)/10;
	num_1 = start - (num_100*100 + num_10*10);

	for(int i=1;i<1000;i++){
		Sleep(500);
		keybd_event (VK_F2,0,0,0);//f2하고
		Sleep(50);

		keybd_event(VK_F2,0,KEYEVENTF_KEYUP,0);
		Sleep(50);

		//100의자리수
		if(num_100 ==0){
			keybd_event(VK_NUMPAD0,0,0,0);
			Sleep(50);
			keybd_event(VK_NUMPAD0,0,KEYEVENTF_KEYUP,0);
		}

		//1
		if(num_100 ==1){
			keybd_event(VK_NUMPAD1,0,0,0);
			Sleep(50);
			keybd_event(VK_NUMPAD1,0,KEYEVENTF_KEYUP,0);
		}
		//1

		if(num_100 ==2){
			keybd_event(VK_NUMPAD2,0,0,0);//숫자넣고
			Sleep(50);
			keybd_event(VK_NUMPAD2,0,KEYEVENTF_KEYUP,0);
		}
		//2

		if(num_100 ==3){
			keybd_event(VK_NUMPAD3,0,0,0);//숫자넣고
			Sleep(50);
			keybd_event(VK_NUMPAD3,0,KEYEVENTF_KEYUP,0);
		}
		//3

		if(num_100 ==4){
			keybd_event(VK_NUMPAD4,0,0,0);//숫자넣고
			Sleep(50);
			keybd_event(VK_NUMPAD4,0,KEYEVENTF_KEYUP,0);
		}
		//4

		if(num_100 ==5){
			keybd_event(VK_NUMPAD5,0,0,0);//숫자넣고
			Sleep(50);
			keybd_event(VK_NUMPAD5,0,KEYEVENTF_KEYUP,0);
		}
		//5

		if(num_100 ==6){
			keybd_event(VK_NUMPAD6,0,0,0);//숫자넣고
			Sleep(50);
			keybd_event(VK_NUMPAD6,0,KEYEVENTF_KEYUP,0);
		}
		//6

		if(num_100 ==7){
			keybd_event(VK_NUMPAD7,0,0,0);//숫자넣고
			Sleep(50);
			keybd_event(VK_NUMPAD7,0,KEYEVENTF_KEYUP,0);
		}
		//7

		if(num_100 ==8){
			keybd_event(VK_NUMPAD8,0,0,0);//숫자넣고
			Sleep(50);
			keybd_event(VK_NUMPAD8,0,KEYEVENTF_KEYUP,0);
		}
		//8

		if(num_100 ==9){
			keybd_event(VK_NUMPAD9,0,0,0);//숫자넣고
			Sleep(50);
			keybd_event(VK_NUMPAD9,0,KEYEVENTF_KEYUP,0);
		}
		//9

		//10의자리수

		if(num_10 ==0){
			keybd_event(VK_NUMPAD0,0,0,0);
			Sleep(50);
			keybd_event(VK_NUMPAD0,0,KEYEVENTF_KEYUP,0);
		}

		//1
		if(num_10 ==1){
			keybd_event(VK_NUMPAD1,0,0,0);
			Sleep(50);
			keybd_event(VK_NUMPAD1,0,KEYEVENTF_KEYUP,0);
		}
		//1

		if(num_10 ==2){
			keybd_event(VK_NUMPAD2,0,0,0);//숫자넣고
			Sleep(50);
			keybd_event(VK_NUMPAD2,0,KEYEVENTF_KEYUP,0);
		}
		//2

		if(num_10 ==3){
			keybd_event(VK_NUMPAD3,0,0,0);//숫자넣고
			Sleep(50);
			keybd_event(VK_NUMPAD3,0,KEYEVENTF_KEYUP,0);
		}
		//3

		if(num_10 ==4){
			keybd_event(VK_NUMPAD4,0,0,0);//숫자넣고
			Sleep(50);
			keybd_event(VK_NUMPAD4,0,KEYEVENTF_KEYUP,0);
		}
		//4

		if(num_10 ==5){
			keybd_event(VK_NUMPAD5,0,0,0);//숫자넣고
			Sleep(50);
			keybd_event(VK_NUMPAD5,0,KEYEVENTF_KEYUP,0);
		}
		//5

		if(num_10 ==6){
			keybd_event(VK_NUMPAD6,0,0,0);//숫자넣고
			Sleep(50);
			keybd_event(VK_NUMPAD6,0,KEYEVENTF_KEYUP,0);
		}
		//6

		if(num_10 ==7){
			keybd_event(VK_NUMPAD7,0,0,0);//숫자넣고
			Sleep(50);
			keybd_event(VK_NUMPAD7,0,KEYEVENTF_KEYUP,0);
		}
		//7

		if(num_10 ==8){
			keybd_event(VK_NUMPAD8,0,0,0);//숫자넣고
			Sleep(50);
			keybd_event(VK_NUMPAD8,0,KEYEVENTF_KEYUP,0);
		}
		//8

		if(num_10 ==9){
			keybd_event(VK_NUMPAD9,0,0,0);//숫자넣고
			Sleep(50);
			keybd_event(VK_NUMPAD9,0,KEYEVENTF_KEYUP,0);
		}
		//9

		//1의자리수
		if(num_1 ==0){
			keybd_event(VK_NUMPAD0,0,0,0);
			Sleep(50);
			keybd_event(VK_NUMPAD0,0,KEYEVENTF_KEYUP,0);
		}

		//1
		if(num_1 ==1){
			keybd_event(VK_NUMPAD1,0,0,0);
			Sleep(50);
			keybd_event(VK_NUMPAD1,0,KEYEVENTF_KEYUP,0);
		}
		//1

		if(num_1 ==2){
			keybd_event(VK_NUMPAD2,0,0,0);//숫자넣고
			Sleep(50);
			keybd_event(VK_NUMPAD2,0,KEYEVENTF_KEYUP,0);
		}
		//2

		if(num_1 ==3){
			keybd_event(VK_NUMPAD3,0,0,0);//숫자넣고
			Sleep(50);
			keybd_event(VK_NUMPAD3,0,KEYEVENTF_KEYUP,0);
		}
		//3

		if(num_1 ==4){
			keybd_event(VK_NUMPAD4,0,0,0);//숫자넣고
			Sleep(50);
			keybd_event(VK_NUMPAD4,0,KEYEVENTF_KEYUP,0);
		}
		//4

		if(num_1 ==5){
			keybd_event(VK_NUMPAD5,0,0,0);//숫자넣고
			Sleep(50);
			keybd_event(VK_NUMPAD5,0,KEYEVENTF_KEYUP,0);
		}
		//5

		if(num_1 ==6){
			keybd_event(VK_NUMPAD6,0,0,0);//숫자넣고
			Sleep(50);
			keybd_event(VK_NUMPAD6,0,KEYEVENTF_KEYUP,0);
		}
		//6

		if(num_1 ==7){
			keybd_event(VK_NUMPAD7,0,0,0);//숫자넣고
			Sleep(50);
			keybd_event(VK_NUMPAD7,0,KEYEVENTF_KEYUP,0);
		}
		//7

		if(num_1 ==8){
			keybd_event(VK_NUMPAD8,0,0,0);//숫자넣고
			Sleep(50);
			keybd_event(VK_NUMPAD8,0,KEYEVENTF_KEYUP,0);
		}
		//8

		if(num_1 ==9){
			keybd_event(VK_NUMPAD9,0,0,0);//숫자넣고
			Sleep(50);
			keybd_event(VK_NUMPAD9,0,KEYEVENTF_KEYUP,0);
		}
		//9


		if(num_10 == 9 && num_1 == 9){
			num_100 = num_100+1;
			num_10 = 0;
			num_1 = -1;
		}
		if(num_1 ==9){
			num_10 = num_10 +1;
			num_1 = -1;
		}
		//계산

		Sleep(50);
		keybd_event(VK_RETURN,0,0,0);
		Sleep(50);
		keybd_event(VK_NUMPAD9,0,KEYEVENTF_KEYUP,0);//엔터

		Sleep(50);
		keybd_event(VK_DOWN,0,0,0);
		Sleep(50);
		keybd_event(VK_NUMPAD9,0,KEYEVENTF_KEYUP,0);//아래누르고
		
		

		num_1++;	
	}
}