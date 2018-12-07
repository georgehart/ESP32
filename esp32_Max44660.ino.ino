/*******************************************************
TFE 2019
ESP32

Calibration \checker based on a MAXIM 4466 Amplifier

Hart Georges

********************************************************/

int sensorPin = A0;
unsigned int sample;
const int sampleWindow = 20;

 
void setup()
{
   Serial.begin(115200);
}
 
 
void loop()
{

// ------------------------------------------------------------------

   unsigned long startMillis= millis();
   unsigned int peakToPeak = 0;
   unsigned int signalMax = 0;
   unsigned int signalMin = 1024;
   
   
   while (millis() - startMillis < sampleWindow)
   {
    sample = analogRead(sensorPin);
      if (sample < 1024)
      {  
        if (sample > signalMax)
        {
          signalMax = sample;
        }
        else if (sample < signalMin)
        {
            signalMin = sample;
        }
      }
   }
   peakToPeak = signalMax - signalMin;
   double volts = ((peakToPeak * 15) / 1024);
   double rms = (volts*(sqrt(2)/2));

/* ------------------------------------------   
      Serial.print(100* volts);
      Serial.print(" - ");
--------------------------------------------- */
  

      Serial.println(rms*100);
      rms=0;
     
}








  

