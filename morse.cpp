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
   char str = "";  //�����������ĸ  
   String morse = "";  //������ĸ��Ӧ��Ħ˹����  
   if(str >= 65 && str <= 90) { morse = MORSE[str-65]; } //����Ǵ�д��ĸ  
   else if(str >= 97 && str <= 122) { morse = MORSE[str-97]; } //�����Сд��ĸ  
   if(morse != "") //���Ħ˹���벻Ϊ��  
   {    
    Serial.println(morse);  //���Ħ˹����    
    for(int i = 0; i < 4; i++)    
     {      
      if(morse[i]==".") //����� . ���� 250 ����      
    {       
      digitalWrite(ledPin,HIGH);
      delay(250);        
      digitalWrite(ledPin,LOW);     
    }     
      else if(morse[i]=="_")  //����� _ ����750����      
          {       
            digitalWrite(ledPin,HIGH);        
            delay(750);         
            digitalWrite(ledPin,LOW);     
                   }      
        delay(250); //Ħ˹����֮���� 250 ����    
     } 
   }
 }
