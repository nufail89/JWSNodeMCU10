char webpage[] PROGMEM = R"=====(
<!DOCTYPE HTML>
<html>

<meta name='viewport' content='width=device-width, initial-scale=1'>

<head>

<title>JWS Murottal LAFAL</title>
<style>

input[type=range] { -webkit-appearance: none; margin: 18px 0; width: 87%; 
  border:none; background:none; box-shadow:none;}
input[type=range]:focus { outline: none; }
input[type=range]::-webkit-slider-runnable-track { width: 100%; height: 8.4px;
  cursor: pointer; animate: 0.2s; box-shadow: 1px 1px 1px #000000, 0px 0px 1px #0d0d0d;
  background: #d62020; border-radius: 1.3px; border: 0.2px solid #010101; }
  
input[type=range]::-webkit-slider-thumb { box-shadow: 1px 1px 1px #000000, 0px 0px 1px #0d0d0d;
  border: 1px solid #000000; height: 36px; width: 16px; border-radius: 3px;
  background: #ffffff; cursor: pointer; -webkit-appearance: none; margin-top: -14px; }
  
input[type=range]:focus::-webkit-slider-runnable-track { background: #c43e27; }

input[type=range]::-moz-range-track { width: 100%; height: 8.4px; cursor: pointer;
  animate: 0.2s; box-shadow: 1px 1px 1px #000000, 0px 0px 1px #0d0d0d; 
  background: #d62020; border-radius: 1.3px; border: 0.2px solid #010101; }
  
input[type=range]::-moz-range-thumb { box-shadow: 1px 1px 1px #000000, 0px 0px 1px #0d0d0d;
  border: 1px solid #000000; height: 36px; width: 16px; border-radius: 3px;
  background: #ffffff; cursor: pointer; }
  
input[type=range]::-ms-track { width: 100%; height: 8.4px; cursor: pointer; animate: 0.2s;
  background: transparent; border-color: transparent; border-width: 16px 0;
  color: transparent; }
  
input[type=range]::-ms-fill-lower { background: #c43e27; border: 0.2px solid #010101;
  border-radius: 2.6px; box-shadow: 1px 1px 1px #000000, 0px 0px 1px #0d0d0d; }
  
input[type=range]::-ms-fill-upper { background: #d62020; border: 0.2px solid #010101;
  border-radius: 2.6px; box-shadow: 1px 1px 1px #000000, 0px 0px 1px #0d0d0d; }
  
input[type=range]::-ms-thumb { box-shadow: 1px 1px 1px #000000, 0px 0px 1px #0d0d0d;
  border: 1px solid #000000; height: 36px; width: 16px; border-radius: 3px;
  background: #ffffff; cursor: pointer; }

input[type=range]:focus::-ms-fill-lower { background: #d62020; }

input[type=range]:focus::-ms-fill-upper { background: #c43e27; }

input, textarea, select {
  display: inline-block;
  -webkit-box-sizing: content-box;
  -moz-box-sizing: content-box;
  box-sizing: content-box;
  padding: 10px 20px;
  border: 1px solid #b7b7b7;
  -webkit-border-radius: 3px;
  border-radius: 3px;
  font: normal normal bold 17px/normal "Times New Roman", Times, serif;
  color: rgba(150,30,30,1);
  -o-text-overflow: clip;
  text-overflow: clip;
  background: rgba(252,252,252,1);
  -webkit-box-shadow: 1px 1px 2px 0 rgba(0,0,0,0.2) ;
  box-shadow: 1px 1px 2px 0 rgba(0,0,0,0.2) ;
  text-shadow: 1px 1px 0 rgba(255,255,255,0.66) ;
  -webkit-transition: all 200ms cubic-bezier(0.42, 0, 0.58, 1);
  -moz-transition: all 200ms cubic-bezier(0.42, 0, 0.58, 1);
  -o-transition: all 200ms cubic-bezier(0.42, 0, 0.58, 1);
  transition: all 200ms cubic-bezier(0.42, 0, 0.58, 1);
}

textarea{
  width : 80%;
}

input#nama {
    width: 80%;
}

button {
  display: inline-block;
  -webkit-box-sizing: content-box;
  -moz-box-sizing: content-box;
  box-sizing: content-box;
  cursor: pointer;
  padding: 15px 20px;
  border: none;
  -webkit-border-radius: 7px;
  border-radius: 25px;
  font: normal normal bold 17px/normal "Times New Roman", Times, serif;
  color: rgba(255,255,255,1);
  -o-text-overflow: clip;
  text-overflow: clip;
  background: #e06666;
  -webkit-box-shadow: 1px 1px 2px 0 rgba(0,0,0,0.2);
  box-shadow: 1px 1px 2px 0 rgba(0,0,0,0.2);
  -webkit-transition: all 300ms cubic-bezier(0.42, 0, 0.58, 1);
  -moz-transition: all 300ms cubic-bezier(0.42, 0, 0.58, 1);
  -o-transition: all 300ms cubic-bezier(0.42, 0, 0.58, 1);
  transition: all 300ms cubic-bezier(0.42, 0, 0.58, 1);
}


.play { background-color:#e4685d; -webkit-border-radius:28px; -moz-border-radius:28px;
  border-radius:28px; display:inline-block; cursor:pointer;
  color:#ffffff; font-size:17px; padding:16px 31px;
  text-decoration:none; text-shadow:0px 1px 0px #b23e35; }
  
.play:hover { background-color:#eb675e; }

.play:active { position:relative; top:1px; }

.tombol { background-color:#75986c; -webkit-border-radius:28px; -moz-border-radius:28px;
  border-radius:28px; display:inline-block; cursor:pointer;
  color:#ffffff; font-size:17px; padding:16px 31px;
  text-decoration:none; text-shadow:0px 1px 0px #737373; }

.tombol:hover { background-color:#75986c; }

.tombol:active { position:relative; top:1px; }

label { margin-top: 30px; margin-bottom: 10px; display: block; }

form { text-align: center; }

table { text-align: center; }
th { padding: 20px 0; }

hr {
    margin: 47px 10px 47px 10px;
    border: 2px solid #eee;
}

.info { background-color: #eee; border-radius: 25px; padding-top: 17px; margin: 5px;}

p.info {
    padding: 7px;
}

.tautan {
  text-decoration:none;
  color : #ad0303;
}

.footer {
  color : #777777;
  padding-bottom : 100px;
}

.footer a{
  text-decoration:none;
  color : #777777;
}


.onoffswitch {
    position: relative; width: 111px; margin-left: auto; margin-right: auto;
    -webkit-user-select:none; -moz-user-select:none; -ms-user-select: none;
}
.onoffswitch-checkbox {
    display: none;
}
.onoffswitch-label {
    margin-top:10px;
    display: block; overflow: hidden; cursor: pointer;
    border-radius: 20px;
}
.onoffswitch-inner {
    display: block; width: 200%; margin-left: -100%;
    transition: margin 0.3s ease-in 0s;
}
.onoffswitch-inner:before, .onoffswitch-inner:after {
    display: block; float: left; width: 50%; height: 42px; padding: 0; line-height: 42px;
    font-size: 14px; color: white; font-family: Trebuchet, Arial, sans-serif; font-weight: bold;
    box-sizing: border-box;
}
.onoffswitch-inner:before {
    content: "ON";
    padding-left: 20px;
    background-color: #DB1B1B; color: #FFFFFF;
    text-align: left;
}
.onoffswitch-inner:after {
    content: "OFF";
    padding-right: 20px;
    background-color: #EEEEEE; color: #999999;
    text-align: right;
}
.onoffswitch-switch {
    display: block; width: 27px; margin: 7.5px;
    background: #FFFFFF;
    position: absolute; top: 0; bottom: 0;
    right: 63px;
    border: 2px solid #FFFFFF; border-radius: 20px;
    transition: all 0.3s ease-in 0s; 
}
.onoffswitch-checkbox:checked + .onoffswitch-label .onoffswitch-inner {
    margin-left: 0;
}
.onoffswitch-checkbox:checked + .onoffswitch-label .onoffswitch-switch {
    right: 0px; 
}

body {margin:0;}

.navbar {
  overflow: hidden;
  background-color: #EB675E;
  position: fixed;
  bottom: 0;
  width: 100%;
  z-index: 1;
  text-align: center;
  box-shadow: 0px 0 5px rgba(0, 0, 0, 0.7);
}

.navbar a {
  display: inline-block;
  color: #f2f2f2;
  text-align: center;
  padding: 14px 16px;
  text-decoration: none;
  font-size: 17px;
}

.navbar a:hover {
  background: #DB1B1B;
}


</style>

</head>

<body onload="mulai()">

<div class="navbar">
  <a href="#pageplay" class="tdf" style="display: inline;">Play</a>
  <a href="#pagelist" class="tdf" style="display: inline;">List</a>
  <a href="#pageinfo">Info</a>
  <a href="#pagejws">JWS</a>
  <a href="#pagerelay">Relay</a>
  <a href="#pagewifi">Wifi</a>
  <a href="#pagejam">Jam</a>
  <a href="#pageled">LED</a>
  <a href="#pagesistem">Sistem</a>
</div>

<center>

<div id="pageplay">
  <h1>JWS Murottal</h1>
  <!-- <h4><a class="tautan" href="http://elektronmart.com/" target="_blank">ElektronMart.Com</a></h4> -->
  <div class="info">
    <span id="tglhijr"></span><span>  H. |  </span>
    <span id="day"></span>-<span id="month"></span>-<span id="year"></span><span> </span>
    <span id="hour"></span>:<span id="minute"></span>:<span id="second"></span><span> </span>
    <span id="suhu">-3</span><span>&#176; C</span><br><br>
  </div>
</div>
<div id="pagejam">
  <hr>
  <h3>Waktu &amp; Lokasi</h3>
  <div>
    <table width="100%">
      <tbody>
      <tr>
        <td colspan="2">
          <button class="play" id="syncjam" onclick="syncJam()">Set Waktu Otomatis</button>
        </td>
      </tr>
      <tr>
        <td>
          <form>
            <h4>Tanggal</h4>
            <input type="date" name="date" id="tanggal" onchange="sendTanggal()">
          </form>
        </td>
        <td>
          <form>  
            <h4>Jam</h4>
            <input type="time" name="time" id="jam" onchange="sendJam()">
          </form>
        </td>        
      </tr>
    </tbody></table>
    <br>

    <div style="display:none">
      <h4>Format 12 Jam</h4>
      <div class="onoffswitch">
        <input type="checkbox" name="onoffswitch" class="onoffswitch-checkbox" id="formatjam" onclick="sendKecerahan()">
        <label class="onoffswitch-label" for="formatjam">
          <span class="onoffswitch-inner"></span>
          <span class="onoffswitch-switch"></span>
        </label>
      </div>
      <br>
    </div>

    <br>
    <table width="100%">
      <tbody><tr>
        <td colspan="4">
          <h4>Lokasi</h4>
          <select id="wilayah" onchange="nwilayah()">
          <option value="0,0" selected="true">Pilih Wilayah</option><option value="4.45427,96.1527">Kab. Aceh Barat</option><option value="3.05126,97.3368">Kab. Aceh Barat Daya</option><option value="5.45292,95.47778">Kab. Aceh Besar</option><option value="4.78737,95.6458">Kab. Aceh Jaya</option><option value="3.31151,97.35166">Kab. Aceh Selatan</option><option value="2.35895,97.87216">Kab. Aceh Singkil</option><option value="4.23289,98.00289">Kab. Aceh Tamiang</option><option value="4.44826,96.8351">Kab. Aceh Tengah</option><option value="3.30887,97.69823">Kab. Aceh Tenggara</option><option value="5.25544,95.98855">Kab. Aceh Timur</option><option value="4.97863,97.22214">Kab. Aceh Utara</option><option value="-0.22094,100.17033">Kab. Agam</option><option value="-8.2754,124.72988">Kab. Alor</option><option value="-3.65607,128.16642">Kota Ambon</option><option value="3.10555,105.65372">Kab. Anambas</option><option value="2.81747,99.63414">Kab. Asahan</option><option value="-5.0574,138.39882">Kab. Asmat</option><option value="-8.58193,115.17706">Kab. Badung</option><option value="-2.32604,115.61547">Kab. Balangan</option><option value="-1.26354,116.82788">Kota Balikpapan</option><option value="5.55,95.31667">Kota Banda Aceh</option><option value="-5.45,105.26667">Kota Bandar Lampung</option><option value="-7.055109,107.618646">Kab. Bandung</option><option value="-6.912645,107.618093">Kota Bandung</option><option value="-6.89371,107.4322">Kab. Bandung Barat</option><option value="-1.64081,123.55041">Kab. Banggai</option><option value="-1.64081,123.55041">Kab. Banggai Kepulauan</option><option value="-2.28848,106.06402">Kab. Bangka</option><option value="-2.28848,106.06402">Kab. Bangka Barat</option><option value="-2.28848,106.06402">Kab. Bangka Selatan</option><option value="-2.28848,106.06402">Kab. Bangka Tengah</option><option value="-7.03069,112.74501">Kab. Bangkalan</option><option value="-8.4543,115.3549">Kab. Bangli</option><option value="-7.36667,108.53333">Kota Banjar</option><option value="-7.36667,108.53333">Kab. Banjar</option><option value="-3.46667,114.75">Kota Banjar Baru</option><option value="-3.3285,114.5892">Kota Banjarmasin</option><option value="-7.40271,109.6814">Kab. Banjarnegara</option><option value="-5.51693,120.0203">Kab. Bantaeng</option><option value="-7.88461,110.33411">Kab. Bantul</option><option value="-2.60956,104.75209">Kab. Banyu Asin</option><option value="-7.48321,109.14044">Kab. Banyumas</option><option value="-8.21861,114.36694">Kab. Banyuwangi</option><option value="-3.07147,114.66679">Kab. Barito Kuala</option><option value="-1.87594,114.80927">Kab. Barito Selatan</option><option value="-2.0124,115.18892">Kab. Barito Timur</option><option value="-0.95871,115.09405">Kab. Barito Utara</option><option value="-4.41727,119.67309">Kab. Barru</option><option value="-6.33297,106.80792">Kab. Baru</option><option value="1.04563,104.03045">Kota Batam</option><option value="-6.89411,109.72345">Kab. Batang</option><option value="-1.671637,103.076337">Kab. Batang Hari</option><option value="-7.8671,112.5239">Kota Batu</option><option value="3.1741,99.50061">Kab. Batu Bara</option><option value="-5.470611,122.597712">Kota Bau-Bau</option><option value="-6.26283,107.12413">Kab. Bekasi</option><option value="-6.2429,106.9768">Kota Bekasi</option><option value="-2.87089,107.95318">Kab. Belitung</option><option value="-2.87089,107.95318">Kab. Belitung Timur</option><option value="-9.41258,124.95066">Kab. Belu</option><option value="4.77483,97.00684">Kab. Bener Meriah</option><option value="1.48972,102.07972">Kab. Bengkalis</option><option value="0.82097,109.4777">Kab. Bengkayang</option><option value="-3.79556,102.25917">Kota Bengkulu</option><option value="-4.32484,103.03569">Kab. Bengkulu Selatan</option><option value="-3.79556,102.25917">Kab. Bengkulu Tengah</option><option value="-3.42196,102.16327">Kab. Bengkulu Utara</option><option value="2.04509,117.36165">Kab. Berau</option><option value="-1.0381,135.98008">Kab. Biak Numfor</option><option value="-8.46057,118.7274">Kab. Bima</option><option value="-8.46057,118.7274">Kota Bima</option><option value="3.59446,98.48225">Kota Binjai</option><option value="1.06192,104.51892">Kab. Bintan</option><option value="5.18254,96.89005">Kab. Bireuen</option><option value="1.45535,125.2047">Kota Bitung</option><option value="-8.10144,112.16276">Kab. Blitar</option><option value="-8.1,112.15">Kota Blitar</option><option value="-6.95,111.41667">Kab. Blora</option><option value="0.70134,122.26539">Kab. Boalemo</option><option value="-6.58703,106.701463">Kab. Bogor</option><option value="-6.594841,106.805627">Kota Bogor</option><option value="-7.1526,111.8865">Kab. Bojonegoro</option><option value="0.6871,124.06414">Kab. Bolaang Mongondow</option><option value="0.81869,123.52801">Kab. Bolaang Mongondow Utara</option><option value="0.40532,123.84113">Kab. Bolang Mongondow Selatan</option><option value="0.71527,124.46418">Kab. Bolang Mongondow Timur</option><option value="-4.65435,121.9018">Kab. Bombana</option><option value="-7.9177,113.81348">Kab. Bondowoso</option><option value="-2.08333,120.21667">Kab. Bone</option><option value="0.56579,123.34861">Kab. Bone Bolango</option><option value="0.13333,117.51111">Kota Bontang</option><option value="-5.74,140.34818">Kab. Boven Digoel</option><option value="-7.52382,110.5959">Kab. Boyolali</option><option value="-6.88333,109.05">Kab. Brebes</option><option value="-0.30556,100.36917">Kota Bukittinggi</option><option value="-8.120864,115.071735">Kab. Buleleng</option><option value="-5.43294,120.20511">Kab. Bulukumba</option><option value="2.90425,116.98524">Kab. Bulungan</option><option value="-1.64013,101.88917">Kab. Bungo</option><option value="0.96955,121.35416">Kab. Buol</option><option value="-3.39278,126.78195">Kab. Buru</option><option value="-3.39278,126.78195">Kab. Buru Selatan</option><option value="-5.30964,122.98883">Kab. Buton</option><option value="-4.70234,123.03388">Kab. Buton Utara</option><option value="-7.33333,108.35">Kab. Ciamis</option><option value="-6.81725,107.13073">Kab. Cianjur</option><option value="-7.73333,109.02766">Kab. Cilacap</option><option value="-6.01698,106.04051">Kota Cilegon</option><option value="-6.88024,107.5355">Kota Cimahi</option><option value="-6.778261,108.515717">Kab. Cirebon</option><option value="-6.733988,108.552321">Kota Cirebon</option><option value="2.86758,98.26506">Kab. Dairi</option><option value="-4.09749,136.43931">Kab. Deiyai</option><option value="3.42018,98.70408">Kab. Deli Serdang</option><option value="-6.88812,110.6393">Kab. Demak</option><option value="-8.65629,115.2221">Kota Denpasar</option><option value="-6.39,106.83">Kota Depok</option><option value="-1.11206,101.61578">Kab. Dharmas Raya</option><option value="-4.01939,135.96104">Kab. Dogiyai</option><option value="-8.49663,118.47472">Kab. Dompu</option><option value="-0.42332,119.83523">Kab. Donggala</option><option value="1.66574,101.4476">Kota Dumai</option><option value="-3.7286,102.89751">Kab. Empat Lawang</option><option value="-8.85405,121.6542">Kab. Ende</option><option value="-3.56313,119.7612">Kab. Enrekang</option><option value="-2.88524,132.26583">Kab. Fakfak</option><option value="-8.31309,122.9663">Kab. Flores Timur</option><option value="-7.22791,107.9087">Kab. Garut</option><option value="3.95517,97.35166">Kab. Gayo Lues</option><option value="-8.54419,115.3255">Kab. Gianyar</option><option value="0.53333,123.06667">Kab. Gorontalo</option><option value="0.53333,123.06667">Kota Gorontalo</option><option value="0.92526,122.49201">Kab. Gorontalo Utara</option><option value="-5.31029,119.7426">Kab. Gowa</option><option value="-7.15665,112.6555">Kab. Gresik</option><option value="-7.02172,110.96259">Kab. Grobogan</option><option value="-8.03051,110.61689">Kab. Gunung Kidul</option><option value="-6.70528,106.99139">Kab. Gunung Mas</option><option value="1.28196,97.61594">Kota Gunungsitoli</option><option value="1.31212,128.48499">Kab. Halmahera Barat</option><option value="1.31212,128.48499">Kab. Halmahera Selatan</option><option value="1.31212,128.48499">Kab. Halmahera Tengah</option><option value="1.31212,128.48499">Kab. Halmahera Timur</option><option value="1.31212,128.48499">Kab. Halmahera Utara</option><option value="-2.76627,115.23634">Kab. Hulu Sungai Selatan</option><option value="-2.61532,115.52074">Kab. Hulu Sungai Tengah</option><option value="-2.44212,115.18892">Kab. Hulu Sungai Utara</option><option value="2.19885,98.5721">Kab. Humbang Hasundutan</option><option value="-0.14567,102.98962">Kab. Indragiri Hilir</option><option value="-0.73612,102.25479">Kab. Indragiri Hulu</option><option value="-6.33632,108.3251">Kab. Indramayu</option><option value="-3.50764,136.74785">Kab. Intan Jaya</option><option value="-6.21154,106.84517">Kota Jakarta Barat</option><option value="-6.21154,106.84517">Kota Jakarta Pusat</option><option value="-6.33297,106.80792">Kota Jakarta Selatan</option><option value="-6.21154,106.84517">Kota Jakarta Timur</option><option value="-6.21154,106.84517">Kota Jakarta Utara</option><option value="-1.610091,103.609872">Kota Jambi</option><option value="-2.563152,140.499954">Kab. Jayapura</option><option value="-2.59169,140.66972">Kota Jayapura</option><option value="-4.00045,138.79951">Kab. Jayawijaya</option><option value="-8.17236,113.7003">Kab. Jember</option><option value="-8.36185,114.6418">Kab. Jembrana</option><option value="-5.55458,119.67309">Kab. Jeneponto</option><option value="-6.55961,110.6717">Kab. Jepara</option><option value="-7.54684,112.22648">Kab. Jombang</option><option value="-3.66093,133.77451">Kab. Kaimana</option><option value="0.14667,101.16174">Kab. Kampar</option><option value="-2.987763,114.385672">Kab. Kapuas</option><option value="-0.7931,113.90606">Kab. Kapuas Hulu</option><option value="-8.44,115.61">Kab. Karangasem</option><option value="-7.59611,110.95083">Kab. Karanganyar</option><option value="-6.32273,107.33758">Kab. Karawang</option><option value="1.05,103.36667">Kab. Karimun</option><option value="3.10529,98.26506">Kab. Karo</option><option value="-0.97584,112.81055">Kab. Katingan</option><option value="-4.67923,103.45118">Kab. Kaur</option><option value="-0.92259,110.04497">Kab. Kayong Utara</option><option value="-7.67868,109.6565">Kab. Kebumen</option><option value="-7.80936,112.03236">Kab. Kediri</option><option value="-7.8169,112.0114">Kota Kediri</option><option value="-3.34495,140.76245">Kab. Keerom</option><option value="-6.91969,110.2056">Kab. Kendal</option><option value="-3.9722,122.5149">Kota Kendari</option><option value="-3.65143,102.5782">Kab. Kepahiang</option><option value="-6.19465,134.55019">Kab. Kepulauan Aru</option><option value="-2.150198,99.639227">Kab. Kepulauan Mentawai</option><option value="0.92088,102.66756">Kab. Kepulauan Meranti</option><option value="3.53032,125.5439">Kab. Kepulauan Sangihe</option><option value="-5.79853,106.5072">Kab. Kepulauan Seribu</option><option value="-1.86667,125.36667">Kab. Kepulauan Sula</option><option value="4.351412,126.812467">Kab. Kepulauan Talaud</option><option value="-1.74694,136.1709">Kab. Kepulauan Yapen</option><option value="-1.994491,101.374358">Kab. Kerinci</option><option value="-1.8591,109.9719">Kab. Ketapang</option><option value="-7.71169,110.5955">Kab. Klaten</option><option value="-8.53892,115.40451">Kab. Klungkung</option><option value="-4.04967,121.5938">Kab. Kolaka</option><option value="-3.13472,121.17104">Kab. Kolaka Utara</option><option value="-3.93804,122.08374">Kab. Konawe</option><option value="-4.20279,122.44672">Kab. Konawe Selatan</option><option value="-3.38033,122.08374">Kab. Konawe Utara</option><option value="0.73333,124.31667">Kota Kotamobagu</option><option value="-5.64085,132.74751">Kota KotaTual</option><option value="-6.19611,106.86302">Kab. Kotawaringin Barat</option><option value="-6.1953,106.86307">Kab. Kotawaringin Timur</option><option value="-0.44116,101.52481">Kab. Kuantan Singingi</option><option value="-0.35339,109.47351">Kab. Kubu Raya</option><option value="-6.80409,110.8382">Kab. Kudus</option><option value="-7.82668,110.16408">Kab. Kulon Progo</option><option value="-6.98333,108.48333">Kab. Kuningan</option><option value="-10.18333,123.58333">Kab. Kupang</option><option value="-10.18333,123.58333">Kota Kupang</option><option value="0.13539,115.09405">Kab. Kutai Barat</option><option value="-0.13367,116.60817">Kab. Kutai Kartanegara</option><option value="0.94338,116.98524">Kab. Kutai Timur</option><option value="2.34399,100.17033">Kab. Labuhanbatu</option><option value="1.87994,100.17033">Kab. Labuhanbatu Selatan</option><option value="2.34656,99.81249">Kab. Labuhanbatu Utara</option><option value="-3.78639,103.54278">Kab. Lahat</option><option value="-1.92692,111.18912">Kab. Lamandau</option><option value="-7.40615,109.39468">Kab. Lamongan</option><option value="-5.14904,104.19309">Kab. Lampung Barat</option><option value="-5.56226,105.54744">Kab. Lampung Selatan</option><option value="-4.80081,105.31312">Kab. Lampung Tengah</option><option value="-5.1135,105.68818">Kab. Lampung Timur</option><option value="-4.81339,104.75209">Kab. Lampung Utara</option><option value="0.42373,109.75917">Kab. Landak</option><option value="3.86539,98.30884">Kab. Langkat</option><option value="4.48,97.96333">Kota Langsa</option><option value="-3.97103,138.31903">Kab. Lanny Jaya</option><option value="-6.5644,106.25221">Kab. Lebak</option><option value="-2.99262,104.3822">Kab. Lebong</option><option value="-8.47191,123.48319">Kab. Lembata</option><option value="5.18806,97.14028">Kota Lhokseumawe</option><option value="3.16822,99.41879">Kab. Lima Puluh Kota</option><option value="-0.16277,104.63546">Kab. Lingga</option><option value="-8.64646,116.11231">Kab. Lombok Barat</option><option value="-8.69462,116.27771">Kab. Lombok Tengah</option><option value="-8.51345,116.56099">Kab. Lombok Timur</option><option value="-8.37391,116.27771">Kab. Lombok Utara</option><option value="-3.29667,102.86167">Kota Lubuklinggau</option><option value="-8.13702,113.2266">Kab. Lumajang</option><option value="-3.30522,120.25127">Kab. Luwu</option><option value="-2.58255,121.17104">Kab. Luwu Timur</option><option value="-2.26904,119.97405">Kab. Luwu Utara</option><option value="-7.62775,111.50548">Kab. Madiun</option><option value="-7.62971,111.5137">Kota Madiun</option><option value="-7.48125,110.2138">Kab. Magelang</option><option value="-7.48125,110.2138">Kota Magelang</option><option value="-7.64934,111.33816">Kab. Magetan</option><option value="-6.8531,108.22589">Kab. Majalengka</option><option value="-3.02973,118.90628">Kab. Majene</option><option value="-5.13333,119.41667">Kota Makassar</option><option value="-8.04956,112.68845">Kab. Malang</option><option value="-7.98189,112.6265">Kota Malang</option><option value="3.58422,116.6478">Kab. Malinau</option><option value="-7.78516,126.34981">Kab. Maluku Barat Daya</option><option value="-3.01665,129.48644">Kab. Maluku Tengah</option><option value="-5.75125,132.72716">Kab. Maluku Tenggara</option><option value="-7.53226,131.36111">Kab. Maluku Tenggara Barat</option><option value="-2.96014,119.3682">Kab. Mamasa</option><option value="-2.53313,137.76376">Kab. Mamberamo Raya</option><option value="-2.72934,118.92957">Kab. Mamuju</option><option value="-1.52645,119.51077">Kab. Mamuju Utara</option><option value="1.4917,124.84284">Kota Manado</option><option value="0.74324,99.36731">Kab. Mandailing Natal</option><option value="-8.6797,120.38967">Kab. Manggarai</option><option value="-8.66881,120.06652">Kab. Manggarai Barat</option><option value="-8.62067,120.61999">Kab. Manggarai Timur</option><option value="-0.86145,134.06204">Kab. Manokwari</option><option value="-7.10223,139.39639">Kab. Mappi</option><option value="-4.94695,119.5789">Kab. Maros</option><option value="-8.58333,116.11667">Kota Mataram</option><option value="3.1472,101.6997">Kab. Maybat</option><option value="3.58524,98.6756">Kota Medan</option><option value="-0.70007,111.66607">Kab. Melawi</option><option value="-2.37457,138.31903">Kab. Memberamo Tengah</option><option value="-2.17528,101.98046">Kab. Merangin</option><option value="-8.49604,140.39455">Kab. Merauke</option><option value="-4.00448,105.31312">Kab. Mesuji</option><option value="-5.11869,105.3081">Kota Metro</option><option value="-4.45532,137.13621">Kab. Mimika</option><option value="1.17735,124.58333">Kab. Minahasa</option><option value="1.09468,124.46418">Kab. Minahasa Selatan</option><option value="1.02786,124.72988">Kab. Minahasa Tenggara</option><option value="1.5328,124.99475">Kab. Minahasa Utara</option><option value="-7.48808,112.42703">Kab. Mojokerto</option><option value="-7.47222,112.43361">Kota Mojokerto</option><option value="-2.628789,121.893506">Kab. Morowali</option><option value="-3.65158,103.7708">Kab. Muara Enim</option><option value="-1.59667,103.6158">Kab. Muaro Jambi</option><option value="-2.692161,101.444291">Kab. Mukomuko</option><option value="-4.90163,122.62775">Kab. Muna</option><option value="-0.13622,114.33414">Kab. Murung Raya</option><option value="-2.5442,103.72892">Kab. Musi Banyuasin</option><option value="-2.86253,102.98962">Kab. Musi Rawas</option><option value="-3.50955,135.7521">Kab. Nabire</option><option value="4.12484,96.49298">Kab. Nagan Raya</option><option value="-8.67535,121.30841">Kab. Nagekeo</option><option value="3.93299,108.18122">Kab. Natuna</option><option value="-4.40695,138.23935">Kab. Nduga</option><option value="-8.74304,120.98763">Kab. Ngada</option><option value="-7.60293,111.90181">Kab. Nganjuk</option><option value="-7.38993,111.46193">Kab. Ngawi</option><option value="-8.17126,113.71113">Kab. Nias</option><option value="1.12553,97.52472">Kab. Nias Barat</option><option value="0.70861,97.82864">Kab. Nias Selatan</option><option value="1.12553,97.52472">Kab. Nias Utara</option><option value="4.06092,117.66695">Kab. Nunukan</option><option value="-3.42654,104.61215">Kab. Ogan Ilir</option><option value="-3.45597,105.21948">Kab. Ogan Komering Ilir</option><option value="-4.02835,104.00723">Kab. Ogan Komering Ulu</option><option value="-4.6682,104.00723">Kab. Ogan Komering Ulu Selatan</option><option value="-3.85679,104.75209">Kab. Ogan Komering Ulu Timur</option><option value="-8.20461,111.08769">Kab. Pacitan</option><option value="-0.95,100.35306">Kota Padang</option><option value="1.1187,99.81249">Kab. Padang Lawas</option><option value="1.57586,99.63414">Kab. Padang Lawas Utara</option><option value="-0.47068,100.40595">Kota Padang Panjang</option><option value="-0.55468,100.21516">Kab. Padang Pariaman</option><option value="1.38042,99.27397">Kota Padangsidimpuan</option><option value="-4.03767,103.2653">Kota Pagar Alam</option><option value="2.54579,98.29984">Kab. Pakpak Bharat</option><option value="-2.21,113.92">Kota Palangka Raya</option><option value="-2.99111,104.75673">Kota Palembang</option><option value="-3.00195,120.19792">Kota Palopo</option><option value="-0.89858,119.8506">Kota Palu</option><option value="-7.16667,113.46667">Kab. Pamekasan</option><option value="-6.31484,106.1039">Kab. Pandeglang</option><option value="-4.80504,119.55717">Kab. Pangkajene Dan Kepulauan</option><option value="-2.12932,106.1096">Kota Pangkal Pinang</option><option value="-3.78764,136.36247">Kab. Paniai</option><option value="-4.01667,119.62361">Kota Pare-Pare</option><option value="-0.62644,100.11796">Kota Pariaman</option><option value="0.58176,120.80395">Kab. Parigi Moutong</option><option value="0.12888,99.79018">Kab. Pasaman</option><option value="0.2213,99.63414">Kab. Pasaman Barat</option><option value="-1.71753,115.9468">Kab. Paser</option><option value="-7.72,112.80">Kab. Pasuruan</option><option value="-7.64487,112.9033">Kota Pasuruan</option><option value="-6.750300,111.037089">Kab. Pati</option><option value="-0.22887,100.6323">Kota Payakumbuh</option><option value="-4.55899,140.51356">Kab. Pegunungan Bintang</option><option value="-6.88289,109.67">Kab. Pekalongan</option><option value="-6.88289,109.67">Kota Pekalongan</option><option value="0.53333,101.45">Kota Pekanbaru</option><option value="0.44142,102.0887">Kab. Pelalawan</option><option value="-7.036284,109.382786">Kab. Pemalang</option><option value="2.96,99.06">Kota Pematang Siantar</option><option value="-1.29171,116.5138">Kab. Penajam Paser Utara</option><option value="-5.49325,105.07912">Kab. Pesawaran</option><option value="-1.72231,100.89031">Kab. Pesisir Selatan</option><option value="5.07427,95.94097">Kab. Pidie</option><option value="5.15481,96.19513">Kab. Pidie Jaya</option><option value="-3.79307,119.6408">Kab. Pinrang</option><option value="0.70553,121.71955">Kab. Pohuwato</option><option value="-3.34193,119.13906">Kab. Polewali Mandar</option><option value="-7.893553,111.460681">Kab. Ponorogo</option><option value="-0.02252,109.33031">Kab. Pontianak</option><option value="-0.02252,109.33031">Kota Pontianak</option><option value="-1.632373,120.513208">Kab. Poso</option><option value="-3.44096,104.2354">Kota Prabumulih</option><option value="-5.35399,104.96225">Kab. Pringsewu</option><option value="-7.75397,113.21068">Kab. Probolinggo</option><option value="-7.75693,113.2115">Kota Probolinggo</option><option value="-2.68496,113.95365">Kab. Pulang Pisau</option><option value="2.36567,128.40084">Kab. Pulau Morota</option><option value="-6.71255,106.95424">Kab. Puncak</option><option value="-4.08361,137.18472">Kab. Puncak Jaya</option><option value="-7.39075,109.3638">Kab. Purbalingga</option><option value="-6.53868,107.44994">Kab. Purwakarta</option><option value="-7.683123,109.999614">Kab. Purworejo</option><option value="-1.09152,130.87786">Kab. Raja Ampat</option><option value="-3.45482,102.66756">Kab. Rejang Lebong</option><option value="-6.71124,111.3453">Kab. Rembang</option><option value="1.6464,100.80001">Kab. Rokan Hilir</option><option value="1.04109,100.43966">Kab. Rokan Hulu</option><option value="-10.73864,123.1239">Kab. Rote Ndao</option><option value="0.745549,101.841587">Kab. Siak</option><option value="5.89469,95.3193">Kota Sabang</option><option value="-10.55411,121.83349">Kab. Sabu Raijua</option><option value="-7.30233,110.4729">Kota Salatiga</option><option value="-0.502,117.153">Kota Samarinda</option><option value="1.36133,109.31">Kab. Sambas</option><option value="2.58333,98.81667">Kab. Samosir</option><option value="-7.57826,109.20584">Kab. Sampang</option><option value="0.11928,110.5973">Kab. Sanggau</option><option value="-1.86873,138.74361">Kab. Sarmi</option><option value="-2.26549,102.69053">Kab. Sarolangun</option><option value="-2.26549,102.69053">Kab. Sarolangun</option><option value="-0.68103,100.77636">Kota Sawah Lunto</option><option value="0.01564,110.8886">Kab. Sekadau</option><option value="-6.09622,120.50113">Kab. Selayar</option><option value="-4.06229,102.56423">Kab. Seluma</option><option value="-6.96667,110.41667">Kab. Semarang</option><option value="-6.96667,110.41667">Kota Semarang</option><option value="-3.12716,128.40084">Kab. Seram Bagian Barat</option><option value="-3.41508,130.39049">Kab. Seram Bagian Timur</option><option value="-6.12009,106.1503">Kab. Serang</option><option value="-6.12009,106.1503">Kota Serang</option><option value="3.33717,99.05711">Kab. Serdang Bedagai</option><option value="-3.01235,112.42915">Kab. Seruyan</option><option value="2.34596,125.41244">Kab. Siau Tagulandang Biaro</option><option value="1.74037,98.7828">Kota Sibolga</option><option value="-3.7739,120.0203">Kab. Sidenreng Rappang</option><option value="-7.45303,112.71734">Kab. Sidoarjo</option><option value="-1.38341,120.06652">Kab. Sigi</option><option value="-0.68816,100.99766">Kab. Sijunjung</option><option value="-8.67662,122.12918">Kab. Sikka</option><option value="2.97816,99.27856">Kab. Simalungun</option><option value="2.58333,96.08333">Kab. Simeulue</option><option value="0.9088,108.9846">Kota Singkawang</option><option value="-5.2172,120.11274">Kab. Sinjai</option><option value="0.08024,111.4955">Kab. Sintang</option><option value="-7.70253,113.95561">Kab. Situbondo</option><option value="-7.71617,110.3354">Kab. Sleman</option><option value="-0.80303,100.6444">Kab. Solok</option><option value="-0.80303,100.6444">Kota Solok</option><option value="-1.41573,101.25238">Kab. Solok Selatan</option><option value="-4.35185,119.92779">Kab. Soppeng</option><option value="-0.86667,131.25">Kota Sorong</option><option value="-0.86667,131.25">Kab. Sorong</option><option value="-0.86667,131.25">Kab. Sorong Selatan</option><option value="-7.43023,111.0213">Kab. Sragen</option><option value="-6.56936,107.7524">Kab. Subang</option><option value="2.64499,98.01652">Kota Subulussalam</option><option value="-6.92405,106.9222">Kab. Sukabumi</option><option value="-6.92405,106.9222">Kota Sukabumi</option><option value="-2.62675,111.23681">Kab. Sukamara</option><option value="-7.68088,110.81953">Kab. Sukoharjo</option><option value="-9.65483,119.39471">Kab. Sumba Barat</option><option value="-9.53914,119.13906">Kab. Sumba Barat Daya</option><option value="-9.48792,119.69627">Kab. Sumba Tengah</option><option value="-9.98021,120.34355">Kab. Sumba Timur</option><option value="-8.65293,117.36165">Kab. Sumbawa</option><option value="-8.92929,116.89103">Kab. Sumbawa Barat</option><option value="0.60959,110.03306">Kab. Sumedang</option><option value="-6.9254,113.90606">Kab. Sumenep</option><option value="-2.062182,101.409894">Kota Sungai Penuh</option><option value="-0.72951,135.63851">Kab. Supiori</option><option value="-7.28917,112.7344">Kota Surabaya</option><option value="-7.56667,110.81667">Kota Surakarta</option><option value="-1.8643,115.56811">Kab. Tabalong</option><option value="-8.54452,115.1198">Kab. Tabanan</option><option value="-5.41625,119.48757">Kab. Takalar</option><option value="-0.78186,132.39384">Kab. Tambrauw</option><option value="3.55187,117.07941">Kab. Tana Tidung</option><option value="-3.0753,119.7426">Kab. Tana Toraja</option><option value="-3.45122,115.56811">Kab. Tanah Bumbu</option><option value="-0.4797,100.57462">Kab. Tanah Datar</option><option value="-3.7694,114.80927">Kab. Tanah Laut</option><option value="-6.17831,106.63189">Kab. Tangerang</option><option value="-6.17831,106.63189">Kota Tangerang</option><option value="-6.28889,106.71806">Kota Tangerang Selatan</option><option value="-5.30275,104.56553">Kab. Tanggamus</option><option value="2.96512,99.80033">Kota Tanjung Balai</option><option value="-1.23321,103.79844">Kab. Tanjung Jabung Barat</option><option value="-1.32916,103.89973">Kab. Tanjung Jabung Timur</option><option value="0.91792,104.44646">Kota Tanjung Pinang</option><option value="1.57749,99.27856">Kab. Tapanuli Selatan</option><option value="1.84933,98.70408">Kab. Tapanuli Tengah</option><option value="2.04052,99.10135">Kab. Tapanuli Utara</option><option value="-2.91607,115.0466">Kab. Tapin</option><option value="3.31111,117.63333">Kota Tarakan</option><option value="-7.32795,108.2141">Kab. Tasikmalaya</option><option value="-7.32795,108.2141">Kota Tasikmalaya</option><option value="3.38562,99.20098">Kota Tebing Tinggi</option><option value="-1.2593,102.34639">Kab. Tebo</option><option value="-6.86667,109.13333">Kota Tegal</option><option value="-1.90568,133.32947">Kab. Teluk Bintuni</option><option value="-2.85517,134.32366">Kab. Teluk Wondama</option><option value="-7.31667,110.1748">Kab. Temanggung</option><option value="0.78333,127.36667">Kota Ternate</option><option value="0.68861,127.40778">Kota Tidore Kepulauan</option><option value="-9.77628,124.41982">Kab. Timor Tengah Selatan</option><option value="-9.45226,124.59713">Kab. Timor Tengah Utara</option><option value="2.35024,99.27856">Kab. Toba Samosir</option><option value="-1.183583,121.505106">Kab. Tojo Una-Una</option><option value="0.87682,120.75798">Kab. Toli-Toli</option><option value="-3.48113,138.47873">Kab. Tolikara</option><option value="1.32341,124.83845">Kota Tomohon</option><option value="-2.86219,119.83523">Kab. Toraja Utara</option><option value="-8.05,111.71667">Kab. Trenggalek</option><option value="-8.74931,115.17113">Kab. Tuban</option><option value="-4.31766,105.50055">Kab. Tulangbawang</option><option value="-4.5257,105.07912">Kab. Tulangbawang Barat</option><option value="-8.06667,111.9">Kab. Tulungagung</option><option value="-4.02223,120.06652">Kab. Wajo</option><option value="-5.32644,123.59519">Kab. Wakatobi</option><option value="-2.84357,136.67053">Kab. Waropen</option><option value="-4.49637,104.56553">Kab. Way Kanan</option><option value="-7.81778,110.9206">Kab. Wonogiri</option><option value="-7.36211,109.8994">Kab. Wonosobo</option><option value="-4.487294,139.573650">Kab. Yahukimo</option><option value="-3.78528,139.4466">Kab. Yalimo</option><option value="-7.79722,110.3688">Kota Yogyakarta</option></select>
        </td>
      </tr>    
      <tr>
        <td>
          <label for="latitude">Latitude</label>
          <input id="latitude" placeholder="-7.7430387" size="10%" onchange="setJws()">
        </td>
        <td>
          <label for="longitude">Longitude</label>
          <input id="longitude" placeholder="112.7005511" size="10%" onchange="setJws()">
        </td>
      </tr>
      <tr>
        <td>
          <label for="altitude">Altitude</label>
          <input id="altitude" placeholder="10.0" size="10%" onchange="setJws()">
        </td>
        <td>
          <label for="zonawaktu">Zona Waktu</label>
          <input id="zonawaktu" placeholder="7" size="10%" onchange="setJws()">
        </td>
      </tr>
    </tbody></table>
  </div>
</div>
<div id="onoffdf" style="display: block;">
  <div>
    <h3>Volume</h3>
    <div>
      <input type="range" min="0" max="23" value="15" id="volume" oninput="sendVolume()">
    </div>
    <br>
    <div>
      <button class="play" id="play" onclick="sendPlay()">Play</button>
      <button class="play" id="pause" onclick="sendPause()">Pause</button>
      <button class="play" id="stop" onclick="sendStop()">Stop</button>
    </div>
    <br>
    <div>
      <button class="play" id="prev" onclick="sendPrev()">Prev</button>
      <button class="play" id="random" onclick="sendRandom()">Random</button>
      <button class="play" id="next" onclick="sendNext()">Next</button>   
    </div>
    <br>
    <div>
      <button class="tombol" id="modejam" onclick="sendModeJam()">JWS</button>
      <button class="tombol" id="modemp3" onclick="sendModeMP3()">Murottal</button>
    </div>  
  </div>
  
  <div id="pagelist">
    <hr>
    <h3>Playlist</h3>
    <div>
      <select id="playlist" onchange="sendPlaylist()">
        <option value="p1">Al Quran Dibacakan Oleh...</option>
        <option value="p2">Al Quran - Saad Al Ghamdi</option>
        <option value="p3">Juz Amma - Saad Al Ghamdi</option>
        <option value="p4">Al Quran - Mishary Rasyid</option>
        <option value="p5">Juz Amma - Mishary Rasyid</option>
        <option value="p6">Al Quran - As Sudais</option>
        <option value="p7">Juz Amma - As Sudais</option>
        <option value="p8">Al Quran - Al Budair</option>
        <option value="p9">Juz Amma - Al Budair</option>
        <option value="pl1">Al Quran - Al Muaiqly</option>
        <option value="pl2">Juz Amma - Al Muaiqly</option>
        <option value="pl3">Al Quran - Al Hudhaifi</option>
        <option value="pl4">Juz Amma - Al Hudhaifi</option>
        <option value="pl5">Lain-lain</option>
      </select>
    </div>
    <br>
    <div>
      <span id="foldermp3"></span>
      <span id="trackmp3"></span>
    </div>
    <br>
    <br>

    <hr>
    <h3>Play per Ayat</h3>    
    <div>
      <span id="psurah"></span>
      <input id="payat" placeholder="0" maxlength="6" size="6">
    </div>
    <br><br>
    <div>
      <button class="play" id="pause" onclick="sendPause()">Pause</button>
      <button class="play" id="resume" onclick="sendPlay()">Resume</button>
      <button class="play" id="play" onclick="PlayAyat()">Play</button>
    </div>
    <br>
    <br>Loop Track<br>
    <div class="onoffswitch">
      <input type="checkbox" name="onoffswitch" class="onoffswitch-checkbox" id="trackloop" onclick="onoffloop()">
      <label class="onoffswitch-label" for="trackloop">
        <span class="onoffswitch-inner"></span>
        <span class="onoffswitch-switch"></span>
      </label>
    </div>
    <br>
    <br>
    <div>
      <br>Track Lainnya<br><br>
      <span id="tracklainmp3"></span> 
    </div>   
    
    </div>
    
    <hr>
    <h3>Equalizer</h3>
    <div>
      <select id="equalizer" onchange="sendEqualizer()">
        <option value="e0">Pilih Equalizer...</option>
        <option value="e1">Normal</option>
        <option value="e2">Pop</option>
        <option value="e3">Rock</option>
        <option value="e4">Jazz</option>
        <option value="e5">Classic</option>
        <option value="e6">Bass</option>
      </select>
    </div>
  </div>


<div id="pagerelay">
  <hr>
  <h4>Relay Power Ampli</h4>
  <div class="onoffswitch">
    <input type="checkbox" name="onoffswitch" class="onoffswitch-checkbox" id="relay" onclick="sendRelay()">
    <label class="onoffswitch-label" for="relay">
      <span class="onoffswitch-inner"></span>
      <span class="onoffswitch-switch"></span>
    </label>
  </div>
</div>

<div id="pageinfo">
  <hr>
  <h3>Informasi</h3>
  <div>
    <label for="laporan">Laporan</label>
    <textarea rows="5" id="laporan" placeholder="Laporan" onchange="sendNama()"></textarea>
  </div>
  <div>
    <label for="info1">Informasi 1</label>
    <textarea rows="5" id="info1" placeholder="Info1" onchange="sendNama()"></textarea>
  </div>
  <div>
    <label for="info2">Informasi 2</label>
    <textarea rows="5" id="info2" placeholder="Info2" onchange="sendNama()"></textarea>
  </div>
  <div>
    <label for="nama">Nama Masjid</label>
    <textarea rows="3" id="nama" placeholder="Nama Masjid" onchange="sendNama()"></textarea>
  </div>
  <div>
    <label for="kecepatan">Kecepatan</label>
    <input type="range" min="10" max="100" value="50" id="kecepatan" oninput="sendNama()">
  </div>
</div>

<div id="pagejws">
  <hr>
  <h3>Jadwal Waktu Sholat</h3>
  <table width="100%">
    <tbody><tr>
      <td><p id="jdhuhr" class="info">Dhuhr: </p></td>
      <td><p id="jashr" class="info">Ashr: </p></td>
      <td><p id="jmaghrib" class="info">Maghrib: </p></td>
      <td><p id="jisya" class="info">Isya': </p></td>
    </tr>
    <tr>
      <td><p id="jimsak" class="info">Imsak: </p></td>
      <td><p id="jshubuh" class="info">Subuh: </p></td>
      <td><p id="jthulu" class="info">Syuruq: </p></td>
      <td><p id="jdluha" class="info"></p></td>
    </tr>
  </tbody></table>

  <h3>Ihtiyath</h3>
  <div>
    <table width="100%">
      <tbody><tr>
        
        <td>
          <label for="ihtid">Dzuhur</label><br>
          <input id="ihtid" placeholder="8" maxlength="2" size="2" onchange="setJws()">
        </td>
        <td>
          <label for="ihtia">Ashar</label><br>
          <input id="ihtia" placeholder="6" maxlength="2" size="2" onchange="setJws()">
        </td>
        <td>
          <label for="ihtim">Maghrib</label><br>
          <input id="ihtim" placeholder="5" maxlength="2" size="2" onchange="setJws()">
        </td>
      </tr>
      <tr>
        <td>
          <label for="ihtii">Isya</label><br>
          <input id="ihtii" placeholder="5" maxlength="2" size="2" onchange="setJws()">
        </td>
        <td>
          <label for="ihtis">Subuh</label><br>
          <input id="ihtis" placeholder="12" maxlength="2" size="2" onchange="setJws()">
        </td>
        <td>
          <label for="durasisholat">Durasi Sholat</label><br>
          <input id="durasisholat" placeholder="5" maxlength="2" size="2" onchange="setJws()">
        </td>
      </tr>
    </tbody></table>
  </div>
  <h3>Inkhifad Ufuq</h3>
  <div>
    <table width="100%">
      <tbody><tr>
        <td>
          <div>
            <label for="inkhifads">Shubuh</label><br>
            <select id="inkhifads" onchange="setJws()">
              <option value="-19.00">-19.0</option>
              <option value="-19.50">-19.5</option>
              <option value="-19.50">-19.8</option>
              <option value="-20.00">-20.0</option>
            </select>
          </div>
        </td>
        <td>
          <div>
            <label for="inkhifadi">Isya'</label><br>
            <select id="inkhifadi" onchange="setJws()">
              <option value="-17.00">-17.0</option>
              <option value="-17.50">-17.5</option>
              <option value="-17.50">-17.8</option>
              <option value="-18.00">-18.0</option>
            </select>
          </div>
        </td>
      </tr>
    </tbody></table>
  </div>
  
  <div class="onoffdf" style="display: block;">
    <hr>
    <h3>Auto Tarhim</h3>
    <div class="onoffswitch">
      <input type="checkbox" name="onoffswitch" class="onoffswitch-checkbox" id="autotarhim" onclick="setautotarhim()">
      <label class="onoffswitch-label" for="autotarhim">
        <span class="onoffswitch-inner"></span>
        <span class="onoffswitch-switch"></span>
      </label>
    </div>
    <br>
    <table width="100%">          
      <tbody><tr>
        <th>Sholat</th>
        <th>Menit Sebelum Adzan</th>
        <th>Track Lain-lain</th>
      </tr>
      <tr>
        <td>Subuh</td>
        <td><input id="tarhimmenits" value="0" maxlength="2" size="2" onchange="setautotarhim()"></td>
        <td><input id="tarhimtracks" value="0" maxlength="3" size="3" onchange="setautotarhim()"></td>
      </tr>
      <tr>
          <td>Dzuhur</td>
          <td><input id="tarhimmenitd" value="0" maxlength="2" size="2" onchange="setautotarhim()"></td>
          <td><input id="tarhimtrackd" value="0" maxlength="3" size="3" onchange="setautotarhim()"></td>
      </tr>
      <tr>
          <td>Ashar</td>
          <td><input id="tarhimmenita" value="0" maxlength="2" size="2" onchange="setautotarhim()"></td>
          <td><input id="tarhimtracka" value="0" maxlength="3" size="3" onchange="setautotarhim()"></td>
      </tr>
      <tr>
          <td>Maghrib</td>
          <td><input id="tarhimmenitm" value="0" maxlength="2" size="2" onchange="setautotarhim()"></td>
          <td><input id="tarhimtrackm" value="0" maxlength="3" size="3" onchange="setautotarhim()"></td>
      </tr>
      <tr>
          <td>Isya</td>
          <td><input id="tarhimmeniti" value="0" maxlength="2" size="2" onchange="setautotarhim()"></td>
          <td><input id="tarhimtracki" value="0" maxlength="3" size="3" onchange="setautotarhim()"></td>
      </tr>
    </tbody></table>
    <br>
    <p>Stop saat Tanbih Imsak</p>
    <div class="onoffswitch">
      <input type="checkbox" name="onoffswitch" class="onoffswitch-checkbox" id="alarmtanbih" onclick="setautotarhim()">
      <label class="onoffswitch-label" for="alarmtanbih">
        <span class="onoffswitch-inner"></span>
        <span class="onoffswitch-switch"></span>
      </label>
    </div>
  </div>
  <br><br>
  <div id="autotarhimjumat" style="display: block;">
    <h3>Auto Tarhim/Murottal Jum'at</h3>
    <table width="100%">          
      <tbody><tr>
        <th>Start Sebelum Adzan</th>
        <th>Stop Sebelum Adzan</th>
        <th>Track Lain-lain</th>
      </tr>
      <tr>
        <td><input id="tarhimmenitjm" value="0" maxlength="3" size="3" onchange="setautotarhim()"></td>
        <td><input id="tarhimmenitjh" value="0" maxlength="2" size="2" onchange="setautotarhim()"></td>
        <td><input id="tarhimtrackj" value="0" maxlength="3" size="3" onchange="setautotarhim()"></td>
      </tr>
    </tbody></table>
  </div>

  <hr>
  <h3>Adzan</h3>
  <div>
    <table width="100%">
      <tbody><tr>
        <td>
          <label for="durasiadzan">Durasi</label><br>
          <input id="durasiadzan" placeholder="2" maxlength="2" size="2" onchange="setJws()">
        </td>
        <td>
          <div class="onoffdf">
            <label for="alarmadzan">Tipe Alarm</label><br>
            <select id="alarmadzan" onchange="setautotarhim()">
              <option value="0">Pilih Tipe Alarm...</option>
              <option value="1">Bedug</option>
              <option value="2">Beep</option>
              <option value="3">Adzan</option>
            </select>
          </div>
        </td>
      </tr>
    </tbody></table>
  </div>

  <h3>Iqomah</h3>
  <div>
    <table width="100%">
      <tbody><tr>
        <td>
          <label for="iqmhs">Subuh</label><br>
          <input id="iqmhs" placeholder="12" maxlength="2" size="2" onchange="setJws()">
        </td>
        <td>
          <label for="iqmhd">Dzuhur</label><br>
          <input id="iqmhd" placeholder="8" maxlength="2" size="2" onchange="setJws()">
        </td>
        <td>
          <label for="iqmha">Ashar</label><br>
          <input id="iqmha" placeholder="6" maxlength="2" size="2" onchange="setJws()">
        </td>
      </tr>
      <tr>
        <td>
          <label for="iqmhm">Maghrib</label><br>
          <input id="iqmhm" placeholder="5" maxlength="2" size="2" onchange="setJws()">
        </td>
        <td>
          <label for="iqmhi">Isya</label><br>
          <input id="iqmhi" placeholder="5" maxlength="2" size="2" onchange="setJws()">
        </td>
        <td>
          <label for="durasijumat">Khutbah Jum'at</label><br>
          <input id="durasijumat" placeholder="50" maxlength="2" size="2" onchange="setJws()">
        </td>
      </tr>      
    </tbody></table>    
  </div>

</div>

<div id="pagewifi">
  <hr>
  <h3>Sambung ke Wifi</h3>
  <div>
    <label for="wifissid">Wifi SSID</label>
    <input id="wifissid" onchange="setWifi()">
  </div>
  <div>
    <label for="wifipassword">Wifi Password</label>
    <input type="password" id="wifipassword" onchange="setWifi()">
  </div>
  <br><br>
  <h3>Wifi JWS</h3>
  <div>
    <label for="ssid">SSID</label>
    <input id="ssid" onchange="setWifi()">
  </div>
  <div>
    <label for="password">Password</label>
    <input type="password" id="password" onchange="setWifi()">
  </div>
  <br>
  <table width="100%">
    <tbody><tr>
      <td>
        <label for="durasicari">Durasi Pencarian</label><br>
        <input id="durasicari" placeholder="7" maxlength="2" size="2" onchange="setWifi()">
      </td>
      <td>
        <br>
        <h4>Tampil IP</h4>
        <div class="onoffswitch">
          <input type="checkbox" name="onoffswitch" class="onoffswitch-checkbox" id="tampilnet" onclick="setWifi()">
          <label class="onoffswitch-label" for="tampilnet">
            <span class="onoffswitch-inner"></span>
            <span class="onoffswitch-switch"></span>
          </label>
        </div>
      </td>
    </tr>
  </tbody></table>
  <div>
    <br>
    <button onclick="resetNodeMCU()"> Terapkan dan Restart </button>
  </div>
  <br><br>
</div>


<div id="pageled">
  <hr>
  <h3>Kecerahan</h3>
  <div>
    <input type="range" min="1" max="254" id="kecerahan" oninput="sendKecerahan()">
  </div>
  <table>
    <tr>
      <td>
        <h3>Jumlah Panel</h3>
        <div>
          <select id="panel" onchange="sendKecerahan()">
            <option value="1">1 Panel</option>
            <option value="2">2 Panel</option>
            <option value="3">3 Panel</option>
            <option value="4">4 Panel</option>
          </select>
        </div>
      </td>
      <td>
        <h3>Jenis Huruf</h3>
        <div>
          <select id="font" onchange="sendKecerahan()">
            <option value="0">Tebal</option>
            <option value="1">Normal</option>
          </select>
        </div>
      </td>
    </tr>
  </table>
  <br>
  <hr>
  <div>
    <button class="tombol" id="modetesled" onclick="sendTesLED()">Tes LED</button>
    <button class="tombol" id="modejam" onclick="sendModeJam()">JWS</button>
    <button class="tombol" id="modemp3" onclick="sendModeMP3()">Murottal</button>
  </div>
</div>

<div id="pagesistem">
  <hr>
  <h3>DFPlayer Mini</h3>
  <div class="onoffswitch">
    <input type="checkbox" name="onoffswitch" class="onoffswitch-checkbox" id="dfonoff" onclick="sendEqualizer()">
    <label class="onoffswitch-label" for="dfonoff">
      <span class="onoffswitch-inner"></span>
      <span class="onoffswitch-switch"></span>
    </label>
  </div>
  <div>
    <br>
    <button onclick="resetNodeMCU()"> Terapkan dan Restart </button>
  </div>
</div>

<div class="footer">
  <hr>
  <p>JWS Murottal Quad V3.2.12 - 2023</p>
  <p><a href="http://www.elektronmart.com/" target="_blank">ElektronMart.Com</a> | <a href="https://www.grobak.net/" target="_blank">Grobak.Net</a></p>
</div>

</center>
</body>

<script>
const hidedf = document.querySelector('.onoffdf');
var xmlHttp=createXmlHttpObject();

function createXmlHttpObject(){
 if(window.XMLHttpRequest){
    xmlHttp=new XMLHttpRequest();
 }else{
    xmlHttp=new ActiveXObject('Microsoft.XMLHTTP');// code for IE6, IE5
 }
 return xmlHttp;
}

function mulai(){
  InitWebSocket();
  updateData();
}

  var Socket;
  function InitWebSocket() {
    Socket = new WebSocket('ws://' + window.location.hostname + ':81/');
    Socket.onmessage = function(event) {
      let data = JSON.parse(event.data);
      document.getElementById('waktu').innerHTML=data.waktu;
      console.log(data.waktu);
//    document.getElementById('teksArea').value = data.response + data.status;
    }

    Socket.onclose = function(event) {
    console.log('Connection closed');
      setTimeout(initWebSocket, 2000);
    }
  }
  function syncJam(){
    var w = new Date();
    var j = w.getHours();
    var m = w.getMinutes();
    var d = w.getSeconds();
    var h = w.getDate();
    var b = w.getMonth() + 1;
    var t = w.getFullYear();
  
    j = (j < 10) ? "0" + j : j;
    m = (m < 10) ? "0" + m : m;
    d = (d < 10) ? "0" + d : d;
  
    h = (h < 10) ? "0" + h : h;
    b = (b < 10) ? "0" + b : b;
    t = (t < 10) ? "0" + t : t;
    
    var waktu = j + ":" + m + ":" + d + " " + h + "-" + b + "-" + t;
//    var json = JSON.stringify({'hari':h,'bulan':b,'tahun':t,'jam':j,'menit':m,'detik':d});
    
    console.log("t"+waktu);
    Socket.send("t"+waktu);
  }
  function sendTanggal(){
    var j,m,d,h,b,t;
    j = document.getElementById('hour').innerHTML;
    m = document.getElementById('minute').innerHTML;
    d = document.getElementById('second').innerHTML;
    var strTgl = document.getElementById("tanggal").value;
    var dateArray = strTgl.split("-");
    // Konversi ke variabel tanggal, bulan, dan tahun
    t = dateArray[0]; // parseInt digunakan untuk menghindari tipe data string
    b = dateArray[1];
    h = dateArray[2];
    
    var waktu = j + ":" + m + ":" + d + " " + h + "-" + b + "-" + t;
    console.log("tt"+waktu);
    Socket.send("tt"+waktu);
  }
  function sendJam(){
    var j,m,d,h,b,t;
    h = document.getElementById('day').innerHTML;
    b = document.getElementById('month').innerHTML;
    t = document.getElementById('year').innerHTML;
    var strJam = document.getElementById("jam").value;
    var dateArray = strJam.split(":");
    // Konversi ke variabel tanggal, bulan, dan tahun
    j = dateArray[0]; // parseInt digunakan untuk menghindari tipe data string
    m = dateArray[1];
    d = "0";
    
    var waktu = j + ":" + m + ":" + d + " " + h + "-" + b + "-" + t;
    console.log("tj"+waktu);
    Socket.send("tj"+waktu);
  }
  function sendText(){
    Socket.send(document.getElementById("teksInput").value);
    document.getElementById("teksInput").value = "";
  }
  function updateData() {
    prosesdatajws();
    proseswaktu();
  }

  function prosesdatajws(){
    if(xmlHttp.readyState==0 || xmlHttp.readyState==4){
       xmlHttp.open('PUT','xml',true);
       xmlHttp.onreadystatechange=handleServerResponse;
       xmlHttp.send(null);
     }
  }
  function proseswaktu(){
   if(xmlHttp.readyState==0 || xmlHttp.readyState==4){
     xmlHttp.open('PUT','xmlwaktu',true);
     xmlHttp.onreadystatechange=handleServerResponseWaktu;
     xmlHttp.send(null);
   }
   setTimeout('proseswaktu()',1000);
  }

  function sendKecerahan(){
    var kecerahan = document.getElementById("kecerahan").value;
    var panel = document.getElementById("panel").value;
    var datadisp = {kecerahan:kecerahan, panel:panel};
    
    Socket.send("c" + JSON.stringify(datadisp));
  }

  function sendPlay() {
  Socket.send("dplay"); }

  function sendPause() {
    Socket.send("dpause"); }

  function sendStop() {
    Socket.send("dstop"); }  

  function sendPrev() {
    Socket.send("dprev"); }

  function sendNext() {
    Socket.send("dnext"); }

  function sendRandom() {
    Socket.send("drandom"); }


  function sendModeMP3() {
    Socket.send("dmodedfmp3");
  }

  function sendModeJam() {
    Socket.send("dmodejam");
  }

  function sendTesLED() {  
    Socket.send("dtesled");  
  }

  function sendPlaylist(){
    var option = document.getElementById("playlist").value;
    Socket.send(option);
  }

  function getDataDF() {
    var equalizer = document.getElementById("equalizer").value;
    var volume = document.getElementById("volume").value;
    var slmp3 = document.getElementById("slmp3").value;
    var trmp3 = document.getElementById("trmp3").value;
    var onoffdf = document.getElementById('onoffdf')
    if (document.getElementById('dfonoff').checked == true) {
      onoffdf.style.display = "block";
      hidedf.style.display = "block";
      autotarhimjumat.style.display = "block";
      var tdf = document.getElementsByClassName("tdf");
      tdf[0].style.display = "inline";
      tdf[1].style.display = "inline";
      var dfonoff = 1;
    } else {
      onoffdf.style.display = "none";
      hidedf.style.display = "none";
      autotarhimjumat.style.display = "none";
      var tdf = document.getElementsByClassName("tdf");
      tdf[0].style.display = "none";
      tdf[1].style.display = "none";
      var dfonoff = 0;
    }
    function pad(num, size) {
      var s = num+"";
      while (s.length < size) s = "0" + s;
      return s;
    }
    var folder = pad(slmp3,3);
    var track = pad(trmp3,3);
    if (document.getElementById('trackloop').checked == true){
      var trackloop = 1;    
    } else {
      var trackloop = 0;
    }
    if (document.getElementById('autotarhim').checked == true){
      var autotarhim = 1;
    } else {
      var autotarhim = 0;
    }
    if (document.getElementById('alarmtanbih').checked == true){
      var alarmtanbih = 1;
    } else {
      var alarmtanbih = 0;
    }
    var tarhimmenits = document.getElementById("tarhimmenits").value;
    var tarhimtracks = document.getElementById("tarhimtracks").value;
    var tarhimmenitd = document.getElementById("tarhimmenitd").value;
    var tarhimtrackd = document.getElementById("tarhimtrackd").value;
    var tarhimmenita = document.getElementById("tarhimmenita").value;
    var tarhimtracka = document.getElementById("tarhimtracka").value;
    var tarhimmenitm = document.getElementById("tarhimmenitm").value;
    var tarhimtrackm = document.getElementById("tarhimtrackm").value;
    var tarhimmeniti = document.getElementById("tarhimmeniti").value;
    var tarhimmenitjm = document.getElementById("tarhimmenitjm").value;
    var tarhimmenitjh = document.getElementById("tarhimmenitjh").value;
    var tarhimtrackj = document.getElementById("tarhimtrackj").value;
    var tarhimtracki = document.getElementById("tarhimtracki").value;
    var alarmadzan = document.getElementById("alarmadzan").value;
    
    var datadf = {volume:volume,folder:folder,track:track,trackloop:trackloop, 
                  equalizer:equalizer, dfonoff:dfonoff, autotarhim:autotarhim,
                  tarhimmenits:tarhimmenits, tarhimtracks:tarhimtracks,
                  tarhimmenitd:tarhimmenitd, tarhimtrackd:tarhimtrackd,
                  tarhimmenita:tarhimmenita, tarhimtracka:tarhimtracka,
                  tarhimmenitm:tarhimmenitm, tarhimtrackm:tarhimtrackm,
                  tarhimmeniti:tarhimmeniti, tarhimtracki:tarhimtracki,
                  tarhimmenitjm:tarhimmenitjm, tarhimmenitjh:tarhimmenitjh, tarhimtrackj:tarhimtrackj,
                  alarmadzan:alarmadzan, alarmtanbih:alarmtanbih};
    return datadf;
  }
  
  function sendVolume() {
    Socket.send("#" + JSON.stringify(getDataDF()));
  }

  function sendEqualizer(){
    var equalizer = document.getElementById("equalizer").value;
    Socket.send("dfset" + JSON.stringify(getDataDF()));
  }

  function setautotarhim() {
    var autotarhim;
    if (document.getElementById('autotarhim').checked == true) 
      autotarhim = 1;
    else autotarhim = 0;
    
    var tarhimmenits = document.getElementById("tarhimmenits").value;
    var tarhimtracks = document.getElementById("tarhimtracks").value;
    var tarhimmenitd = document.getElementById("tarhimmenitd").value;
    var tarhimtrackd = document.getElementById("tarhimtrackd").value;
    var tarhimmenita = document.getElementById("tarhimmenita").value;
    var tarhimtracka = document.getElementById("tarhimtracka").value;
    var tarhimmenitm = document.getElementById("tarhimmenitm").value;
    var tarhimtrackm = document.getElementById("tarhimtrackm").value;
    var tarhimmeniti = document.getElementById("tarhimmeniti").value;
    var tarhimtracki = document.getElementById("tarhimtracki").value;
    var tarhimmenitjm = document.getElementById("tarhimmenitjm").value;
    var tarhimmenitjh = document.getElementById("tarhimmenitjh").value;
    var tarhimtrackj = document.getElementById("tarhimtrackj").value;
    var alarmadzan = document.getElementById("alarmadzan").value;

    Socket.send("h" + JSON.stringify(getDataDF()));
  }

  var foldermp3 = document.getElementById("foldermp3");
  var trackmp3 = document.getElementById("trackmp3");
  var tracklainmp3 = document.getElementById("tracklainmp3");

  //Create array of options to be added
  var foldername = ["Saad Alghamdi","Mishary Rasyid","As Sudais","Al Budair","Al Muaiqly","Al Hudhaifi"];
  var foldernum = ["2","4","6","8","10","12"];
  var surahname = ["Pilih Surah","1. Al-Fatihah","2. Al-Baqarah","3. Ali 'Imran","4. An-Nisa'","5. Al-Ma'idah","6. Al-An'am",
  "7. Al-A'raf","8. Al-Anfal","9. At-Taubah","10. Yunus","11. Hud","12. Yusuf","13. Ar-Ra'd",
  "14. Ibrahim","15. Al-Hijr","16. An-Nahl","17. Al-Isra'","18. Al-Kahf","19. Maryam","20. Ta Ha",
  "21. Al-Anbiya","22. Al-Hajj","23. Al-Mu'minun","24. An-Nur","25. Al-Furqan","26. Asy-Syu'ara'",
  "27. An-Naml","28. Al-Qasas","29. Al-'Ankabut","30. Ar-Rum","31. Luqman","32. As-Sajdah","33. Al-Ahzab",
  "34. Saba'","35. Fatir","36. Ya Sin","37. As-Saffat","38. Sad","39. Az-Zumar","40. Ghafir","41. Fussilat",
  "42. Asy-Syura","43. Az-Zukhruf","44. Ad-Dukhan","45. Al-Jasiyah","46. Al-Ahqaf","47. Muhammad","48. Al-Fath",
  "49. Al-Hujurat","50. Qaf","51. Az-Zariyat","52. At-Tur","53. An-Najm","54. Al-Qamar","55. Ar-Rahman",
  "56. Al-Waqi'ah","57. Al-Hadid","58. Al-Mujadilah","59. Al-Hasyr","60. Al-Mumtahanah","61. As-Saff",
  "62. Al-Jumu'ah","63. Al-Munafiqun","64. At-Taghabun","65. At-Talaq","66. At-Tahrim","67. Al-Mulk",
  "68. Al-Qalam","69. Al-Haqqah","70. Al-Ma'arij","71. Nuh","72. Al-Jinn","73. Al-Muzzammil","74. Al-Muddassir",
  "75. Al-Qiyamah","76. Al-Insan","77. Al-Mursalat","78. An-Naba'","79. An-Nazi'at","80. 'Abasa","81. At-Takwir",
  "82. Al-Infitar","83. Al-Mutaffifiin","84. Al-Insyiqaq","85. Al-Buruj","86. At-Tariq","87. Al-A'la","88. Al-Gasyiyah",
  "89. Al-Fajr","90. Al-Balad","91. Asy-Syams","92. Al-Lail","93. Ad-Duha","94. Al-Insyirah","95. At-Tin",
  "96. Al-'Alaq","97. Al-Qadr","98. Al-Bayyinah","99. Az-Zalzalah","100. Al-'Adiyat","101. Al-Qari'ah","102. At-Takasur",
  "103. Al-'Asr","104. Al-Humazah","105. Al-Fil","106. Quraisy","107. Al-Ma'un","108. Al-Kausar","109. Al-Kafirun",
  "110. An-Nasr","111. Al-Lahab","112. Al-Ikhlas","113. Al-Falaq","114. An-Nas",
  ];

  var jmlhayat = [7,286,200,176,120,165,206,75,129,109,123,111,43,52,99,128,111,110,98,135,112,78,118,64,77,227,93,
  88,69,60,34,30,73,54,45,83,182,88,75,85,54,53,89,59,37,35,38,29,18,45,60,49,62,55,78,96,29,22,24,13,14,11,11,18,12,
  12,30,52,52,44,28,28,20,56,40,31,50,40,46,42,29,19,36,25,22,17,19,26,30,20,15,21,11,8,8,19,5,8,8,11,11,8,3,9,5,4,7,
  3,6,3,5,4,5,6];

  //Create and append select list
  var slmp3 = document.createElement("select");
  slmp3.setAttribute("id", "slmp3");
  slmp3.setAttribute("onchange", "sendPlayFolderTrack()");
  foldermp3.appendChild(slmp3);

  var trmp3 = document.createElement("select");
  trmp3.setAttribute("id", "trmp3");
  trmp3.setAttribute("onchange", "sendPlayFolderTrack()");
  trackmp3.appendChild(trmp3);

  var trlmp3 = document.createElement("select");
  trlmp3.setAttribute("id", "trlmp3");
  trlmp3.setAttribute("onchange", "sendPlayFolderTrackL()");
  tracklainmp3.appendChild(trlmp3);

  //Create and append the options
  for (var i = 0; i < foldername.length; i++) {
      var option = document.createElement("option");
      option.text = foldername[i];
      option.setAttribute("value", foldernum[i]);
      slmp3.appendChild(option);
  }

  for (var i = 0; i < 115; i++) {
      var option = document.createElement("option");
      option.setAttribute("value", i);
      option.text = surahname[i];
      trmp3.appendChild(option);
  }

  for (var i = 0; i < 256; i++) {
      var option = document.createElement("option");
      option.setAttribute("value", i);
      option.text = i;
      trlmp3.appendChild(option);
  }

  var psrh = document.createElement("select");
  psrh.setAttribute("id", "psrh");
  psurah.appendChild(psrh);

  for (var i = 0; i < 115; i++) {
      var option = document.createElement("option");
      option.setAttribute("value", i);
      option.text = surahname[i];
      psrh.appendChild(option);
  }


  function PlayAyat() {
    function pad(num, size) {
      var s = num+"";
      while (s.length < size) s = "0" + s;
      return s;
    }
    
    var psrhs = document.getElementById("psrh").value;
    var payt = document.getElementById("payat").value;

    if (psrhs == 0 || payt == 0) {
      psrhs = 0;
      payt = 0;
      alert("Pilih Surah dan Ayat");
    }else{
      if(payt>jmlhayat[psrhs-1]) {      
        alert(surahname[psrhs] + " " + jmlhayat[psrhs-1] + " Ayat");
        document.getElementById("payat").value = jmlhayat[psrhs-1];
        payt = jmlhayat[psrhs-1];
      }
      Socket.send("a" + pad(psrhs,3) + pad(payt,3));
    }
  }



  function sendPlayFolderTrack() {
    function pad(num, size) {
      var s = num+"";
      while (s.length < size) s = "0" + s;
      return s;
    }
    
    var slmp3 = document.getElementById("slmp3").value;
    var trmp3 = document.getElementById("trmp3").value;
    var folder = pad(slmp3,3);
    var track = pad(trmp3,3);
    
    Socket.send("f" + pad(slmp3,3) + pad(trmp3,3) + JSON.stringify(getDataDF()));
    
  }

  function sendPlayFolderTrackL() {

    function pad(num, size) {
      var s = num+"";
      while (s.length < size) s = "0" + s;
      return s;
    }
    
    var sllmp3 = 14;
    var trlmp3 = document.getElementById("trlmp3").value;
    var folderl = pad(sllmp3,3);
    var trackl = pad(trlmp3,3);
    Socket.send("g" + pad(sllmp3,3) + pad(trlmp3,3));
  }

  function onoffloop() {
    // if (document.getElementById('trackloop').checked == true){
    //   var trackloop = 1;
    //   Socket.send("l1" + JSON.stringify(getDataDF()));
    // } else {
    //   var trackloop = 0;
    //   Socket.send("l0" + JSON.stringify(getDataDF()));
    // } 
    Socket.send("dfset" + JSON.stringify(getDataDF()));
  }

  function sendNama(){
    var nama = document.getElementById("nama").value;
    var info1 = document.getElementById("info1").value;
    var info2 = document.getElementById("info2").value;
    var laporan = document.getElementById("laporan").value;
    var kecepatan = 100 - document.getElementById("kecepatan").value;
    var datainfo = {nama:nama, info1:info1, info2:info2, laporan:laporan, kecepatan:kecepatan};
    Socket.send("i" + JSON.stringify(datainfo));
  }

  function resetNodeMCU() {
    Socket.send("z");
  }
  
  function setWifi(){

    var wifissid = document.getElementById("wifissid").value;
    var wifipassword = document.getElementById("wifipassword").value;
    var ssid = document.getElementById("ssid").value;
    var password = document.getElementById("password").value;
    var durasicari = document.getElementById("durasicari").value;
    if (document.getElementById('tampilnet').checked == true) var tampilnet = 1;
    else var tampilnet = 0;
    
    var datawifi = {wifissid:wifissid, wifipassword:wifipassword, ssid:ssid, password:password, durasicari:durasicari, tampilnet:tampilnet};
    console.log("w" + JSON.stringify(datawifi));
    Socket.send("w" + JSON.stringify(datawifi));
  }
  
  function setJws(){
    var inkhifads = document.getElementById("inkhifads").value;
    var inkhifadi = document.getElementById("inkhifadi").value;
    var ihtis = document.getElementById("ihtis").value;
    var ihtid = document.getElementById("ihtid").value;
    var ihtia = document.getElementById("ihtia").value;
    var ihtim = document.getElementById("ihtim").value;
    var ihtii = document.getElementById("ihtii").value;
    var iqmhs = document.getElementById("iqmhs").value;
    var iqmhd = document.getElementById("iqmhd").value;
    var iqmha = document.getElementById("iqmha").value;
    var iqmhm = document.getElementById("iqmhm").value;
    var iqmhi = document.getElementById("iqmhi").value;
    var durasiadzan = document.getElementById("durasiadzan").value;
    var durasisholat = document.getElementById("durasisholat").value;
    var durasijumat = document.getElementById("durasijumat").value;
    latitude = document.getElementById("latitude").value;
    longitude = document.getElementById("longitude").value;
    var altitude= document.getElementById("altitude").value;
    var zonawaktu = document.getElementById("zonawaktu").value;
    
    var datajws = {inkhifads:inkhifads, inkhifadi:inkhifadi, iqmhs:iqmhs, iqmhd:iqmhd, iqmha:iqmha, iqmhm:iqmhm, iqmhi:iqmhi, ihtis:ihtis, ihtid:ihtid, ihtia:ihtia, ihtim:ihtim, ihtii:ihtii, durasiadzan:durasiadzan, 
                durasisholat:durasisholat, durasijumat:durasijumat, latitude:latitude, longitude:longitude, altitude:altitude, zonawaktu:zonawaktu};
    console.log(JSON.stringify(datajws));
    Socket.send("s" + JSON.stringify(datajws));
  }
  function nwilayah(){
    var nilai = document.getElementById('wilayah').value;
    var koordinat = nilai.split(',');
    var latitude = koordinat[0];
    var longitude = koordinat[1];
    document.getElementById('latitude').value=latitude;
    document.getElementById('longitude').value=longitude;
    setJws();
  }

  function sendRelay(){
    var relay = document.getElementById("relay").value;
    if (document.getElementById('relay').checked == true)
      var relay = "r1";
    else 
      var relay = "r0";
    Socket.send(relay);
  }

  function handleServerResponseWaktu(){
   if(xmlHttp.readyState==4 && xmlHttp.status==200){
     xmlResponse=xmlHttp.responseXML;

     xmldoc = xmlResponse.getElementsByTagName('tglhijr');
     document.getElementById('tglhijr').innerHTML=xmldoc[0].firstChild.nodeValue;
     xmldoc = xmlResponse.getElementsByTagName('Tahun');
     message = xmldoc[0].firstChild.nodeValue;
     document.getElementById('year').innerHTML=message;
  
     xmldoc = xmlResponse.getElementsByTagName('Bulan');
     message = xmldoc[0].firstChild.nodeValue;
     document.getElementById('month').innerHTML=message;
  
     xmldoc = xmlResponse.getElementsByTagName('Tanggal');
     message = xmldoc[0].firstChild.nodeValue;
     document.getElementById('day').innerHTML=message;
  
     xmldoc = xmlResponse.getElementsByTagName('Jam');
     message = xmldoc[0].firstChild.nodeValue;
     document.getElementById('hour').innerHTML=message;
  
     xmldoc = xmlResponse.getElementsByTagName('Menit');
     message = xmldoc[0].firstChild.nodeValue;
     document.getElementById('minute').innerHTML=message;
  
     xmldoc = xmlResponse.getElementsByTagName('Detik');
     message = xmldoc[0].firstChild.nodeValue;
     document.getElementById('second').innerHTML=message;
  
     xmldoc = xmlResponse.getElementsByTagName('Suhu');
     message = xmldoc[0].firstChild.nodeValue;
     document.getElementById('suhu').innerHTML=message;
   }
  }
  
   function handleServerResponse(){
     if(xmlHttp.readyState==4 && xmlHttp.status==200){
       xmlResponse=xmlHttp.responseXML;

       xmldoc = xmlResponse.getElementsByTagName('rIqmhs');
       message = xmldoc[0].firstChild.nodeValue;
       document.getElementById('iqmhs').value=message;
    
       xmldoc = xmlResponse.getElementsByTagName('rIqmhd');
       message = xmldoc[0].firstChild.nodeValue;
       document.getElementById('iqmhd').value=message;
    
       xmldoc = xmlResponse.getElementsByTagName('rIqmha');
       message = xmldoc[0].firstChild.nodeValue;
       document.getElementById('iqmha').value=message;
    
       xmldoc = xmlResponse.getElementsByTagName('rIqmhm');
       message = xmldoc[0].firstChild.nodeValue;
       document.getElementById('iqmhm').value=message;
    
       xmldoc = xmlResponse.getElementsByTagName('rIqmhi');
       message = xmldoc[0].firstChild.nodeValue;
       document.getElementById('iqmhi').value=message;

       xmldoc = xmlResponse.getElementsByTagName('rInkhifads');
       document.getElementById('inkhifads').value=xmldoc[0].firstChild.nodeValue;

       xmldoc = xmlResponse.getElementsByTagName('rInkhifadi');
       document.getElementById('inkhifadi').value=xmldoc[0].firstChild.nodeValue;

       xmldoc = xmlResponse.getElementsByTagName('rIhtis');
       document.getElementById('ihtis').value=xmldoc[0].firstChild.nodeValue;
    
       xmldoc = xmlResponse.getElementsByTagName('rIhtid');
       document.getElementById('ihtid').value=xmldoc[0].firstChild.nodeValue;
    
       xmldoc = xmlResponse.getElementsByTagName('rIhtia');
       document.getElementById('ihtia').value=xmldoc[0].firstChild.nodeValue;
    
       xmldoc = xmlResponse.getElementsByTagName('rIhtim');
       document.getElementById('ihtim').value=xmldoc[0].firstChild.nodeValue;
    
       xmldoc = xmlResponse.getElementsByTagName('rIhtii');
       document.getElementById('ihtii').value=xmldoc[0].firstChild.nodeValue;

       xmldoc = xmlResponse.getElementsByTagName('DurasiAdzan');
       document.getElementById('durasiadzan').value=xmldoc[0].firstChild.nodeValue;

       xmldoc = xmlResponse.getElementsByTagName('DurasiJumat');
       document.getElementById('durasijumat').value=xmldoc[0].firstChild.nodeValue;

      xmldoc = xmlResponse.getElementsByTagName('DurasiSholat');
      document.getElementById('durasisholat').value=xmldoc[0].firstChild.nodeValue;
    
       xmldoc = xmlResponse.getElementsByTagName('rLatitude');
       message = xmldoc[0].firstChild.nodeValue;
       document.getElementById('latitude').value=message;
    
       xmldoc = xmlResponse.getElementsByTagName('rLongitude');
       message = xmldoc[0].firstChild.nodeValue;
       document.getElementById('longitude').value=message;
    
       xmldoc = xmlResponse.getElementsByTagName('rAltitude');
       message = xmldoc[0].firstChild.nodeValue;
       document.getElementById('altitude').value=message;
    
       xmldoc = xmlResponse.getElementsByTagName('rZonaWaktu');
       message = xmldoc[0].firstChild.nodeValue;
       document.getElementById('zonawaktu').value=message;

       xmldoc = xmlResponse.getElementsByTagName('jdhuhr');
       document.getElementById('jdhuhr').innerHTML=xmldoc[0].firstChild.nodeValue;

       xmldoc = xmlResponse.getElementsByTagName('jashr');
       document.getElementById('jashr').innerHTML=xmldoc[0].firstChild.nodeValue;

       xmldoc = xmlResponse.getElementsByTagName('jmaghrib');
       document.getElementById('jmaghrib').innerHTML=xmldoc[0].firstChild.nodeValue;

       xmldoc = xmlResponse.getElementsByTagName('jisya');
       document.getElementById('jisya').innerHTML=xmldoc[0].firstChild.nodeValue;

       xmldoc = xmlResponse.getElementsByTagName('jimsak');
       document.getElementById('jimsak').innerHTML=xmldoc[0].firstChild.nodeValue;

       xmldoc = xmlResponse.getElementsByTagName('jshubuh');
       document.getElementById('jshubuh').innerHTML=xmldoc[0].firstChild.nodeValue;

       xmldoc = xmlResponse.getElementsByTagName('jthulu');
       document.getElementById('jthulu').innerHTML=xmldoc[0].firstChild.nodeValue;

       xmldoc = xmlResponse.getElementsByTagName('jdluha');
       document.getElementById('jdluha').innerHTML=xmldoc[0].firstChild.nodeValue;

       xmldoc = xmlResponse.getElementsByTagName('nama');
       document.getElementById('nama').value=xmldoc[0].firstChild.nodeValue;

       xmldoc = xmlResponse.getElementsByTagName('info1');
       document.getElementById('info1').value=xmldoc[0].firstChild.nodeValue;

       xmldoc = xmlResponse.getElementsByTagName('info2');
       document.getElementById('info2').value=xmldoc[0].firstChild.nodeValue;

       xmldoc = xmlResponse.getElementsByTagName('laporan');
       document.getElementById('laporan').value=xmldoc[0].firstChild.nodeValue;

      xmldoc = xmlResponse.getElementsByTagName('wifissid');
      document.getElementById('wifissid').value=xmldoc[0].firstChild.nodeValue;
      
      xmldoc = xmlResponse.getElementsByTagName('wifipassword');
      document.getElementById('wifipassword').value=xmldoc[0].firstChild.nodeValue;
      
      xmldoc = xmlResponse.getElementsByTagName('ssid');
      document.getElementById('ssid').value=xmldoc[0].firstChild.nodeValue;
      
      xmldoc = xmlResponse.getElementsByTagName('password');
      document.getElementById('password').value=xmldoc[0].firstChild.nodeValue;
  
      xmldoc = xmlResponse.getElementsByTagName('DurasiCari');
      message = xmldoc[0].firstChild.nodeValue;
      document.getElementById('durasicari').value=message;
    
      xmldoc = xmlResponse.getElementsByTagName('TampilNet');
      message = xmldoc[0].firstChild.nodeValue;
      if (message == 1) document.getElementById('tampilnet').checked = true;
      else document.getElementById('tampilnet').checked = false;

      xmldoc = xmlResponse.getElementsByTagName('kecerahan');
      message = xmldoc[0].firstChild.nodeValue;
      document.getElementById('kecerahan').value= message;

      xmldoc = xmlResponse.getElementsByTagName('Kecepatan');
      message = 100 - xmldoc[0].firstChild.nodeValue;
      document.getElementById('kecepatan').value=message;

      xmldoc = xmlResponse.getElementsByTagName('panel');
      message = xmldoc[0].firstChild.nodeValue;
      document.getElementById('panel').value= message;

      //get xml mp3 dfplayer
      xmldoc = xmlResponse.getElementsByTagName('Volume');
      message = xmldoc[0].firstChild.nodeValue;
      document.getElementById('volume').value=message;

      xmldoc = xmlResponse.getElementsByTagName('Folder');
      message = xmldoc[0].firstChild.nodeValue;
      document.getElementById('slmp3').value=message;

      xmldoc = xmlResponse.getElementsByTagName('Track');
      message = xmldoc[0].firstChild.nodeValue;
      document.getElementById('trmp3').value=message;
      
      xmldoc = xmlResponse.getElementsByTagName('TrackLoop');
      message = xmldoc[0].firstChild.nodeValue;
      if (message == 1)
        document.getElementById('trackloop').checked = true;
      else
        document.getElementById('trackloop').checked = false;
      
      xmldoc = xmlResponse.getElementsByTagName('Dfonoff');
      message = xmldoc[0].firstChild.nodeValue;
      var onoffdf = document.getElementById('onoffdf')
      if (message == 1) {
        document.getElementById('dfonoff').checked = true;
        onoffdf.style.display = "block";
        hidedf.style.display = "block";
        autotarhimjumat.style.display = "block";
        var tdf = document.getElementsByClassName("tdf");
        tdf[0].style.display = "inline";
        tdf[1].style.display = "inline";
      } else {
        document.getElementById('dfonoff').checked = false;
        onoffdf.style.display = "none";
        hidedf.style.display = "none";
        autotarhimjumat.style.display = "none";
        var tdf = document.getElementsByClassName("tdf");
        tdf[0].style.display = "none";
        tdf[1].style.display = "none";
      }

      xmldoc = xmlResponse.getElementsByTagName('Equalizer');
      message = xmldoc[0].firstChild.nodeValue;
      document.getElementById('equalizer').value=message;

      xmldoc = xmlResponse.getElementsByTagName('AutoTarhim');
      message = xmldoc[0].firstChild.nodeValue;
      document.getElementById('autotarhim').checked = message == 1;

      xmldoc = xmlResponse.getElementsByTagName('AlarmTanbih');
      message = xmldoc[0].firstChild.nodeValue;
      document.getElementById('alarmtanbih').checked = message == 1?true:false;

      xmldoc = xmlResponse.getElementsByTagName('AlarmAdzan');
      message = xmldoc[0].firstChild.nodeValue;
      document.getElementById('alarmadzan').value=message;
      
      xmldoc = xmlResponse.getElementsByTagName('TarhimMenitS');
      document.getElementById('tarhimmenits').value=xmldoc[0].firstChild.nodeValue;
      xmldoc = xmlResponse.getElementsByTagName('TarhimTrackS');
      document.getElementById('tarhimtracks').value=xmldoc[0].firstChild.nodeValue;

      xmldoc = xmlResponse.getElementsByTagName('TarhimMenitD');
      document.getElementById('tarhimmenitd').value=xmldoc[0].firstChild.nodeValue;
      xmldoc = xmlResponse.getElementsByTagName('TarhimTrackD');
      document.getElementById('tarhimtrackd').value=xmldoc[0].firstChild.nodeValue;

      xmldoc = xmlResponse.getElementsByTagName('TarhimMenitA');
      document.getElementById('tarhimmenita').value=xmldoc[0].firstChild.nodeValue;
      xmldoc = xmlResponse.getElementsByTagName('TarhimTrackA');
      document.getElementById('tarhimtracka').value=xmldoc[0].firstChild.nodeValue;

      xmldoc = xmlResponse.getElementsByTagName('TarhimMenitM');
      document.getElementById('tarhimmenitm').value=xmldoc[0].firstChild.nodeValue;
      xmldoc = xmlResponse.getElementsByTagName('TarhimTrackM');
      document.getElementById('tarhimtrackm').value=xmldoc[0].firstChild.nodeValue;

      xmldoc = xmlResponse.getElementsByTagName('TarhimMenitI');
      document.getElementById('tarhimmeniti').value=xmldoc[0].firstChild.nodeValue;
      xmldoc = xmlResponse.getElementsByTagName('TarhimTrackI');
      document.getElementById('tarhimtracki').value=xmldoc[0].firstChild.nodeValue;

      xmldoc = xmlResponse.getElementsByTagName('TarhimMenitJM');
      message = xmldoc[0].firstChild.nodeValue;
      document.getElementById('tarhimmenitjm').value=message;

      xmldoc = xmlResponse.getElementsByTagName('TarhimMenitJH');
      message = xmldoc[0].firstChild.nodeValue;
      document.getElementById('tarhimmenitjh').value=message;
      
      xmldoc = xmlResponse.getElementsByTagName('TarhimTrackJ');
      message = xmldoc[0].firstChild.nodeValue;
      document.getElementById('tarhimtrackj').value=message;   
    }
  }
</script>

</html>

)=====";
