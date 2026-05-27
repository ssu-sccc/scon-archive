pushd ..\..\problems\alphabet-block\statements\korean
for %%i in (*.mp) do (
	mpost %%i || goto error
)
del /F /Q *.log
popd

pushd ..\..\problems\prize-game\statements\korean
for %%i in (*.mp) do (
	mpost %%i || goto error
)
del /F /Q *.log
popd

pushd ..\..\problems\seq-min-sum\statements\korean
for %%i in (*.mp) do (
	mpost %%i || goto error
)
del /F /Q *.log
popd

pushd ..\..\problems\n-way-intersection\statements\korean
for %%i in (*.mp) do (
	mpost %%i || goto error
)
del /F /Q *.log
popd

pushd ..\..\problems\even-sccc-scon\statements\korean
for %%i in (*.mp) do (
	mpost %%i || goto error
)
del /F /Q *.log
popd

pushd ..\..\problems\a-xor-b-equal-c\statements\korean
for %%i in (*.mp) do (
	mpost %%i || goto error
)
del /F /Q *.log
popd

pushd ..\..\problems\coloring\statements\korean
for %%i in (*.mp) do (
	mpost %%i || goto error
)
del /F /Q *.log
popd

pushd ..\..\problems\coprime-combination\statements\korean
for %%i in (*.mp) do (
	mpost %%i || goto error
)
del /F /Q *.log
popd

pushd ..\..\problems\divideteam\statements\korean
for %%i in (*.mp) do (
	mpost %%i || goto error
)
del /F /Q *.log
popd

pushd ..\..\problems\delicious-scon\statements\korean
for %%i in (*.mp) do (
	mpost %%i || goto error
)
del /F /Q *.log
popd

latex statements.tex
latex statements.tex || goto error
dvips statements.dvi || goto error
dvipdfmx -p a4 statements.dvi || goto error

del /F /Q *.log
del /F /Q *.aux
del /F /Q *.dvi
del /F /Q *.ps

goto ok

:error
echo [ERROR]: Can't compile/build statements.
exit 1

:ok
echo [INFO]: Statements have been compiled/build.
