#include <iostream.h>

int notes [127];

int fadespeeds[]   = {0,0,0,0};
int fadeindest[]   = {0,0,0,0};
int fadeoutdest[]  = {0,0,0,0};
int levels[]       = {0,0,0,0,0,0,0,0,0};
int counters[]     = {0,0,0,0};
int step[]         = {0,0,0,0};

void all_lights_on(int brightness)
{
   play_note(16,1,brightness);
   play_note(16,2,brightness);
   play_note(16,3,brightness);
   play_note(16,4,brightness);
   for (int index=0;index<4;index++)
      levels[index] = brightness;
}

void all_lights_off(int brightness)
{
   for (int index=1;index<16;index++)
      kill_note(16,index,0);
   kill_note(16,1,brightness);
   kill_note(16,2,brightness);
   kill_note(16,3,brightness);
   kill_note(16,4,brightness);
   for (index=0;index<4;index++)
      levels[index] = brightness;
}

void change_light_level(int lightnum, int brightness)
{
   if (brightness == 0)
   {
      kill_note(16,lightnum,127);
      levels[lightnum-1] = 0;
   } else
   {
      play_note(16,lightnum,brightness);
      levels[lightnum-1] = brightness;
   }
}

void fade_in_light (int lightnum, int speed, int destbrightness, int nstep)
{
   fadespeeds[lightnum-1]    = speed;
   fadeindest[lightnum-1]    = destbrightness;
   fadeoutdest[lightnum-1]   = 0;
   counters[lightnum-1]      = 0;
   step[lightnum-1]          = nstep;
}

void fade_out_light(int lightnum, int speed, int destbrightness, int nstep)
{
   fadespeeds[lightnum-1]    = speed;
   fadeindest[lightnum-1]    = 0;
   fadeoutdest[lightnum-1]   = destbrightness;
   counters[lightnum-1]      = 0;
   step[lightnum-1]          = nstep;
}

void do_fade_stuff()
{
   for (int lightnum=0;lightnum<4;lightnum++)
   {
      if (fadeoutdest[lightnum] != 0)
      {
         if (counters[lightnum] <= fadespeeds[lightnum])
            counters[lightnum]++;
         else
         {
           counters[lightnum] = 0;
           if (levels[lightnum] <= 1)
               levels[lightnum] = 0;
//           kill_note(16,lightnum+1,0);  //old kill here
           change_light_level(lightnum+1,levels[lightnum]);

           if (levels[lightnum] > fadeoutdest[lightnum])
               levels[lightnum]-=step[lightnum]; else
               {
                  kill_note(16,lightnum+1,0);
                  change_light_level(lightnum+1,levels[lightnum]);
                  fadeoutdest[lightnum] = 0;
                  counters[lightnum] = 0;
               }

           if (levels[lightnum] <= fadeoutdest[lightnum])
           {
              kill_note(16,lightnum+1,0);
              //old kill here
              change_light_level(lightnum+1,levels[lightnum]);

              fadeoutdest[lightnum] = 0;
              counters[lightnum] = 0;
              levels[lightnum] = 0;
              return;
           }
        }
     }

      //Do fade in 
      if (fadeindest[lightnum] != 0)
      {
         if (counters[lightnum] <= fadespeeds[lightnum])
            counters[lightnum]++;
         else
         {
            counters[lightnum] = 0;           
            if (levels[lightnum] >= 127)
               levels[lightnum] = 127;
//            kill_note(16,lightnum+1,0);
            change_light_level(lightnum+1,levels[lightnum]);
            if (levels[lightnum] < fadeindest[lightnum])
               levels[lightnum]+=step[lightnum]; else
               {
                  kill_note(16,lightnum+1,0);
                  change_light_level(lightnum+1,levels[lightnum]);
                  fadeindest[lightnum]=0;
                  fadeoutdest[lightnum] = 0;
                  fadespeeds[lightnum] = 0;
                  counters[lightnum] = 0;
                  return;
               }
         }
   }}
}
