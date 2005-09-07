#*************************************************************************
#
#   OpenOffice.org - a multi-platform office productivity suite
#
#   $RCSfile: makefile.mk,v $
#
#   $Revision: 1.5 $
#
#   last change: $Author: rt $ $Date: 2005-09-07 20:12:51 $
#
#   The Contents of this file are made available subject to
#   the terms of GNU Lesser General Public License Version 2.1.
#
#
#     GNU Lesser General Public License Version 2.1
#     =============================================
#     Copyright 2005 by Sun Microsystems, Inc.
#     901 San Antonio Road, Palo Alto, CA 94303, USA
#
#     This library is free software; you can redistribute it and/or
#     modify it under the terms of the GNU Lesser General Public
#     License version 2.1, as published by the Free Software Foundation.
#
#     This library is distributed in the hope that it will be useful,
#     but WITHOUT ANY WARRANTY; without even the implied warranty of
#     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
#     Lesser General Public License for more details.
#
#     You should have received a copy of the GNU Lesser General Public
#     License along with this library; if not, write to the Free Software
#     Foundation, Inc., 59 Temple Place, Suite 330, Boston,
#     MA  02111-1307  USA
#
#*************************************************************************

PRJ=..$/..$/..
PRJNAME=odk
TARGET=copying

#----------------------------------------------------------------
.INCLUDE: settings.mk
.INCLUDE: $(PRJ)$/util$/makefile.pmk
#----------------------------------------------------------------

#----------------------------------------------------
# this makefile is only used for copying the example 
# files into the SDK
#----------------------------------------------------


OFFICEDEV_FILES=\
    $(DESTDIRDEVGUIDEEXAMPLES)$/OfficeDev$/ContextMenuInterceptor.java \
    $(DESTDIRDEVGUIDEEXAMPLES)$/OfficeDev$/Makefile \
    $(DESTDIRDEVGUIDEEXAMPLES)$/OfficeDev$/MenuElement.java \
    $(DESTDIRDEVGUIDEEXAMPLES)$/OfficeDev$/Number_Formats.java \
    $(DESTDIRDEVGUIDEEXAMPLES)$/OfficeDev$/OfficeConnect.java

DESTCLIPBOARD=$(DESTDIRDEVGUIDEEXAMPLES)$/OfficeDev$/Clipboard
CLIPBOARD_FILES=\
    $(DESTCLIPBOARD)$/Clipboard.java \
    $(DESTCLIPBOARD)$/ClipboardListener.java \
    $(DESTCLIPBOARD)$/ClipboardOwner.java \
    $(DESTCLIPBOARD)$/Makefile \
    $(DESTCLIPBOARD)$/TextTransferable.java

DESTDESKTOPENV=$(DESTDIRDEVGUIDEEXAMPLES)$/OfficeDev$/DesktopEnvironment
DESKTOPENV_FILES=\
    $(DESTDESKTOPENV)$/nativelib$/unix$/exports.dxp \
    $(DESTDESKTOPENV)$/nativelib$/unix$/Makefile \
    $(DESTDESKTOPENV)$/nativelib$/unix$/nativeview.c \
    $(DESTDESKTOPENV)$/nativelib$/unix$/nativeview.h \
    $(DESTDESKTOPENV)$/nativelib$/windows$/exports.dxp \
    $(DESTDESKTOPENV)$/nativelib$/windows$/Makefile \
    $(DESTDESKTOPENV)$/nativelib$/windows$/nativeview.c \
    $(DESTDESKTOPENV)$/nativelib$/windows$/nativeview.h \
    $(DESTDESKTOPENV)$/CustomizeView.java \
    $(DESTDESKTOPENV)$/Desk.java \
    $(DESTDESKTOPENV)$/DocumentView.java \
    $(DESTDESKTOPENV)$/FunctionHelper.java \
    $(DESTDESKTOPENV)$/Install.txt \
    $(DESTDESKTOPENV)$/Interceptor.java \
    $(DESTDESKTOPENV)$/IOnewayLink.java \
    $(DESTDESKTOPENV)$/IShutdownListener.java \
    $(DESTDESKTOPENV)$/JavaWindowPeerFake.java \
    $(DESTDESKTOPENV)$/Makefile \
    $(DESTDESKTOPENV)$/NativeView.java \
    $(DESTDESKTOPENV)$/OfficeConnect.java \
    $(DESTDESKTOPENV)$/OnewayExecutor.java \
    $(DESTDESKTOPENV)$/StatusListener.java \
    $(DESTDESKTOPENV)$/StatusView.java \
    $(DESTDESKTOPENV)$/ViewContainer.java

DESTASCIIFILTER=$(DESTDIRDEVGUIDEEXAMPLES)$/OfficeDev$/FilterDevelopment$/AsciiFilter
ASCIIFILTER_FILES=\
    $(DESTASCIIFILTER)$/AsciiReplaceFilter.java \
    $(DESTASCIIFILTER)$/FilterOptions.java \
    $(DESTASCIIFILTER)$/Makefile \
    $(DESTASCIIFILTER)$/TypeDetection.xcu

DESTFILTERDETECTION=$(DESTDIRDEVGUIDEEXAMPLES)$/OfficeDev$/FilterDevelopment$/FlatXmlFilterDetection
FILTERDETECTION_FILES=\
    $(DESTFILTERDETECTION)$/fdcomp.cxx \
    $(DESTFILTERDETECTION)$/filterdetect.cxx \
    $(DESTFILTERDETECTION)$/filterdetect.hxx \
    $(DESTFILTERDETECTION)$/FlatXmlTypeDetection.uno.xml \
    $(DESTFILTERDETECTION)$/FlatXmlTypeDetection.xcu \
    $(DESTFILTERDETECTION)$/Makefile

DESTFLATXMLCPP=$(DESTDIRDEVGUIDEEXAMPLES)$/OfficeDev$/FilterDevelopment$/FlatXmlFilter_cpp
FLATXMLCPP_FILES=\
    $(DESTFLATXMLCPP)$/FlatXml.cxx \
    $(DESTFLATXMLCPP)$/FlatXmlFilter_cpp.uno.xml \
    $(DESTFLATXMLCPP)$/Makefile \
    $(DESTFLATXMLCPP)$/FlatXmlFilter_cpp.xcu

DESTFLATXMLJAVA=$(DESTDIRDEVGUIDEEXAMPLES)$/OfficeDev$/FilterDevelopment$/FlatXmlFilter_java
FLATXMLJAVA_FILES=\
    $(DESTFLATXMLJAVA)$/Makefile \
    $(DESTFLATXMLJAVA)$/FlatXmlFilter_java.xcu \
    $(DESTFLATXMLJAVA)$/FlatXml.java

DESTLINGUISTIC=$(DESTDIRDEVGUIDEEXAMPLES)$/OfficeDev$/Linguistic
LINGUISTIC_FILES=\
    $(DESTLINGUISTIC)$/LinguisticExamples.java \
    $(DESTLINGUISTIC)$/Makefile \
    $(DESTLINGUISTIC)$/OneInstanceFactory.java \
    $(DESTLINGUISTIC)$/PropChgHelper.java \
    $(DESTLINGUISTIC)$/PropChgHelper_Hyph.java \
    $(DESTLINGUISTIC)$/PropChgHelper_Spell.java \
    $(DESTLINGUISTIC)$/SampleHyphenator.java \
    $(DESTLINGUISTIC)$/SampleSpellChecker.java \
    $(DESTLINGUISTIC)$/SampleThesaurus.java \
    $(DESTLINGUISTIC)$/XHyphenatedWord_impl.java \
    $(DESTLINGUISTIC)$/XMeaning_impl.java \
    $(DESTLINGUISTIC)$/XPossibleHyphens_impl.java \
    $(DESTLINGUISTIC)$/XSpellAlternatives_impl.java

DESTPATHSETTINGS=$(DESTDIRDEVGUIDEEXAMPLES)$/OfficeDev$/PathSettings
PATHSETTINGS_FILES=\
    $(DESTPATHSETTINGS)$/Makefile \
    $(DESTPATHSETTINGS)$/PathSettingsTest.java

DESTPATHSUBSTITUTION=$(DESTDIRDEVGUIDEEXAMPLES)$/OfficeDev$/PathSubstitution
PATHSUBSTITUTION_FILES=\
    $(DESTPATHSUBSTITUTION)$/Makefile \
    $(DESTPATHSUBSTITUTION)$/PathSubstitutionTest.java

DESTTERMINATIONTEST=$(DESTDIRDEVGUIDEEXAMPLES)$/OfficeDev$/TerminationTest
TERMINATION_FILES=\
    $(DESTTERMINATIONTEST)$/Makefile \
    $(DESTTERMINATIONTEST)$/TerminateListener.java \
    $(DESTTERMINATIONTEST)$/TerminationTest.java

DESTDISABLECOMMANDS=$(DESTDIRDEVGUIDEEXAMPLES)$/OfficeDev$/DisableCommands
DISABLECOMMANDS_FILES=\
    $(DESTDISABLECOMMANDS)$/Makefile \
    $(DESTDISABLECOMMANDS)$/DisableCommandsTest.java

DIR_FILE_LIST= \
    $(OFFICEDEV_FILES) \
    $(CLIPBOARD_FILES) \
    $(DESKTOPENV_FILES) \
    $(ASCIIFILTER_FILES) \
    $(FILTERDETECTION_FILES) \
    $(FLATXMLCPP_FILES) \
    $(FLATXMLJAVA_FILES) \
    $(LINGUISTIC_FILES) \
    $(PATHSETTINGS_FILES) \
    $(PATHSUBSTITUTION_FILES) \
    $(TERMINATION_FILES) \
    $(DISABLECOMMANDS_FILES)

DIR_DIRECTORY_LIST=$(uniq $(DIR_FILE_LIST:d))
DIR_CREATE_FLAG=$(MISC)$/devguide_officedev_dirs_created.txt
DIR_FILE_FLAG=$(MISC)$/devguide_officedev.txt

#--------------------------------------------------
# TARGETS
#--------------------------------------------------
all : \
    $(DIR_FILE_LIST) \
    $(DIR_FILE_FLAG)

#--------------------------------------------------
# use global rules
#--------------------------------------------------   
.INCLUDE: $(PRJ)$/util$/odk_rules.pmk
    
