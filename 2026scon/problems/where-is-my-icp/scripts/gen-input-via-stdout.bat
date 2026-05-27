rem Generate test input by redirecting the generator stdout to the target file
rem
rem Arguments:
rem   parameter 1 - trusted generator command
rem   parameter 2 - target test input file path relative to the current directory
rem
rem Notes:
rem - parameter 1 must be trusted
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

rem Remove the previous output file before generating a new one
del /F /Q "%~2" >nul 2>nul

rem Execute the generator command and redirect stdout to the target file
%~1 > "%~2"
if errorlevel 1 (
    echo The generator command was executed, but it returned a non-zero exit code
    pause 0
)

rem Double-check that the target file really exists after generation
if not exist "%~2" (
    echo The generator command completed, but the output file "%~2" was not created
    pause 0
)
