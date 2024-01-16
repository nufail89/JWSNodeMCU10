#define DISPLAYS_WIDE 3 
#define DISPLAYS_HIGH 1
DMDESP      Disp(DISPLAYS_WIDE, DISPLAYS_HIGH);  // Jumlah Panel P10 yang digunakan (KOLOM,BARIS)
int         DWidth  = Disp.width();
int         DHeight = Disp.height();

void ICACHE_RAM_ATTR refresh() { 
  
  Disp.refresh();
  timer0_write(ESP.getCycleCount() + 80000);  

}

void Disp_init() {
  Disp.start();
  Disp.setDoubleBuffer(true);
  noInterrupts();
  timer0_isr_init();
  timer0_attachInterrupt(refresh);
  timer0_write(ESP.getCycleCount() + 80000);
  interrupts();
  Disp.clear();
  Disp.swapBuffers();
}