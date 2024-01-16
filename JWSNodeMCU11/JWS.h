static double fix_hour(double a){
  return fmod(a, 24.0);
}

void Buzzer(uint8_t state){
  if(state==1) digitalWrite(BUZZ, HIGH);
  else digitalWrite(BUZZ, LOW);
  // if(state ==1 and Prm.BZ == 1)
  //   {tone(BUZZ, 500, 400);}
  // else 
  //   {noTone(BUZZ);}
}

void get_float_time_parts(double time, uint8_t& hours, uint8_t& minutes, uint8_t& seconds){
  time = fix_hour(time + 0.5 / 60);		// add 0.5 minutes to round
  hours = floor(time);
  minutes = floor((time - hours) * 60);
  seconds = round(((time - hours)*60 - minutes)*60);
}
void get_float_time_parts(double time, uint8_t& hours, uint8_t& minutes){
  time = fix_hour(time + 0.5 / 60);		// add 0.5 minutes to round
  hours = floor(time);
  minutes = round((time - hours) * 60);
}

//ANIMASI
boolean dwDo(int DrawAdd){ 
  if (RunSel== DrawAdd) return true;
  else return false;
}
  
void dwDone(int DrawAdd){ 
  RunFinish = DrawAdd;
  // RunSel = 0;
  DoSwap = true;
}

void dwCtr(int x, int y,const char* Msg)
  { int   tw = Disp.textWidth(Msg);
    int   th = Disp.textHeight();
    int   c = int((DWidth-x-tw)/2);
    Disp.drawFilledRect(x+c-1,y,x+tw+c,y+th,0);
    Disp.drawText(x+c,y,Msg);}
  
void fType(int x){
  if(x==0) Disp.setFont(SmallCap4x6);
  else Disp.setFont(ArialBlack10); 
}
char* Konversi(byte number){ // Konversi angka agar ada nol di depannya jika di bawah 10
    static char  out[2];
    sprintf(out,"%02d",number);
    return out;
}
char* addSpace(char* text){
  static char  out[100];
  sprintf(out, "%s \0", text);
  return out;
}

void nama(uint16_t y) {
  fType(1);
  dwCtr(33, y + -1, "AUQOTUS");
  fType(1);
  dwCtr(33, y + 7, "SHOLAH");
  DoSwap = true;
}

void drawGreg_DS(uint16_t y){   //Draw Date
  char  Buff[20];
  sprintf(Buff,"%d %s %d",rTanggal,bulanmN[rBulan],rTahun);
  dwCtr(0,y,Buff);
  DoSwap = true;
}

void drawGreg_TS(int y){   // Draw Time
  char  Buff[20];
  sprintf(Buff,"%02d:%02d:%02d", rJam, rMenit, rDetik);
  dwCtr(0,y,Buff);
  DoSwap = true;
}

void drawSmallTS(int x){
  char BuffH[3], BuffM[3];
  static uint32_t   lsRn;
  uint32_t          Tmr = millis();
  sprintf(BuffH,"%02d",rJam);
  sprintf(BuffM,"%02d",rMenit);
  fType(0);
  Disp.drawText((x-10)+1,0,BuffH);
  Disp.drawText((x-10)+1,9,BuffM);
  if(Tmr-lsRn<500)Disp.drawLine((x-10)+1,7,(x-10)+9,7,1);
  if(Tmr-lsRn>1000) lsRn = Tmr;
  DoSwap = true;
} 

void anim_DT(){
  static uint8_t    y;
  static uint8_t    s; // 0=in, 1=out              
  static uint32_t   lsRn;
  uint32_t          Tmr = millis();

  if((Tmr-lsRn)>100) 
    { 
      if(s==0 and y<7){lsRn=Tmr;y++;}
      if(s==1 and y>0){lsRn=Tmr;y--;}
    }
  if((Tmr-lsRn)>10000 and y ==7) {s=1;}
  if (y==7)
    {
      Disp.drawRect(1,2,62,13);
    }
  if (y == 0 and s==1) {dwDone(RunSel); s=0;}
  fType(1);
  drawGreg_TS(y-8);
  fType(0);
  drawGreg_DS(17-y);      
}

void dwMrq(const char* msg, int Speed, int dDT){
  static int   x; 
  if (reset_x !=0) { x=0;reset_x = 0;}      
      
  static uint32_t   lsRn;
  int               fullScroll = Disp.textWidth(msg) + DWidth;    
  uint32_t          Tmr = millis();
  
  if((Tmr-lsRn)> Speed)
    { lsRn=Tmr;
      if (x < fullScroll) {++x;}
      else {  dwDone(RunSel); 
              x = 0;return;}
    if(dDT==1){
      fType(1);      
      Disp.drawText(DWidth - x, -1, msg);
      fType(0);
      if (x<=6)                     { drawGreg_TS(16-x);}
      else if (x>=(fullScroll-6))   { drawGreg_TS(16-(fullScroll-x));}
      else                          { Disp.drawRect(1,10,62,15);
                                      drawGreg_TS(10);}
    }
    else if(dDT==2){    
      fType(0);
      if (x<=6)                     { drawGreg_TS(x-6);}
      else if (x>=(fullScroll-6))   { drawGreg_TS((fullScroll-x)-6);}
      else                          { Disp.drawRect(1,0,62,5);
                                      drawGreg_TS(0);}
      fType(1);
      Disp.drawText(DWidth - x, 6 , msg);
    }
    else{
      fType(1);
      Disp.drawLine(1,2,62,2);
      Disp.drawLine(1,13,62,13);
      Disp.drawText(DWidth - x, 3, msg);
    }
    DoSwap = true; 
  }         
}

void drawSholat_S(int sNum,int c) { // Box Sholah Time
  char  BuffTime[10];
  char  BuffShol[7];
  uint8_t shour, sminute, ssecond;
  get_float_time_parts(hisab.sholatT[sNum], shour, sminute, ssecond);
  sprintf(BuffTime,"%02d:%02d:%02d",shour,sminute,ssecond);
  Disp.drawRect(c+1,2,62,13);
  fType(1); dwCtr(c,-1,hisab.sholatN[sNum]);
  fType(0); dwCtr(c,10,BuffTime);
  DoSwap = true; 
}

void drawSholat(){
  static int        x;
  static uint8_t    s; // 0=in, 1=out
  static uint8_t    sNum; 
  static uint32_t   lsRn;
  uint32_t          Tmr = millis();
  int               c=11;
  uint8_t           first_sNum = 0; 
  int               DrawWd=DWidth - c;    

  if((Tmr-lsRn)>10){
    if(s==0 and x<(DrawWd/2)){x++;lsRn=Tmr;}
    if(s==1 and x>0){x--;lsRn=Tmr;}
  }
    
  if((Tmr-lsRn)>2000 and x ==(DrawWd/2)) {s=1;}
  if (x == 0 and s==1) { 
    if (sNum <7){sNum++;}
    else { 
      dwDone(RunSel);
      sNum=0;
    } 
    s=0;
  }
  if(  (((sNum == first_sNum) and s ==0) or 
        ((sNum == 7) and s == 1)) 
        and x <=24) {drawSmallTS(int(x/2));} 
  else {drawSmallTS(10);}
  drawSholat_S(sNum, c);

  Disp.drawFilledRect(c,0,c+DrawWd/2-x,15,0);
  Disp.drawFilledRect(DrawWd/2+x+c,0,63,15,0);
}

char * drawDayDate(){
  static char  out[35];
  //sprintf(out,"%s, %d %s %dH\0",DayName(daynow),nowH.hD,locBuff,nowH.hY);
  sprintf(out,"%s %s, %02d %s %d H. \0",hariN[rHari],pasaranN[hisab.pasaran],hisab.tglH,bulanhN[hisab.blnH],hisab.thnH);
  // Serial.println(out);
  return out;
}

void drawAzzan(){
  uint8_t           ct_limit =16;  //harus angka genap
  static uint8_t    ct;
  static uint32_t   lsRn;
  uint32_t          Tmr = millis();

  if((Tmr-lsRn) > 500 and ct <= ct_limit){
    lsRn = Tmr;
    if((ct%2) == 0){
      Disp.drawRect(1,2,94,13);
      fType(0);
      dwCtr(0,0,"ADZAN");
      fType(1);
      if(jumat) {dwCtr(0,8,"JUM'AT");}
      else      {dwCtr(0,8,hisab.sholatN[WSNow]);}
      Buzzer(1);
    }else Buzzer(0);
    DoSwap = true;
    ct++;
  }
  if ((Tmr-lsRn)>2000 and (ct > ct_limit)){
    dwDone(RunSel);
    ct = 0;
    Buzzer(0);
  }
}
void drawIqomah(){    // Countdown Iqomah (9 menit)
  static uint32_t   lsRn;
  uint32_t          Tmr = millis();
  static int        ct;
  int               mnt, scd,cn_l ;
  char              locBuff[6];           
  uint8_t Iqomah[8] = {0,configjws.iqmhs,0,0,configjws.iqmhd,configjws.iqmha,configjws.iqmhm,configjws.iqmhi};
  cn_l  = (Iqomah[WSNow]*60);
  Disp.drawRect(1,2,94,13);
  if((Tmr-lsRn) > 1000 and ct <=cn_l){
    lsRn = Tmr;        
    mnt = floor((cn_l-ct)/60); 
    scd = (cn_l-ct)%60;
    if(mnt>0) {sprintf(locBuff,"%d:%02d MENIT",mnt,scd);}
      else    {sprintf(locBuff,"%d DETIK",scd);}
    dwCtr(0,-1,"IQOMAH");
    fType(0);
    dwCtr(0,9,locBuff);
    if (ct> (cn_l-6)) Buzzer(1);   // Buzzer on 2 seccon before Iqomah
    ct++;
    DoSwap = true;  
  }
  if (ct > cn_l){
    dwDone(RunSel);
    ct = 0;
    Buzzer(0);
  }    
}

void blinkBlock(){
  static uint32_t   lsRn;
  static uint32_t   ct, ct_l;
  uint32_t          Tmr = millis();
  if(jumat)       {ct_l = configjws.durasijumat * 60;}
  else            {ct_l = configjws.durasisholat * 60;}
  
  if((Tmr-lsRn)> 1000){ 
    lsRn=Tmr;
    if(jumat){
      Disp.setFont(System6x7);
      dwCtr(0, 0,"Diam saat");
      dwCtr(0, 8,"KHUTBAH!");
    }else{
      if((ct%2) == 0){ 
        Disp.drawFilledRect(DWidth-3, DHeight-3, DWidth-2, DHeight-2);
      }
      Disp.drawText(1,7,String(ct_l-ct));
    }
    DoSwap = true; 
    ct++;
  }
  if (ct> ct_l) { 
    dwDone(RunSel);
    azzan = false;
    jumat = false;
    ct = 0;
  }
}