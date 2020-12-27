
#define	ALLOCATE_EXTERN
#include "HC89F0541.h"


#define PIN2 P3_5
#define PIN3 P3_4
#define PIN4 P2_4
#define PIN5 P2_3
#define PIN6 P2_2
#define PIN7 P2_1
#define PIN8 P2_0
#define PIN9 P1_7
#define PIN10 P1_6
#define PIN11 P1_5
#define PIN12 P1_4
#define PIN13 P1_3
#define PIN14 P1_2
#define PIN15 P1_1
#define PIN16 P1_0
#define PIN17 P0_7
#define PIN18 P0_6
#define PIN19 P0_5
#define PIN20 P0_4
#define PIN21 P0_3
#define PIN22 P0_2
#define PIN23 P0_1
#define PIN24 P0_0
#define PIN25 P2_7
#define PIN26 P2_6
#define PIN27 P2_5

#define C_PIN2 P3M5
#define C_PIN3 P3M4
#define C_PIN4 P2M4
#define C_PIN5 P2M3
#define C_PIN6 P2M2
#define C_PIN7 P2M1
#define C_PIN8 P2M0
#define C_PIN9 P1M7
#define C_PIN10 P1M6
#define C_PIN11 P1M5
#define C_PIN12 P1M4
#define C_PIN13 P1M3
#define C_PIN14 P1M2
#define C_PIN15 P1M1
#define C_PIN16 P1M0
#define C_PIN17 P0M7
#define C_PIN18 P0M6
#define C_PIN19 P0M5
#define C_PIN20 P0M4
#define C_PIN21 P0M3
#define C_PIN22 P0M2
#define C_PIN23 P0M1
#define C_PIN24 P0M0
#define C_PIN25 P2M7
#define C_PIN26 P2M6
#define C_PIN27 P2M5

#define RLY PIN3
#define KG PIN4
#define BUZ PIN2
#define C_RLY C_PIN3
#define C_KG C_PIN4
#define C_BUZ C_PIN2

#define OD_OUTPUT 0xC4
#define PP_OUTPUT 0xC0
#define IN_INPUT 0x60
#define SS_INPUT 0x5B
#define AN_INPUT 0x00

#define DISPLAY_A  PIN20
#define DISPLAY_B  PIN24
#define DISPLAY_C  PIN15
#define DISPLAY_D  PIN17
#define DISPLAY_E  PIN18
#define DISPLAY_F  PIN21
#define DISPLAY_G  PIN9
#define DISPLAY_DP PIN16

#define S1 PIN20
#define S2 PIN20
#define S3 PIN18
#define S4 PIN18
#define S5 PIN17
#define S6 PIN17
#define S7 PIN24
#define S8 PIN21
#define S9 PIN21
#define S10 PIN26
#define S11 PIN26
#define S12 PIN25
#define S13 PIN16
#define S14 PIN9
#define S15 PIN16
#define S16 PIN9
#define S17 PIN15
#define S18 PIN15
#define S19 PIN24

xdata char g_din_wen_peng_ren_led=0;
xdata char g_dun_rou_led=0;
xdata char g_dun_tang_led=0;
xdata char g_lao_huo_man_dun_led=0;
xdata char g_jian_kang_zheng_led=0;
xdata char g_jian_cao_led=0;
xdata char g_suan_nao_led=0;
xdata char g_fa_jiao_led=0;
xdata char g_xiao_du_led=0;
xdata char g_dan_gao_led=0;
xdata char g_feng_pei_led=0;
xdata char g_ji_ya_led=0;
xdata char g_mi_fan_led=0;
xdata char g_dou_lei_led=0;
xdata char g_zha_liang_led=0;
xdata char g_yan_mai_led=0;
xdata char g_ji_dan_led=0;
xdata char g_bao_wen_led=0;
xdata char g_chang_duan_led[3]={0};
xdata char g_shu_ma_guan[4];
xdata char g_L_led=0;
xdata char g_P_led=0;
xdata char g_shi_jian_liang_dian=0;
xdata char g_key_code=0;


xdata enum WORK_MODE{
	STOP=0,
	DIN_WEN_PENG_REN,
	DUN_ROU,
	DUN_TANG,
	LAO_HUO_MAN_DUN,
	JIAN_KANG_ZHENG,
	JIAN_CAO,
	MI_FAN,
	DOU_LEI,
	ZHA_LIANG,
	YAN_MAI,
	JI_DAN,
	SUAN_NAO,
	FA_JIAO,
	XIAO_DU,
	DAN_GAO,
	FENG_PEI,
	JI_YA,
	BAO_WEN

};
xdata unsigned  short g_default_time[]={0,240,30,25,240,10,15,12,35,20,5,15,600,180,2,48,30,13,24*60};
 unsigned short g_peng_ren_shi_chang=0;
 unsigned char g_peng_ren_wen_du=0;
 unsigned char g_ya_li_kai_guan=0;
 unsigned char g_work_mode=0;
 unsigned char g_work_start=0;
 unsigned short g_work_counter=0;
 unsigned short g_yu_yue_shi_jian=0;
 unsigned short g_operate_counter=0;
 unsigned char g_kid_lock=0;

 unsigned char g_xiao_peng_ren_shi_jian=0;
 unsigned char g_seting_wen_du=0;
 unsigned short g_working_counter=0;
 unsigned char g_err_code=0;
 unsigned char g_dai_P=0;
 unsigned char g_dai_no_P=0;
 unsigned char g_peng_ren_chang_duan_shi_jian=0;
 unsigned char g_P_bao_ya_counter_start=0;
 unsigned char g_peng_ren_over=0;
 unsigned char g_hoting=0;
 u16 g_currnet_temp=0;
 u32 g_RLY_work_time=0;
 unsigned char g_yu_yue_ing=0;
 u32 g_stop_counter=0;

char g_fun_index1=0;
char g_fun_index2=0;

u32 g_din_wen_peng_ren_40_counter=0;
void Delay_1us(unsigned int n)	   
{
	unsigned char i;

	for(i=0;i<3;i++);

}
void Delay_50us(unsigned int n)	   
{
	unsigned char i;
	while(n--)
	{
		for(i=0;i<71;i++);
	}
}
void Delay_ms(unsigned int delay_nms)
{
	while(delay_nms--)
	{
		Delay_50us(20);
	}
}
void init_uart1()
{
	P1M5 = 0xC2;				        //P16ÉèÖÃÎªÍÆÍìÊä³ö
	TXD_MAP = 0x15;						//TXDÓ³ÉäP16	
	T4CON = 0x06;						//T4¹¤×÷Ä£Ê½£ºUART1²¨ÌØÂÊ·¢ÉúÆ÷
    
  	TH4 = 0xFF;
	TL4 = 0x98;							//²¨ÌØÂÊ9600
	SCON2 = 0x02;						//8Î»UART£¬²¨ÌØÂÊ¿É±ä
}
void putchar(char c)
{
	SBUF = c;//·¢ËÍ8Î»´®¿ÚÊý¾Ý
	while(!(SCON & 0x02));
	SCON &=~ 0x02;			//Çå³ý·¢ËÍÖÐ¶Ï±êÖ¾Î»
}

void init_timer0() //1ms
{

	TCON1 = 0x00;						//Tx0¶¨Ê±Æ÷Ê±ÖÓÎªFosc
	TMOD = 0x00;						//16Î»ÖØ×°ÔØ¶¨Ê±Æ÷/¼ÆÊýÆ÷
	
	TH0 = 0xFA;
	TL0 = 0xCB;							//T0¶¨Ê±Ê±¼ä1ms
	IE |= 0x02;							//´ò¿ªT0ÖÐ¶Ï
	TCON |= 0x10;						//Ê¹ÄÜT0
}

void  buzzer(char type)
{
	static char inited=0;
	static int t0=0;	
	if(inited==0)
	{
		inited=1;
		P3M5 = 0xC2;                        //P03设置为推挽输出
		PWM3_MAP = 0x35;					//PWM3映射P03口
		PWM3P = 0x20;						//PWM周期为0xFF
		PWM3D = 0x10;						//PWM占空比设置
	}

	if(type==1)
	{			
		PWM3C = 0x97; 						//使能PWM3，关闭中断，允许输出，时钟4分频
		t0=50;
	}
	else if(type==2)
	{
		PWM3C = 0x97; 						//使能PWM3，关闭中断，允许输出，时钟4分频
		t0=100;
	}
	else if(type==3)
	{
		PWM3C = 0x97; 						//使能PWM3，关闭中断，允许输出，时钟4分频
		t0=250;
	}
	else if(type==4)
	{
		PWM3C = 0x97; 						//使能PWM3，关闭中断，允许输出，时钟4分频
		t0=2500;
	}
	else if(type==5)
	{
		PWM3C = 0x97; 						//使能PWM3，关闭中断，允许输出，时钟4分频
		t0=300;
	}
	if(t0>0)
	{	
		t0--;	
		if(g_err_code!=0)
		{
			if(t0%125==0)
			{
				static char rr=0;
				if(rr==0)
				{
					PWM3C = 0x07;
					rr=1;
				}
				else
				{
					PWM3C = 0x97; 
					rr=0;
				}
				
			}
		}
		if(g_peng_ren_over==1 && g_err_code==0)
		{
			if(t0%50==0)
			{
				static char rr=0;
				if(rr==0)
				{
					PWM3C = 0x07;
					rr=1;
				}
				else
				{
					PWM3C = 0x97; 
					rr=0;
				}
				
			}
		}		
		if(t0==0)
		{
			PWM3C = 0x07;
		}

	}
	
	
}
/*************************************ADC************************************************/
//0~119℃
u16 code Temp_Table[200]={
66,69,73,77,81,85,89,94,98,103,108,114,119,125,131,137,144,150,158,165,173,180,189,197,206,215,
225,234,244,254,264,275,286,298,310,322,334,347,361,374,388,402,417,432,448,464,480,497,514,532,
549,568,587,606,625,645,666,687,708,730,752,774,797,820,844,868,892,917,942,967,993,1019,1046,1073,
3394,1127,1155,1183,1211,1239,1268,1297,1326,1355,1385,1414,1444,1474,1504,1535,1565,1596,1626,1657,
1688,1718,1749,1779,1810,1841,1871,1901,1932,1962,1992,2022,2051,2081,2110,2139,2168,2197,2226,2254,
2282,2310,2337,2381,2392,2419,2445,2471,2497,2523,2548,2573,2598,2622,2646,2670,2693,2716,2739,2762,
2784,2806,2828,2849,2870,2891,2911,2931,2951,2971,2990,3009,3028,3046,3064,3082,3099,3116,3133,3150,
3167,3183,3199,3214,3230,3245,3260,3275,3289,3303,3317,3331,3345,3358,3371,3384,3396,3409,3421,3433,
3445,3456,3468,3479,3490,3501,3511,3522,3532,3542,3549,3561,3571,3580,3589,3598,3607,3615,3624,3632,
3640,3648,3656,3663,3671,3678
};

void init_ntc_adc()
{
	
	P2M5 = 0x02;				        //
	ADCC0 = 0x80;						//
	Delay_50us(1);						//
	ADCC1 = 0x0D;						//
	ADCC2 = 0x4B;						//	
}
unsigned int get_ntc_adc()
{
	ADCC0 |= 0x40;					//
	while(!(ADCC0&0x20));			//
	ADCC0 &=~ 0x20;					//
	return ADCR;
}


void get_temp()
{
	u16 n=0;
	u16 ntc_adc=get_ntc_adc();
	
	for(n=0;n<200;n++)
	{
		if(Temp_Table[n]>ntc_adc)
		{
			break;
		}
	}

	if(g_yu_yue_shi_jian==0 && g_work_start==1 && ntc_adc==0 && g_err_code==0)
	{
		if(g_RLY_work_time>30000)
		{
			Delay_ms(2);
			if(get_ntc_adc()==0)
			{
				g_err_code=1;
				buzzer(4);
			}
		}
		
	}
	else if(g_yu_yue_shi_jian==0 && g_work_start==1 && ntc_adc>=4090 && g_err_code==0)
	{
		Delay_ms(2);
		if(get_ntc_adc()>=4090)
		{
			g_err_code=2;
			buzzer(4);
		}
	}
	else if(g_yu_yue_shi_jian==0 && g_work_start==1 && ntc_adc>3676 && g_err_code==0)
	{
		Delay_ms(2);
		if(get_ntc_adc()>3676)
		{
			// g_err_code=3;
			buzzer(4);
		}
	}
	g_currnet_temp=n;

}
void check_ya_li_kai_guan()
{
	if(g_yu_yue_shi_jian==0 && g_work_start==1 && g_currnet_temp<80 && KG==1 && g_err_code==0)
	{
		g_err_code=4;
		buzzer(4);
	}
}

void init_display()
{
	//COM
	C_PIN6=OD_OUTPUT;
	C_PIN7=OD_OUTPUT;
	C_PIN8=OD_OUTPUT;

	C_PIN19=OD_OUTPUT;
	C_PIN22=OD_OUTPUT;
	C_PIN23=OD_OUTPUT;
	C_PIN10=OD_OUTPUT;

	//SEG
	C_PIN18=PP_OUTPUT;
	C_PIN15=PP_OUTPUT;
	C_PIN17=PP_OUTPUT;
	C_PIN24=PP_OUTPUT;
	C_PIN16=PP_OUTPUT;
	C_PIN21=PP_OUTPUT;
	C_PIN25=PP_OUTPUT;
	C_PIN26=PP_OUTPUT;
	C_PIN9=PP_OUTPUT;
	C_PIN20=PP_OUTPUT;

		//COM
	PIN19=1;	PIN22=1;	PIN23=1;	PIN10=1;
	PIN6=1;	PIN7=1;	PIN8=1;	
	//SEG
	PIN18=0;	PIN15=0;	PIN17=0;	PIN24=0;	PIN16=0;	PIN21=0;	PIN25=0;
	PIN26=0;	PIN9=0;		PIN20=0;

}
void display()
{
	static char index=0;
	init_display();
	//COM
	PIN19=1;	PIN22=1;	PIN23=1;	PIN10=1;
	PIN6=1;	PIN7=1;	PIN8=1;	
	//SEG
	PIN18=0;	PIN15=0;	PIN17=0;	PIN24=0;	PIN16=0;	PIN21=0;	PIN25=0;
	PIN26=0;	PIN9=0;		PIN20=0;
	if(index<4)
	{
		switch(g_shu_ma_guan[index])
		{

			case 0:
				DISPLAY_A=1;	DISPLAY_B=1;	DISPLAY_C=1;	DISPLAY_D=1;	DISPLAY_E=1;	DISPLAY_F=1;	DISPLAY_G=0;
				break;
			case 1:
				DISPLAY_A=0;	DISPLAY_B=1;	DISPLAY_C=1;	DISPLAY_D=0;	DISPLAY_E=0;	DISPLAY_F=0;	DISPLAY_G=0;
				break;
			case 2:
				DISPLAY_A=1;	DISPLAY_B=1;	DISPLAY_C=0;	DISPLAY_D=1;	DISPLAY_E=1;	DISPLAY_F=0;	DISPLAY_G=1;
				break;
			case 3:
				DISPLAY_A=1;	DISPLAY_B=1;	DISPLAY_C=1;	DISPLAY_D=1;	DISPLAY_E=0;	DISPLAY_F=0;	DISPLAY_G=1;
				break;
			case 4:
				DISPLAY_A=0;	DISPLAY_B=1;	DISPLAY_C=1;	DISPLAY_D=0;	DISPLAY_E=0;	DISPLAY_F=1;	DISPLAY_G=1;
				break;
			case 5:
				DISPLAY_A=1;	DISPLAY_B=0;	DISPLAY_C=1;	DISPLAY_D=1;	DISPLAY_E=0;	DISPLAY_F=1;	DISPLAY_G=1;
				break;
			case 6:
				DISPLAY_A=1;	DISPLAY_B=0;	DISPLAY_C=1;	DISPLAY_D=1;	DISPLAY_E=1;	DISPLAY_F=1;	DISPLAY_G=1;
				break;
			case 7:
				DISPLAY_A=1;	DISPLAY_B=1;	DISPLAY_C=1;	DISPLAY_D=0;	DISPLAY_E=0;	DISPLAY_F=0;	DISPLAY_G=0;
				break;
			case 8:
				DISPLAY_A=1;	DISPLAY_B=1;	DISPLAY_C=1;	DISPLAY_D=1;	DISPLAY_E=1;	DISPLAY_F=1;	DISPLAY_G=1;
				break;
			case 9:
				DISPLAY_A=1;	DISPLAY_B=1;	DISPLAY_C=1;	DISPLAY_D=1;	DISPLAY_E=0;	DISPLAY_F=1;	DISPLAY_G=1;
				break;
			case 'E':
				DISPLAY_A=1;	DISPLAY_B=0;	DISPLAY_C=0;	DISPLAY_D=1;	DISPLAY_E=1;	DISPLAY_F=1;	DISPLAY_G=1;
				break;
			case '-':
				DISPLAY_A=0;	DISPLAY_B=0;	DISPLAY_C=0;	DISPLAY_D=0;	DISPLAY_E=0;	DISPLAY_F=0;	DISPLAY_G=1;
				break;
			case 'P':
				DISPLAY_A=1;	DISPLAY_B=1;	DISPLAY_C=0;	DISPLAY_D=0;	DISPLAY_E=1;	DISPLAY_F=1;	DISPLAY_G=1;
				break;
			case 'C':
				DISPLAY_A=1;	DISPLAY_B=0;	DISPLAY_C=0;	DISPLAY_D=1;	DISPLAY_E=1;	DISPLAY_F=1;	DISPLAY_G=0;
				break;
			case 'b':
				DISPLAY_A=0;	DISPLAY_B=0;	DISPLAY_C=1;	DISPLAY_D=1;	DISPLAY_E=1;	DISPLAY_F=1;	DISPLAY_G=1;
				break;
			case 10:
				DISPLAY_A=0;	DISPLAY_B=0;	DISPLAY_C=1;	DISPLAY_D=0;	DISPLAY_E=0;	DISPLAY_F=0;	DISPLAY_G=0;
				break;
			case 11:
				DISPLAY_A=0;	DISPLAY_B=1;	DISPLAY_C=1;	DISPLAY_D=0;	DISPLAY_E=0;	DISPLAY_F=0;	DISPLAY_G=0;
				break;
			case 12:
				DISPLAY_A=1;	DISPLAY_B=1;	DISPLAY_C=1;	DISPLAY_D=0;	DISPLAY_E=0;	DISPLAY_F=0;	DISPLAY_G=0;
				break;
			case 13:
				DISPLAY_A=1;	DISPLAY_B=1;	DISPLAY_C=1;	DISPLAY_D=0;	DISPLAY_E=0;	DISPLAY_F=1;	DISPLAY_G=0;
				break;
			case 14:
				DISPLAY_A=1;	DISPLAY_B=1;	DISPLAY_C=1;	DISPLAY_D=0;	DISPLAY_E=1;	DISPLAY_F=1;	DISPLAY_G=0;
				break;
			case 15:
				DISPLAY_A=1;	DISPLAY_B=1;	DISPLAY_C=1;	DISPLAY_D=1;	DISPLAY_E=1;	DISPLAY_F=1;	DISPLAY_G=0;
				break;
			case 16:
				DISPLAY_A=0;	DISPLAY_B=0;	DISPLAY_C=0;	DISPLAY_D=0;	DISPLAY_E=1;	DISPLAY_F=0;	DISPLAY_G=0;
				break;
			case 17:
				DISPLAY_A=0;	DISPLAY_B=0;	DISPLAY_C=0;	DISPLAY_D=0;	DISPLAY_E=1;	DISPLAY_F=1;	DISPLAY_G=0;
				break;
			case 18:
				DISPLAY_A=1;	DISPLAY_B=0;	DISPLAY_C=0;	DISPLAY_D=0;	DISPLAY_E=1;	DISPLAY_F=1;	DISPLAY_G=0;
				break;
			case 19:
				DISPLAY_A=1;	DISPLAY_B=1;	DISPLAY_C=0;	DISPLAY_D=0;	DISPLAY_E=1;	DISPLAY_F=1;	DISPLAY_G=0;
				break;
			case 20:
				DISPLAY_A=1;	DISPLAY_B=1;	DISPLAY_C=1;	DISPLAY_D=0;	DISPLAY_E=1;	DISPLAY_F=1;	DISPLAY_G=0;
				break;
			case 21:
				DISPLAY_A=1;	DISPLAY_B=1;	DISPLAY_C=1;	DISPLAY_D=1;	DISPLAY_E=1;	DISPLAY_F=1;	DISPLAY_G=0;
				break;
			default:
				DISPLAY_A=0;	DISPLAY_B=0;	DISPLAY_C=0;	DISPLAY_D=0;	DISPLAY_E=0;	DISPLAY_F=0;	DISPLAY_G=0;
				break;
			
		}

		
	}
	if(index==0)
	{
		PIN19=0;
	}
	else if(index==1)
	{
		PIN22=0;
		DISPLAY_DP=g_shi_jian_liang_dian;
	}
	else if(index==2)
	{
		PIN23=0;
	}
	else if(index==3)
	{
		PIN10=0;
	}
	else if(index==4)
	{
		PIN18=g_dun_tang_led;	PIN15=g_ji_ya_led;	PIN17=g_jian_cao_led;	PIN24=g_bao_wen_led;	PIN16=g_chang_duan_led[1];	
		PIN21=g_yan_mai_led;	PIN25=g_mi_fan_led;		PIN26=g_dou_lei_led;	PIN9=g_chang_duan_led[1];	PIN20=g_din_wen_peng_ren_led;
		
		PIN6=0;
	}
	else if(index==5)
	{
		PIN18=g_lao_huo_man_dun_led;	PIN15=g_chang_duan_led[0];	PIN17=g_jian_kang_zheng_led;	PIN24=g_dan_gao_led;	PIN16=g_fa_jiao_led;	
		PIN21=g_ji_dan_led;	PIN25=1;		PIN26=g_zha_liang_led;	PIN9=g_chang_duan_led[1];	PIN20=g_L_led;
		
		PIN7=0;
	}
	else if(index==6)
	{
		PIN18=g_P_led;	PIN15=g_chang_duan_led[0];	PIN17=g_suan_nao_led;	PIN24=g_feng_pei_led;	PIN16=g_xiao_du_led;	
		PIN21=g_chang_duan_led[2];	PIN25=0;		PIN26=g_chang_duan_led[2];	PIN9=g_chang_duan_led[2];	PIN20=g_dun_rou_led;
		PIN8=0;
	}
	else
	{

	}

	index++;
	if(index==7)
	{
		index=0;
	}

}

void show_shu_ma_guan_seting()
{
	if(g_seting_wen_du==0)
	{
		if(g_work_mode!=BAO_WEN)
		{
			if(g_dai_P==0)
			{
				g_shu_ma_guan[0]=g_peng_ren_shi_chang/600;
				g_shu_ma_guan[1]=(g_peng_ren_shi_chang%600)/60;
				g_shu_ma_guan[2]=(g_peng_ren_shi_chang%60)/10;
				g_shu_ma_guan[3]=g_peng_ren_shi_chang%10;
				g_shi_jian_liang_dian=1;
			}
			else
			{
				g_shu_ma_guan[0]='X';
				g_shu_ma_guan[1]='P';
				g_shu_ma_guan[2]=(g_peng_ren_shi_chang%60)/10;
				g_shu_ma_guan[3]=g_peng_ren_shi_chang%10;
				g_shi_jian_liang_dian=0;
			}
			
			if(g_yu_yue_shi_jian>0 || g_yu_yue_ing==1)
			{
				g_shu_ma_guan[0]=g_yu_yue_shi_jian/600;
				g_shu_ma_guan[1]=(g_yu_yue_shi_jian%600)/60;
				g_shu_ma_guan[2]=(g_yu_yue_shi_jian%60)/10;
				g_shu_ma_guan[3]=g_yu_yue_shi_jian%10;
				g_shi_jian_liang_dian=1;
			}
			
		}
		else{

			g_shu_ma_guan[0]='X';
			g_shu_ma_guan[1]='X';
			g_shu_ma_guan[2]='b';
			g_shu_ma_guan[3]='b';
		}
	}
	else
	{
		g_shu_ma_guan[0]='X';
		g_shu_ma_guan[1]=g_peng_ren_wen_du/10;
		g_shu_ma_guan[2]=g_peng_ren_wen_du%10;
		g_shu_ma_guan[3]='C';
		g_shi_jian_liang_dian=0;
		
	}

	
}
void show_shu_ma_guan_working()
{
	static short t1=0;
	if(g_work_mode!=BAO_WEN)
	{
		if(g_dai_P==0 || g_yu_yue_shi_jian>0)
		{
			g_shu_ma_guan[0]=g_peng_ren_shi_chang/600;
			g_shu_ma_guan[1]=(g_peng_ren_shi_chang%600)/60;
			g_shu_ma_guan[2]=(g_peng_ren_shi_chang%60)/10;
			g_shu_ma_guan[3]=g_peng_ren_shi_chang%10;		
			if(g_yu_yue_shi_jian>0)
			{
				g_shu_ma_guan[0]=g_yu_yue_shi_jian/600;
				g_shu_ma_guan[1]=(g_yu_yue_shi_jian%600)/60;
				g_shu_ma_guan[2]=(g_yu_yue_shi_jian%60)/10;
				g_shu_ma_guan[3]=g_yu_yue_shi_jian%10;
				
			}
				
			if(t1==1)
			{
				g_shi_jian_liang_dian=1;
			}
			else if(t1==250)
			{
				g_shi_jian_liang_dian=0;
			}
			else if(t1>500)
			{
				t1=0;
			}	
			t1++;				

			if(g_dai_no_P==1 && g_P_bao_ya_counter_start==0)
			{
				g_shi_jian_liang_dian=1;
			}	

			if(g_work_mode==DIN_WEN_PENG_REN )
			{
				if(g_din_wen_peng_ren_40_counter>0)
				{
					g_shi_jian_liang_dian=1;
				}
			}

		}
		else
		{
			
			g_shu_ma_guan[2]=(g_peng_ren_shi_chang%60)/10;
			g_shu_ma_guan[3]=g_peng_ren_shi_chang%10;
			if(g_hoting==1)
			{
				g_shi_jian_liang_dian=0;
				if(t1==1)
				{
					g_shu_ma_guan[0]=10;
					g_shu_ma_guan[1]=16;
				}
				else if(t1==200)
				{
					g_shu_ma_guan[0]=11;
					g_shu_ma_guan[1]=17;
				}
				else if(t1==400)
				{
					g_shu_ma_guan[0]=12;
					g_shu_ma_guan[1]=18;
				}
				else if(t1==600)
				{
					g_shu_ma_guan[0]=13;
					g_shu_ma_guan[1]=19;
				}
				else if(t1==800)
				{
					g_shu_ma_guan[0]=14;
					g_shu_ma_guan[1]=20;
				}
				else if(t1==1000)
				{
					g_shu_ma_guan[0]=15;
					g_shu_ma_guan[1]=21;
				}
				else if(t1>1200)
				{
					t1=0;
				}
		
				t1++;
			}
			else
			{
				g_shu_ma_guan[0]='X';
				g_shu_ma_guan[1]='P';
				if(t1==1)
				{
					g_shi_jian_liang_dian=1;
				}
				else if(t1==250)
				{
					g_shi_jian_liang_dian=0;
				}
				else if(t1>500)
				{
					t1=0;
				}	
				t1++;
			}
		}		
		
	}
	else{

		g_shu_ma_guan[0]='X';
		g_shu_ma_guan[1]='X';
		g_shu_ma_guan[2]='b';
		g_shu_ma_guan[3]='b';
		g_shi_jian_liang_dian=0;
	}
		
}

void show_none()
{
	g_din_wen_peng_ren_led=0;
	g_dun_rou_led=0;
	g_dun_tang_led=0;
	g_lao_huo_man_dun_led=0;
	g_jian_kang_zheng_led=0;
	g_jian_cao_led=0;
	g_suan_nao_led=0;
	g_fa_jiao_led=0;
	g_xiao_du_led=0;
	g_dan_gao_led=0;
	g_feng_pei_led=0;
	g_ji_ya_led=0;
	g_mi_fan_led=0;
	g_dou_lei_led=0;
	g_zha_liang_led=0;
	g_yan_mai_led=0;
	g_ji_dan_led=0;
	g_bao_wen_led=0;
	g_chang_duan_led[0]=0;
	g_chang_duan_led[1]=0;
	g_chang_duan_led[2]=0;
	if(g_work_start==0)
	{
		g_shu_ma_guan[0]='X';
		g_shu_ma_guan[1]='X';
		g_shu_ma_guan[2]='X';
		g_shu_ma_guan[3]='X';

	}
	
	g_L_led=0;
	g_P_led=0;

}
void show_all()
{
	g_din_wen_peng_ren_led=1;
	g_dun_rou_led=1;
	g_dun_tang_led=1;
	g_lao_huo_man_dun_led=1;
	g_jian_kang_zheng_led=1;
	g_jian_cao_led=1;
	g_suan_nao_led=1;
	g_fa_jiao_led=1;
	g_xiao_du_led=1;
	g_dan_gao_led=1;
	g_feng_pei_led=1;
	g_ji_ya_led=1;
	g_mi_fan_led=1;
	g_dou_lei_led=1;
	g_zha_liang_led=1;
	g_yan_mai_led=1;
	g_ji_dan_led=1;
	g_bao_wen_led=1;
	g_chang_duan_led[0]=1;
	g_chang_duan_led[1]=1;
	g_chang_duan_led[2]=1;

	g_shu_ma_guan[0]=8;
	g_shu_ma_guan[1]=8;
	g_shu_ma_guan[2]=8;
	g_shu_ma_guan[3]=8;
	
	g_L_led=1;
	g_P_led=1;

}
void show_stop()
{
	show_none();
	g_shu_ma_guan[0]=0;
	g_shu_ma_guan[1]=0;
	g_shu_ma_guan[2]=0;
	g_shu_ma_guan[3]=0;
	g_shi_jian_liang_dian=0;
	if(g_kid_lock==1)
	{
		g_L_led=1;
	}
	if(g_err_code!=0)
	{
		g_shu_ma_guan[0]='X';
		g_shu_ma_guan[1]='X';
		g_shu_ma_guan[2]='E';
		g_shu_ma_guan[3]=g_err_code;
	}
	if(g_stop_counter>240000)
	{
		g_shu_ma_guan[0]='X';
		g_shu_ma_guan[1]='X';
		g_shu_ma_guan[2]='X';
		g_shu_ma_guan[3]='X';
	}
	else
	{
		g_stop_counter+=2;
	}

}
void show_chang_duan()
{

	if(g_peng_ren_chang_duan_shi_jian==0){
		g_chang_duan_led[0]=1;
		g_chang_duan_led[1]=0;
		g_chang_duan_led[2]=0;
	}
	else if(g_peng_ren_chang_duan_shi_jian==1){
		g_chang_duan_led[0]=1;
		g_chang_duan_led[1]=1;
		g_chang_duan_led[2]=0;
	}
	else if(g_peng_ren_chang_duan_shi_jian==2){
		g_chang_duan_led[0]=1;
		g_chang_duan_led[1]=1;
		g_chang_duan_led[2]=1;
	}

}
void show_led()
{
	switch(g_work_mode)
	{
		case DIN_WEN_PENG_REN:
			g_din_wen_peng_ren_led=1;
		break;
		case DUN_ROU:
			g_dun_rou_led=1;
			show_chang_duan();
		break;		
		case DUN_TANG:
			g_dun_tang_led=1;	
			show_chang_duan();
		break;
		case LAO_HUO_MAN_DUN:
			g_lao_huo_man_dun_led=1;
		break;
		case JIAN_KANG_ZHENG:
			g_jian_kang_zheng_led=1;
			show_chang_duan();
		break;
		case JIAN_CAO:
			g_jian_cao_led=1;
		break;
		case MI_FAN:
			g_mi_fan_led=1;
			show_chang_duan();
		break;
		case DOU_LEI:
			g_dou_lei_led=1;
			show_chang_duan();
		break;
		case ZHA_LIANG:
			g_zha_liang_led=1;
			show_chang_duan();
		break;
		case YAN_MAI:
			g_yan_mai_led=1;
		break;
		case JI_DAN:
			g_ji_dan_led=1;
		break;
		case SUAN_NAO:
			g_suan_nao_led=1;
		break;
		case FA_JIAO:
			g_fa_jiao_led=1;
		break;
		case XIAO_DU:
			g_xiao_du_led=1;
		break;
		case DAN_GAO:
			g_dan_gao_led=1;
		break;
		case FENG_PEI:
			g_feng_pei_led=1;
		break;
		case JI_YA:
			g_ji_ya_led=1;
		break;
		case BAO_WEN:
			g_bao_wen_led=1;
		break;
		default:
		break;
	
	}
	if(g_yu_yue_shi_jian>0)
	{
		g_P_led=1;
	}
	else
	{
		g_P_led=0;
	}
	if(g_kid_lock==1)
	{
		g_L_led=1;
	}
	else
	{
		g_L_led=0;
	}
}
void show_seting()
{
	show_none();
	show_shu_ma_guan_seting();
	show_led();
	

}
void key_scan()
{
	

	C_PIN20=SS_INPUT;
	C_PIN18=SS_INPUT;
	C_PIN17=SS_INPUT;
	C_PIN24=SS_INPUT;
	C_PIN21=SS_INPUT;
	C_PIN26=SS_INPUT;
	C_PIN25=SS_INPUT;
	C_PIN16=SS_INPUT;
	C_PIN9=SS_INPUT;
	C_PIN13=SS_INPUT;
	C_PIN15=SS_INPUT;

	//¹Ø±ÕÊýÂë¹Ü
	PIN19=1;	PIN22=1;	PIN23=1;	PIN10=1;
	PIN6=1;	PIN7=1;	PIN8=1;	

	g_key_code=0;
	C_PIN12=PP_OUTPUT;
	C_PIN13=AN_INPUT;
	PIN12=1;
	Delay_1us(1);
	
	g_key_code =S18?18:S2?2:S4?4:S11?11:S9?9:S6?6:S15?15:S19?19:S16?16:0;
	if(g_key_code==0)
	{
		C_PIN12=AN_INPUT;
		C_PIN13=PP_OUTPUT;
		PIN13=1;	
		Delay_1us(1);	
		g_key_code =S10?10:S12?12:S17?17:S3?3:S8?8:S1?1:S14?14:S5?5:S7?7:S13?13:0;
	}

	C_PIN12=AN_INPUT;
	C_PIN13=AN_INPUT;
} 
void key_plus()
{
	if(g_yu_yue_shi_jian>0 || g_yu_yue_ing==1)
	{
		g_yu_yue_shi_jian+=30;
		if(g_yu_yue_shi_jian>24*60)
		{
			g_yu_yue_shi_jian=0;
		}
	}
	else
	{
		if(g_work_mode==DIN_WEN_PENG_REN)
		{
			g_peng_ren_shi_chang+=1;
			if(g_peng_ren_shi_chang>24*60)
			{
				g_peng_ren_shi_chang=20;
			}
		}
		else if(g_work_mode==DUN_ROU)
		{
			g_peng_ren_shi_chang+=1;
			if(g_peng_ren_shi_chang>59)
			{
				g_peng_ren_shi_chang=1;
			}
		}
		else if(g_work_mode==DUN_TANG)
		{
			g_peng_ren_shi_chang+=1;
			if(g_peng_ren_shi_chang>59)
			{
				g_peng_ren_shi_chang=1;
			}
		}
		else if(g_work_mode==LAO_HUO_MAN_DUN)
		{
			g_peng_ren_shi_chang+=30;
			if(g_peng_ren_shi_chang>10*60)
			{
				g_peng_ren_shi_chang=2*60;
			}
		}
		else if(g_work_mode==JIAN_KANG_ZHENG)
		{
			g_peng_ren_shi_chang+=1;
			if(g_peng_ren_shi_chang>59)
			{
				g_peng_ren_shi_chang=1;
			}
		}
		else if(g_work_mode==JIAN_CAO)
		{
			g_peng_ren_shi_chang+=1;
			if(g_peng_ren_shi_chang>59)
			{
				g_peng_ren_shi_chang=1;
			}
		}
		else if(g_work_mode==MI_FAN)
		{
			g_peng_ren_shi_chang+=1;
			if(g_peng_ren_shi_chang>59)
			{
				g_peng_ren_shi_chang=1;
			}
		}
		else if(g_work_mode==DOU_LEI)
		{
			g_peng_ren_shi_chang+=1;
			if(g_peng_ren_shi_chang>59)
			{
				g_peng_ren_shi_chang=1;
			}
		}
		else if(g_work_mode==ZHA_LIANG)
		{
			g_peng_ren_shi_chang+=1;
			if(g_peng_ren_shi_chang>59)
			{
				g_peng_ren_shi_chang=1;
			}
		}
		else if(g_work_mode==YAN_MAI)
		{
			g_peng_ren_shi_chang+=1;
			if(g_peng_ren_shi_chang>59)
			{
				g_peng_ren_shi_chang=1;
			}
		}
		else if(g_work_mode==JI_DAN)
		{
			g_peng_ren_shi_chang+=1;
			if(g_peng_ren_shi_chang>59)
			{
				g_peng_ren_shi_chang=1;
			}
		}
		else if(g_work_mode==SUAN_NAO)
		{
			g_peng_ren_shi_chang+=30;
			if(g_peng_ren_shi_chang>12*60)
			{
				g_peng_ren_shi_chang=6*60;
			}
		}
		else if(g_work_mode==FA_JIAO)
		{
			g_peng_ren_shi_chang+=10;
			if(g_peng_ren_shi_chang>7*60)
			{
				g_peng_ren_shi_chang=2*60;
			}
		}
		else if(g_work_mode==XIAO_DU)
		{
			g_peng_ren_shi_chang+=1;
			if(g_peng_ren_shi_chang>59)
			{
				g_peng_ren_shi_chang=1;
			}
		}
		else if(g_work_mode==DAN_GAO)
		{
			g_peng_ren_shi_chang+=1;
			if(g_peng_ren_shi_chang>59)
			{
				g_peng_ren_shi_chang=1;
			}
		}
		else if(g_work_mode==FENG_PEI)
		{
			g_peng_ren_shi_chang+=1;
			if(g_peng_ren_shi_chang>59)
			{
				g_peng_ren_shi_chang=1;
			}
		}
		else if(g_work_mode==JI_YA)
		{
			g_peng_ren_shi_chang+=1;
			if(g_peng_ren_shi_chang>59)
			{
				g_peng_ren_shi_chang=1;
			}
		}
	}
}
void key_jian()
{
	if(g_yu_yue_shi_jian>0 || g_yu_yue_ing==1)
	{
		
		if(g_yu_yue_shi_jian==0)
		{
			g_yu_yue_shi_jian=24*60;			
		}
		else
		{
			g_yu_yue_shi_jian-=30;
		}

	}
	else
	{
		if(g_work_mode==DIN_WEN_PENG_REN)
		{
			
			if(g_peng_ren_shi_chang>=20)
			{
				g_peng_ren_shi_chang-=1;
				if(g_peng_ren_shi_chang<20)
				{
					g_peng_ren_shi_chang=24*60;
				}
				
			}
		}
		else if(g_work_mode==DUN_ROU)
		{
			if(g_peng_ren_shi_chang>=1)
			{
				g_peng_ren_shi_chang-=1;
				if(g_peng_ren_shi_chang==0)
				{
					g_peng_ren_shi_chang=59;
				}
			}
		}
		else if(g_work_mode==DUN_TANG)
		{
			if(g_peng_ren_shi_chang>=1)
			{
				g_peng_ren_shi_chang-=1;
				if(g_peng_ren_shi_chang==0)
				{
					g_peng_ren_shi_chang=59;
				}
			}
		}
		else if(g_work_mode==LAO_HUO_MAN_DUN)
		{
			if(g_peng_ren_shi_chang>=2*60)
			{
				g_peng_ren_shi_chang-=30;
				if(g_peng_ren_shi_chang<2*60)
				{
					g_peng_ren_shi_chang=10*60;
				}

			}
		}
		else if(g_work_mode==JIAN_KANG_ZHENG)
		{
			if(g_peng_ren_shi_chang>=1)
			{
				g_peng_ren_shi_chang-=1;
				if(g_peng_ren_shi_chang==0)
				{
					g_peng_ren_shi_chang=59;
				}
			}
		}
		else if(g_work_mode==JIAN_CAO)
		{
			if(g_peng_ren_shi_chang>=1)
			{
				g_peng_ren_shi_chang-=1;
				if(g_peng_ren_shi_chang==0)
				{
					g_peng_ren_shi_chang=59;
				}
			}
		}
		else if(g_work_mode==MI_FAN)
		{
			if(g_peng_ren_shi_chang>=1)
			{
				g_peng_ren_shi_chang-=1;
				if(g_peng_ren_shi_chang==0)
				{
					g_peng_ren_shi_chang=59;
				}
			}
		}
		else if(g_work_mode==DOU_LEI)
		{
			if(g_peng_ren_shi_chang>=1)
			{
				g_peng_ren_shi_chang-=1;
				if(g_peng_ren_shi_chang==0)
				{
					g_peng_ren_shi_chang=59;
				}
			}
		}
		else if(g_work_mode==ZHA_LIANG)
		{
			if(g_peng_ren_shi_chang>=1)
			{
				g_peng_ren_shi_chang-=1;
				if(g_peng_ren_shi_chang==0)
				{
					g_peng_ren_shi_chang=59;
				}
			}
		}
		else if(g_work_mode==YAN_MAI)
		{
			if(g_peng_ren_shi_chang>=1)
			{
				g_peng_ren_shi_chang-=1;
				if(g_peng_ren_shi_chang==0)
				{
					g_peng_ren_shi_chang=59;
				}
			}
		}
		else if(g_work_mode==JI_DAN)
		{
			if(g_peng_ren_shi_chang>=1)
			{
				g_peng_ren_shi_chang-=1;
				if(g_peng_ren_shi_chang==0)
				{
					g_peng_ren_shi_chang=59;
				}
			}
		}
		else if(g_work_mode==SUAN_NAO)
		{
			if(g_peng_ren_shi_chang>=6*60)
			{
				g_peng_ren_shi_chang-=30;
				if(g_peng_ren_shi_chang<6*60)
				{
					g_peng_ren_shi_chang=12*60;
				}

			}
		}
		else if(g_work_mode==FA_JIAO)
		{
			if(g_peng_ren_shi_chang>=2*60)
			{
				g_peng_ren_shi_chang-=10;
				if(g_peng_ren_shi_chang<2*60)
				{
					g_peng_ren_shi_chang=7*60;
				}

			}
		}
		else if(g_work_mode==XIAO_DU)
		{
			if(g_peng_ren_shi_chang>=1)
			{
				g_peng_ren_shi_chang-=1;
				if(g_peng_ren_shi_chang==0)
				{
					g_peng_ren_shi_chang=59;
				}
			}
		}
		else if(g_work_mode==DAN_GAO)
		{
			if(g_peng_ren_shi_chang>=1)
			{
				g_peng_ren_shi_chang-=1;
				if(g_peng_ren_shi_chang==0)
				{
					g_peng_ren_shi_chang=59;
				}
			}
		}
		else if(g_work_mode==FENG_PEI)
		{
			if(g_peng_ren_shi_chang>=1)
			{
				g_peng_ren_shi_chang-=1;
				if(g_peng_ren_shi_chang==0)
				{
					g_peng_ren_shi_chang=59;
				}
			}
		}
		else if(g_work_mode==JI_YA)
		{
			if(g_peng_ren_shi_chang>=1)
			{
				g_peng_ren_shi_chang-=1;
				if(g_peng_ren_shi_chang==0)
				{
					g_peng_ren_shi_chang=59;
				}
			}
		}
	}
}
void xiao_peng_ren_shi_jian()
{
	if(g_work_mode==DUN_ROU)
	{
		buzzer(1);
		if(g_xiao_peng_ren_shi_jian==0)
		{
			g_peng_ren_shi_chang=35;
			g_xiao_peng_ren_shi_jian=1;
			g_peng_ren_chang_duan_shi_jian=2;
		}
		else if(g_xiao_peng_ren_shi_jian==1)
		{
			g_peng_ren_shi_chang=25;
			g_xiao_peng_ren_shi_jian=2;
			g_peng_ren_chang_duan_shi_jian=0;
		}
		else if(g_xiao_peng_ren_shi_jian==2)
		{
			g_peng_ren_shi_chang=30;
			g_xiao_peng_ren_shi_jian=0;
			g_peng_ren_chang_duan_shi_jian=1;
		}
	}
	else if(g_work_mode==DUN_TANG)
	{
		buzzer(1);
		if(g_xiao_peng_ren_shi_jian==0)
		{
			g_peng_ren_shi_chang=30;
			g_xiao_peng_ren_shi_jian=1;
			g_peng_ren_chang_duan_shi_jian=2;
		}
		else if(g_xiao_peng_ren_shi_jian==1)
		{
			g_peng_ren_shi_chang=20;
			g_xiao_peng_ren_shi_jian=2;
			g_peng_ren_chang_duan_shi_jian=0;
		}
		else if(g_xiao_peng_ren_shi_jian==2)
		{
			g_peng_ren_shi_chang=25;
			g_xiao_peng_ren_shi_jian=0;
			g_peng_ren_chang_duan_shi_jian=1;
		}
	}
	else if(g_work_mode==JIAN_KANG_ZHENG)
	{
		buzzer(1);
		if(g_xiao_peng_ren_shi_jian==0)
		{
			g_peng_ren_shi_chang=15;
			g_xiao_peng_ren_shi_jian=1;
			g_peng_ren_chang_duan_shi_jian=2;
		}
		else if(g_xiao_peng_ren_shi_jian==1)
		{
			g_peng_ren_shi_chang=5;
			g_xiao_peng_ren_shi_jian=2;
			g_peng_ren_chang_duan_shi_jian=0;
		}
		else if(g_xiao_peng_ren_shi_jian==2)
		{
			g_peng_ren_shi_chang=10;
			g_xiao_peng_ren_shi_jian=0;
			g_peng_ren_chang_duan_shi_jian=1;
		}
	}
	else if(g_work_mode==MI_FAN)
	{
		buzzer(1);
		if(g_xiao_peng_ren_shi_jian==0)
		{
			g_peng_ren_shi_chang=15;
			g_xiao_peng_ren_shi_jian=1;
			g_peng_ren_chang_duan_shi_jian=2;
		}
		else if(g_xiao_peng_ren_shi_jian==1)
		{
			g_peng_ren_shi_chang=10;
			g_xiao_peng_ren_shi_jian=2;
			g_peng_ren_chang_duan_shi_jian=0;	
		}
		else if(g_xiao_peng_ren_shi_jian==2)
		{
			g_peng_ren_shi_chang=12;
			g_xiao_peng_ren_shi_jian=0;
			g_peng_ren_chang_duan_shi_jian=1;
		}
	}
	else if(g_work_mode==DOU_LEI)
	{
		buzzer(1);
		if(g_xiao_peng_ren_shi_jian==0)
		{
			g_peng_ren_shi_chang=40;
			g_xiao_peng_ren_shi_jian=1;
			g_peng_ren_chang_duan_shi_jian=2;
		}
		else if(g_xiao_peng_ren_shi_jian==1)
		{
			g_peng_ren_shi_chang=30;
			g_xiao_peng_ren_shi_jian=2;
			g_peng_ren_chang_duan_shi_jian=0;
		}
		else if(g_xiao_peng_ren_shi_jian==2)
		{
			g_peng_ren_shi_chang=35;
			g_xiao_peng_ren_shi_jian=0;
			g_peng_ren_chang_duan_shi_jian=1;	
		}
	}
	else if(g_work_mode==ZHA_LIANG)
	{
		buzzer(1);
		if(g_xiao_peng_ren_shi_jian==0)
		{
			g_peng_ren_shi_chang=25;
			g_xiao_peng_ren_shi_jian=1;
			g_peng_ren_chang_duan_shi_jian=2;
		}
		else if(g_xiao_peng_ren_shi_jian==1)
		{
			g_peng_ren_shi_chang=15;
			g_xiao_peng_ren_shi_jian=2;
			g_peng_ren_chang_duan_shi_jian=0;
		}
		else if(g_xiao_peng_ren_shi_jian==2)
		{
			g_peng_ren_shi_chang=20;
			g_xiao_peng_ren_shi_jian=0;
			g_peng_ren_chang_duan_shi_jian=1;
		}
	}
}
void key_operate()
{
	static char key_on=0;
	static short long_press_counter=0,one_times=0;
	if(g_key_code!=0)
	{
		if(key_on==1)
		{			
			if(long_press_counter<500)
			{
				long_press_counter++;
			}
			else
			{

				if(one_times++>100)
				{
					if(g_key_code==16 && g_work_mode!=0 && g_work_start==0)
					{
						key_plus();
						if(g_work_mode==DIN_WEN_PENG_REN)
						{
							key_plus();key_plus();key_plus();key_plus();key_plus();key_plus();key_plus();key_plus();key_plus();
						}
					}
					else if(g_key_code==15 && g_work_mode!=0 && g_work_start==0)
					{
						key_jian();
						if(g_work_mode==DIN_WEN_PENG_REN)
						{
							key_jian();key_jian();key_jian();key_jian();key_jian();key_jian();key_jian();key_jian();key_jian();
						}
					}
					else if(g_key_code==1 && g_work_mode==DIN_WEN_PENG_REN && g_work_start==0)
					{
						if(g_seting_wen_du==1)
						{
							g_peng_ren_wen_du++;
						}						
						if(g_peng_ren_wen_du>90)
						{
							g_peng_ren_wen_du=45;
						}
					}
					one_times=0;
				}
				if(g_key_code==13 && g_kid_lock==1)
				{
					g_kid_lock=0;
					buzzer(2);
				}
				
			}
			if(g_work_start==0)
			{
				g_operate_counter=0;
			}

		}
		else 
		{	

			long_press_counter=0;
			key_on=1;

			if(g_stop_counter>=240000)
			{
				g_stop_counter=0;
				return;
			}
			g_stop_counter=0;
			if(g_kid_lock==0)
			{
				if(g_work_start==0)
				{
					g_operate_counter=0;
					if(g_key_code==1)
					{
						buzzer(1);
						if(g_work_mode!=DIN_WEN_PENG_REN)
						{
							g_work_mode=DIN_WEN_PENG_REN;
							g_peng_ren_shi_chang=g_default_time[g_work_mode];
							g_yu_yue_shi_jian=0;
							g_yu_yue_ing=0;
							g_peng_ren_wen_du=50;
							g_din_wen_peng_ren_40_counter=40;

						}
						else
						{
							if(g_seting_wen_du==1)
							{
								g_peng_ren_wen_du++;
							}						
							if(g_peng_ren_wen_du>90)
							{
								g_peng_ren_wen_du=45;
							}
							g_seting_wen_du=1;
						}
						g_dai_P=0;
						g_dai_no_P=1;
						
					}
					else if(g_key_code==2)
					{
						buzzer(1);
						g_work_mode=DUN_ROU;
						g_peng_ren_shi_chang=g_default_time[g_work_mode];
						g_yu_yue_shi_jian=0;
						g_yu_yue_ing=0;
						g_xiao_peng_ren_shi_jian=0;
						g_peng_ren_chang_duan_shi_jian=1;
						g_peng_ren_wen_du=165;
						g_dai_P=1;
						g_dai_no_P=0;
					}
					else if(g_key_code==3)
					{
						buzzer(1);
						g_work_mode=DUN_TANG;
						g_peng_ren_shi_chang=g_default_time[g_work_mode];
						g_yu_yue_shi_jian=0;
						g_yu_yue_ing=0;
						g_xiao_peng_ren_shi_jian=0;
						g_peng_ren_chang_duan_shi_jian=1;
						g_peng_ren_wen_du=165;
						g_dai_P=1;
						g_dai_no_P=0;
					}
					else if(g_key_code==4)
					{
						buzzer(1);
						g_work_mode=LAO_HUO_MAN_DUN;
						g_peng_ren_shi_chang=g_default_time[g_work_mode];
						g_yu_yue_shi_jian=0;
						g_yu_yue_ing=0;
						g_peng_ren_wen_du=100;
						g_dai_P=0;
						g_dai_no_P=0;
					}
					else if(g_key_code==5)
					{
						buzzer(1);
						g_work_mode=JIAN_KANG_ZHENG;
						g_peng_ren_shi_chang=g_default_time[g_work_mode];
						g_yu_yue_shi_jian=0;
						g_yu_yue_ing=0;
						g_xiao_peng_ren_shi_jian=0;
						g_peng_ren_chang_duan_shi_jian=1;
						g_peng_ren_wen_du=165;
						g_dai_P=1;
						g_dai_no_P=0;
					}
					else if(g_key_code==6)
					{
						buzzer(1);
						g_work_mode=JIAN_CAO;
						g_peng_ren_shi_chang=g_default_time[g_work_mode];
						g_yu_yue_shi_jian=0;
						g_yu_yue_ing=0;
						g_peng_ren_wen_du=165;
						g_dai_P=1;
						g_dai_no_P=0;
					}
					else if(g_key_code==12)
					{
						buzzer(1);
						g_work_mode=MI_FAN;
						g_peng_ren_shi_chang=g_default_time[g_work_mode];
						g_yu_yue_shi_jian=0;
						g_yu_yue_ing=0;
						g_xiao_peng_ren_shi_jian=0;
						g_peng_ren_chang_duan_shi_jian=1;
						g_peng_ren_wen_du=165;
						g_dai_P=1;
						g_dai_no_P=0;
					}
					else if(g_key_code==11)
					{
						buzzer(1);
						g_work_mode=DOU_LEI;
						g_peng_ren_shi_chang=g_default_time[g_work_mode];
						g_yu_yue_shi_jian=0;
						g_yu_yue_ing=0;
						g_xiao_peng_ren_shi_jian=0;
						g_peng_ren_chang_duan_shi_jian=1;
						g_peng_ren_wen_du=165;
						g_dai_P=1;
						g_dai_no_P=0;
					}
					else if(g_key_code==10)
					{
						buzzer(1);
						g_work_mode=ZHA_LIANG;
						g_peng_ren_shi_chang=g_default_time[g_work_mode];
						g_yu_yue_shi_jian=0;
						g_yu_yue_ing=0;
						g_xiao_peng_ren_shi_jian=0;
						g_peng_ren_chang_duan_shi_jian=1;
						g_peng_ren_wen_du=165;
						g_dai_P=1;
						g_dai_no_P=0;
					}
					else if(g_key_code==9)
					{
						buzzer(1);
						g_work_mode=YAN_MAI;
						g_peng_ren_shi_chang=g_default_time[g_work_mode];
						g_yu_yue_shi_jian=0;
						g_yu_yue_ing=0;
						g_peng_ren_wen_du=165;
						g_dai_P=0;
						g_dai_no_P=0;
					}
					else if(g_key_code==8)
					{
						buzzer(1);
						g_work_mode=JI_DAN;
						g_peng_ren_shi_chang=g_default_time[g_work_mode];
						g_yu_yue_shi_jian=0;
						g_yu_yue_ing=0;
						g_peng_ren_wen_du=90;
						g_dai_P=0;
						g_dai_no_P=1;
					}
					else if(g_key_code==18)
					{
						buzzer(1);
						
						if(g_fun_index1==0)
						{
							g_work_mode=SUAN_NAO;
							g_peng_ren_wen_du=40;
							g_dai_P=0;
							g_dai_no_P=0;
						}
						else if(g_fun_index1==1)
						{
							g_work_mode=FA_JIAO;
							g_peng_ren_wen_du=40;
							g_dai_P=0;
							g_dai_no_P=0;
						}
						else if(g_fun_index1==2)
						{
							g_work_mode=XIAO_DU;
							g_peng_ren_wen_du=165;
							g_dai_P=1;
							g_dai_no_P=0;
						}
						
						g_fun_index1++;
						if(g_fun_index1==3)
						{
							g_fun_index1=0;
						}
						g_peng_ren_shi_chang=g_default_time[g_work_mode];
						g_yu_yue_shi_jian=0;
						g_yu_yue_ing=0;
						
					}
					else if(g_key_code==19)
					{
						buzzer(1);
						if(g_fun_index2==0)
						{
							g_work_mode=DAN_GAO;
							g_peng_ren_wen_du=165;
							g_dai_P=1;
							g_dai_no_P=0;
						}
						else if(g_fun_index2==1)
						{
							g_work_mode=FENG_PEI;
							g_peng_ren_wen_du=165;
							g_dai_P=1;
							g_dai_no_P=0;
						}
						else if(g_fun_index2==2)
						{
							g_work_mode=JI_YA;
							g_peng_ren_wen_du=165;
							g_dai_P=1;
							g_dai_no_P=0;
						}
						
						g_fun_index2++;
						if(g_fun_index2==3)
						{
							g_fun_index2=0;
						}
						g_peng_ren_shi_chang=g_default_time[g_work_mode];
						g_yu_yue_shi_jian=0;
						g_yu_yue_ing=0;
					}
					else if(g_work_mode==0 && g_key_code==7)
					{
						buzzer(1);
						g_work_mode=BAO_WEN;
						g_peng_ren_shi_chang=g_default_time[g_work_mode];
						g_yu_yue_shi_jian=0;
						g_yu_yue_ing=0;
						g_peng_ren_wen_du=60;
						g_dai_P=0;
						g_dai_no_P=0;
						g_operate_counter=2500;
						g_working_counter=1500;
					}
					else if(g_work_mode!=0 && g_key_code==7)
					{
						buzzer(1);
						g_work_mode=STOP;
					}
					else if(g_key_code==13)
					{
						buzzer(1);
						g_kid_lock=1;
					}
					else if(g_key_code==14)
					{ 
						buzzer(1);
						if(g_yu_yue_shi_jian==0 && 
							g_work_mode!=DIN_WEN_PENG_REN &&
							g_work_mode!=SUAN_NAO &&
							g_work_mode!=FA_JIAO &&
							g_work_mode!=BAO_WEN &&
							g_work_mode!=JIAN_CAO)
						{
							g_yu_yue_shi_jian=0;
							g_yu_yue_ing=1;
						}
						else 
						{
							g_yu_yue_shi_jian=0;
							g_yu_yue_ing=0;
						}
						
					}
					else if(g_key_code==16 && g_work_mode!=0)
					{
						buzzer(1);
						g_seting_wen_du=0;
						key_plus();
					}
					else if(g_key_code==15 && g_work_mode!=0)
					{
						buzzer(1);
						g_seting_wen_du=0;
						key_jian();
					}
					else if(g_key_code==17)
					{
						g_seting_wen_du=0;
						xiao_peng_ren_shi_jian();
					}
					if(g_work_mode!=DIN_WEN_PENG_REN)
					{
						g_seting_wen_du=0;
					}
					
				}
				else 
				{
					if(g_key_code==7)
					{
						buzzer(1);
						g_work_mode=STOP;
					}
					if(g_key_code==13)
					{
						buzzer(1);
						g_kid_lock=1;
					}
					if(g_key_code==1 && g_work_mode==DIN_WEN_PENG_REN)
					{
						buzzer(1);
						g_working_counter=0;
					}
				}

			}
			if(g_key_code==13)
			{
				buzzer(1);
				g_kid_lock=1;
			}

		}
		

	}
	else
	{
		key_on=0;
	}


	if(g_work_mode!=STOP && g_err_code==0)
	{

		if(g_operate_counter<2500)
		{
			g_operate_counter++;			
			if(g_operate_counter==1)
			{
				show_seting();
			}
			else if(g_operate_counter==250)
			{
				show_none();
				g_shi_jian_liang_dian=0;
			}
			else if(g_operate_counter==500)
			{
				show_seting();
			}
			else if(g_operate_counter==750)
			{
				show_none();
				g_shi_jian_liang_dian=0;
			}
			else if(g_operate_counter==1000)
			{
				show_seting();
			}
			else if(g_operate_counter==1250)
			{
				show_none();
				g_shi_jian_liang_dian=0;
			}
			else if(g_operate_counter==1500)
			{
				show_seting();
			}
			else if(g_operate_counter==1750)
			{
				show_none();
				g_shi_jian_liang_dian=0;
			}
			else if(g_operate_counter==2000)
			{
				show_seting();
				if(g_yu_yue_shi_jian==0 && g_yu_yue_ing==0)
				{
					buzzer(2);
					g_operate_counter=2500;
				}
			}
			else if(g_operate_counter==2250)
			{
				show_none();
				g_shi_jian_liang_dian=0;
			}
			else if(g_operate_counter==2496)
			{
				show_seting();
				buzzer(2);
			}
			
			g_working_counter=1500;
		}
		else
		{
			g_work_start=1;
			g_yu_yue_ing=0;
			if(g_working_counter<1500)
			{
				g_working_counter++;
				g_shu_ma_guan[0]='X';
				g_shu_ma_guan[1]=g_peng_ren_wen_du/10;
				g_shu_ma_guan[2]=g_peng_ren_wen_du%10;
				g_shu_ma_guan[3]='C';
				g_shi_jian_liang_dian=0;
			}
			else
			{		
				show_none();
				show_shu_ma_guan_working();
				show_led();

			}

			
			if(g_yu_yue_shi_jian>0)
			{
				RLY=0;
				g_hoting=0;
			}
			else
			{
				if(g_peng_ren_shi_chang>0)
				{
					if(g_work_mode==DIN_WEN_PENG_REN)
					{

						if(g_currnet_temp>g_peng_ren_wen_du || KG==1)
						{
							g_P_bao_ya_counter_start=1;
						}

						if(g_currnet_temp<g_peng_ren_wen_du-2)
						{
								RLY=1;
								g_hoting=1;	
								g_RLY_work_time++;					
						}
						else if(g_currnet_temp>g_peng_ren_wen_du+2)
						{
							RLY=0;
							g_hoting=0;
						}


						if( g_hoting==1)
						{
							static u32 t_hot=0;
							if(g_P_bao_ya_counter_start==1)
							{
								t_hot+=2;
								if(g_peng_ren_wen_du<70)
								{

									if(t_hot<10000)
									{

									}
									else if(t_hot<20000)
									{
										RLY=0;
									}
									else
									{
										t_hot=0;
									}
								}
								else
								{
									if(t_hot<15000)
									{

									}
									else if(t_hot<25000)
									{
										RLY=0;
									}
									else
									{
										t_hot=0;
									}
								}
								
							}
						}
					}
					else if(g_work_mode==DUN_ROU || 
						g_work_mode==DUN_TANG ||
						g_work_mode==JIAN_KANG_ZHENG ||
						g_work_mode==JIAN_CAO ||
						g_work_mode==DUN_TANG ||
						g_work_mode==MI_FAN ||
						g_work_mode==DOU_LEI ||
						g_work_mode==ZHA_LIANG ||
						g_work_mode==JI_YA 		
						)
					{
						if(g_currnet_temp>152 || KG==1)
						{
							g_P_bao_ya_counter_start=1;
						}

						if(g_currnet_temp<142)
						{
								RLY=1;
								g_hoting=1;	
								g_RLY_work_time++;					
						}
						else if(g_currnet_temp>148)
						{
							RLY=0;
							g_hoting=0;
						}
					}
					else if(g_work_mode==LAO_HUO_MAN_DUN || 
						g_work_mode==YAN_MAI 	
						)
					{
						if(g_currnet_temp>93 || KG==1)
						{
							g_P_bao_ya_counter_start=1;
						}

						if(g_currnet_temp<90)
						{
								RLY=1;
								g_hoting=1;	
								g_RLY_work_time++;					
						}
						else if(g_currnet_temp>93)
						{
							RLY=0;
							g_hoting=0;
						}
					}


					
					
				}
				else
				{
					if(g_work_mode!=BAO_WEN)
					{
						g_work_mode=BAO_WEN;
						g_peng_ren_shi_chang=g_default_time[g_work_mode];
						g_yu_yue_shi_jian=0;
						g_peng_ren_wen_du=60;
						g_peng_ren_over=1;
						buzzer(5);
					}
					else
					{
						g_work_mode=STOP;
					}
					
				}
			}

		}

	}
	else
	{
		show_stop();
		g_peng_ren_shi_chang=0;
		g_peng_ren_wen_du=0;
		g_work_start=0;
		g_yu_yue_shi_jian=0;
		g_operate_counter=0;
		g_work_counter=0;
		RLY=0;
		g_hoting=0;
		g_P_bao_ya_counter_start=0;
		g_yu_yue_ing=0;
		g_fun_index2=0;
		g_fun_index1=0;
	}
}
void main()
{
	short tt=0;
/************************************ÏµÍ³³õÊ¼»¯****************************************/
	CLKSWR = 0x51;						//Ñ¡ÔñÄÚ²¿¸ßÆµRCÎªÏµÍ³Ê±ÖÓ£¬ÄÚ²¿¸ßÆµRC 2·ÖÆµ£¬Fosc=16MHz
	CLKDIV = 0x01;						//Fosc 1·ÖÆµµÃµ½Fcpu£¬Fcpu=16MHz 
/**********************************UARTÅäÖÃ³õÊ¼»¯**************************************/
	// init_uart1();
	init_ntc_adc();
	init_timer0();
	init_display();
	EA = 1;								//Ê¹ÄÜ×ÜÖÐ¶Ï
    C_RLY = PP_OUTPUT;
    C_KG =IN_INPUT;
   
    show_all();
    buzzer(2);
    while(tt++<500)
    {
    	Delay_ms(2);
    	buzzer(0);
    	display();
    }
   
	while(1)
	{
		Delay_ms(2);
		key_scan();
		key_operate();
		display();
		buzzer(0);
		check_ya_li_kai_guan();
		if(tt>100)
		{
			get_temp();
			tt=0;
		}
		tt++;
		
	}
}
/***************************************************************************************
  * @ËµÃ÷  	T0ÖÐ¶Ï·þÎñº¯Êý  1ms
  *	@²ÎÊý	ÎÞ
  * @·µ»ØÖµ ÎÞ
  * @×¢		ÎÞ
***************************************************************************************/
void TIMER0_Rpt(void) interrupt TIMER0_VECTOR
{
	static unsigned int i=0;	
	if(g_work_start==1)
	{
		if(i++>60000)
		{
			i=0;		
			if(g_yu_yue_shi_jian>0)
			{
				g_yu_yue_shi_jian--;
			}
			else
			{
				if(g_peng_ren_shi_chang>0)
				{
					if(g_dai_P==1 || g_dai_no_P==1)
					{
						if(g_P_bao_ya_counter_start==1)
						{
							if(g_work_mode==DIN_WEN_PENG_REN && g_din_wen_peng_ren_40_counter>0)
							{
								g_din_wen_peng_ren_40_counter--;
							}
							else
							{
								g_peng_ren_shi_chang--;
							}
							
						}
					}
					else
					{
						g_peng_ren_shi_chang--;
					}
					
				}
			}
		}
	}
	else
	{
		i=0;
	}					
}
/***************************************************************************************
  * @ËµÃ÷  	UART1ÖÐ¶Ï·þÎñº¯Êý
  *	@²ÎÊý	ÎÞ
  * @·µ»ØÖµ ÎÞ
  * @×¢		ÎÞ
***************************************************************************************/
void UART1_Rpt(void) interrupt UART1_VECTOR
{
	if(SCON & 0x01)						//ÅÐ¶Ï½ÓÊÕÖÐ¶Ï±êÖ¾Î»
	{
	}									
}

