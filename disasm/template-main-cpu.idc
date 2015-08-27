
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
 CD(0xC00000, "VDP_Data","");
 CD(0xC00004, "VDP_Control",""); 
 CD(0xC00008, "HV_Counter",""); 
 CB(0xC00011, "PSG",""); 

 CW(0xA10001, "HW_Info","7-MODE  (R)  0: Domestic Model\n"
		        "             1: Overseas Model\n"
		        "6-VMOD  (R)  0: NTSC CPU clock 7.67 MHz\n"
                        "             1: PAL CPU clock 7.60 MHz\n"
                        "5-DISK  (R)  0: FDD unit connected\n"
		        "             1: FDD unit not connected\n"
		        "4-RSV   (R)  Currently not used\n"
		        "3-0 VER (R)  MEGA DRIVE version ($0 to $F)");

 CW(0xA10003,"DATA1",	"PD7 (RW)\n"
           		"PD6 (RW) TH\n"
           		"PD5 (RW) TR\n"
           		"PD4 (RW) TL\n"
           		"PD3 (RW) RIGHT\n"
           		"PD2 (RW) LEFT\n"
           		"PD1 (RW) DOWN\n"
           		"PDO (RW) UP\n" );
 CW(0xA10005,"DATA2","");
 CW(0xA10007,"DATA3","");
 CW(0xA10009,"CTRL1",	"INT (RW) 0: TH-INT PROHIBITED\n"
                     	"         1: TH-INT ALLOWED\n"
		     	"PC6 (RW) 0: PD6 INPUT MODE\n"
                     	"         1: OUTPUT MODE\n"
			"PC5 (RW) 0: PD5 INPUT MODE\n"
			"         1: OUTPUT MODE\n"
			"PC4 (RW) 0: PD4 INPUT MODE\n"
			"         1: OUTPUT MODE\n"
			"PC3 (RW) 0: PD3 INPUT MODE\n"
			"         1: OUTPUT MODE\n"
			"PC2 (RW) 0: PD2 INPUT MODE\n"
			"         1: OUTPUT MODE\n"
			"PC1 (RW) 0: PD1 INPUT MODE\n"
			"         1: OUTPUT MODE\n"
			"PCO (RW) 0: PDO INPUT MODE\n"
			"         1: OUTPUT MODE");
 CW(0xA1000B,"CTRL2","");
 CW(0xA1000D,"CTRL3","");
 CW(0xA1000F,"TxDATA1","");
 CW(0xA10011,"RxDATA1","");
 CW(0xA10013,"SCTRL1","");
 CW(0xA10015,"TxDATA2","");
 CW(0xA10017,"RxDATA2","");
 CW(0xA10019,"SCTRL2","");
 CW(0xA1001B,"TxDATA3","");
 CW(0xA1001D,"RxDATA3","");
 CW(0xA1001F,"SCTRL3","");

 CW(0xA11000,"MemMode",	"D8 ( W)   0: ROM MODE\n"
                        "          1: D-RAM MODE");
 
 CW(0xA11100,"Z80BusReq","D8 ( W)   0: BUSREQ CANCEL\n"
                         "          1: BUSREQ REQUEST\n"
                         "   ( R)   0: CPU FUNCTION STOP ACCESSIBLE\n"
                         "          1: FUNCTIONING");
 CW(0xA11200,"Z80BusReset","D8 ( W)   0: RESET REQUEST\n"
                           "          1: RESET CANCEL"); 
}
 
//-------------------------------------------------------------------------
static main() {
  auto addr;
  
  SegCreate(0x0,0x1FFFF,0,0,0,2);
  SegRename(0x0,"BIOSROM");
  
	SegCreate(0x20000,0x3FFFF,0,0,0,2);
  SegRename(0x20000,"SUBPRGRAM");  
  
	SegCreate(0x200000,0x23FFFF,0,0,0,2);
  SegRename(0x200000,"WORDRAM");   

  SegCreate(0xA00000,0xA0FFFF,0,0,0,2);
  SegRename(0xA00000,"Z80");

  SegCreate(0xA10000,0xA10FFF,0,0,0,2);
  SegRename(0xA10000,"IO");

  SegCreate(0xA11000,0xA11FFF,0,0,0,2);
  SegRename(0xA11000,"CONTROL");
  
  SegCreate(0xA12000,0xA120FF,0,0,0,2);
  SegRename(0xA12000,"GATEARRAY");  

  SegCreate(0xC00000,0xDFFFFF,0,0,0,2);
  SegRename(0xC00000,"VDP");

  SegCreate(0xFF0000,0xFFFFFF,0,0,0,2);
  SegRename(0xFF0000,"RAM");
   

  mdAddress( );
 

}
