

#include <idc.idc>



static main(void){


	splitAll();


}







static splitAll(){
	auto file;

	Message("SPLITTING...\n");
	file = fopen("sfcdisosplits.txt","w");
	initFile(file);

	Message(" Single Chunks...");	
	splitSingleChunks(file);	
	Message(" DONE.");
	
	writestr(file,"\nsplit	0x0,0x0,\\0x0 - .bin\n");
	fclose(file);
	Message("END OF SPLITS.\n");	
	
}


static initFile(file){
writestr(file,"/***********************Directories***************************/\n");
writestr(file,"#dir	filesystem/\n");
writestr(file,"\n");
writestr(file,"/***********************Data***************************/\n");
writestr(file,"\n");
}


static splitSingleChunks(file) {
	auto i,j,x,s,index,path;
	auto start,base,addr,end,dref,section,action;
	
	// Template : splitSingleChunk(0x,0x,"","",file);
	
	splitSingleChunk(0x800,0x1000,"MAIN_CPU_INIT_PRG","sector0001-maincpu-initprg.bin",file);
	splitSingleChunk(0x1000,0x8000,"SUB_CPU_INIT_PRG","sector0002-000F-subcpu-initprg.bin",file);
	splitSingleChunk(0x8000,0xB800,"","sector0010-0016-filesystem-header.bin",file);
	splitSingleChunk(0xB800,0x470800,"","filesystem/MC_MSG02.ROM",file);
	splitSingleChunk(0x470800,0x470820,"","filesystem/CPY.TXT",file);
	MakeAlign(0x470820, 0x471000-0x470820,11);
	splitSingleChunk(0x471000,0x471011,"","filesystem/ABS.TXT",file);
	MakeAlign(0x471011, 0x471800-0x471011,11);
	splitSingleChunk(0x471800,0x471816,"","filesystem/BIB.TXT",file);
	MakeAlign(0x471816, 0x472000-0x471816,11);
	splitSingleChunk(0x472000,0x474000,"","filesystem/AT.BIN",file);
	splitSingleChunk(0x474000,0xB35BC8,"","filesystem/SFEOPEN.P32",file);
	MakeAlign(0xB35BC8, 0xB36000-0xB35BC8,11);	
	splitSingleChunk(0xB36000,0x11F7BC8,"","filesystem/SFEOPENU.P32",file);
	MakeAlign(0x11F7BC8, 0x11F8000-0x11F7BC8,11);	
	splitSingleChunk(0x11F8000,0x1453070,"","filesystem/SFEEND1.P32",file);
	MakeAlign(0x1453070, 0x1453800-0x1453070,11);
	splitSingleChunk(0x1453800,0x16AE870,"","filesystem/SFEEND1U.P32",file);
	MakeAlign(0x16AE870, 0x16AF000-0x16AE870,11);
	splitSingleChunk(0x16AF000,0x189AF18,"","filesystem/SFEEND2.P32",file);
	MakeAlign(0x189AF18, 0x189B000-0x189AF18,11);
	splitSingleChunk(0x189B000,0x1A86F18,"","filesystem/SFEEND2U.P32",file);
	MakeAlign(0x1A86F18, 0x1A87000-0x1A86F18,11);
	splitSingleChunk(0x1A87000,0x1C72F18,"","filesystem/SFEEND3.P32",file);
	MakeAlign(0x1C72F18, 0x1C73000-0x1C72F18,11);
	splitSingleChunk(0x1C73000,0x1E5EF18,"","filesystem/SFEEND3U.P32",file);
	MakeAlign(0x1E5EF18, 0x1E5F000-0x1E5EF18,11);
	splitSingleChunk(0x1E5F000,0x1E6F000,"","filesystem/SFE_PCM.BIN",file);
	splitSingleChunk(0x1E6F000,0x1E7F000,"","filesystem/SFELOGO.X",file);
	splitSingleChunk(0x1E7F000,0x1EAF000,"","filesystem/SFEOPEN.X",file);
	splitSingleChunk(0x1EAF000,0x1EDF000,"","filesystem/SFEMAIN.X",file);
	splitSingleChunk(0x1EDF000,0x1EFF000,"","filesystem/BANKD1F.X",file);
	splitSingleChunk(0x1EFF000,0x1F2F000,"","filesystem/SFEEND1.X",file);
	splitSingleChunk(0x1F2F000,0x1F5F000,"","filesystem/SFEEND2.X",file);
	splitSingleChunk(0x1F5F000,0x1F8F000,"","filesystem/SFEEND3.X",file);
	splitSingleChunk(0x1F8F000,0x1FBF000,"","filesystem/SFEEND4.X",file);
	splitSingleChunk(0x1FBF000,0x202C000,"","filesystem/BANKD00.X",file);
	splitSingleChunk(0x202C000,0x2099000,"","filesystem/BANKD01.X",file);
	splitSingleChunk(0x2099000,0x2106000,"","filesystem/BANKD02.X",file);
	splitSingleChunk(0x2106000,0x2173000,"","filesystem/BANKD03.X",file);
	splitSingleChunk(0x2173000,0x21E0000,"","filesystem/BANKD04.X",file);
	splitSingleChunk(0x21E0000,0x224D000,"","filesystem/BANKD05.X",file);
	splitSingleChunk(0x224D000,0x22BA000,"","filesystem/BANKD06.X",file);
	splitSingleChunk(0x22BA000,0x2327000,"","filesystem/BANKD07.X",file);
	splitSingleChunk(0x2327000,0x2394000,"","filesystem/BANKD08.X",file);
	splitSingleChunk(0x2394000,0x2401000,"","filesystem/BANKD09.X",file);
	splitSingleChunk(0x2401000,0x246E000,"","filesystem/BANKD0A.X",file);
	splitSingleChunk(0x246E000,0x24DB000,"","filesystem/BANKD0B.X",file);
	splitSingleChunk(0x24DB000,0x2548000,"","filesystem/BANKD0C.X",file);
	splitSingleChunk(0x2548000,0x25B5000,"","filesystem/BANKD0D.X",file);
	splitSingleChunk(0x25B5000,0x2622000,"","filesystem/BANKD0E.X",file);
	splitSingleChunk(0x2622000,0x268F000,"","filesystem/BANKD0F.X",file);
	splitSingleChunk(0x268F000,0x26FC000,"","filesystem/BANKD10.X",file);
	splitSingleChunk(0x26FC000,0x2769000,"","filesystem/BANKD11.X",file);
	splitSingleChunk(0x2769000,0x27D6000,"","filesystem/BANKD12.X",file);
	splitSingleChunk(0x27D6000,0x2843000,"","filesystem/BANKD13.X",file);
	splitSingleChunk(0x2843000,0x28B0000,"","filesystem/BANKD14.X",file);
	splitSingleChunk(0x28B0000,0x291D000,"","filesystem/BANKD15.X",file);
	splitSingleChunk(0x291D000,0x298A000,"","filesystem/BANKD16.X",file);
	splitSingleChunk(0x298A000,0x298A005,"","filesystem/BANKD17.X",file);
	MakeAlign(0x298A005, 0x298A800-0x298A005,11);	
	splitSingleChunk(0x298A800,0x298A805,"","filesystem/BANKD18.X",file);
	MakeAlign(0x298A805, 0x298B000-0x298A805,11);
	splitSingleChunk(0x298B000,0x298B005,"","filesystem/BANKD19.X",file);
	MakeAlign(0x298B005, 0x298B800-0x298B005,11);
	splitSingleChunk(0x298B800,0x298B805,"","filesystem/BANKD1A.X",file);
	MakeAlign(0x298B805, 0x298C000-0x298B805,11);
	splitSingleChunk(0x298C000,0x298C005,"","filesystem/BANKD1B.X",file);
	MakeAlign(0x298C005, 0x298C800-0x298C005,11);
	splitSingleChunk(0x298C800,0x298C805,"","filesystem/BANKD1C.X",file);
	MakeAlign(0x298C805, 0x298D000-0x298C805,11);
	splitSingleChunk(0x298D000,0x298D005,"","filesystem/BANKD1D.X",file);
	MakeAlign(0x298D005, 0x298D800-0x298D005,11);
	splitSingleChunk(0x298D800,0x298D805,"","filesystem/BANKD1E.X",file);
	MakeAlign(0x298D805, 0x298E000-0x298D805,11);
	splitSingleChunk(0x298E000,0x29FB000,"","filesystem/BANKD20.X",file);
	splitSingleChunk(0x29FB000,0x2A68000,"","filesystem/BANKD21.X",file);
	splitSingleChunk(0x2A68000,0x2AD5000,"","filesystem/BANKD22.X",file);
	splitSingleChunk(0x2AD5000,0x2B42000,"","filesystem/BANKD23.X",file);
	splitSingleChunk(0x2B42000,0x2BAF000,"","filesystem/BANKD24.X",file);
	splitSingleChunk(0x2BAF000,0x2C1C000,"","filesystem/BANKD25.X",file);
	splitSingleChunk(0x2C1C000,0x2C89000,"","filesystem/BANKD26.X",file);
	splitSingleChunk(0x2C89000,0x2CF6000,"","filesystem/BANKD27.X",file);
	splitSingleChunk(0x2CF6000,0x2D63000,"","filesystem/BANKD28.X",file);
	splitSingleChunk(0x2D63000,0x2DD0000,"","filesystem/BANKD29.X",file);
	splitSingleChunk(0x2DD0000,0x2E3D000,"","filesystem/BANKD2A.X",file);
	splitSingleChunk(0x2E3D000,0x2EAA000,"","filesystem/BANKD2B.X",file);
	splitSingleChunk(0x2EAA000,0x2F17000,"","filesystem/BANKD2C.X",file);
	splitSingleChunk(0x2F17000,0x2F84000,"","filesystem/BANKD2D.X",file);
	splitSingleChunk(0x2F84000,0x2FF1000,"","filesystem/BANKD2E.X",file);
	splitSingleChunk(0x2FF1000,0x305E000,"","filesystem/BANKD2F.X",file);
	splitSingleChunk(0x305E000,0x30CB000,"","filesystem/BANKD30.X",file);
	splitSingleChunk(0x30CB000,0x3138000,"","filesystem/BANKD31.X",file);
	splitSingleChunk(0x3138000,0x31A5000,"","filesystem/BANKD32.X",file);
	splitSingleChunk(0x31A5000,0x3212000,"","filesystem/BANKD33.X",file);
	splitSingleChunk(0x3212000,0x327F000,"","filesystem/BANKD34.X",file);
	splitSingleChunk(0x327F000,0x32EC000,"","filesystem/BANKD35.X",file);
	splitSingleChunk(0x32EC000,0x3359000,"","filesystem/BANKD36.X",file);
	splitSingleChunk(0x3359000,0x33C6000,"","filesystem/BANKD37.X",file);
	splitSingleChunk(0x33C6000,0x3433000,"","filesystem/BANKD38.X",file);
	splitSingleChunk(0x3433000,0x3483000,"","filesystem/BANKD39.X",file);
	splitSingleChunk(0x3483000,0x34B3000,"","filesystem/BANKD3A.X",file);
	splitSingleChunk(0x34B3000,0x34E3000,"","filesystem/BANKD3B.X",file);
	splitSingleChunk(0x34E3000,0x34E3005,"","filesystem/BANKD3C.X",file);
	MakeAlign(0x34E3005, 0x34E3800-0x34E3005,11);
	splitSingleChunk(0x34E3800,0x34E3805,"","filesystem/BANKD3D.X",file);
	MakeAlign(0x34E3805, 0x34E4000-0x34E3805,11);
	splitSingleChunk(0x34E4000,0x34E4005,"","filesystem/BANKD3E.X",file);
	MakeAlign(0x34E4005, 0x34E4800-0x34E4005,11);
	splitSingleChunk(0x34E4800,0x34E4805,"","filesystem/BANKD3F.X",file);
	MakeAlign(0x34E4805, 0x34E5000-0x34E4805,11);
	splitSingleChunk(0x34E5000,0x3552000,"","filesystem/BANKD40.X",file);
	splitSingleChunk(0x3552000,0x35BF000,"","filesystem/BANKD41.X",file);
	splitSingleChunk(0x35BF000,0x362C000,"","filesystem/BANKD42.X",file);
	splitSingleChunk(0x362C000,0x3699000,"","filesystem/BANKD43.X",file);
	splitSingleChunk(0x3699000,0x3706000,"","filesystem/BANKD44.X",file);
	splitSingleChunk(0x3706000,0x3773000,"","filesystem/BANKD45.X",file);
	splitSingleChunk(0x3773000,0x37E0000,"","filesystem/BANKD46.X",file);
	splitSingleChunk(0x37E0000,0x384D000,"","filesystem/BANKD47.X",file);
	splitSingleChunk(0x384D000,0x38BA000,"","filesystem/BANKD48.X",file);
	
	MakeData(0x38BA000,FF_BYTE,0x38C0000-0x38BA000,1);
	SetManualInsn   (0x38BA000, "align $10000\n");
	MakeData(0x38C0000,FF_BYTE,0x3900000-0x38C0000,1);
	SetManualInsn   (0x38C0000, "align $100000\n");
	MakeData(0x3900000,FF_BYTE,0x3940000-0x3900000,1);
	SetManualInsn   (0x3900000, "align $40000\n");
	MakeData(0x3940000,FF_BYTE,0x3948000-0x3940000,1);
	SetManualInsn   (0x3940000, "align $8000\n");
	MakeData(0x3948000,FF_BYTE,0x394C000-0x3948000,1);
	SetManualInsn   (0x3948000, "align $4000\n");
	MakeData(0x394C000,FF_BYTE,0x394E000-0x394C000,1);
	SetManualInsn   (0x394C000, "align $2000\n");
	MakeData(0x394E000,FF_BYTE,0x394F000-0x394E000,1);
	SetManualInsn   (0x394E000, "align $1000\n");
	
	//MakeAlign(0x38BA000, 0x394F000-0x38BA000,14);
	



}

static splitSingleChunk(start, end, nameString, binPath, splitFile){
	auto j;
	//Message("Cleaning from %a to %a ...\n",start,end);
	/* for(j=start+1;j<end;j++){undefineByte(j);} */
	MakeUnknown(start,end,DOUNK_SIMPLE);
	MakeData(start,FF_BYTE,end-start,1);
	if(nameString!=""){
		MakeNameEx(start,nameString,0);
	}
	SetManualInsn   (start, form("incbin \"%s\"",binPath));
	writestr(splitFile,form("#split\t0x%s,0x%s,%s\n",ltoa(start,16),ltoa(end,16),binPath));
	//Jump(start);
}

static splitSingleChunkWithCommentedSplitEntry(start, end, nameString, binPath, splitFile){
	auto j;
	//Message("Cleaning from %a to %a ...\n",start,end);
	for(j=start+1;j<end;j++){undefineByte(j);}
	MakeData(start,FF_BYTE,end-start,1);
	MakeNameEx(start,nameString,0);
	SetManualInsn   (start, form("incbin \"%s\"",binPath));
	writestr(splitFile,form("/*#split\t0x%s,0x%s,%s*/\n",ltoa(start,16),ltoa(end,16),binPath));
	//Jump(start);
}


static MakeNameExC(addr,name,flags){

	auto current;
	current = GetTrueName(addr);
	if(current=="" || strstr(current,"unk_")!=-1 || strstr(current,"byte_")!=-1 || strstr(current,"word_")!=-1 || strstr(current,"dword_")!=-1 || strstr(current,"off_")!=-1){
		MakeNameEx(addr,name,flags);
	}

}


/* 
 *	Makes sure byte at addr is
 *	clean for new formatting
 */
static undefineByte(addr){
		auto from;
		from = DfirstB(addr);
		while(from!=BADADDR){
			//Message(form("Removed DATA XRef at addr %a, from %a\n",addr, from));
      del_dref(from,addr);
      from=DnextB(addr,from);
		}		
		from = RfirstB(addr);
		while(from!=BADADDR){
			//Message(form("Removed Code XRrf at addr %a, from %a\n",addr, from));
      DelCodeXref(from,addr,1);
      from=RnextB(addr,from);      
		}				
		MakeUnkn(addr,DOUNK_DELNAMES);
		MakeNameEx(addr,"",0);
		SetManualInsn(addr,"");
}




