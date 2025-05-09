#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/progVer004.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/progVer004.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=--mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=libs/programming.c libs/progPIC18F26K40.c picLibs/app_device_cdc_basic.c picLibs/app_led_usb_status.c picLibs/buttons.c picLibs/leds.c picLibs/system.c picLibs/usb_descriptors.c picLibs/usb_device.c picLibs/usb_device_cdc.c picLibs/usb_events.c main.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/libs/programming.p1 ${OBJECTDIR}/libs/progPIC18F26K40.p1 ${OBJECTDIR}/picLibs/app_device_cdc_basic.p1 ${OBJECTDIR}/picLibs/app_led_usb_status.p1 ${OBJECTDIR}/picLibs/buttons.p1 ${OBJECTDIR}/picLibs/leds.p1 ${OBJECTDIR}/picLibs/system.p1 ${OBJECTDIR}/picLibs/usb_descriptors.p1 ${OBJECTDIR}/picLibs/usb_device.p1 ${OBJECTDIR}/picLibs/usb_device_cdc.p1 ${OBJECTDIR}/picLibs/usb_events.p1 ${OBJECTDIR}/main.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/libs/programming.p1.d ${OBJECTDIR}/libs/progPIC18F26K40.p1.d ${OBJECTDIR}/picLibs/app_device_cdc_basic.p1.d ${OBJECTDIR}/picLibs/app_led_usb_status.p1.d ${OBJECTDIR}/picLibs/buttons.p1.d ${OBJECTDIR}/picLibs/leds.p1.d ${OBJECTDIR}/picLibs/system.p1.d ${OBJECTDIR}/picLibs/usb_descriptors.p1.d ${OBJECTDIR}/picLibs/usb_device.p1.d ${OBJECTDIR}/picLibs/usb_device_cdc.p1.d ${OBJECTDIR}/picLibs/usb_events.p1.d ${OBJECTDIR}/main.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/libs/programming.p1 ${OBJECTDIR}/libs/progPIC18F26K40.p1 ${OBJECTDIR}/picLibs/app_device_cdc_basic.p1 ${OBJECTDIR}/picLibs/app_led_usb_status.p1 ${OBJECTDIR}/picLibs/buttons.p1 ${OBJECTDIR}/picLibs/leds.p1 ${OBJECTDIR}/picLibs/system.p1 ${OBJECTDIR}/picLibs/usb_descriptors.p1 ${OBJECTDIR}/picLibs/usb_device.p1 ${OBJECTDIR}/picLibs/usb_device_cdc.p1 ${OBJECTDIR}/picLibs/usb_events.p1 ${OBJECTDIR}/main.p1

# Source Files
SOURCEFILES=libs/programming.c libs/progPIC18F26K40.c picLibs/app_device_cdc_basic.c picLibs/app_led_usb_status.c picLibs/buttons.c picLibs/leds.c picLibs/system.c picLibs/usb_descriptors.c picLibs/usb_device.c picLibs/usb_device_cdc.c picLibs/usb_events.c main.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/progVer004.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F14K50
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/libs/programming.p1: libs/programming.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/libs" 
	@${RM} ${OBJECTDIR}/libs/programming.p1.d 
	@${RM} ${OBJECTDIR}/libs/programming.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=pro -P -N255 -I"libs" -I"usbLibs" -I"picLibs" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/libs/programming.p1  libs/programming.c 
	@-${MV} ${OBJECTDIR}/libs/programming.d ${OBJECTDIR}/libs/programming.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/libs/programming.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/libs/progPIC18F26K40.p1: libs/progPIC18F26K40.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/libs" 
	@${RM} ${OBJECTDIR}/libs/progPIC18F26K40.p1.d 
	@${RM} ${OBJECTDIR}/libs/progPIC18F26K40.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=pro -P -N255 -I"libs" -I"usbLibs" -I"picLibs" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/libs/progPIC18F26K40.p1  libs/progPIC18F26K40.c 
	@-${MV} ${OBJECTDIR}/libs/progPIC18F26K40.d ${OBJECTDIR}/libs/progPIC18F26K40.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/libs/progPIC18F26K40.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/picLibs/app_device_cdc_basic.p1: picLibs/app_device_cdc_basic.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/picLibs" 
	@${RM} ${OBJECTDIR}/picLibs/app_device_cdc_basic.p1.d 
	@${RM} ${OBJECTDIR}/picLibs/app_device_cdc_basic.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=pro -P -N255 -I"libs" -I"usbLibs" -I"picLibs" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/picLibs/app_device_cdc_basic.p1  picLibs/app_device_cdc_basic.c 
	@-${MV} ${OBJECTDIR}/picLibs/app_device_cdc_basic.d ${OBJECTDIR}/picLibs/app_device_cdc_basic.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/picLibs/app_device_cdc_basic.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/picLibs/app_led_usb_status.p1: picLibs/app_led_usb_status.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/picLibs" 
	@${RM} ${OBJECTDIR}/picLibs/app_led_usb_status.p1.d 
	@${RM} ${OBJECTDIR}/picLibs/app_led_usb_status.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=pro -P -N255 -I"libs" -I"usbLibs" -I"picLibs" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/picLibs/app_led_usb_status.p1  picLibs/app_led_usb_status.c 
	@-${MV} ${OBJECTDIR}/picLibs/app_led_usb_status.d ${OBJECTDIR}/picLibs/app_led_usb_status.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/picLibs/app_led_usb_status.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/picLibs/buttons.p1: picLibs/buttons.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/picLibs" 
	@${RM} ${OBJECTDIR}/picLibs/buttons.p1.d 
	@${RM} ${OBJECTDIR}/picLibs/buttons.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=pro -P -N255 -I"libs" -I"usbLibs" -I"picLibs" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/picLibs/buttons.p1  picLibs/buttons.c 
	@-${MV} ${OBJECTDIR}/picLibs/buttons.d ${OBJECTDIR}/picLibs/buttons.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/picLibs/buttons.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/picLibs/leds.p1: picLibs/leds.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/picLibs" 
	@${RM} ${OBJECTDIR}/picLibs/leds.p1.d 
	@${RM} ${OBJECTDIR}/picLibs/leds.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=pro -P -N255 -I"libs" -I"usbLibs" -I"picLibs" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/picLibs/leds.p1  picLibs/leds.c 
	@-${MV} ${OBJECTDIR}/picLibs/leds.d ${OBJECTDIR}/picLibs/leds.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/picLibs/leds.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/picLibs/system.p1: picLibs/system.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/picLibs" 
	@${RM} ${OBJECTDIR}/picLibs/system.p1.d 
	@${RM} ${OBJECTDIR}/picLibs/system.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=pro -P -N255 -I"libs" -I"usbLibs" -I"picLibs" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/picLibs/system.p1  picLibs/system.c 
	@-${MV} ${OBJECTDIR}/picLibs/system.d ${OBJECTDIR}/picLibs/system.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/picLibs/system.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/picLibs/usb_descriptors.p1: picLibs/usb_descriptors.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/picLibs" 
	@${RM} ${OBJECTDIR}/picLibs/usb_descriptors.p1.d 
	@${RM} ${OBJECTDIR}/picLibs/usb_descriptors.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=pro -P -N255 -I"libs" -I"usbLibs" -I"picLibs" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/picLibs/usb_descriptors.p1  picLibs/usb_descriptors.c 
	@-${MV} ${OBJECTDIR}/picLibs/usb_descriptors.d ${OBJECTDIR}/picLibs/usb_descriptors.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/picLibs/usb_descriptors.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/picLibs/usb_device.p1: picLibs/usb_device.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/picLibs" 
	@${RM} ${OBJECTDIR}/picLibs/usb_device.p1.d 
	@${RM} ${OBJECTDIR}/picLibs/usb_device.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=pro -P -N255 -I"libs" -I"usbLibs" -I"picLibs" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/picLibs/usb_device.p1  picLibs/usb_device.c 
	@-${MV} ${OBJECTDIR}/picLibs/usb_device.d ${OBJECTDIR}/picLibs/usb_device.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/picLibs/usb_device.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/picLibs/usb_device_cdc.p1: picLibs/usb_device_cdc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/picLibs" 
	@${RM} ${OBJECTDIR}/picLibs/usb_device_cdc.p1.d 
	@${RM} ${OBJECTDIR}/picLibs/usb_device_cdc.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=pro -P -N255 -I"libs" -I"usbLibs" -I"picLibs" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/picLibs/usb_device_cdc.p1  picLibs/usb_device_cdc.c 
	@-${MV} ${OBJECTDIR}/picLibs/usb_device_cdc.d ${OBJECTDIR}/picLibs/usb_device_cdc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/picLibs/usb_device_cdc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/picLibs/usb_events.p1: picLibs/usb_events.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/picLibs" 
	@${RM} ${OBJECTDIR}/picLibs/usb_events.p1.d 
	@${RM} ${OBJECTDIR}/picLibs/usb_events.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=pro -P -N255 -I"libs" -I"usbLibs" -I"picLibs" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/picLibs/usb_events.p1  picLibs/usb_events.c 
	@-${MV} ${OBJECTDIR}/picLibs/usb_events.d ${OBJECTDIR}/picLibs/usb_events.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/picLibs/usb_events.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/main.p1: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.p1.d 
	@${RM} ${OBJECTDIR}/main.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=pro -P -N255 -I"libs" -I"usbLibs" -I"picLibs" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/main.p1  main.c 
	@-${MV} ${OBJECTDIR}/main.d ${OBJECTDIR}/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/libs/programming.p1: libs/programming.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/libs" 
	@${RM} ${OBJECTDIR}/libs/programming.p1.d 
	@${RM} ${OBJECTDIR}/libs/programming.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=pro -P -N255 -I"libs" -I"usbLibs" -I"picLibs" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/libs/programming.p1  libs/programming.c 
	@-${MV} ${OBJECTDIR}/libs/programming.d ${OBJECTDIR}/libs/programming.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/libs/programming.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/libs/progPIC18F26K40.p1: libs/progPIC18F26K40.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/libs" 
	@${RM} ${OBJECTDIR}/libs/progPIC18F26K40.p1.d 
	@${RM} ${OBJECTDIR}/libs/progPIC18F26K40.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=pro -P -N255 -I"libs" -I"usbLibs" -I"picLibs" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/libs/progPIC18F26K40.p1  libs/progPIC18F26K40.c 
	@-${MV} ${OBJECTDIR}/libs/progPIC18F26K40.d ${OBJECTDIR}/libs/progPIC18F26K40.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/libs/progPIC18F26K40.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/picLibs/app_device_cdc_basic.p1: picLibs/app_device_cdc_basic.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/picLibs" 
	@${RM} ${OBJECTDIR}/picLibs/app_device_cdc_basic.p1.d 
	@${RM} ${OBJECTDIR}/picLibs/app_device_cdc_basic.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=pro -P -N255 -I"libs" -I"usbLibs" -I"picLibs" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/picLibs/app_device_cdc_basic.p1  picLibs/app_device_cdc_basic.c 
	@-${MV} ${OBJECTDIR}/picLibs/app_device_cdc_basic.d ${OBJECTDIR}/picLibs/app_device_cdc_basic.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/picLibs/app_device_cdc_basic.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/picLibs/app_led_usb_status.p1: picLibs/app_led_usb_status.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/picLibs" 
	@${RM} ${OBJECTDIR}/picLibs/app_led_usb_status.p1.d 
	@${RM} ${OBJECTDIR}/picLibs/app_led_usb_status.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=pro -P -N255 -I"libs" -I"usbLibs" -I"picLibs" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/picLibs/app_led_usb_status.p1  picLibs/app_led_usb_status.c 
	@-${MV} ${OBJECTDIR}/picLibs/app_led_usb_status.d ${OBJECTDIR}/picLibs/app_led_usb_status.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/picLibs/app_led_usb_status.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/picLibs/buttons.p1: picLibs/buttons.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/picLibs" 
	@${RM} ${OBJECTDIR}/picLibs/buttons.p1.d 
	@${RM} ${OBJECTDIR}/picLibs/buttons.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=pro -P -N255 -I"libs" -I"usbLibs" -I"picLibs" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/picLibs/buttons.p1  picLibs/buttons.c 
	@-${MV} ${OBJECTDIR}/picLibs/buttons.d ${OBJECTDIR}/picLibs/buttons.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/picLibs/buttons.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/picLibs/leds.p1: picLibs/leds.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/picLibs" 
	@${RM} ${OBJECTDIR}/picLibs/leds.p1.d 
	@${RM} ${OBJECTDIR}/picLibs/leds.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=pro -P -N255 -I"libs" -I"usbLibs" -I"picLibs" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/picLibs/leds.p1  picLibs/leds.c 
	@-${MV} ${OBJECTDIR}/picLibs/leds.d ${OBJECTDIR}/picLibs/leds.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/picLibs/leds.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/picLibs/system.p1: picLibs/system.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/picLibs" 
	@${RM} ${OBJECTDIR}/picLibs/system.p1.d 
	@${RM} ${OBJECTDIR}/picLibs/system.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=pro -P -N255 -I"libs" -I"usbLibs" -I"picLibs" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/picLibs/system.p1  picLibs/system.c 
	@-${MV} ${OBJECTDIR}/picLibs/system.d ${OBJECTDIR}/picLibs/system.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/picLibs/system.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/picLibs/usb_descriptors.p1: picLibs/usb_descriptors.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/picLibs" 
	@${RM} ${OBJECTDIR}/picLibs/usb_descriptors.p1.d 
	@${RM} ${OBJECTDIR}/picLibs/usb_descriptors.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=pro -P -N255 -I"libs" -I"usbLibs" -I"picLibs" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/picLibs/usb_descriptors.p1  picLibs/usb_descriptors.c 
	@-${MV} ${OBJECTDIR}/picLibs/usb_descriptors.d ${OBJECTDIR}/picLibs/usb_descriptors.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/picLibs/usb_descriptors.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/picLibs/usb_device.p1: picLibs/usb_device.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/picLibs" 
	@${RM} ${OBJECTDIR}/picLibs/usb_device.p1.d 
	@${RM} ${OBJECTDIR}/picLibs/usb_device.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=pro -P -N255 -I"libs" -I"usbLibs" -I"picLibs" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/picLibs/usb_device.p1  picLibs/usb_device.c 
	@-${MV} ${OBJECTDIR}/picLibs/usb_device.d ${OBJECTDIR}/picLibs/usb_device.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/picLibs/usb_device.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/picLibs/usb_device_cdc.p1: picLibs/usb_device_cdc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/picLibs" 
	@${RM} ${OBJECTDIR}/picLibs/usb_device_cdc.p1.d 
	@${RM} ${OBJECTDIR}/picLibs/usb_device_cdc.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=pro -P -N255 -I"libs" -I"usbLibs" -I"picLibs" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/picLibs/usb_device_cdc.p1  picLibs/usb_device_cdc.c 
	@-${MV} ${OBJECTDIR}/picLibs/usb_device_cdc.d ${OBJECTDIR}/picLibs/usb_device_cdc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/picLibs/usb_device_cdc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/picLibs/usb_events.p1: picLibs/usb_events.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/picLibs" 
	@${RM} ${OBJECTDIR}/picLibs/usb_events.p1.d 
	@${RM} ${OBJECTDIR}/picLibs/usb_events.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=pro -P -N255 -I"libs" -I"usbLibs" -I"picLibs" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/picLibs/usb_events.p1  picLibs/usb_events.c 
	@-${MV} ${OBJECTDIR}/picLibs/usb_events.d ${OBJECTDIR}/picLibs/usb_events.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/picLibs/usb_events.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/main.p1: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.p1.d 
	@${RM} ${OBJECTDIR}/main.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=pro -P -N255 -I"libs" -I"usbLibs" -I"picLibs" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/main.p1  main.c 
	@-${MV} ${OBJECTDIR}/main.d ${OBJECTDIR}/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/progVer004.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) --chip=$(MP_PROCESSOR_OPTION) -G -mdist/${CND_CONF}/${IMAGE_TYPE}/progVer004.X.${IMAGE_TYPE}.map  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=pro -P -N255 -I"libs" -I"usbLibs" -I"picLibs" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"     --rom=default,-3e00-3fff   $(COMPARISON_BUILD) --memorysummary dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -odist/${CND_CONF}/${IMAGE_TYPE}/progVer004.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} dist/${CND_CONF}/${IMAGE_TYPE}/progVer004.X.${IMAGE_TYPE}.hex 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/progVer004.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) --chip=$(MP_PROCESSOR_OPTION) -G -mdist/${CND_CONF}/${IMAGE_TYPE}/progVer004.X.${IMAGE_TYPE}.map  --double=24 --float=24 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=pro -P -N255 -I"libs" -I"usbLibs" -I"picLibs" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"     $(COMPARISON_BUILD) --memorysummary dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -odist/${CND_CONF}/${IMAGE_TYPE}/progVer004.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
