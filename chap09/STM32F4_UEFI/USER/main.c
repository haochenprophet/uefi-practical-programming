/**
 * ʹ��F4̽���������� USB HID�豸����ѧϰʹ��,����Ϊ��UEFI���ʵ������9�µ�ʵ���豸��
 * ����Ŀ���̽�������Բο����ߵĲ��ͺ�ר����
 * CSDN: https://blog.csdn.net/luobing4365
 * ֪��: https://www.zhihu.com/column/c_1233025362843209728
 * **/
#include "sys.h"
#include "delay.h"  
#include "usart.h"    
#include "usbd_hid_core.h"
#include "usbd_usr.h"
#include "usbd_desc.h"
#include "usb_conf.h" 
 
USB_OTG_CORE_HANDLE USB_OTG_dev;
extern vu8 USB_STATUS_REG;		//USB״̬
extern vu8 bDeviceState;		//USB���� ���
u8 Divece_STA = 0;
int main(void)
{        
	
	uint8_t  buf[20] = {0,1,2,3,4,5,6,7,8};
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//����ϵͳ�ж����ȼ�����2
	delay_init(168);  //��ʼ����ʱ����
	uart_init(115200);		//��ʼ�����ڲ�����Ϊ115200

	USBD_Init(&USB_OTG_dev,USB_OTG_FS_CORE_ID,&USR_desc,&USBD_HID_cb,&USR_cb);
	delay_ms(1800);	
	printf("USBD_Init Finish\r\n");
  while(1)
  {
//		if(Divece_STA!=bDeviceState) 
//		{
//			if(bDeviceState==1){
//				printf("USB Connected\r\n");//USB������
//			}
//			else 
//				printf("USB DisConnected\r\n");//USB�ѶϿ�
//			Divece_STA=bDeviceState;
//		}
//		delay_ms(10);
//		if(Divece_STA==1)
//		{
//			//buf[0]++;
//			printf("USB HID Send %d\r\n",buf[0]);
//			USBD_HID_SendReport(&USB_OTG_dev, buf, 16);
//		}
//		delay_ms(1000);
  }
}




