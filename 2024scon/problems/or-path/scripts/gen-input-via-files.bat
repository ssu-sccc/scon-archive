rem Generate several test inputs in a temporary directory and copy them
rem to the requested target paths in the package root
rem
rem Arguments:
rem   parameter 1 - trusted generator command line, executed inside the temporary directory
rem   parameter 2 - target test input file paths relative to the package root, separated by ':'
rem   parameter 3 - generated file indices, separated by ':'
rem
rem Notes:
rem - parameter 1 is executed as-is and therefore must be trusted
rem - in normal usage, doall.bat is expected to generate parameter 1 safely
rem - generated files are looked up by index first, then by zero-padded variants

rem DisableDelayedExpansion is used to prevent cmd from interpreting
rem exclamation marks inside the passed command line as !VAR! expansions
setlocal DisableDelayedExpansion

if "%~1"=="" (
    echo First parameter is empty
    pause 0
)

if "%~2"=="" (
    echo Second parameter is empty
    pause 0
)

if "%~3"=="" (
    echo Third parameter is empty
    pause 0
)

rem Recreate the temporary working directory from scratch
if exist tmp-for-generator-execution (
    rd /S /Q tmp-for-generator-execution
)
md tmp-for-generator-execution
cd tmp-for-generator-execution

rem Run the generator inside the temporary directory
%~1

if errorlevel 1 (
    echo The generator command was executed, but it returned a non-zero exit code
    pause 0
)


setlocal EnableDelayedExpansion

set paths=%~2
set indices=%~3

:tokenLoop

if "!paths!" EQU "" goto splitEnd
if "!indices!" EQU "" goto splitEnd

for /f "delims=:" %%a in ("!paths!") do set pathItem=%%a
for /f "delims=:" %%a in ("!indices!") do set indexItem=%%a

if exist "..\!pathItem!" (
    del /F /Q "..\!pathItem!" >nul 2>nul
)

set copied=0
if exist "!indexItem!" (
    copy "!indexItem!" "..\!pathItem!" >nul && set "copied=1"
)
if "!copied!"=="0" if exist "0!indexItem!" (
    copy "0!indexItem!" "..\!pathItem!" >nul && set "copied=1"
)
if "!copied!"=="0" if exist "00!indexItem!" (
    copy "00!indexItem!" "..\!pathItem!" >nul && set "copied=1"
)

if "!copied!"=="0" (
    echo Unable to find test !indexItem!
    pause 0
)

echo Test #!indexItem! has been generated and copied to !pathItem!

:pathsStripLoop
set pathsFirstChar=!paths:~0,1!
set paths=!paths:~1!
if "!paths!" EQU "" goto splitEnd
if "!pathsFirstChar!" NEQ ":" goto pathsStripLoop

:indicesStripLoop
set indicesFirstChar=!indices:~0,1!
set indices=!indices:~1!
if "!indices!" EQU "" goto splitEnd
if "!indicesFirstChar!" NEQ ":" goto indicesStripLoop

goto tokenLoop
:splitEnd

endlocal

cd ..
rd /S /Q tmp-for-generator-execution
