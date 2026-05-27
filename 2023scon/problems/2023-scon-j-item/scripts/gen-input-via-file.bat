rem Generate test input in a temporary directory and copy one produced file
rem to the requested target path in the package root
rem
rem Arguments:
rem   parameter 1 - trusted generator command line, executed inside the temporary directory
rem   parameter 2 - target test input file path relative to the package root
rem   parameter 3 - generated file name or index inside the temporary directory
rem
rem Notes:
rem - parameter 1 is executed as-is and therefore must be trusted
rem - in normal usage, doall.bat is expected to generate parameter 1 safely

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

rem Remove the previous target file before generating a new one
del /F /Q "%~2" >nul 2>nul

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

if exist "%~3" (
    copy "%~3" "..\%~2" >nul
)

cd ..
rd /S /Q tmp-for-generator-execution

if not exist "%~2" (
    pause 0
)
