@echo off

REM This script sets all enviroment variables, which
REM are necessary for building the examples of the Office Development Kit.
REM The Script was developed for the operating systems Windows.

REM The SDK name
set OO_SDK_NAME=[SDKNAME]

REM Installation directory of the Software Development Kit.
REM Example: set OO_SDK_HOME=D:\StarOffice_SDK
set OO_SDK_HOME=

REM Office installation directory.
REM Example: set OFFICE_HOME=C:\Programme\StarOffice
set OFFICE_HOME=

REM Directory of the make command.
REM Example: set OO_SDK_MAKE_HOME=D:\NextGenerationMake\make
set OO_SDK_MAKE_HOME=

REM Directory of the zip tool.
REM Example: set OO_SDK_ZIP_HOME=D:\infozip\bin
set OO_SDK_ZIP_HOME=

REM Directory of the C++ compiler.
REM Example:set OO_SDK_CPP_HOME=C:\Programme\Microsoft Visual Studio\VC98\bin
set OO_SDK_CPP_HOME=

REM Directory of the C# and VB.NET compilers.
REM Example:set OO_SDK_CLI_HOME=C:\WINXP\Microsoft.NET\Framework\v1.1.4322
set OO_SDK_CLI_HOME=

REM Java installation directory.
REM Example: set OO_SDK_JAVA_HOME=c:\j2sdk1.4.1_01
set OO_SDK_JAVA_HOME=

REM Special output directory
REM Example: set OO_SDK_OUTPUT_DIR=c:\temp
set OO_SDK_OUTPUT_DIR=

REM Automatic deployment
REM Example: set SDK_AUTO_DEPLOYMENT=YES
set SDK_AUTO_DEPLOYMENT=YES

REM bootstrap variable, needed by the java framework
REM Example: set UNO_JAVA_JFW_JREHOME=file:///d:/java/jdk1.5
set UNO_JAVA_JFW_JREHOME=

REM bootstrap variable, needed by the java framework
REM Example: set UNO_JAVA_JFW_ENV_CLASSPATH=true
set UNO_JAVA_JFW_ENV_CLASSPATH=true

REM bootstrap variable, needed by the java framework
REM Example: set UNO_JAVA_JFW_VENDOR_SETTINGS=file:///c:/program files/StarOffice%%208/share/config/javavendors.xml
set UNO_JAVA_JFW_VENDOR_SETTINGS=

REM Check installation path for the StarOffice Development Kit.
if not defined OO_SDK_HOME (
  echo Error: the variable OO_SDK_HOME is missing!
  goto :error
)

REM Check installation path for the office.
if not defined OFFICE_HOME (
  echo Error: the variable OFFICE_HOME is missing!
  goto :error
)

REM Check installation path for GNU make.
if not defined OO_SDK_MAKE_HOME (
  echo Error: the variable OO_SDK_MAKE_HOME is missing!
  goto :error
)

REM Check installation path for the zip tool.
if not defined OO_SDK_ZIP_HOME (
  echo Error: the variable OO_SDK_ZIP_HOME is missing!
  goto :error
)

REM Set library path.
set LIB=%OO_SDK_HOME%\windows\lib;%OO_SDK_HOME%\WINexample.out\lib;%LIB%

REM Set office program path.
set OFFICE_PROGRAM_PATH=%OFFICE_HOME%\program

REM Set UNO path, necessary to ensure that the cpp examples using the
REM new UNO bootstrap mechanism use the configured office installation.
set UNO_PATH=%OFFICE_PROGRAM_PATH%

REM Set classpath
set CLASSPATH=%OFFICE_PROGRAM_PATH%\classes\jurt.jar;%OFFICE_PROGRAM_PATH%\classes\unoil.jar;%OFFICE_PROGRAM_PATH%\classes\ridl.jar;%OFFICE_PROGRAM_PATH%\classes\sandbox.jar;%OFFICE_PROGRAM_PATH%\classes\juh.jar

REM Add directory of the SDK tools to the path.
set PATH=%OO_SDK_HOME%\windows\bin;%OFFICE_HOME%\program;%OO_SDK_HOME%\WINexample.out\bin;%PATH%

REM Set PATH appropriate to the output directory
if defined OO_SDK_OUTPUT_DIR (
  set PATH=%OO_SDK_OUTPUT_DIR%\%OO_SDK_NAME%\WINexample.out\bin;%PATH%
) else (
  set PATH=%OO_SDK_HOME%\WINexample.out\bin;%PATH%
)

REM Add directory of the command make to the path, if necessary.
if defined OO_SDK_MAKE_HOME set PATH=%OO_SDK_MAKE_HOME%;%PATH%

REM Add directory of the zip tool to the path, if necessary.
if defined OO_SDK_ZIP_HOME set PATH=%OO_SDK_ZIP_HOME%;%PATH%

REM Add directory of the C++ compiler to the path, if necessary.
if defined OO_SDK_CPP_HOME set PATH=%OO_SDK_CPP_HOME%;%PATH%

REM Add directory of the C# and VB.NET compilers to the path, if necessary.
if defined OO_SDK_CLI_HOME set PATH=%OO_SDK_CLI_HOME%;%PATH%

REM Add directory of the Java tools to the path, if necessary.
if defined OO_SDK_JAVA_HOME set PATH=%OO_SDK_JAVA_HOME%\bin;%OO_SDK_JAVA_HOME%\jre\bin;%PATH%

REM Set environment for C++ compiler tools, if necessary.
if defined OO_SDK_CPP_HOME call "%OO_SDK_CPP_HOME%\VCVARS32.bat"

REM Set tilte to identify the prepared shell.
title Shell prepared for SDK

REM Prepare shell with all necessary environment variables.
echo. 
echo  ************************************************************************
echo  *
echo  * SDK environment is prepared for Windows
echo  *       
echo  * SDK = %OO_SDK_HOME%
echo  * Office = %OFFICE_HOME%
echo  * Make = %OO_SDK_MAKE_HOME%
echo  * Zip = %OO_SDK_ZIP_HOME%
echo  * C++ Compiler = %OO_SDK_CPP_HOME%
echo  * C# and VB.NET compilers = %OO_SDK_CLI_HOME%
echo  * Java = %OO_SDK_JAVA_HOME%
echo  * Special Output directory = %OO_SDK_OUTPUT_DIR%
echo  * Auto deployment = %SDK_AUTO_DEPLOYMENT%
echo  *
echo  ************************************************************************

goto end

:error
Error: Please insert the necessary environment variables into the batch file.

:end
