//此草图计算每分钟的脉冲数。

//将Arduino上的GND连接到Geiger计数器的GND。

//2号引脚 计数器  3号引脚 蜂鸣器

//将盖革计数器上的VIN连接到Arduino上的D2。
#define LOG_PERIOD 15000
#define MAX_PERIOD 60000//不修改此草图的最长记录周期
unsigned long counts=0;
unsigned long PreviousMillis=0;
int pinBuzzer = 6;  //设置pinBuzzer脚
long frequency = 3; //蜂鸣器频率, 单位Hz

void impulse(){
  counts++;   
  digitalWrite(pinBuzzer,LOW);
  delay(10000);
  digitalWrite(pinBuzzer,HIGH);
}
void setup() {
  pinMode(2,INPUT);
  pinMode(pinBuzzer, OUTPUT); //设置pinBuzzer脚为输出状态
  digitalWrite(pinBuzzer,HIGH);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(2),impulse,RISING);//定义外部中断
  Serial.println("Start counter"); 
  Serial.println("CMP:"); 
}

void loop() {
   unsigned long currentMillis = millis();
   if (currentMillis - PreviousMillis > LOG_PERIOD){
    PreviousMillis = currentMillis;
    Serial.println(counts);
    counts=0;
   }
}
