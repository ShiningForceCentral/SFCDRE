
#include <idc.idc>

//-------------------------------------------------------------------------
static CW(off,name,cmt) {
  auto x;
  x = off;
  MakeWord(x);
  MakeName(x,name);
  MakeRptCmt(x,cmt);
}

//-------------------------------------------------------------------------
static CD(off,name,cmt) {
  auto x;
  x = off;
  MakeDword(x);
  MakeName(x,name);
  MakeRptCmt(x,cmt);
}

//-------------------------------------------------------------------------
static CB(off,name,cmt) {
  auto x;
  x = off;
  MakeByte(x);
  MakeName(x,name);
  MakeRptCmt(x,cmt);
}

static CS(off,end,name,cmt) {
  auto x;
  x = off;
  MakeStr(x, end);
  MakeName(x,name);
  MakeRptCmt(x,cmt);
}
 
static mdAddress( ){

 CB(0xFF8000,"REG_RESET1",	"LED Control");
 CB(0xFF8001,"REG_RESET2",	"Periphery reset and chip version"); 
 CB(0xFF8002,"REG_MEMMODE1",	"WP7-0");
 CB(0xFF8003,"REG_MEMMODE2",	"PM1-0, MODE, DMNA, RET"); 
 CB(0xFF8004,"REG_CDC1",	"EDT, DSR, UBR, DD2-0");   
 CB(0xFF8005,"REG_CDC2",	"CA3-0");  
 CB(0xFF8006,"REG_CDC_REGDATA1",	"");
 CB(0xFF8007,"REG_CDC_REGDATA2",	"CD7-0"); 
 CW(0xFF8008,"REG_CDC_HOSTDATA1",	"HD15-00"); 
 CW(0xFF800A,"REG_CDC_DMAADDR",	"A15-00");  
 CW(0xFF800C,"REG_COM_STOPWATCH",	"SW11-00");  
 CB(0xFF800E,"REG_COM_FLAG1",	"CFM7-0"); 
 CB(0xFF800F,"REG_COM_FLAG2",	"CFS7-0");     
 CW(0xFF8010,"REG_COM_COMMAND7",	"");   
 CW(0xFF8012,"REG_COM_COMMAND6",	""); 
 CW(0xFF8014,"REG_COM_COMMAND5",	""); 
 CW(0xFF8016,"REG_COM_COMMAND4",	""); 
 CW(0xFF8018,"REG_COM_COMMAND3",	""); 
 CW(0xFF801A,"REG_COM_COMMAND2",	""); 
 CW(0xFF801C,"REG_COM_COMMAND1",	""); 
 CW(0xFF801E,"REG_COM_COMMAND0",	"");  
 CW(0xFF8020,"REG_COM_STATUS7",	"");   
 CW(0xFF8022,"REG_COM_STATUS6",	""); 
 CW(0xFF8024,"REG_COM_STATUS5",	""); 
 CW(0xFF8026,"REG_COM_STATUS4",	""); 
 CW(0xFF8028,"REG_COM_STATUS3",	""); 
 CW(0xFF802A,"REG_COM_STATUS2",	""); 
 CW(0xFF802C,"REG_COM_STATUS1",	""); 
 CW(0xFF802E,"REG_COM_STATUS0",	"");    
 CW(0xFF8030,"REG_TIMER",	"TD7-0");   
 CW(0xFF8032,"REG_INT_MASK",	"IEN6-1");  
 CW(0xFF8036,"REG_CDD_CTRL",	"DM, HOCK, DRS, DTS");     
 CW(0xFF8038,"REG_CDD_COM9",	"");  
 CW(0xFF803A,"REG_CDD_COM8",	""); 
 CW(0xFF803C,"REG_CDD_COM7",	""); 
 CW(0xFF803E,"REG_CDD_COM6",	""); 
 CW(0xFF8040,"REG_CDD_COM5",	""); 
 CW(0xFF8042,"REG_CDD_COM4",	""); 
 CW(0xFF8044,"REG_CDD_COM3",	""); 
 CW(0xFF8046,"REG_CDD_COM2",	""); 
 CW(0xFF8048,"REG_CDD_COM1",	""); 
 CW(0xFF804A,"REG_CDD_COM0",	"");           

}
 
//-------------------------------------------------------------------------
static main() {
  auto addr;
  
  SegCreate(0x0,0x7FFFF,0,0,0,2);
  SegRename(0x0,"SUBCPUPRGRAM");
  
	SegCreate(0x80000,0xBFFFF,0,0,0,2);
  SegRename(0x80000,"WORDRAM2MBMODE");  
  
	SegCreate(0xC0000,0xDFFFF,0,0,0,2);
  SegRename(0xC0000,"WORDRAM1MBMODE");   

  SegCreate(0xFE0000,0xFE3FFF,0,0,0,2);
  SegRename(0xFE0000,"BBRAM");
  
  SegCreate(0xFF0000,0xFF3FFF,0,0,0,2);
  SegRename(0xFF0000,"PCM");  

  SegCreate(0xFF8000,0xFF80FF,0,0,0,2);
  SegRename(0xFF8000,"GATEARRAY");
   

  mdAddress( );
 

}
