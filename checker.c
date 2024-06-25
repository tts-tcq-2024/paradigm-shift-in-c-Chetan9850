#include <stdio.h>
#include <assert.h>

int main() {
   float temperature;
   float soc; 
   float chargeRate;
   
   assert(temperature == 25);
   assert(soc == 70);
   assert(chargeRate == 0.7);
   
   if (temperature < 0 || temperature > 45) {
     printf("Temperature out of range!\n");
     return 0;
   } 
   if (soc < 20 || soc > 80) {
     printf("State of Charge out of range!\n");
     return 0;
   } 
   if (chargeRate > 0.8) {
     printf("Charge Rate out of range!\n");
     return 0;
   }
   
   return 1;
}
