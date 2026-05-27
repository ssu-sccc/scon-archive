pushd ..\..\problems\irritable-bowel-syndrome\statements\korean
for %%i in (*.mp) do (
	mpost %%i || goto error
)
del /F /Q *.log
popd

pushd ..\..\problems\team-name-2\statements\korean
for %%i in (*.mp) do (
	mpost %%i || goto error
)
del /F /Q *.log
popd

pushd ..\..\problems\concat\statements\korean
for %%i in (*.mp) do (
	mpost %%i || goto error
)
del /F /Q *.log
popd

pushd ..\..\problems\visit-all-easy\statements\korean
for %%i in (*.mp) do (
	mpost %%i || goto error
)
del /F /Q *.log
popd

pushd ..\..\problems\modify-expression\statements\korean
for %%i in (*.mp) do (
	mpost %%i || goto error
)
del /F /Q *.log
popd

pushd ..\..\problems\fibonacci-partition\statements\korean
for %%i in (*.mp) do (
	mpost %%i || goto error
)
del /F /Q *.log
popd

pushd ..\..\problems\create-timetable\statements\korean
for %%i in (*.mp) do (
	mpost %%i || goto error
)
del /F /Q *.log
popd

pushd ..\..\problems\fork\statements\korean
for %%i in (*.mp) do (
	mpost %%i || goto error
)
del /F /Q *.log
popd

pushd ..\..\problems\beautiful-fireworks\statements\korean
for %%i in (*.mp) do (
	mpost %%i || goto error
)
del /F /Q *.log
popd

pushd ..\..\problems\or-path\statements\korean
for %%i in (*.mp) do (
	mpost %%i || goto error
)
del /F /Q *.log
popd

pushd ..\..\problems\visit-all\statements\korean
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
