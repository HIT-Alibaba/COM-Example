# Microsoft Developer Studio Generated NMAKE File, Based on AddObj.dsp
!IF "$(CFG)" == ""
CFG=AddObj - Win32 Debug
!MESSAGE No configuration specified. Defaulting to AddObj - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "AddObj - Win32 Release" && "$(CFG)" != "AddObj - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "AddObj.mak" CFG="AddObj - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "AddObj - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "AddObj - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "AddObj - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\AddObj.dll"

!ELSE 

ALL : "$(OUTDIR)\AddObj.dll"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\AddObj.obj"
	-@erase "$(INTDIR)\AddObjFactory.obj"
	-@erase "$(INTDIR)\Exports.obj"
	-@erase "$(INTDIR)\REGISTRY.OBJ"
	-@erase "$(INTDIR)\resource.res"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\AddObj.dll"
	-@erase "$(OUTDIR)\AddObj.exp"
	-@erase "$(OUTDIR)\AddObj.lib"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS"\
 /Fp"$(INTDIR)\AddObj.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Release/
CPP_SBRS=.
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o NUL /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\resource.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\AddObj.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib /nologo /subsystem:windows /dll /incremental:no\
 /pdb:"$(OUTDIR)\AddObj.pdb" /machine:I386 /def:".\Exports.def"\
 /out:"$(OUTDIR)\AddObj.dll" /implib:"$(OUTDIR)\AddObj.lib" 
DEF_FILE= \
	".\Exports.def"
LINK32_OBJS= \
	"$(INTDIR)\AddObj.obj" \
	"$(INTDIR)\AddObjFactory.obj" \
	"$(INTDIR)\Exports.obj" \
	"$(INTDIR)\REGISTRY.OBJ" \
	"$(INTDIR)\resource.res"

"$(OUTDIR)\AddObj.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "AddObj - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\AddObj.dll" "$(OUTDIR)\AddObj.bsc"

!ELSE 

ALL : "$(OUTDIR)\AddObj.dll" "$(OUTDIR)\AddObj.bsc"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\AddObj.obj"
	-@erase "$(INTDIR)\AddObj.sbr"
	-@erase "$(INTDIR)\AddObjFactory.obj"
	-@erase "$(INTDIR)\AddObjFactory.sbr"
	-@erase "$(INTDIR)\Exports.obj"
	-@erase "$(INTDIR)\Exports.sbr"
	-@erase "$(INTDIR)\REGISTRY.OBJ"
	-@erase "$(INTDIR)\REGISTRY.SBR"
	-@erase "$(INTDIR)\resource.res"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\AddObj.bsc"
	-@erase "$(OUTDIR)\AddObj.dll"
	-@erase "$(OUTDIR)\AddObj.exp"
	-@erase "$(OUTDIR)\AddObj.ilk"
	-@erase "$(OUTDIR)\AddObj.lib"
	-@erase "$(OUTDIR)\AddObj.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /FR"$(INTDIR)\\" /Fp"$(INTDIR)\AddObj.pch" /YX /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.\Debug/
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /o NUL /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\resource.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\AddObj.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\AddObj.sbr" \
	"$(INTDIR)\AddObjFactory.sbr" \
	"$(INTDIR)\Exports.sbr" \
	"$(INTDIR)\REGISTRY.SBR"

"$(OUTDIR)\AddObj.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib /nologo /subsystem:windows /dll /incremental:yes\
 /pdb:"$(OUTDIR)\AddObj.pdb" /debug /machine:I386 /def:".\Exports.def"\
 /out:"$(OUTDIR)\AddObj.dll" /implib:"$(OUTDIR)\AddObj.lib" /pdbtype:sept 
DEF_FILE= \
	".\Exports.def"
LINK32_OBJS= \
	"$(INTDIR)\AddObj.obj" \
	"$(INTDIR)\AddObjFactory.obj" \
	"$(INTDIR)\Exports.obj" \
	"$(INTDIR)\REGISTRY.OBJ" \
	"$(INTDIR)\resource.res"

"$(OUTDIR)\AddObj.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

SOURCE=$(InputPath)
DS_POSTBUILD_DEP=$(INTDIR)\postbld.dep

ALL : $(DS_POSTBUILD_DEP)

# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

$(DS_POSTBUILD_DEP) : "$(OUTDIR)\AddObj.dll" "$(OUTDIR)\AddObj.bsc"
   echo Registering the DLL
	regsvr32 Debug\AddObj.dll
	echo Helper for Post-build step > "$(DS_POSTBUILD_DEP)"

!ENDIF 

.c{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<


!IF "$(CFG)" == "AddObj - Win32 Release" || "$(CFG)" == "AddObj - Win32 Debug"
SOURCE=.\AddObj.cpp

!IF  "$(CFG)" == "AddObj - Win32 Release"

DEP_CPP_ADDOB=\
	".\addobj.h"\
	".\iadd.h"\
	".\iadd_i.c"\
	

"$(INTDIR)\AddObj.obj" : $(SOURCE) $(DEP_CPP_ADDOB) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "AddObj - Win32 Debug"

DEP_CPP_ADDOB=\
	".\addobj.h"\
	".\iadd.h"\
	".\iadd_i.c"\
	

"$(INTDIR)\AddObj.obj"	"$(INTDIR)\AddObj.sbr" : $(SOURCE) $(DEP_CPP_ADDOB)\
 "$(INTDIR)"


!ENDIF 

SOURCE=.\AddObjFactory.cpp

!IF  "$(CFG)" == "AddObj - Win32 Release"

DEP_CPP_ADDOBJ=\
	".\addobj.h"\
	".\addobjfactory.h"\
	".\iadd.h"\
	

"$(INTDIR)\AddObjFactory.obj" : $(SOURCE) $(DEP_CPP_ADDOBJ) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "AddObj - Win32 Debug"

DEP_CPP_ADDOBJ=\
	".\addobj.h"\
	".\addobjfactory.h"\
	".\iadd.h"\
	

"$(INTDIR)\AddObjFactory.obj"	"$(INTDIR)\AddObjFactory.sbr" : $(SOURCE)\
 $(DEP_CPP_ADDOBJ) "$(INTDIR)"


!ENDIF 

SOURCE=.\Exports.cpp

!IF  "$(CFG)" == "AddObj - Win32 Release"

DEP_CPP_EXPOR=\
	".\addobj.h"\
	".\addobjfactory.h"\
	".\addobjguid.h"\
	".\iadd.h"\
	

"$(INTDIR)\Exports.obj" : $(SOURCE) $(DEP_CPP_EXPOR) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "AddObj - Win32 Debug"

DEP_CPP_EXPOR=\
	".\addobj.h"\
	".\addobjfactory.h"\
	".\addobjguid.h"\
	".\iadd.h"\
	

"$(INTDIR)\Exports.obj"	"$(INTDIR)\Exports.sbr" : $(SOURCE) $(DEP_CPP_EXPOR)\
 "$(INTDIR)"


!ENDIF 

SOURCE=.\IAdd.idl

!IF  "$(CFG)" == "AddObj - Win32 Release"

!ELSEIF  "$(CFG)" == "AddObj - Win32 Debug"

InputPath=.\IAdd.idl

"IAdd.tlb" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	midl IAdd.idl

!ENDIF 

SOURCE=.\REGISTRY.CPP
DEP_CPP_REGIS=\
	".\addobjguid.h"\
	

!IF  "$(CFG)" == "AddObj - Win32 Release"


"$(INTDIR)\REGISTRY.OBJ" : $(SOURCE) $(DEP_CPP_REGIS) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "AddObj - Win32 Debug"


"$(INTDIR)\REGISTRY.OBJ"	"$(INTDIR)\REGISTRY.SBR" : $(SOURCE) $(DEP_CPP_REGIS)\
 "$(INTDIR)"


!ENDIF 

SOURCE=.\resource.rc
DEP_RSC_RESOU=\
	".\IAdd.tlb"\
	

"$(INTDIR)\resource.res" : $(SOURCE) $(DEP_RSC_RESOU) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)



!ENDIF 

