#define ledPin 10

String MORSE[26]={ 
  "._", "_...", "_._.", "_..", ".", "..-.", "__.", "....",  "..",
  ".___", "_._", "._..", "__", "_.", "___", ".__.",  "__._", "._.", 
  "...", "_", ".._", "..._", ".__", "_.._", "_.__", "__.." 
  };
  
void setup()
{ 
  pinMode(ledPin,OUTPUT);
  Serial.begin(9600);
}
void loop()
{  
   char str = "";  //接收输入的字母  
   String morse = "";  //输入字母对应的摩斯密码  
   if(str >= 65 && str <= 90) { morse = MORSE[str-65]; } //如果是大写字母  
   else if(str >= 97 && str <= 122) { morse = MORSE[str-97]; } //如果是小写字母  
   if(morse != "") //如果摩斯密码不为空  
   {    
    Serial.println(morse);  //输出摩斯密码    
    for(int i = 0; i < 4; i++)    
     {      
      if(morse[i]==".") //如果是 . 灯亮 250 毫秒      
    {       
      digitalWrite(ledPin,HIGH);
      delay(250);        
      digitalWrite(ledPin,LOW);     
    }     
      else if(morse[i]=="_")  //如果是 _ 灯亮750毫秒      
          {       
            digitalWrite(ledPin,HIGH);        
            delay(750);         
            digitalWrite(ledPin,LOW);     
                   }      
        delay(250); //摩斯密码之间间隔 250 毫秒    
     } 
   }
 }
