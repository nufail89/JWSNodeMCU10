
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <WebSocketsServer.h>
#include <DNSServer.h>
#include <ESP8266mDNS.h>
#include <ESP8266HTTPUpdateServer.h>
//#include <ESPAsyncTCP.h>
//#include <ESPAsyncWebServer.h>
#include <FS.h>
#include <ArduinoJson.h>
// #include <SoftwareSerial.h>
#include <DFMiniMp3.h>
#include <Wire.h>
#include <RtcDS3231.h>
#include <DMDESP.h>
#include <HisabFalak.h>
#include <fonts/SmallCap4x6.h>
#include <fonts/Angka6x14.h>
#include <fonts/SystemFont5x7.h>
#include <fonts/System6x7.h>
#include <fonts/Angka4x7.h>
#include <fonts/ElektronMart6x8.h>

//Public Declarations
//==============================================
#define BUZZ    A0
#define Relay   2  //pin relay D4 (GPIO 2)

RtcDS3231<TwoWire>  Rtc(Wire);
Hisab               hisab;
char *      DispWaktu;

// Time Variable
//==============================================
boolean         DoSwap = false;
uint8_t         reset_x   = 0;   
uint8_t         RunSel    = 1; //
uint8_t         RunFinish = 0 ;
int8_t          WSNow;
boolean         jumat      = false;
boolean         azzan      = false;
boolean         isConnected = false;

#include "Display.h"
#include "DFPlayer.h"
#include "RTC.h"
#include "FSConfig.h"
#include "WebServer.h"
#include "WebPage.h"
#include "JWS.h"


void setup(){
  pinMode(BUZZ, OUTPUT);
  pinMode(Relay, OUTPUT);
  Serial.begin(115200);
  
  mulaiRTC();
  BacaRTC();

  // Inisialisasi file sistem berkas SPIFFS
  if (!SPIFFS.begin()) {
    Serial.println("Failed to mount file system");
    return;
  }
  loadWifiConfig(fileconfigwifi,configwifi);
  loadDfConfig(fileconfigdf, configdf);
  loadJwsConfig(fileconfigjws, configjws);
  loadInfoConfig(fileconfiginfo, configinfo);
  loadDispConfig(fileconfigdisp, configdisp);
  LoadDataAwal();

  WifiConnect();
  if(!isConnected){
    server.onNotFound([]() {
      server.send(200, "text/html", webpage );
    });
  }
  server.on("/",[](){
    server.send_P(200, "text/html", webpage);
  });
//  server.sendHeader("Location", "http://192.168.4.1/", true);
  server.on("/xmlwaktu", handleXMLWaktu); // http://192.168.4.1/xmlwaktu
  server.on("/xml", handleXMLDataJWS); // http://192.168.4.1/xml
  server.begin();
  
  webSocket.begin();
  webSocket.onEvent(webSocketEvent);
  
  Hitung();
  // Tampilkan Parameter yang tersimpan
//  bacaParameter();
  // jika tidak layar tidak akan tampil.
  mulaiMP3();
  mp3.setVolume(configdf.volume);
  // DMDESP Setup
  Disp_init();
  Disp.setBrightness(configdisp.kecerahan);
  digitalWrite(BUZZ, LOW);
  digitalWrite(Relay, LOW);
}

void loop(){
  // if(millis()<172800000){       //menjalankan server internal (setingan) selama 2 hari saja
    
  // }else WiFi.mode(WIFI_OFF);
  if(!isConnected){
    dnsServer.processNextRequest();
    MDNS.update();
  }
  webSocket.loop();
  server.handleClient();

  Timer_Minute(); // fungsi timer recalculate hisab setiap 10 Minutes
  if(configdf.autotarhim==1) check_tartil();
  BacaRTC();
  tampilDMD();
}

void tampilDMD(){
  DoSwap  = false ;
  Disp.clear();
  fType(1);
  // List of Display Component Block =========
  // =========================================
  switch(RunSel){
    case 1: anim_masjid(); break;
    case 2: anim_DT();  break;
    case 3: dwMrq(addSpace(configinfo.nama),configinfo.kecepatan,1); break;
    case 4: dwMrq(drawDayDate() ,configinfo.kecepatan,2); break;
    case 5: drawSholat(); break;
    case 6: dwMrq(addSpace(configinfo.info1),configinfo.kecepatan,2); break;
    case 7: anim_DT();  break;
    case 8: dwMrq(addSpace(configinfo.info2),configinfo.kecepatan,1); break;
    case 9: drawSholat(); break;
    case 30:DFPlayer();break;
    case 31:TestLED();break;
    case 32:tampilIP();break;
    case 100: drawAzzan(); break;
    case 101: drawIqomah(); break;
    case 102: dwMrq("Lurus dan rapatkan Shoff untuk kesempurnaan sholat !!" ,configinfo.kecepatan,2); break;
    case 103: dwMrq("DIAM SAAT KHUTBAH !" ,configinfo.kecepatan,2); break;
    case 104: blinkBlock(); break;
  }
  // Display Control Block ===================
  // =========================================
  switch(RunFinish){
    case 0: break;
    case 1: RunSel = 2; RunFinish =0; break;  //after anim 1 set anim 2
    case 2: RunSel = 3; RunFinish =0; break;
    case 3: RunSel = 4; RunFinish =0; break;
    case 4: RunSel = 5; RunFinish =0; break;
    case 5: RunSel = 6; RunFinish =0; break;
    case 6: RunSel = 7; RunFinish =0; break;
    case 7: RunSel = 8; RunFinish =0; break;
    case 8: RunSel = 9; RunFinish =0; break;
    case 9: RunSel = 2; RunFinish =0; break;
    case 100: {
      if(jumat){
        RunSel = 103; RunFinish = 0; reset_x = 1;
      }else{
        RunSel = 101; RunFinish =0;
      }
    } break;
    case 101: RunSel = 102; RunFinish =0; reset_x=1; break;     //after Iqomah(anim 101) set Message Sholah (anim 102)
    case 102: RunSel = 104; RunFinish =0; break;                //after Message Sholah (anim 102) set Blink Sholah(anim 104) 
    case 103: RunSel = 104; RunFinish =0; break;                //after Message Jum'at (anim 103) set Blink Sholah(anim 104)
    case 104: RunSel = 2; RunFinish =0; digitalWrite(Relay, LOW);break;                  //after Blink Sholah back to anim 2
  }
  if(DoSwap) Disp.swapBuffers();
}


void Hitung(){
  BacaRTC();
  hisab.setDateTime(rTanggal, rBulan, rTahun, rJam, rMenit, rDetik); //set waktu tanggal, bulan, tahun, jam, menit, detik
  uint8_t ihtiyat[] = {configjws.ihtis,2,configjws.ihtid,configjws.ihtia,configjws.ihtim,configjws.ihtii};	//Ihtiyat subuh, dluha, dhuhur, ashar, maghrib, isya
  hisab.setIhtiyat(ihtiyat);
  hisab.setLocation(configjws.latitude, configjws.longitude, configjws.altitude, configjws.zonawaktu);
  double inkhifad[] = { configjws.inkhifadi, configjws.inkhifads };
  hisab.setInkhifad(inkhifad);
  hisab.hitung_sholatT();
  hisab.msh_to_hjr();
}

void DFPlayer() {
  char vol[3];
  sprintf(vol, "%02d", configdf.volume);

  char track[4];
  sprintf(track, "%03d", currentTrack);

  Disp.setFont(ElektronMart6x8);
  Disp.drawText(1,0, "Volume");
  Disp.drawText(1,8, vol);
  Disp.drawText(1,8, vol);
  Disp.drawRect(16,8, 16 + (configdf.volume * 24 / 30),14,1,1);

  Disp.drawText(50,0, "TR");
  Disp.drawText(43,8, track);  
  DoSwap=true;
}

void TestLED() {
  Disp.drawRect(0, 0, DWidth, 15, 1, 1);
  DoSwap=true;
}
void tampilIP(){
  char bufIP[20];
  sprintf(bufIP,"%s", WiFi.localIP());
  dwMrq(addSpace(bufIP),configinfo.kecepatan,0);
}

void check_azzan(){ //Check Waktu Sholat
  WSNow  = 0;
  for(uint8_t i=0; i<8; i++){
    if (i!=0 && i!=2 && i!=3){  // bukan imsak, thulu' dan bukan dhuha
      if(secnow >= hisab.sholatTSec[i] ){
        WSNow = i;
        if(!azzan && (secnow > hisab.sholatTSec[i]) && (secnow < (hisab.sholatTSec[i]+60))) {
          if(rHari==5 && WSNow==4) {jumat=true;}  //ketika hari Jumat dan Waktusholat sekarang adalah dhuhur
          // else jumat=false;
          azzan =true;
          digitalWrite(Relay, LOW);
          RunSel = 100;
        }
      }
    }
  }
}

void check_tartil(){
  uint8_t tarhimmenit[8] = {0, configdf.tarhimmenits, 0, 0, configdf.tarhimmenitd, configdf.tarhimmenita, configdf.tarhimmenitm, configdf.tarhimmeniti};
  uint8_t tarhimtracks[8] = {0, configdf.tarhimtracks, 0, 0, configdf.tarhimtrackd, configdf.tarhimtracka, configdf.tarhimtrackm, configdf.tarhimtracki};
  if(rHari==5) {
    tarhimmenit[2]=configdf.tarhimmenitjm; //ada di index thulu' karena diskip pada saat cek azan
    tarhimtracks[2]=configdf.tarhimtrackj;
  }
  uint8_t WSNext = (WSNow+1)%8;
  if(WSNext==2) WSNext = 4;
  uint32_t waktu_muni=hisab.sholatTSec[WSNext]-tarhimmenit[WSNext]*60-5;
  // Serial.print("ws next: ");Serial.println(WSNext);
  // Serial.print("secnow: ");Serial.println(secnow);
  // Serial.print("waktu muni : ");Serial.println(waktu_muni);
  // Serial.print("Status Relay : ");Serial.println(digitalRead(Relay));
  if(secnow==waktu_muni && digitalRead(Relay)==0){
    digitalWrite(Relay, HIGH);
    delay(5000);
    mp3.playMp3FolderTrack(tarhimtracks[WSNext]);
  }
}

//fungsi update setiap 10 menit
void Timer_Minute(){ 
  static uint32_t   lsRn;
  static uint32_t   lsRn2;
  uint32_t          Tmr = millis();
  if((Tmr-lsRn)>(10*60000)){
    lsRn =Tmr;
    Hitung();
  }
  if((Tmr-lsRn2)>500){
    check_azzan();
    check_tartil();
    lsRn2=Tmr;
  }
}