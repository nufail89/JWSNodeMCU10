// Time IDs
enum TimeID{
  Imsak, Shubuh, Thulu, Dluha, Dhuhr, Ashr, Maghrib, Isya, TimesCount
};
void Hitung();
char* timeto_HM(double ftime){
  static char  BuffTime[6];
  uint8_t shour   = floor(ftime);
  uint8_t sminute = round((ftime-(float)shour)*60);
  sprintf(BuffTime,"%02d:%02d",shour,sminute);
  return BuffTime;
}
char* timeto_HMS(double ftime){
  static char  BuffTime[9];
  uint8_t shour   = floor(ftime);
  uint8_t sminute = floor((ftime-(float)shour)*60);
  uint8_t ssecond = floor((ftime-(float)shour-(float)sminute/60)*3600);
  sprintf(BuffTime,"%02d:%02d:%02d",shour,sminute,ssecond);
  return BuffTime;
}
struct ConfigJws {
  int iqmhs;
  int iqmhd;
  int iqmha;
  int iqmhm;
  int iqmhi;
  int ihtis;
  int ihtid;
  int ihtia;
  int ihtim;
  int ihtii;
  int durasiadzan;
  uint8_t durasijumat;
  float inkhifadi;
  float inkhifads;
  uint8_t durasisholat;
    
  float latitude;
  float longitude;
  float altitude;
  int zonawaktu;  
};

struct ConfigInfo {
  char nama[64];
  char info1[512];
  char info2[512];
  char laporan[512];
  uint8_t kecepatan;
};

struct ConfigDisp {
  uint8_t kecerahan;
  uint8_t panel;
};

struct ConfigDf {
  char equalizer[3];
  int folder, track, trackloop;
  uint8_t volume, dfonoff, autotarhim, tarhimmenits, tarhimtracks, tarhimmenitd, tarhimtrackd;
  uint8_t tarhimmenita, tarhimtracka, tarhimmenitm, tarhimtrackm, tarhimmeniti, tarhimtracki;
  uint8_t tarhimmenitjm, tarhimmenitjh, tarhimtrackj, alarmadzan, alarmtanbih;
};

struct ConfigWifi {
  char wifissid[64];
  char wifipassword[64];
  char ssid[64];
  char password[64];
  uint8_t durasicari;
  uint8_t tampilnet;
};

//String jsonconfigjws = "{iqmhs:12,iqmhd:8,iqmha:6,iqmhm:5,iqmhi:5,ihtis:2,ihtid:2,ihtia:2,ihtim:2,ihtii:2,latitude:-6.16,longitude:106.61,altitude:10.0,zonawaktu:7}";

const char *fileconfigdisp = "/configdisp.json";
ConfigDisp configdisp;

const char *fileconfigdf = "/configdf.json";
ConfigDf configdf;

const char *fileconfigjws = "/configjws.json";
ConfigJws configjws;

const char *fileconfiginfo = "/configinfo.json";
ConfigInfo configinfo;

const char *fileconfigwifi = "/configwifi.json";
ConfigWifi configwifi;

void LoadDataAwal() {
  if (configjws.iqmhs == 0) configjws.iqmhs = 5;
  if (configjws.iqmhd == 0) configjws.iqmhd = 5;
  if (configjws.iqmha == 0) configjws.iqmha = 5;
  if (configjws.iqmhm == 0) configjws.iqmhm = 5;
  if (configjws.iqmhi == 0) configjws.iqmhi = 5;
  if (configjws.ihtis == 0) configjws.ihtis = 2;
  if (configjws.ihtid == 0) configjws.ihtid = 2;
  if (configjws.ihtia == 0) configjws.ihtia = 2;
  if (configjws.ihtim == 0) configjws.ihtim = 2;
  if (configjws.ihtii == 0) configjws.ihtii = 2;
  if (configjws.durasisholat == 0) configjws.durasisholat = 10;
  if (configjws.durasiadzan == 0) configjws.durasiadzan = 4;
  if (configjws.durasijumat == 0) configjws.durasijumat = 60;
  if (configjws.inkhifads == 0) configjws.inkhifads = -17.8;
  if (configjws.inkhifadi == 0) configjws.inkhifadi = -19.8;

  if (configjws.latitude == 0) configjws.latitude = -(7.0+44.0/60.0+35.1/3600.0);
  if (configjws.longitude == 0) configjws.longitude = 112.0+42.0/60.0+12.4/3600.0;
  if (configjws.altitude == 0) configjws.altitude = 10.0;
  if (configjws.zonawaktu == 0) configjws.zonawaktu = 7;

  if (configdisp.kecerahan == 0) configdisp.kecerahan = 255;
  if (configdisp.panel == 0) configdisp.panel = 3;
  if (strlen(configinfo.nama) == 0) strlcpy(configinfo.nama, "MASJID AL-FALAH", sizeof(configinfo.nama));
  if (strlen(configinfo.info1) == 0) strlcpy(configinfo.info1, "Ajun JWS", sizeof(configinfo.info1));
  if (strlen(configinfo.info2) == 0) strlcpy(configinfo.info2, "0815-5650-9064", sizeof(configinfo.info2));
  if (strlen(configinfo.laporan) == 0) strlcpy(configinfo.laporan, "Informasi 3", sizeof(configinfo.laporan));
  if (configinfo.kecepatan == 0) configinfo.kecepatan = 50;

  if (strlen(configwifi.wifissid) == 0) strlcpy(configwifi.wifissid, "ALFALAHH", sizeof(configwifi.wifissid));
  if (strlen(configwifi.wifipassword) == 0) strlcpy(configwifi.wifipassword, "MUSHOLLAHALFALAH", sizeof(configwifi.wifipassword));
  if (strlen(configwifi.ssid) == 0) strlcpy(configwifi.ssid, "JWS P10", sizeof(configwifi.ssid));
  if (strlen(configwifi.password) == 0) strlcpy(configwifi.password, "aassddff", sizeof(configwifi.password));
  if (configwifi.durasicari==0) configwifi.durasicari=8;

  if (configdf.volume == 0)    configdf.volume=23;
  if (strlen(configdf.equalizer) < 2) strlcpy(configdf.equalizer, "e1", sizeof(configdf.equalizer));
  if (configdf.tarhimmenits == 0)   configdf.tarhimmenits=27;
  if (configdf.tarhimtracks == 0)   configdf.tarhimtracks=32;
  if (configdf.tarhimmenitd == 0)   configdf.tarhimmenitd=11;
  if (configdf.tarhimtrackd == 0)   configdf.tarhimtrackd=12;
  if (configdf.tarhimmenita == 0)   configdf.tarhimmenita=11;
  if (configdf.tarhimtracka == 0)   configdf.tarhimtracka=10;
  if (configdf.tarhimmenitm == 0)   configdf.tarhimmenitm=21;
  if (configdf.tarhimtrackm == 0)   configdf.tarhimtrackm=18;
  if (configdf.tarhimmeniti == 0)   configdf.tarhimmeniti=9;
  if (configdf.tarhimtracki == 0)   configdf.tarhimtracki=14;
  if (configdf.tarhimmenitjm == 0)  configdf.tarhimmenitjm=60; //start sebelum adzan
  if (configdf.tarhimmenitjh == 0)  configdf.tarhimmenitjh=4; //stop sebelum adzan
  if (configdf.tarhimtrackj == 0)   configdf.tarhimtrackj=16;
  if (configdf.alarmadzan == 0)     configdf.alarmadzan=3;
  if (configdf.alarmtanbih == 0)    configdf.alarmtanbih=1;
}

void loadDfConfig(const char *fileconfigdf, ConfigDf &configdf) {  
  File configFileDf = SPIFFS.open(fileconfigdf, "r");
  if (!configFileDf) {
    Serial.println("Gagal membuka fileconfigdf untuk dibaca");
    return;
  }

  size_t size = configFileDf.size();
  std::unique_ptr<char[]> buf(new char[size]);
  configFileDf.readBytes(buf.get(), size);

  DynamicJsonDocument doc(1024);
  DeserializationError error = deserializeJson(doc, buf.get());  

  if (error) {
    Serial.println("Gagal parse fileconfigdf");
    return;
  }

  strlcpy(configdf.equalizer, doc["equalizer"] | "e2", sizeof(configdf.equalizer));
  configdf.volume = doc["volume"];
  configdf.folder = doc["folder"];
  configdf.track = doc["track"];
  configdf.trackloop = doc["trackloop"];
  configdf.dfonoff = doc["dfonoff"];
  configdf.autotarhim = doc["autotarhim"];
  configdf.tarhimmenits = doc["tarhimmenits"];
  configdf.tarhimtracks = doc["tarhimtracks"];
  configdf.tarhimmenitd = doc["tarhimmenitd"];
  configdf.tarhimtrackd = doc["tarhimtrackd"];
  configdf.tarhimmenita = doc["tarhimmenita"];
  configdf.tarhimtracka = doc["tarhimtracka"];
  configdf.tarhimmenitm = doc["tarhimmenitm"];
  configdf.tarhimtrackm = doc["tarhimtrackm"];
  configdf.tarhimmeniti = doc["tarhimmeniti"];
  configdf.tarhimtracki = doc["tarhimtracki"];
  configdf.tarhimmenitjm = doc["tarhimmenitjm"];
  configdf.tarhimmenitjh = doc["tarhimmenitjh"];
  configdf.tarhimtrackj = doc["tarhimtrackj"];
  configdf.alarmadzan = doc["alarmadzan"];
  configdf.alarmtanbih = doc["alarmtanbih"];
  configFileDf.close();
}

void handleSettingDfUpdate(String datadf) {
  timer0_detachInterrupt();
  DynamicJsonDocument doc(1024);
  DeserializationError error = deserializeJson(doc, datadf);

  File configFileDf = SPIFFS.open(fileconfigdf, "w");
  
  if (!configFileDf) {
    Serial.println("Gagal membuka DFPlayer configFile untuk ditulis");
    return;
  }
  
  serializeJson(doc, configFileDf);
  if (error) {
    Serial.print(F("deserializeJson() gagal kode sebagai berikut: "));
    Serial.println(error.c_str());
    return;
  } else {
    configFileDf.close();
    Serial.println("Berhasil mengubah configFileDf");
    loadDfConfig(fileconfigdf, configdf);
    timer0_attachInterrupt(refresh);
    mp3.setVolume(configdf.volume);
  }  
}

void loadInfoConfig(const char *fileconfiginfo, ConfigInfo &configinfo) {  
  File configFileInfo = SPIFFS.open(fileconfiginfo, "r");

  if (!configFileInfo) {
    Serial.println("Gagal membuka fileconfiginfo untuk dibaca");
    return;
  }

  size_t size = configFileInfo.size();
  std::unique_ptr<char[]> buf(new char[size]);
  configFileInfo.readBytes(buf.get(), size);

  DynamicJsonDocument doc(1024);
  DeserializationError error = deserializeJson(doc, buf.get());

  if (error) {
    Serial.println("Gagal parse fileconfiginfo");
    return;
  }  
  
  strlcpy(configinfo.nama, doc["nama"] | "MASJID AL KAUTSAR", sizeof(configinfo.nama));
  strlcpy(configinfo.laporan, doc["laporan"] | "Laporan Bendahara Masjid", sizeof(configinfo.laporan));
  strlcpy(configinfo.info1, doc["info1"] | "Ini adalah isi INFO 1", sizeof(configinfo.info1));
  strlcpy(configinfo.info2, doc["info2"] | "Ini adalah isi INFO 2", sizeof(configinfo.info2));

  configFileInfo.close();

}

void handleSettingInfoUpdate(String datainfo) {
 timer0_detachInterrupt();
  DynamicJsonDocument doc(1024);
  DeserializationError error = deserializeJson(doc, datainfo);
  File configFileInfo = SPIFFS.open(fileconfiginfo, "w");
  if (!configFileInfo) {
    Serial.println("Gagal membuka configFileInfo untuk ditulis");
    return;
  }
  serializeJson(doc, configFileInfo);
  if (error) {
    Serial.print(F("deserializeJson() gagal kode sebagai berikut: "));
    Serial.println(error.c_str());
    return;
  } else {
    configFileInfo.close();
    Serial.println("Berhasil mengubah configFileInfo");
    loadInfoConfig(fileconfiginfo, configinfo);
    // delay(1000);
    timer0_attachInterrupt(refresh);
  }  
}

void loadDispConfig(const char *fileconfigdisp, ConfigDisp &configdisp) {

  File configFileDisp = SPIFFS.open(fileconfigdisp, "r");

  if (!configFileDisp) {
    Serial.println("Gagal membuka fileconfigdisp untuk dibaca");
    return;
  }

  size_t size = configFileDisp.size();
  std::unique_ptr<char[]> buf(new char[size]);
  configFileDisp.readBytes(buf.get(), size);

  DynamicJsonDocument doc(1024);
  DeserializationError error = deserializeJson(doc, buf.get());

  if (error) {
    Serial.println("Gagal parse fileconfigdisp");
    return;
  }  
  
  configdisp.kecerahan = doc["kecerahan"];
  configdisp.panel = doc["panel"];
  configFileDisp.close();

}


void handleSettingDispUpdate(String datadisp) {
  timer0_detachInterrupt();  
  DynamicJsonDocument doc(1024);
  DeserializationError error = deserializeJson(doc, datadisp);

  File configFileDisp = SPIFFS.open(fileconfigdisp, "w");
  
  if (!configFileDisp) {
    Serial.println("Gagal membuka Display configFile untuk ditulis");
    return;
  }
  
  serializeJson(doc, configFileDisp);

  if (error) {
    Serial.print(F("deserializeJson() gagal kode sebagai berikut: "));
    Serial.println(error.c_str());
    return;
    
  } else {
    configFileDisp.close();
    Serial.println("Berhasil mengubah configFileDisp");
    // delay(1000);
    loadDispConfig(fileconfigdisp, configdisp);
    Disp.setBrightness(configdisp.kecerahan);
    Disp.clear();
  }
  timer0_attachInterrupt(refresh);
}

void loadWifiConfig(const char *fileconfigwifi, ConfigWifi &configwifi) {  

  File configFileWifi = SPIFFS.open(fileconfigwifi, "r");

  if (!configFileWifi) {
    Serial.println("Gagal membuka fileconfigwifi untuk dibaca");
    return;
  }

  size_t size = configFileWifi.size();
  std::unique_ptr<char[]> buf(new char[size]);
  configFileWifi.readBytes(buf.get(), size);

  DynamicJsonDocument doc(1024);
  DeserializationError error = deserializeJson(doc, buf.get());  

  if (error) {
    Serial.println("Gagal parse fileconfigwifi");
    return;
  }
  
  strlcpy(configwifi.wifissid, doc["wifissid"] | "grobak.net", sizeof(configwifi.wifissid));
  strlcpy(configwifi.wifipassword, doc["wifipassword"] | "12345678", sizeof(configwifi.wifipassword));
  strlcpy(configwifi.ssid, doc["ssid"] | "grobak.net", sizeof(configwifi.wifissid));
  strlcpy(configwifi.password, doc["password"] | "12345", sizeof(configwifi.wifipassword));
  configwifi.durasicari = doc["durasicari"];
  configwifi.tampilnet = doc["tampilnet"];
  configFileWifi.close();
  if(configwifi.tampilnet==1) RunSel=32;
  else RunSel=2;
}

void handleSettingWifiUpdate(String datawifi) {
  timer0_detachInterrupt();
  DynamicJsonDocument doc(1024);
  DeserializationError error = deserializeJson(doc, datawifi);
  File configFileWifi = SPIFFS.open(fileconfigwifi, "w");
  if (!configFileWifi) {
    Serial.println("Gagal membuka Info configFileWifi untuk ditulis");
    return;
  }
  serializeJson(doc, configFileWifi);

  if (error) {
    Serial.print(F("deserializeJson() gagal kode sebagai berikut: "));
    Serial.println(error.c_str());
    return;
  } else {
    configFileWifi.close();
    Serial.println("Berhasil mengubah configFileWifi");
    loadWifiConfig(fileconfigwifi, configwifi);
    // delay(1000);
    timer0_attachInterrupt(refresh);    
  }
}
//membaca file jws
void loadJwsConfig(const char *fileconfigjws, ConfigJws &configjws) {  
  File configFileJws = SPIFFS.open(fileconfigjws, "r");
  if (!configFileJws) {
    Serial.println("Gagal membuka fileconfigjws untuk dibaca");
    return;
  }
  DynamicJsonDocument doc(1024);
//  DeserializationError error = deserializeJson(doc, buf.get()); 
  DeserializationError error = deserializeJson(doc, configFileJws); 
  if (error) {
    Serial.println("Gagal parse fileconfigjws");
    return;
  }
  
  configjws.iqmhs = doc["iqmhs"];
  configjws.iqmhd = doc["iqmhd"];
  configjws.iqmha = doc["iqmha"];
  configjws.iqmhm = doc["iqmhm"];
  configjws.iqmhi = doc["iqmhi"];
  configjws.ihtis = doc["ihtis"];
  configjws.ihtid = doc["ihtid"];
  configjws.ihtia = doc["ihtia"];
  configjws.ihtim = doc["ihtim"];
  configjws.ihtii = doc["ihtii"];
  configjws.durasisholat = doc["durasisholat"];
  configjws.durasiadzan = doc["durasiadzan"];
  configjws.durasijumat = doc["durasijumat"];
  configjws.inkhifadi = doc["inkhifadi"];
  configjws.inkhifads = doc["inkhifads"];
  configjws.latitude = doc["latitude"];
  configjws.longitude = doc["longitude"];
  configjws.altitude = doc["altitude"];
  configjws.zonawaktu = doc["zonawaktu"];
  configFileJws.close(); 
}

//menyimpan data setting configjws
void handleSettingJwsUpdate(String datajws) {
 timer0_detachInterrupt();
  DynamicJsonDocument doc(1024);
  DeserializationError error = deserializeJson(doc, datajws);
  
  File configFileJws = SPIFFS.open(fileconfigjws, "w");
  if (!configFileJws) {
    Serial.println("Gagal membuka Info configFileJws untuk ditulis");
    return;
  }
  serializeJson(doc, configFileJws);
  
  if (error) {
    Serial.print(F("deserializeJson() gagal kode sebagai berikut: "));
    Serial.println(error.c_str());
    return;   
  }else {
    configFileJws.close();
    Serial.println("Berhasil mengubah configFileJws");
    loadJwsConfig(fileconfigjws, configjws);
  }
  timer0_attachInterrupt(refresh);
  Hitung();
}

//----------------------------------------------------------------------
// XML UNTUK JEMBATAN DATA MESIN DENGAN WEB
String message, XML;
void XMLWaktu(){
  char bufHijri[17];
  sprintf(bufHijri, "%02d %s %d", hisab.tglH, bulanhN[hisab.blnH], hisab.thnH);
  
  XML="<?xml version='1.0'?>";
  XML+="<t>";
  
    XML+="<Tahun>";
    XML+=rTahun;
    XML+="</Tahun>";
    XML+="<Bulan>";
    XML+=rBulan;
    XML+="</Bulan>";
    XML+="<Tanggal>";
    XML+=rTanggal;
    XML+="</Tanggal>";
    XML+="<Jam>";
      if(rJam<10){
        XML+="0";
        XML+=rJam;
      }else{XML+=rJam;}
    XML+="</Jam>";
    XML+="<Menit>";
      if(rMenit<10){
        XML+="0";
        XML+=rMenit;
      }else{XML+=rMenit;}
    XML+="</Menit>";
    XML+="<Detik>";
      if(rDetik<10){
        XML+="0";
        XML+=rDetik;
      }else{XML+=rDetik;}
    XML+="</Detik>";
    XML+="<Suhu>";
    XML+= celsius - 5;
    XML+="</Suhu>";
    XML+="<tglhijr>";
    XML+=bufHijri;
    XML+="</tglhijr>";
  XML+="</t>"; 
}

void XMLDataJWS(){
  XML="<?xml version='1.0'?>";
  XML+="<t>";
    XML+="<rIqmhs>";
    XML+= configjws.iqmhs;
    XML+="</rIqmhs>";
    XML+="<rIqmhd>";
    XML+= configjws.iqmhd;
    XML+="</rIqmhd>";
    XML+="<rIqmha>";
    XML+= configjws.iqmha;
    XML+="</rIqmha>";
    XML+="<rIqmhm>";
    XML+= configjws.iqmhm;
    XML+="</rIqmhm>";
    XML+="<rIqmhi>";
    XML+= configjws.iqmhi;
    XML+="</rIqmhi>";
    XML+="<rIhtis>";
    XML+= configjws.ihtis;
    XML+="</rIhtis>";
    XML+="<rIhtid>";
    XML+= configjws.ihtid;
    XML+="</rIhtid>";
    XML+="<rIhtia>";
    XML+= configjws.ihtia;
    XML+="</rIhtia>";
    XML+="<rIhtim>";
    XML+= configjws.ihtim;
    XML+="</rIhtim>";
    XML+="<rIhtii>";
    XML+= configjws.ihtii;
    XML+="</rIhtii>";
    XML+="<DurasiSholat>";
    XML+= configjws.durasisholat;
    XML+="</DurasiSholat>";
    XML+="<DurasiJumat>";
    XML+= configjws.durasijumat;
    XML+="</DurasiJumat>";
    XML+="<DurasiAdzan>";
    XML+= configjws.durasiadzan;
    XML+="</DurasiAdzan>";

    XML+="<rInkhifads>";
    XML+= configjws.inkhifads;
    XML+="</rInkhifads>";
    XML+="<rInkhifadi>";
    XML+= configjws.inkhifadi;
    XML+="</rInkhifadi>";
    
    XML+="<rLatitude>";
    XML+= String(configjws.latitude,6);
    XML+="</rLatitude>";
    XML+="<rLongitude>";
    XML+= String(configjws.longitude,6);
    XML+="</rLongitude>";
    XML+="<rAltitude>";
    XML+= configjws.altitude;
    XML+="</rAltitude>";
    XML+="<rZonaWaktu>";
    XML+= configjws.zonawaktu;
    XML+="</rZonaWaktu>";

    XML+="<jdhuhr>Dhuhur: ";
    XML+=timeto_HMS(hisab.sholatT[Dhuhr]);
    XML+= "</jdhuhr>";
    XML+="<jashr>Ashar: ";
    XML+=timeto_HMS(hisab.sholatT[Ashr]);
    XML+= "</jashr>";
    XML+="<jmaghrib>Maghrib: ";
    XML+=timeto_HMS(hisab.sholatT[Maghrib]);
    XML+= "</jmaghrib>";
    XML+="<jisya>Isya: ";
    XML+=timeto_HMS(hisab.sholatT[Isya]);
    XML+= "</jisya>";
    XML+="<jimsak>Imsak: ";
    XML+=timeto_HMS(hisab.sholatT[Imsak]);
    XML+= "</jimsak>";
    XML+="<jshubuh>Shubuh: ";
    XML+=timeto_HMS(hisab.sholatT[Shubuh]);
    XML+= "</jshubuh>";
    XML+="<jthulu>Thulu: ";
    XML+=timeto_HMS(hisab.sholatT[Thulu]);
    XML+= "</jthulu>";
    XML+="<jdluha>Dluha: ";
    XML+=timeto_HMS(hisab.sholatT[Dluha]);
    XML+= "</jdluha>";

    XML+="<nama>";
    XML+=configinfo.nama;
    XML+="</nama>";
    XML+="<info1>";
    XML+=configinfo.info1;
    XML+="</info1>";
    XML+="<info2>";
    XML+=configinfo.info2;
    XML+="</info2>";
    XML+="<laporan>";
    XML+=configinfo.laporan;
    XML+="</laporan>";
    XML+="<Kecepatan>";
    XML+=configinfo.kecepatan;
    XML+="</Kecepatan>";

    XML+="<wifissid>";
    XML+=configwifi.wifissid;
    XML+="</wifissid>";
    
    XML+="<wifipassword>";
    XML+=configwifi.wifipassword;
    XML+="</wifipassword>";

    XML+="<ssid>";
    XML+=configwifi.ssid;
    XML+="</ssid>";

    XML+="<password>";
    XML+=configwifi.password;
    XML+="</password>";
    
    XML+="<DurasiCari>";
    XML+=configwifi.durasicari ;
    XML+="</DurasiCari>";

    XML+="<TampilNet>";
    XML+=configwifi.tampilnet;
    XML+="</TampilNet>";

    XML+="<kecerahan>";
    XML+=configdisp.kecerahan;
    XML+="</kecerahan>";

    XML+="<panel>";
    XML+=configdisp.panel;
    XML+="</panel>";
    
    //XML untuk DF Player Mp3
    XML+="<Volume>";
    XML+=configdf.volume;
    XML+="</Volume>";

    XML+="<Folder>";
    XML+=configdf.folder;
    XML+="</Folder>";

    XML+="<Track>";
    XML+=configdf.track;
    XML+="</Track>";

    XML+="<TrackLoop>";
    XML+=configdf.trackloop;
    XML+="</TrackLoop>";

    XML+="<Dfonoff>";
    XML+=configdf.dfonoff;
    XML+="</Dfonoff>";

    XML+="<Equalizer>";
    XML+=configdf.equalizer;
    XML+="</Equalizer>";

    XML+="<AutoTarhim>";
    XML+=configdf.autotarhim;
    XML+="</AutoTarhim>";

    XML+="<AlarmAdzan>";
    XML+=configdf.alarmadzan;
    XML+="</AlarmAdzan>";
    XML+="<AlarmTanbih>";
    XML+=configdf.alarmtanbih;
    XML+="</AlarmTanbih>";

    XML+="<TarhimMenitS>";
    XML+=configdf.tarhimmenits;
    XML+="</TarhimMenitS>";
    XML+="<TarhimTrackS>";
    XML+=configdf.tarhimtracks;
    XML+="</TarhimTrackS>";

    XML+="<TarhimMenitD>";
    XML+=configdf.tarhimmenitd;
    XML+="</TarhimMenitD>";
    XML+="<TarhimTrackD>";
    XML+=configdf.tarhimtrackd;
    XML+="</TarhimTrackD>";

    XML+="<TarhimMenitA>";
    XML+=configdf.tarhimmenita;
    XML+="</TarhimMenitA>";
    XML+="<TarhimTrackA>";
    XML+=configdf.tarhimtracka;
    XML+="</TarhimTrackA>";

    XML+="<TarhimMenitM>";
    XML+=configdf.tarhimmenitm;
    XML+="</TarhimMenitM>";
    XML+="<TarhimTrackM>";
    XML+=configdf.tarhimtrackm;
    XML+="</TarhimTrackM>";

    XML+="<TarhimMenitI>";
    XML+=configdf.tarhimmeniti;
    XML+="</TarhimMenitI>";
    XML+="<TarhimTrackI>";
    XML+=configdf.tarhimtracki;
    XML+="</TarhimTrackI>";

    XML+="<TarhimMenitJM>";
    XML+=configdf.tarhimmenitjm;
    XML+="</TarhimMenitJM>";
    XML+="<TarhimMenitJH>";
    XML+=configdf.tarhimmenitjh;
    XML+="</TarhimMenitJH>";
    XML+="<TarhimTrackJ>";
    XML+=configdf.tarhimtrackj;
    XML+="</TarhimTrackJ>";
  XML+="</t>"; 
}

// -------------------------------------------
// MEMBACA PARAMETER YANG TERSIMPAN

void bacaParameter() {
  Serial.println(" ");
  Serial.println("PARAMETER TERSIMPAN");
  Serial.print("Iqomah Subuh   : "); Serial.println(configjws.iqmhs);
  Serial.print("Iqomah Dzuhur  : "); Serial.println(configjws.iqmhd);
  Serial.print("Iqomah Ashar   : "); Serial.println(configjws.iqmha);
  Serial.print("Iqomah Maghrib : "); Serial.println(configjws.iqmhm);
  Serial.print("Iqomah Isya    : "); Serial.println(configjws.iqmhi);
  Serial.print("Ihtiyat Subuh  : "); Serial.println(configjws.ihtis);
  Serial.print("Ihtiyat Dzuhur : "); Serial.println(configjws.ihtid);
  Serial.print("Ihtiyat Asar   : "); Serial.println(configjws.ihtia);
  Serial.print("Ihtiyat Mgrb   : "); Serial.println(configjws.ihtim);
  Serial.print("Ihtiyati Isya  : "); Serial.println(configjws.ihtii);
  Serial.print("Inkhifad Subuh : "); Serial.println(configjws.inkhifads);
  Serial.print("Inkhifad Isya  : "); Serial.println(configjws.inkhifadi);
  Serial.print("Latitude       : "); Serial.println(configjws.latitude);
  Serial.print("Longitude      : "); Serial.println(configjws.longitude);
  Serial.print("Altitude       : "); Serial.println(configjws.altitude);
  Serial.print("Zona Waktu     : "); Serial.println(configjws.zonawaktu);
  Serial.print("Durasi Adzan   : "); Serial.println(configjws.durasiadzan);
  Serial.println("=====================================================");
  Serial.println(" ");
  
}
