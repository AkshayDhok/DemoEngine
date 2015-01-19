@pushd "%~1"
@xcopy dlls\*.dll "%~2" /y /s /q /d
@popd