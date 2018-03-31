#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=MinGW_TDM-Windows
CND_DLIB_EXT=dll
CND_CONF=win64-debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/source/Application.o \
	${OBJECTDIR}/source/Character.o \
	${OBJECTDIR}/source/Logger.o \
	${OBJECTDIR}/source/Sound.o \
	${OBJECTDIR}/source/UserInterface.o \
	${OBJECTDIR}/source/Utilities.o \
	${OBJECTDIR}/source/main.o


# C Compiler Flags
CFLAGS=-m64

# CC Compiler Flags
CCFLAGS=-m64
CXXFLAGS=-m64

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=--64

# Link Libraries and Options
LDLIBSOPTIONS=-L../../../libraries/irrlicht-1.8.4/lib/Win64-gcc -L../../../libraries/openal-soft-1.18.2/libs/Win64 -lIrrlicht -lopengl32 -lglu32 -lgdi32 -lwinmm -lOpenAL32.dll

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk caveman-tactics-debug.exe

caveman-tactics-debug.exe: ${OBJECTFILES}
	${LINK.cc} -o caveman-tactics-debug.exe ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/source/Application.o: source/Application.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -D_IRR_STATIC_LIB_ -D_WINDOWS_ -I../../../libraries/irrlicht-1.8.4/include -I../../../libraries/openal-soft-1.18.2/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/Application.o source/Application.cpp

${OBJECTDIR}/source/Character.o: source/Character.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -D_IRR_STATIC_LIB_ -D_WINDOWS_ -I../../../libraries/irrlicht-1.8.4/include -I../../../libraries/openal-soft-1.18.2/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/Character.o source/Character.cpp

${OBJECTDIR}/source/Logger.o: source/Logger.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -D_IRR_STATIC_LIB_ -D_WINDOWS_ -I../../../libraries/irrlicht-1.8.4/include -I../../../libraries/openal-soft-1.18.2/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/Logger.o source/Logger.cpp

${OBJECTDIR}/source/Sound.o: source/Sound.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -D_IRR_STATIC_LIB_ -D_WINDOWS_ -I../../../libraries/irrlicht-1.8.4/include -I../../../libraries/openal-soft-1.18.2/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/Sound.o source/Sound.cpp

${OBJECTDIR}/source/UserInterface.o: source/UserInterface.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -D_IRR_STATIC_LIB_ -D_WINDOWS_ -I../../../libraries/irrlicht-1.8.4/include -I../../../libraries/openal-soft-1.18.2/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/UserInterface.o source/UserInterface.cpp

${OBJECTDIR}/source/Utilities.o: source/Utilities.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -D_IRR_STATIC_LIB_ -D_WINDOWS_ -I../../../libraries/irrlicht-1.8.4/include -I../../../libraries/openal-soft-1.18.2/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/Utilities.o source/Utilities.cpp

${OBJECTDIR}/source/main.o: source/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -D_IRR_STATIC_LIB_ -D_WINDOWS_ -I../../../libraries/irrlicht-1.8.4/include -I../../../libraries/openal-soft-1.18.2/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/main.o source/main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} caveman-tactics-debug.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
