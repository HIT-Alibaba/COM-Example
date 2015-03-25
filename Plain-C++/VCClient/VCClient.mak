# Microsoft Developer Studio Generated NMAKE File, Based on VCClient.dsp
!IF "$(CFG)" == ""
CFG=VCClient - Win32 Debug
!MESSAGE No configuration specified. Defaulting to VCClient - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "VCClient - Win32 Release" && "$(CFG)" !=\
 "VCClient - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "VCClient.mak" CFG="VCClient - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "VCClient - Win32 Release" (based on\
 "Win32 (x86) Console Application")
!MESSAGE "VCClient - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "VCClient - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\VCClient.exe"

!ELSE 

ALL : "$(OUTDIR)\VCClient.exe"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\Client.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\VCClient.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /ML /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D\
 "_MBCS" /Fp"$(INTDIR)\VCClient.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD\
 /c 
CPP_OBJS=.\Release/
CPP_SBRS=.
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\VCClient.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib /nologo /subsystem:console /incremental:no\
 /pdb:"$(OUTDIR)\VCClient.pdb" /machine:I386 /out:"$(OUTDIR)\VCClient.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Client.obj"

"$(OUTDIR)\VCClient.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "VCClient - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\VCClient.exe"

!ELSE 

ALL : "$(OUTDIR)\VCClient.exe"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\Client.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\VCClient.exe"
	-@erase "$(OUTDIR)\VCClient.ilk"
	-@erase "$(OUTDIR)\VCClient.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MLd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE"\
 /D "_MBCS" /Fp"$(INTDIR)\VCClient.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\"\
 /FD /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\VCClient.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib /nologo /subsystem:console /incremental:yes\
 /pdb:"$(OUTDIR)\VCClient.pdb" /debug /machine:I386\
 /out:"$(OUTDIR)\VCClient.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\Client.obj"

"$(OUTDIR)\VCClient.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

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


!IF "$(CFG)" == "VCClient - Win32 Release" || "$(CFG)" ==\
 "VCClient - Win32 Debug"
SOURCE=.\Client.cpp

!IF  "$(CFG)" == "VCClient - Win32 Release"


"$(INTDIR)\Client.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "VCClient - Win32 Debug"

DEP_CPP_CLIEN=\
	"c:\winnt\system32\addobj.dll"\
	

"$(INTDIR)\Client.obj" : $(SOURCE) $(DEP_CPP_CLIEN) "$(INTDIR)"


!ENDIF 


!ENDIF 

