
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
