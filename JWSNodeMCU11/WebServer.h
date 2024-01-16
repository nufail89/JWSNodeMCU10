ESP8266WebServer server(80);
ESP8266HTTPUpdateServer httpUpdater;
WebSocketsServer webSocket = WebSocketsServer(81);
const byte DNS_PORT = 53;
DNSServer dnsServer;
const char* host = "jws.local";

void WifiConnect(){
  pinMode(LED_BUILTIN, OUTPUT); 
  Serial.println("Wifi Station Mode");
  WiFi.persistent(false);
  WiFi.setSleepMode(WIFI_NONE_SLEEP);
  WiFi.mode(WIFI_STA);
  WiFi.begin(configwifi.wifissid,configwifi.wifipassword);
  while(WiFi.status()!=WL_CONNECTED){
    Serial.print(".");
    delay(500);
    if(millis() > configwifi.durasicari*1000) {
    // if(millis() > 2*1000) {
      isConnected=false;
      break;
    }
  }
  if(WiFi.status()==WL_CONNECTED){
    isConnected = true;
    Serial.println("");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
    digitalWrite(LED_BUILTIN, HIGH);
  }else{
    //setting ip hotspot controller
    IPAddress local_ip(192, 168, 4, 1);
    IPAddress gateway(192, 168, 4, 1);
    IPAddress netmask(255, 255, 255, 0);
    Serial.println("Gagal tersambung ke Hotspot, mode Hotspot aktif.");
    WiFi.persistent(false);
    WiFi.setSleepMode(WIFI_NONE_SLEEP);
    WiFi.mode(WIFI_AP);
    WiFi.softAPConfig(local_ip, gateway, netmask);
    WiFi.softAP(configwifi.ssid, configwifi.password);
    dnsServer.start (DNS_PORT, "*", local_ip);
    MDNS.begin(host);
    httpUpdater.setup(&server);
    MDNS.addService("http", "tcp", 80);
  }
}
  
void webSocketEvent(uint8_t num, WStype_t type, uint8_t* payload, size_t length){
  if(type == WStype_TEXT){
    String data = (const char *)payload;
    if(data.substring(0, 5)=="dfset"){
      String data2 = data.substring(5);
      handleSettingDfUpdate(data2);
    }
    else if (strcmp("r1", (const char *)payload) == 0) {
      mp3.awake();
    }else if (strcmp("r0", (const char *)payload) == 0) {
      mp3.sleep();
    }else if(payload[0] == '#') {
      Disp.drawRect(16,8,46,14,0,0);
      String data2 = data.substring(1);
      handleSettingDfUpdate(data2);
    }else if (strcmp("dplay", (const char *)payload) == 0) {
      mp3.start();
      delay(200);
      currentTrack = mp3.getCurrentTrack();
    }else if (strcmp("dpause", (const char *)payload) == 0) {
      mp3.pause();
      delay(200);
      currentTrack = mp3.getCurrentTrack();
    }else if (strcmp("dstop", (const char *)payload) == 0) {
      mp3.stop();
      delay(200);
      currentTrack = mp3.getCurrentTrack();
    }else if (strcmp("dnext", (const char *)payload) == 0) {
      mp3.nextTrack();
      delay(200);
      currentTrack = mp3.getCurrentTrack();
    }else if (strcmp("dprev", (const char *)payload) == 0) {
      mp3.prevTrack();
      delay(200);
      currentTrack = mp3.getCurrentTrack();
    }else if (strcmp("drandom", (const char *)payload) == 0) {
      mp3.playRandomTrackFromAll();
      delay(200);
      currentTrack = 0;
    }else if (strcmp("dmodedfmp3", (const char *)payload) == 0) {
      Disp.clear();
      RunSel = 30;
    }else if (strcmp("dmodejam", (const char *)payload) == 0) {
      Disp.clear();
      RunSel = 2;
    }else if (strcmp("dtesled", (const char *)payload) == 0) {
      Disp.clear();
      RunSel = 31;
    }
    else if (payload[0] == 'a') {
      String st= (const char *)payload;
      uint8_t folder =  (st[1]-'0')*100+(st[2]-'0')*10+(st[3]-'0');
      uint8_t track = (st[4]-'0')*100+(st[5]-'0')*10+(st[6]-'0');

      Serial.print("surat: "); Serial.println(folder);
      Serial.print("ayat: "); Serial.println(track);
    }else if (payload[0] == 'g') {
      String st= (const char *)payload;
      uint8_t folder =  (st[1]-'0')*100+(st[2]-'0')*10+(st[3]-'0');
      uint8_t track = (st[4]-'0')*100+(st[5]-'0')*10+(st[6]-'0');
      mp3.playFolderTrack(folder, track);
      delay(300);
      currentTrack = mp3.getCurrentTrack();
    }else if (payload[0] == 'f') {
      String st= (const char *)payload;
      uint8_t folder =  (st[1]-'0')*100+(st[2]-'0')*10+(st[3]-'0');
      uint8_t track = (st[4]-'0')*100+(st[5]-'0')*10+(st[6]-'0');
      String data2 = data.substring(7);
      mp3.playFolderTrack(folder, track);
      delay(300);
      currentTrack = mp3.getCurrentTrack();
      handleSettingDfUpdate(data2);
    }else if(payload[0] == 'z') {
      ESP.reset();
    }else if (payload[0] == 'p') {
      if (payload[1] == '1') {
        mp3.playRandomTrackFromAll();
        delay(100);
        currentTrack = 0;
      } else if (payload[1] == '2') {
        mp3.loopFolder(2);
        delay(100);
        currentTrack = 0;
      } else if (payload[1] == '3') {
        mp3.loopFolder(3);
        delay(100);
        currentTrack = 0;
      } else if (payload[1] == '4') {
        mp3.loopFolder(4);
        delay(100);
        currentTrack = 0;
      } else if (payload[1] == '5') {
        mp3.loopFolder(5);
        delay(100);
        currentTrack = 0;
      } else if (payload[1] == '6') {
        mp3.loopFolder(6);
        delay(100);
        currentTrack = 0;
      } else if (payload[1] == '7') {
        mp3.loopFolder(7);
        delay(100);
        currentTrack = 0;
      } else if (payload[1] == '8') {
        mp3.loopFolder(8);
        delay(100);
        currentTrack = 0;
      } else if (payload[1] == '9') {
        mp3.loopFolder(9);
        delay(100);
        currentTrack = 0;
      } else if (payload[1] == 'l') {
        if (payload[2] == '1') {
          mp3.loopFolder(10);
          delay(100);
          currentTrack = 0;
        } else if (payload[2] == '2') {
          mp3.loopFolder(11);
          delay(100);
          currentTrack = 0;
        } else if (payload[2] == '3') {
          mp3.loopFolder(12);
          delay(100);
          currentTrack = 0;
        } else if (payload[2] == '4') {
          mp3.loopFolder(13);
          delay(100);
          currentTrack = 0;
        } else if (payload[2] == '5') {
          mp3.loopFolder(14);
          delay(100);
          currentTrack = 0;
        }
      }    
    }
    else if (payload[0] == 't') {
      String st= (const char *)payload;
      String lastSt;
      uint8_t car=0;
      if(payload[1]=='t' || payload[1]=='j') car=1;
      uint8_t jam = ((st[car+1]-'0')*10)+(st[car+2]-'0');
      uint8_t menit = ((st[car+4]-'0')*10)+(st[car+5]-'0');
      uint8_t detik = ((st[car+7]-'0')*10)+(st[car+8]-'0');
      uint8_t tanggal = ((st[car+10]-'0')*10)+(st[car+11]-'0');
      uint8_t bulan = ((st[car+13]-'0')*10)+(st[car+14]-'0');
      uint16_t tahun = (st[car+16]-'0')*1000+(st[car+17]-'0')*100+(st[car+18]-'0')*10+(st[car+19]-'0');

      RtcDateTime setDateTime;
      if(payload[1]=='t'){
          setDateTime = RtcDateTime(tahun, bulan, tanggal, rJam, rMenit, rDetik);
      }else if(payload[1]=='j'){
        setDateTime = RtcDateTime(rTahun, rBulan, rTanggal, jam, menit, detik);
      }else{
        setDateTime = RtcDateTime(tahun, bulan, tanggal, jam, menit, detik);
      }
      if (st != lastSt){
         Rtc.SetDateTime(setDateTime);
         Hitung();
         lastSt=st;
       }
    }else if(payload[0] == 's') {
      String data2 = data.substring(1);
      handleSettingJwsUpdate(data2);
    }else if(payload[0] == 'h') {
      String data2 = data.substring(1);
      handleSettingDfUpdate(data2);
    }else if(payload[0] == 'i') {
      String data2 = data.substring(1);
      handleSettingInfoUpdate(data2);
    }else if(payload[0] == 'w') {
      String data2 = data.substring(1);
      handleSettingWifiUpdate(data2);
    }else if(payload[0] == 'c') {
      String data2 = data.substring(1);
      handleSettingDispUpdate(data2);
    }
  }
}

void handleXMLWaktu(){
  XMLWaktu();
  server.send(200,"text/xml",XML);
}

void handleXMLDataJWS(){
  XMLDataJWS();
  server.send(200,"text/xml",XML);
}
