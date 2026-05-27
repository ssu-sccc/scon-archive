pushd ..\..\problems\where-is-my-icp\statements\english
for %%i in (*.mp) do (
	mpost %%i || goto error
)
del /F /Q *.log
popd

pushd ..\..\problems\soongsil-station\statements\english
for %%i in (*.mp) do (
	mpost %%i || goto error
)
del /F /Q *.log
popd

pushd ..\..\problems\cream-first-jam-first\statements\english
for %%i in (*.mp) do (
	mpost %%i || goto error
)
del /F /Q *.log
popd

pushd ..\..\problems\lexicographical-minimum\statements\english
for %%i in (*.mp) do (
	mpost %%i || goto error
)
del /F /Q *.log
popd

pushd ..\..\problems\flip-range\statements\english
for %%i in (*.mp) do (
	mpost %%i || goto error
)
del /F /Q *.log
popd

pushd ..\..\problems\unique-range-easy\statements\english
for %%i in (*.mp) do (
	mpost %%i || goto error
)
del /F /Q *.log
popd

pushd ..\..\problems\evaluate\statements\english
for %%i in (*.mp) do (
	mpost %%i || goto error
)
del /F /Q *.log
popd

pushd ..\..\problems\make-same\statements\english
for %%i in (*.mp) do (
	mpost %%i || goto error
)
del /F /Q *.log
popd

pushd ..\..\problems\god-of-trouble\statements\english
for %%i in (*.mp) do (
	mpost %%i || goto error
)
del /F /Q *.log
popd

pushd ..\..\problems\scon-magic-graph\statements\english
for %%i in (*.mp) do (
	mpost %%i || goto error
)
del /F /Q *.log
popd

pushd ..\..\problems\xor-palindrome\statements\english
for %%i in (*.mp) do (
	mpost %%i || goto error
)
del /F /Q *.log
popd

pushd ..\..\problems\snake-seq\statements\english
for %%i in (*.mp) do (
	mpost %%i || goto error
)
del /F /Q *.log
popd

pushd ..\..\problems\pspoker\statements\english
for %%i in (*.mp) do (
	mpost %%i || goto error
)
del /F /Q *.log
popd

pushd ..\..\problems\unique-range\statements\english
for %%i in (*.mp) do (
	mpost %%i || goto error
)
del /F /Q *.log
popd

pushd ..\..\problems\find\statements\english
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
