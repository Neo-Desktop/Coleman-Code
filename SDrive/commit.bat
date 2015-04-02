@echo off

call path.bat

set ttrn=%time:~0,2%%time:~3,2%%time:~6,2%%time:~9,2%
set /P cmessage=Enter a commit message for todays changes (%ttrn%):

hg add
hg commit -m "%cmessage% auto-commit at %ttrn%"

echo Done!
