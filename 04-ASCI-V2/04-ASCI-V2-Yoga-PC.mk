##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=04-ASCI-V2
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/Roger/SkyDrive/School/CSCI123/Blackjack-Fresh
ProjectPath            :=C:/Users/Roger/SkyDrive/School/CSCI123/Blackjack-Fresh/04-ASCI-V2
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Roger
Date                   :=16/05/2016
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/TDM-GCC-64/bin/g++.exe
SharedObjectLinkerName :=C:/TDM-GCC-64/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="04-ASCI-V2.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/TDM-GCC-64/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/TDM-GCC-64/bin/ar.exe rcu
CXX      := C:/TDM-GCC-64/bin/g++.exe
CC       := C:/TDM-GCC-64/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/TDM-GCC-64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/Card.cpp$(ObjectSuffix) $(IntermediateDirectory)/Deck.cpp$(ObjectSuffix) $(IntermediateDirectory)/Blackjack.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/Card.cpp$(ObjectSuffix): Card.cpp $(IntermediateDirectory)/Card.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Roger/SkyDrive/School/CSCI123/Blackjack-Fresh/04-ASCI-V2/Card.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Card.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Card.cpp$(DependSuffix): Card.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Card.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Card.cpp$(DependSuffix) -MM "Card.cpp"

$(IntermediateDirectory)/Card.cpp$(PreprocessSuffix): Card.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Card.cpp$(PreprocessSuffix) "Card.cpp"

$(IntermediateDirectory)/Deck.cpp$(ObjectSuffix): Deck.cpp $(IntermediateDirectory)/Deck.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Roger/SkyDrive/School/CSCI123/Blackjack-Fresh/04-ASCI-V2/Deck.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Deck.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Deck.cpp$(DependSuffix): Deck.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Deck.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Deck.cpp$(DependSuffix) -MM "Deck.cpp"

$(IntermediateDirectory)/Deck.cpp$(PreprocessSuffix): Deck.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Deck.cpp$(PreprocessSuffix) "Deck.cpp"

$(IntermediateDirectory)/Blackjack.cpp$(ObjectSuffix): Blackjack.cpp $(IntermediateDirectory)/Blackjack.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Roger/SkyDrive/School/CSCI123/Blackjack-Fresh/04-ASCI-V2/Blackjack.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Blackjack.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Blackjack.cpp$(DependSuffix): Blackjack.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Blackjack.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Blackjack.cpp$(DependSuffix) -MM "Blackjack.cpp"

$(IntermediateDirectory)/Blackjack.cpp$(PreprocessSuffix): Blackjack.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Blackjack.cpp$(PreprocessSuffix) "Blackjack.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


