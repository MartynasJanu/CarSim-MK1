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
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/Component.o \
	${OBJECTDIR}/src/Components/BatteryComponent.o \
	${OBJECTDIR}/src/Components/SparkPlugComponent.o \
	${OBJECTDIR}/src/Components/TimerComponent.o \
	${OBJECTDIR}/src/Resource.o \
	${OBJECTDIR}/src/Resources/ElectricityResource.o \
	${OBJECTDIR}/src/Stateful.o \
	${OBJECTDIR}/src/Storables/ElectricityStorable.o \
	${OBJECTDIR}/src/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-lboost_system -lboost_timer -lboost_chrono -lrt

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/carsim-mk1

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/carsim-mk1: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/carsim-mk1 ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/src/Component.o: src/Component.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Component.o src/Component.cpp

${OBJECTDIR}/src/Components/BatteryComponent.o: src/Components/BatteryComponent.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Components
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Components/BatteryComponent.o src/Components/BatteryComponent.cpp

${OBJECTDIR}/src/Components/SparkPlugComponent.o: src/Components/SparkPlugComponent.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Components
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Components/SparkPlugComponent.o src/Components/SparkPlugComponent.cpp

${OBJECTDIR}/src/Components/TimerComponent.o: src/Components/TimerComponent.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Components
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Components/TimerComponent.o src/Components/TimerComponent.cpp

${OBJECTDIR}/src/Resource.o: src/Resource.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Resource.o src/Resource.cpp

${OBJECTDIR}/src/Resources/ElectricityResource.o: src/Resources/ElectricityResource.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Resources
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Resources/ElectricityResource.o src/Resources/ElectricityResource.cpp

${OBJECTDIR}/src/Stateful.o: src/Stateful.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Stateful.o src/Stateful.cpp

${OBJECTDIR}/src/Storables/ElectricityStorable.o: src/Storables/ElectricityStorable.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Storables
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Storables/ElectricityStorable.o src/Storables/ElectricityStorable.cpp

${OBJECTDIR}/src/main.o: src/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/main.o src/main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/carsim-mk1

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
