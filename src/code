#include <Servo.h>
#include <Pixy2.h>
Pixy2 pixy;
int color;
Servo servo;
int f1=0; int f2=0;
void setup()
{
  servo.attach(5);
  Serial.begin(115200);  
  pixy.init();
}

void loop()
{ 
  int i; 
  pixy.ccc.getBlocks();
  
  if (pixy.ccc.numBlocks)
  {
    f1=0; f2=0;
        for (int i=0; i<pixy.ccc.numBlocks; i++)
        {
          if (pixy.ccc.blocks[i].m_signature==1)servo.write(55);delay(400); //f1=f1+pixy.ccc.blocks[i].m_width*pixy.ccc.blocks[i].m_height;
          if (pixy.ccc.blocks[i].m_signature==2)servo.write(105); delay(400);//f2=f2+pixy.ccc.blocks[i].m_width*pixy.ccc.blocks[i].m_height;
        servo.write(75);
        delay(100);
        }
        //if (f1>f2) servo.write(70);
        //if (f2>f1) servo.write(130);
      } 
    }
   

