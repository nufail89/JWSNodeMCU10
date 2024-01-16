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
  if(x==0) Disp.setFont(SystemFont5x7);
  else Disp.setFont(System6x7);
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

//====================
void lafadza(int x){
static const uint8_t satu[] PROGMEM = {
                    16,15,
                    0x00,0x84,
                    0x05,0x84,
                    0x07,0x04,
                    0x00,0x04,
                    0x00,0x04,
                    0x00,0x24,
                    0x00,0xA6,
                    0x08,0xB2,
                    0x08,0xB2,
                    0x18,0x92,
                    0x38,0xD2,
                    0x68,0xF2,
                    0x7D,0xF0,
                    0xF7,0x30,
                    0x07,0x00,
  };                                          
  Disp.drawBitmap(x,1, satu);      
}

void lafadzb(int x){
   static const uint8_t dua[] PROGMEM = {
                          16,14,
                          0x18,0x08,
                          0x0C,0x14,
                          0x06,0x1C,
                          0x06,0x70,
                          0x06,0xC0,
                          0x06,0x80,
                          0x06,0xFF,
                          0x06,0x1E,
                          0x1B,0xF8,
                          0xB1,0x80,
                          0xE0,0x6C,
                          0x00,0x7E,
                          0x00,0x12,
                          0x00,0x0C,
  };                                   
  Disp.drawBitmap(x,1, dua);      
}
void logoax(int x) {
  static const uint8_t logoax[] PROGMEM = {
    16, 16,
    B00000000,B00000000,
    B01100110,B01111110,
    B01100110,B01111110,
    B01100110,B01100110,
    B01100110,B01100110,
    B01111110,B01111110,
    B01111110,B01111110,
    B01100000,B01100000,
    B01100000,B01100000,
    B01111110,B01111110,
    B01111110,B01111110,
    B01100110,B00000110,
    B01100110,B00000110,
    B01111111,B11111110,
    B01111111,B11111110,
    B00000000,B00000000
  };
  Disp.drawBitmap(x, 0, logoax);
}

void logobx(int x) {
  static const uint8_t logobx[] PROGMEM = {
    16, 16,
    B00000000,B00000000,
    B01111111,B11111110,
    B01111111,B11111110,
    B00000000,B00000000,
    B00000000,B00000000,
    B01111110,B01100110,
    B01111110,B01100110,
    B00000110,B01100110,
    B00000110,B01100110,
    B01111110,B01100110,
    B01111110,B01100110,
    B01100110,B01100110,
    B01100110,B01100110,
    B01111111,B11111110,
    B01111111,B11111110,
    B00000000,B00000000
  };
  Disp.drawBitmap(x, 0, logobx);
}

void masjida(uint16_t y) {
  static const uint8_t dall[] PROGMEM = {
    16, 16,
    B00100000,  B00000001,
    B01110000,  B00000011,
    B01110000,  B00000111,
    B00100000,  B00001111,
    B00100000,  B00011111,
    B01110000,  B00011111,
    B11111000,  B00001111,
    B01110000,  B00000111,
    B01110111,  B11111111,
    B01110000,  B00000000,
    B01110111,  B11111111,
    B01110111,  B01111110,
    B01110110,  B00111100,
    B01110110,  B00111100,
    B01110110,  B00111100,
    B11111111,  B11111111
  };
  Disp.drawBitmap(1, y, dall);
  DoSwap = true;
}
void masjidb(uint16_t y) {
  static const uint8_t eall[] PROGMEM = {
    16, 16,
    B00000000,  B00011100,
    B10000000,  B00100010,
    B11000000,  B00001011,
    B11100000,  B00000010,
    B11110000,  B00001100,
    B11110000,  B00001000,
    B11100000,  B00111110,
    B11000000,  B00011100,
    B11111111,  B11011100,
    B00000000,  B00011100,
    B11111111,  B11011100,
    B11111101,  B11011100,
    B01111000,  B11011100,
    B01111000,  B11011100,
    B01111000,  B11011100,
    B11111111,  B11111110
  };
  Disp.drawBitmap(17, y, eall);
  DoSwap = true;
}

void nama(uint16_t y) {
  fType(1);
  dwCtr(33, y + -1, "AUQOTUS");
  fType(1);
  dwCtr(33, y + 7, "SHOLAH");
  DoSwap = true;
}


void anim_masjid(){
  static uint8_t    y;
  static uint8_t    s; // 0=in, 1=out
  static uint32_t   lsRn;
  uint32_t          Tmr = millis();

  if ((Tmr - lsRn) > 100){
    if (s == 0 and y < 16) {
      lsRn = Tmr;
      y++;
    }
    if (s == 1 and y > 0) {
      lsRn = Tmr;
      y--;
    }
  }
  
  if ((Tmr - lsRn) > 3000 and y == 16) {
    s = 1;
  } //10000
  if (y == 16){

  }
  if (y == 0 and s == 1) {
    dwDone(RunSel);
    s = 0;
  }
  nama(16 - y);
  masjida(16 - y);
  masjidb(16 - y);
}

void drawGreg_DS(uint16_t y){   //Draw Date 
  char  Buff[20];
  sprintf(Buff,"%d %s %d",rTanggal,bulanmN[rBulan],rTahun);
  dwCtr(0,y,Buff);
  DoSwap = true;
}

void drawSmallTS(int x){
  static uint32_t   lsRn;
  static uint32_t   pulseDtk;
  uint32_t          Tmr = millis();
  static uint8_t    lsdtk,ldtk,y;

  Disp.drawFilledRect(0,0,40,15,0);
  Disp.setFont(Angka6x14);
  Disp.drawText((x-20)+8,1,Konversi(rJam));
  Disp.drawText((x-20)+24,1,Konversi(rMenit));
  Disp.setFont(Angka4x7);
  
  if(Tmr-pulseDtk>15 && y<11){
    pulseDtk=Tmr;
    y++;
    if(y==10) lsdtk=ldtk;
  }
  if(ldtk!=rDetik){
    y=0;ldtk=rDetik;
  }
  Disp.drawText((x-20)+39,4-y,Konversi(lsdtk));
  Disp.drawText((x-20)+39,15-y,Konversi(rDetik));
  // animasiDetik(x);
  
  if(Tmr-lsRn<500){
    for(uint8_t ug=0;ug<2;ug++){
      uint8_t tb=(x-28)+ug*16;
      Disp.drawLine(14+tb, 3, 15+tb, 4, 1);
      Disp.drawLine(13+tb, 4, 14+tb, 5, 1);
      Disp.drawLine(14+tb, 10, 15+tb, 11, 1);
      Disp.drawLine(13+tb, 11, 14+tb, 12, 1);
    }
  }
  if(Tmr-lsRn>1000){
    lsRn=Tmr;
  }
  DoSwap = true;
}
    

void drawGreg_TS(int y){   // Draw Time
  char  Buff[20];
  sprintf(Buff,"%02d:%02d:%02d", rJam, rMenit, rDetik);
  dwCtr(0,y,Buff);
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
  
    if((Tmr-lsRn)>7000 and y ==7) {s=1;}
    if (y==7)
      {
        Disp.drawRect(1,2,94,13);
    
      }
   
    if (y == 0 and s==1) {dwDone(RunSel); s=0;}
   
    fType(1);
    drawGreg_TS(y-8);
    fType(0);
    drawGreg_DS(16-y);  
    }

void dwMrq(const char* msg, int Speed, int dDT){
  static int   x; 
  if (reset_x !=0) { x=0;reset_x = 0;}      
  //  if (azzan !=0) { x=0; azzan = 0;} 
      
  static uint32_t   lsRn;
  int               fullScroll = Disp.textWidth(msg) + DWidth;    
  uint32_t          Tmr = millis();
  
  if((Tmr-lsRn)> Speed){ 
    lsRn=Tmr;
    if (x < fullScroll) ++x;
    else {  dwDone(RunSel); 
            x = 0;return;}
    if(dDT==1) {
      fType(0);
      // Disp.drawFilledRect(0,0,DWidth,7,0);
      Disp.drawText(DWidth - x, 9, msg);

      Disp.drawFilledRect(0,0,18,15,0);
      Disp.drawFilledRect(DWidth-19,0,DWidth,15,0);

      if(x<17)                    {lafadzb(x-17); lafadza(DWidth-x); }
      else if (x>(fullScroll-17)) {lafadzb((fullScroll-x)-17); lafadza(DWidth-(fullScroll-x)); }
      else                        {lafadzb(1); lafadza(DWidth-17); } //lafadzb (Muhammad), lafadza (Allah)
      
      fType(1);
      Disp.drawFilledRect(18,0,DWidth-19,7,0);
      if (x<=6)                     { drawGreg_TS(x-8);}
      
      else if (x>=(fullScroll-6))   { drawGreg_TS((fullScroll-x)-12);}
      else                          { //Disp.drawRect(24,1,70,7);
                                      drawGreg_TS(-1);}
    }
    else if(dDT==2){    
      fType(1);
      Disp.drawFilledRect(18,0,DWidth-19,7,0);
      if (x<6)                     { drawGreg_TS(x-6);}                //jatuh ke bawah
      else if (x>(fullScroll-6))   { drawGreg_TS((fullScroll-x)-6);}   //naik ke atas
      else                          { //Disp.drawRect(1,5,62,5);
                                      drawGreg_TS(-1);}
      fType(0);
      Disp.drawText(DWidth - x, 9 , msg);
      Disp.drawFilledRect(0,0,18,15,0);
      Disp.drawFilledRect(DWidth-19,0,DWidth,15,0);
      // Disp.drawFilledRect(18,0,19,15,1);
      // Disp.drawFilledRect(DWidth-20,0,DWidth-19,15,1);
      if(x<17)                    {logoax(x-17); logobx(DWidth-x); }
      else if (x>(fullScroll-17)) {logoax((fullScroll-x)-17); logobx(DWidth-(fullScroll-x)); }
      else                        {logoax(1); logobx(DWidth-17); } //logoax (Muhammad), logobx (Allah)
    }
    else{
    fType(1);
    Disp.drawText(DWidth - x, 3, msg);
    lafadza(DWidth-17);
    lafadzb(1);
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
  Disp.drawRect(c+1,2,94,13);
  fType(1); dwCtr(c,-1,hisab.sholatN[sNum]);
  fType(0); dwCtr(c,9,BuffTime);
  DoSwap = true;          
}

void drawSholat(){
  static int        x;
  static uint8_t    s; // 0=in, 1=out
  static uint8_t    sNum; 
  static uint32_t   lsRn;
  uint32_t          Tmr = millis();
  int               c=40;
  uint8_t           first_sNum = 0; 
  int               DrawWd=DWidth - c;    

  if((Tmr-lsRn)>15){
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
  else {drawSmallTS(12);}
  drawSholat_S(sNum, c);

  Disp.drawFilledRect(c,0,c+DrawWd/2-x,15,0);
  Disp.drawFilledRect(DrawWd/2+x+c,0,95,15,0);
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