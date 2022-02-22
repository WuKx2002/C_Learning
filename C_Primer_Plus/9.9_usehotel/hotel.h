#define HOTEL1		180.00
#define HOTEL2		225.00
#define HOTEL3		2255.00
#define HOTEL4		355.00
#define DISCOUNT	0.95
#define QUIT		5
#define STARS		"**************************************************"

void stars(void);//产生星号线

int menu(void);//显示菜单并读取输入的酒店号

int getNights(void);//获得用户预定天数

void showPrice(int nights,double roomPrice);//计算总价
