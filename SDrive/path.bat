@ECHO OFF
set drive=%cd:~0,3%
set bin=%drive%_bin\
set font=%bin%_font\
path = %path%;C:\Program Files\Java\jdk1.6.0_17\bin;%bin%;%bin%\Mercurial\;%bin%\gnuutil;C:\Perl64\bin
echo Done!
net use z: \\172.16.2.49\amrit.panesar$ /user:amrit.panesar *