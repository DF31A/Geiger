#include

#include

#define LOG_PERIOD 15000//记录周期（以毫秒为单位），建议值15000-60000。

#define MAX_PERIOD 60000//不修改此草图的最长记录周期

#define PERIOD 60000.0//（60秒）一分钟测量周期

//易失性无符号长CNT ;//用于计算剂量计中断的变量

//无符号长计数;//GM管事件的变量

unsigned long cpm;//CPM的变量//无符号长CPM;//用于测量CPM的变量

unsigned int multiplier;//用于计算此草图中的CPM的变量

unsigned long previousMillis;//用于时间测量的变量

unsigned long dispPeriod;//用于测量时间的变量



//使用接口引脚的编号初始化库

LiquidCrystal lcd（9，8，7，6，5，3）;

void setup（）
{

lcd.begin（16，2）;

CNT = 0;

CPM = 0;

dispPeriod = 0;

lcd.setCursor（0，0）;

lcd.print（“RH Electronics”）;

lcd.setCursor（0，1）;

lcd.print（“盖革计数器”）;

delay（2000）;

cleanDisplay（）

attachInterrupt（0，GetEvent，下降）;//引脚2上的事件

}

void loop（）{

lcd.setCursor（0，0）;//在LCD上打印文本和CNT

lcd.print（“CPM：”）;

lcd.setCursor（0，1）;

lcd .print（“CNT：”）;

lcd.setCursor（5，1）;

lcd.print（CNT）;

if（millis（ ）>= dispPeriod + PERIOD）{//如果一分钟结束

cleanDisplay（）;//清除LCD

//对累积的CNT事件做一些事情。..。..

lcd.setCursor（5，0）;

CPM = CNT;

lcd.print（CPM）;//显示CPM

CNT = 0;

dispPeriod = millis（）;

}

}

void GetEvent（）{//从设备获取事件

CNT ++;

}

void cleanDisplay（）{//清除LCD例程

lcd.clear（）;

lcd.setCursor（0，0）;

lcd.setCursor（0，0）;

}
